/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */
#include "atraso.h"
#include "defPrincipais.h"
#include "NOKIA5110_fb.h"
#include "figuras.h"
#include "PRNG_LFSR.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

//osThreadId defaultTaskHandle;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
volatile uint32_t ADC_VALOR[2];
uint32_t adcDmaBuffer[2];
__IO ITStatus ADCReady = RESET;

static uint32_t media_eixoX, media_eixoY;
static struct pontos_t p;
typedef struct Player{
	uint32_t scores;
	uint32_t missings;
}player_t;

player_t player;
Missings_t missings;

//missingsSquare[0]={ZeroMole};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
//void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */
void Start_Game();
/* Private function prototypes -----------------------------------------------*/
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	if(hadc->Instance == ADC1)
	{
		ADC_VALOR[0] = adcDmaBuffer[0];
		ADC_VALOR[1] = adcDmaBuffer[1];
	}

}
//---------------------------------------------------------------------------------------------------
// Tarefa para atualizar periodicamente o LCD
void vTask_LCD_Print(void *pvParameters)
{
	while(1) imprime_LCD();
}
//---------------------------------------------------------------------------------------------------
// Tarefa para imprimir um numero aleatorio
void vTask_Nr_Print(void *pvParameters)
{
	//uint32_t rand_prng;
	//(83 - fig.largura)/2 +1 = 38
	//static uint32_t x = (83-29)/2, y = (47-19)/2;
	//static int32_t dif_eixoX, dif_eixoY;

	//p.x1 = 83-9; p.y1 = 47-8;
	p.x1 = 0; p.y1 = 0;
	p.x2 = 0; p.y2 = 0;
	p.x3 = 0; p.y3 = 0;

	//while(1)
	/*{
		//rand_prng = prng_LFSR();
		//escreve_Nr_Peq(10,10, rand_prng, 10);
		escreve_Nr_Peq(10,20, media_eixoX, 10);
		escreve_Nr_Peq(10,30, media_eixoY, 10);
		goto_XY(0,0);
		//desenha_fig(&p, &nave0f);

		//string_LCD_Nr("Nr=", rand_prng, 10);			// escreve uma mensagem com um número

		vTaskDelay(500);
	}*/
	while(1)
	{
	}
}

void vTask_move_MrWatchAndGame(void *pvParameters)
{
	static uint32_t x = (83-29)/2, y = (47-19)/2;  //(83 - fig.largura)/2 +1
	static int32_t dif_eixoX, dif_eixoY;

	p.x1 = 0; p.y1 = 0;
	p.x2 = 0; p.y2 = 0;
	p.x3 = 0; p.y3 = 0;

	while(1)
	{
		dif_eixoX = 2048 - media_eixoX;
		dif_eixoY = 2048 - media_eixoY;

		if(dif_eixoX < -100)
		{
			if(x>0) x--;
		}
		else if(dif_eixoX > 100) // 100 = Delta de tolerancia no deslocamento do eixo
		{
			if(x<55) x++;
		}
		// ------------------------------------------------------------------------
		if(dif_eixoY < -100)
		{
			if(y<29) y++;
		}

		else if(dif_eixoY > 100)
		{
			if(y>0) y--;
		}
		// ------------------------------------------------------------------------
		p.x1 = x;  p.y1 = 2;

		desenha_fig(&p,&MrGameAndWatch);
		vTaskDelay(MS(20));					// atraso para a nave não se movimentar muito rápido.
		desenha_fig(&p,&delete_MrGameAndWatch);
	}
}

void vTask_read_joystick(void *pvParameters)
{
	uint8_t i;
	static uint32_t x[32], y[32], k=0;
	uint32_t x_aux, y_aux;
	while(1){
		x[k] = ADC_VALOR[0];
		y[k] = ADC_VALOR[1];
		k++; if(k==32) k=0;
		x_aux=0;
		y_aux=0;
		for(i = 0; i<32; i++){
			x_aux += x[i];
			y_aux += y[i];
		}
		media_eixoX = x_aux/32;
		media_eixoY = y_aux/32;
	}
}
//---------------------------------------------------------------------------------------------------
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* MCU Configuration----------------------------------------------------------*/
 player.missings = 0;
 player.scores = 222;
 set_missingFigures(&missings,&ZeroMole,0 );

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();


	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_ADC1_Init();

	/* USER CODE BEGIN 2 */
	HAL_ADCEx_Calibration_Start(&hadc1);
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*)adcDmaBuffer,2);
	HAL_ADC_Start_IT(&hadc1);

	// inicializa LCD 5110
	inic_LCD();
	limpa_LCD();

	// --------------------------------------------------------------------------------------
	// inicializa tela
	Start_Game();

	/* USER CODE BEGIN RTOS_THREADS */
	xTaskCreate(vTask_LCD_Print, "Task 1", 100, NULL, 1,NULL);
	xTaskCreate(vTask_read_joystick, "Task 2", 100, NULL, 1, NULL);
	xTaskCreate(vTask_Nr_Print, "Task 3", 100, NULL, 1,NULL);
	xTaskCreate(vTask_move_MrWatchAndGame, "Task 4", 100, NULL, 1,NULL);

	/* Start scheduler */
	vTaskStartScheduler();	// apos este comando o RTOS passa a executar as tarefas

    while (1);
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}

/* ADC1 init function */
static void MX_ADC1_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Common config 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 2;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES5_SMPR1ALLCHANNELS;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES5_SMPR1ALLCHANNELS;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6 
                          |GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA3 PA4 PA5 PA6 
                           PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6 
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void Start_Game(){
	struct pontos_t p_line;

	goto_XY(0, 0);
	escreve2fb((unsigned char *) GameAndWatch_start);
	imprime_LCD();
	HAL_Delay(1000);
	limpa_LCD();
	escreve2fb((unsigned char *) start_icon);
	imprime_LCD();

	while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15)); // wait to joystick be pressed
	limpa_LCD();

	escreve2fb((unsigned char *) romexterminator_all);
	imprime_LCD();
	HAL_Delay(1000);
	limpa_LCD();

	//draw a line
	p_line.x1 = 0; p_line.y1 = 25;
	p_line.x2 = 0; p_line.y2 = 0;
	p_line.x3 = 0; p_line.y3 = 0;
	desenha_fig(&p_line, &line);

	for (uint8_t i=0; i<4; i++){
		p_line.x1 = p_line.x1 + 17;
		desenha_fig(&p_line, &line);
	}
	p_line.x1 = 0; p_line.y1 = 47-7;
	p_line.x2 = 0; p_line.y2 = 0;
	p_line.x3 = 0; p_line.y3 = 0;
	desenha_fig(&p_line, (figura_t*)get_missingFigures(&missings, 0));

	escreve_Nr_Peq(36,42,player.scores, 3);


}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

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
#include "string.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;
TIM_HandleTypeDef htim3;
//osThreadId defaultTaskHandle;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
typedef struct Player{
	uint32_t scores;
	uint32_t missing;
	uint8_t smash;
}player_t;

typedef struct moles{
	pontos_t Top_p;
	pontos_t Middle_p;
	pontos_t Bottom_p;
	uint8_t top_flag;
}moles_t;

volatile uint32_t ADC_VALOR[2];
uint32_t adcDmaBuffer[2];
static pontos_t Mr_p;
static pontos_t missing_p;
static uint32_t j[5];  //a pos de cada mole gerado (são 5 posições possiveis)
static uint32_t mole_num= 0;  //qtd de moles por rodada
static uint32_t total_mole_n= 0;  //qtd total de moles
static uint32_t last_missing = 0;
static uint32_t media_eixoX, media_eixoY;
xTaskHandle vTask_LCD_Print_Handle;

player_t player;
moles_t mole[5];

uint32_t melody[3] = {
		F1, E1, C1
};

uint32_t notes_duration[3]={
		4, 4, 2
};

uint32_t nota_freq;
char *nome_nota;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM3_Init(void);

/* USER CODE BEGIN PFP */
void setMolesPos();
void Start_Game();
void create_tasks();
void restart_game();
void CLR_moleFlag();
void ball_Hit_Sound();
void game_over_song();
void vTask_Game_Over(void *pvParameters);

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

void vTask_CreateMoles(void *pvParameters)
{
	uint8_t i,k;
	while(1)
	{
		mole_num = (prng_LFSR() % 5) + 1;  //quantidade de moles por rodada 1 a 5
		total_mole_n += mole_num;
		memset(j, 0, sizeof(j));  //zerar os valores anteriores
		CLR_moleFlag();
		for(i = 0; i < mole_num; i++){
			j[i] = (prng_LFSR() % 5);  //sortear a pos de cada mole e armazenar num vetor 0 a 4
			k=0;
			while(k < (mole_num-1)){  //para não sortear a mesma posição
				if((j[i] == j[k]) && (i!=k)){
					j[i] = (prng_LFSR() % 4);
					k=0;
				}else
					k++;
			}
			desenha_fig(&mole[j[i]].Bottom_p, &Bottom_mole);
			vTaskDelay(MS(600));
			desenha_fig(&mole[j[i]].Middle_p, &Middle_mole);
			vTaskDelay(MS(600));
			desenha_fig(&mole[j[i]].Top_p, &Top_mole);
			mole[j[i]].top_flag = 1;
			vTaskDelay(MS(300));
		}
		vTaskDelay(MS(800));
		for(i = 0; i<mole_num; i++){  //apagar os moles gerados anteriormente
			mole[j[i]].top_flag = 0;
			desenha_fig(&mole[j[i]].Top_p, &delete_Top_mole);
			desenha_fig(&mole[j[i]].Middle_p, &delete_Middle_mole);
			desenha_fig(&mole[j[i]].Bottom_p, &delete_Bottom_mole);
			vTaskDelay(MS(200));
		}
	}
}

void vTask_checkScores(void *pvParameters){
	pontos_t smash_p;
	smash_p.y1 = 21;

	while(1){
		if(player.smash){
			for(uint8_t i = 0; i < mole_num; i++){
				if(mole[j[i]].top_flag == 1){
					if((Mr_p.x1) >= mole[j[i]].Top_p.x1  && (Mr_p.x1) <= ((mole[j[i]].Top_p.x1)+10)){   //martelo esquerdo
						smash_p.x1 = mole[j[i]].Top_p.x1;
						ball_Hit_Sound();
						desenha_fig(&smash_p, &smash);
						vTaskDelay(MS(80));
						desenha_fig(&smash_p, &delete_smash);
						escreve_Nr_Peq(40,42,player.scores++, 3);
						mole[j[i]].top_flag = 0;
						desenha_fig(&mole[j[i]].Top_p, &delete_Top_mole);
						desenha_fig(&mole[j[i]].Middle_p, &delete_Middle_mole);
						desenha_fig(&mole[j[i]].Bottom_p, &delete_Bottom_mole);
					}
					else if ((Mr_p.x1+29) >= mole[j[i]].Top_p.x1  && (Mr_p.x1+29) <= ((mole[j[i]].Top_p.x1)+10)) {  //martelo direito
						smash_p.x1 = mole[j[i]].Top_p.x1;
						ball_Hit_Sound();
						desenha_fig(&smash_p, &smash);
						vTaskDelay(MS(80));
						desenha_fig(&smash_p, &delete_smash);
						escreve_Nr_Peq(40,42,player.scores++, 3);
						mole[j[i]].top_flag = 0;
						desenha_fig(&mole[j[i]].Top_p, &delete_Top_mole);
						desenha_fig(&mole[j[i]].Middle_p, &delete_Middle_mole);
						desenha_fig(&mole[j[i]].Bottom_p, &delete_Bottom_mole);
					}
				}
			}
		}
		player.smash = 0;
	}
}

void vTask_LifeBar_update(void *pvParameters){
	uint32_t x=0;

	while(1){
		if(total_mole_n > player.scores){
			player.missing = total_mole_n - player.scores;

			if(player.missing > last_missing){
				x = player.missing - last_missing;
				last_missing = player.missing;
				for(uint8_t k = 0; (k < x) && (missing_p.x1 != 0) ; k++){
					desenha_fig(&missing_p, &life_line);
					missing_p.x1--;
					if(missing_p.x1 == 0){
						xTaskCreate(vTask_Game_Over, "Task 8", 100, NULL, 2, NULL);
						vTaskDelay(MS(1000));
					}
					vTaskDelay(MS(20));
				}
			}
		}
	}
}

void vTask_Game_Over(void *pvParameters){
	char buffer[2];
	while(1){

		vTaskPrioritySet(vTask_LCD_Print_Handle,2);		//coloca a prioridade de atualizar o LCD no mesmo nível desta tarefa

		limpa_LCD();
		goto_XY(15, 1);
		string_LCD("Game-Over");

		goto_XY(20, 2);
		string_LCD("Scores");

		goto_XY(32, 3);
		itoa(player.scores, buffer, 10);
		string_LCD(buffer);

		game_over_song();

		vTaskDelay(MS(3000));

		// Da opção de novo jogo
		limpa_LCD();
		goto_XY(5, 1);
		string_LCD("Press Button");
		goto_XY(32, 2);
		string_LCD("for");
		goto_XY(18, 3);
		string_LCD("New Game");

		// enquando nao pressionar joystick fica travado
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15));

		restart_game();

		vTaskPrioritySet(vTask_LCD_Print_Handle,1);  //retornar a prioridade original

		vTaskDelete(NULL);
	}
}
void vTask_move_MrWatchAndGame(void *pvParameters)
{
	static uint32_t x = (83-29)/2;
	static int32_t dif_eixoX;

	Mr_p.x1 = 0; Mr_p.y1 = 2;  //y é fixo
	Mr_p.x2 = 0; Mr_p.y2 = 0;
	Mr_p.x3 = 0; Mr_p.y3 = 0;

	while(1)
	{
		dif_eixoX = 2048 - media_eixoX;

		if(dif_eixoX < -100)
		{
			if(x>0) x--;
		}
		else if(dif_eixoX > 100) // 100 = Delta de tolerância no deslocamento do eixo
		{
			if(x<55) x++;
		}
		// ------------------------------------------------------------------------
		Mr_p.x1 = x;

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == 0){
			player.smash = 1;
			desenha_fig(&Mr_p,&MrGameAndWatch_smash);
			vTaskDelay(MS(40));
			desenha_fig(&Mr_p,&delete_MrGameAndWatch);
		}else{
			player.smash = 0;
			desenha_fig(&Mr_p,&MrGameAndWatch);
			vTaskDelay(MS(40));
			desenha_fig(&Mr_p,&delete_MrGameAndWatch);
		}
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
int main(void)
{
	/* MCU Configuration----------------------------------------------------------*/
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();


	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_ADC1_Init();
	MX_TIM3_Init();
	/* USER CODE BEGIN 2 */
	HAL_ADCEx_Calibration_Start(&hadc1);
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*)adcDmaBuffer,2);
	HAL_ADC_Start_IT(&hadc1);

	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3, 100); // som


	// inicializa LCD 5110
	inic_LCD();
	limpa_LCD();

	// inicializa tela
	Start_Game();

	/* USER CODE BEGIN RTOS_THREADS */
	create_tasks();

	/* Start scheduler */
	vTaskStartScheduler();

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

/* TIM3 init function */
static void MX_TIM3_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 4000;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 200;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim3);

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
  __HAL_RCC_GPIOB_CLK_ENABLE();


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
void setMolesPos(){
	mole[0].Bottom_p.x1 = 0;   mole[0].Bottom_p.y1 = 35;
	mole[0].Middle_p.x1 = 4;   mole[0].Middle_p.y1 = 29;
	mole[0].Top_p.x1 = 8;  	   mole[0].Top_p.y1 = 24;

	mole[1].Bottom_p.x1 = 17;  mole[1].Bottom_p.y1 = 35;
	mole[1].Middle_p.x1 = 21;   mole[1].Middle_p.y1 = 29;
	mole[1].Top_p.x1 = 25;      mole[1].Top_p.y1 = 24;

	mole[2].Bottom_p.x1 = 34;  mole[2].Bottom_p.y1 = 35;
	mole[2].Middle_p.x1 = 38;   mole[2].Middle_p.y1 = 29;
	mole[2].Top_p.x1 = 42;      mole[2].Top_p.y1 = 24;

	mole[3].Bottom_p.x1 = 51;  mole[3].Bottom_p.y1 = 35;
	mole[3].Middle_p.x1 = 55;   mole[3].Middle_p.y1 = 29;
	mole[3].Top_p.x1 = 59;      mole[3].Top_p.y1 = 24;

	mole[4].Bottom_p.x1 = 68;  mole[4].Bottom_p.y1 = 35;
	mole[4].Middle_p.x1 = 72;   mole[4].Middle_p.y1 = 29;
	mole[4].Top_p.x1 = 76;      mole[4].Top_p.y1 = 24;
}

void CLR_moleFlag(){
	mole[0].top_flag = 0;
	mole[1].top_flag = 0;
	mole[2].top_flag = 0;
	mole[3].top_flag = 0;
	mole[4].top_flag = 0;
}
void Start_Game(){
	pontos_t p_line;

	setMolesPos();
	CLR_moleFlag();
    player.scores = 0;
    player.smash = 0;
    player.missing = 0;

    missing_p.x1 = 33; missing_p.y1 = 40;

	goto_XY(0, 0);
	escreve2fb((unsigned char *) GameAndWatch_start);
	imprime_LCD();
	HAL_Delay(1000);
	limpa_LCD();
	escreve2fb((unsigned char *) start_icon);
	imprime_LCD();

	while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15)); // wait to joystick be pressed
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

	p_line.x1 = 0; p_line.y1 = 38;
	desenha_fig(&p_line, &LifeBar);

	escreve_Nr_Peq(40,42,player.scores, 3);
}
void restart_game(){
	limpa_LCD();
	pontos_t p_line;

	player.scores = 0;
	player.smash = 0;
	player.missing = 0;
	CLR_moleFlag();
	total_mole_n = 0;
	last_missing = 0;

	missing_p.x1 = 33;
	//draw a line
	p_line.x1 = 0; p_line.y1 = 25;
	desenha_fig(&p_line, &line);

	for (uint8_t i=0; i<4; i++){
		p_line.x1 = p_line.x1 + 17;
		desenha_fig(&p_line, &line);
	}

	p_line.x1 = 0; p_line.y1 = 38;
	desenha_fig(&p_line, &LifeBar);

	escreve_Nr_Peq(40,42,player.scores, 3);
}

void ball_Hit_Sound()
{
	__HAL_TIM_SET_PRESCALER(&htim3,36000/32);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	vTaskDelay(MS(100));
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
}

void game_over_song(){
	for(uint8_t i=0; i<3; i++ ){
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
		vTaskDelay(MS(10));
		__HAL_TIM_SET_PRESCALER(&htim3,(36000/melody[i])-1);
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		vTaskDelay(MS(2000/notes_duration[i]));
	}
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
	vTaskDelay(MS(500));
}

void create_tasks(){
	xTaskCreate(vTask_LCD_Print, "Task 1", 100, NULL, 1,&vTask_LCD_Print_Handle);
	xTaskCreate(vTask_checkScores, "Task 2", 100, NULL, 1,NULL);
	xTaskCreate(vTask_read_joystick, "Task 3", 100, NULL, 1, NULL);
	xTaskCreate(vTask_CreateMoles, "Task 4", 100, NULL, 1,NULL);
	xTaskCreate(vTask_move_MrWatchAndGame, "Task 5", 100, NULL, 1,NULL);
	xTaskCreate(vTask_LifeBar_update, "Task 6", 100, NULL, 1,NULL);
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

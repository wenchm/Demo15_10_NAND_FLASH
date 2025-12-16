/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "fsmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "nand_flash.h"
#include "nand_func.h"
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_FSMC_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  printf("Test NAND FLASH R/W.\n\r");

  HAL_NAND_StateTypeDef sta;	//0=reset,1=ready,2=busy,3=error
  sta = HAL_NAND_GetState(&hnand1);
  if(sta ==0)
	  printf("Nand Flash status is reset.\n\r");
  else if(sta ==1)
  	  printf("Nand Flash status is ready.\n\r");
  else if(sta ==2)
  	  printf("Nand Flash status is busy.\n\r");
  else if(sta ==3)
  	  printf("Nand Flash status is error.\n\r");

  printf("Nand Flash pagesize = %ld\n",hnand1.Config.PageSize);
  printf("Nand Flash SpareAreaSize = %ld\n",hnand1.Config.SpareAreaSize);
  printf("Nand Flash PlaneSize = %ld\n",hnand1.Config.PlaneSize);
  printf("Nand Flash BlockSize = %ld\n",hnand1.Config.BlockSize);
  printf("Nand Flash BlockNbr = %ld\n",hnand1.Config.BlockNbr);
  printf("Nand Flash PlaneNbr = %ld\n\r",hnand1.Config.PlaneNbr);

  FSMC_NAND_Test();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void FSMC_NAND_Test(void)
{
  //logic drive mapped to physic drive
  NAND_AddressTypeDef addr ={	//初始化
		  addr.Page =0,
  	  	  addr.Plane =0,
  	  	  addr.Block =0
  	  	  };
  addr.Page = FLASH_PAGE_63;
  addr.Plane= FLASH_PLANE_0;
  addr.Block= FLASH_BLOCK_1023;

  *(uint32_t*)((uint32_t)(addr.Page)) =ADDR_FLASH_PAGE_63;
  *(uint32_t*)((uint32_t)(addr.Plane)) =ADDR_FLASH_PLANE_0;
  *(uint32_t*)((uint32_t)(addr.Block)) =ADDR_FLASH_BLOCK_1023;

//  *(uint32_t*)((uint32_t)(FLASH_BLOCK_0)) =ADDR_FLASH_BLOCK_0;

  //test erase a block
  printf("test erase a block.\r\n");
  HAL_StatusTypeDef ret = HAL_NAND_Erase_Block(&hnand1, &addr);
  if(ret ==0)
	  printf("erase block is HAL_OK.\n\r");
  else if(ret ==1)
	  printf("erase block is HAL_ERROR.\n\r");
  else if(ret ==2)
	  printf("erase block is HAL_BUSY.\n\r");
  else if(ret ==3)
	  printf("erase block is HAL_TIMEOUT.\n\r");

  // test Reset
  HAL_StatusTypeDef ret1 =HAL_NAND_Reset(&hnand1);	// all bit set 0xFF
  if(ret1 ==0)
	  printf("Nand Flash reset is HAL_OK.\n\r");
  else if(ret1 ==1)
  	  printf("Nand Flash reset is HAL_ERROR.\n\r");
  else if(ret1 ==2)
  	  printf("Nand Flash reset is HAL_BUSY.\n\r");
  else if(ret1 ==3)
  	  printf("Nand Flash reset is HAL_TIMEOUT.\n\r");
  HAL_Delay(500);

  // test READ_ID
  NAND_IDTypeDef info;
  HAL_StatusTypeDef ret2 =HAL_NAND_Read_ID(&hnand1, &info);
  if(ret2 ==0)
	  printf("Nand Flash Read_ID is HAL_OK.\n");
  else if(ret2 ==1)
  	  printf("Nand Flash Read_ID is HAL_ERROR.\n");
  else if(ret2 ==2)
  	  printf("Nand Flash Read_ID is HAL_BUSY.\n");
  else if(ret2 ==3)
  	  printf("Nand Flash Read_ID is HAL_TIMEOUT.\n");

  printf("Nand Flash ID = %02X-%02X-%02X-%02X\n\r",info.Maker_Id, info.Device_Id,info.Third_Id,info.Fourth_Id);

  //test memory Read_Status
/**
  * @brief NAND memory status
  * NAND_VALID_ADDRESS         0x00000100UL
  * NAND_INVALID_ADDRESS       0x00000200UL
  * NAND_TIMEOUT_ERROR         0x00000400UL
  * NAND_BUSY                  0x00000000UL
  * NAND_ERROR                 0x00000001UL
  * NAND_READY                 0x00000040UL
  */
/**
  * @brief  NAND memory read status
  * @param  hnand pointer to a NAND_HandleTypeDef structure that contains
  *                the configuration information for NAND module.
  * @retval NAND status
  */
  uint32_t sta = HAL_NAND_Read_Status(&hnand1);
  if(sta ==0x00000100UL)
	  printf("NAND memory read status is NAND_VALID_ADDRESS.\r\n");
  else if(sta ==0x00000200UL)
	  printf("NAND memory read status is NAND_INVALID_ADDRESS.\r\n");
  else if(sta ==0x00000400UL)
	  printf("NAND memory read status is NAND_TIMEOUT_ERROR.\r\n");
  else if(sta ==0x00000000UL)
	  printf("NAND memory read status is NAND_BUSY.\r\n");
  else if(sta ==0x00000001UL)
	  printf("NAND memory read status is NAND_ERROR.\r\n");
  else if(sta ==0x00000040UL)
	  printf("NAND memory read status is NAND_READY.\r\n");

  printf("\r\n");
  //test write
  uint8_t buffer_write[2048];
  for(int i = 0; i < 2048; i++)
  {
	  buffer_write[i] = (uint8_t)i;
  }

  //Write into page 63 of the {63,0,1023} defined above.
  HAL_StatusTypeDef ret3 = HAL_NAND_Write_Page_8b(&hnand1, &addr, buffer_write, 1);
  if(ret3 == 0)
	  printf("write natural numbers into a page is HAL_OK。\r\n");
  else if(ret3 == 1)
	  printf("write natural numbers into a page is HAL_ERROR。\r\n");
  else if(ret3 == 2)
	  printf("write natural numbers into a page is HAL_BUSY。\r\n");
  else if(ret3 == 3)
	  printf("write natural numbers into a page is HAL_TIMEOUT。\r\n");

  printf("\r\n");

  //test read
  uint8_t buffer1[2048];
  memset(buffer1, 0, 2048);
  HAL_StatusTypeDef ret4 = HAL_NAND_Read_Page_8b(&hnand1, &addr, buffer1, 1);
  if(ret4 == 0)
  {
	  printf("Read a written page, each byte shows natural numbers.\r\n");
	  for(int i = 0; i < 64; i++)
	  {
		  printf("%02X,",buffer1[i]);
	  }
	  printf("\r\n");
  }
  printf("\r\n");

  uint8_t buffer[2048];
  addr.Page = 1;
  addr.Plane= 0;
  addr.Block= 1;
  *(uint32_t*)((uint32_t)(addr.Page)) =ADDR_FLASH_PAGE_1;
  *(uint32_t*)((uint32_t)(addr.Plane)) =ADDR_FLASH_PLANE_0;
  *(uint32_t*)((uint32_t)(addr.Block)) =ADDR_FLASH_BLOCK_1;
  memset(buffer, 0, 2048);
  HAL_StatusTypeDef ret5 = HAL_NAND_Read_Page_8b(&hnand1, &addr, buffer, 1);
  if(ret5 == 0)
  {
	  printf("Read a page that has not been written, each byte shows 0xFF.\r\n");
	  for(int i = 0; i < 64; i++)
	  {
		  printf("%02X,",buffer[i]);
	  }
	  printf("\r\n");
  }

}


int __io_putchar(int ch)
{
	HAL_UART_Transmit(&huart3,(uint8_t*)&ch,1,0xFFFF);
	return ch;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

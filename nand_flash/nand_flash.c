/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : nand_flash.c
  * @brief          : program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) wenchm.
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
#include "nand_flash.h"
#include "nand_func.h"

/* Private function declaration for Nand Flash */
extern void FSMC_NAND_Test(void);

/* Private user code ---------------------------------------------------------*/





//HAL_StatusTypeDef FLASHEx_Erase_Mass(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError)
//{
//	pEraseInit->TypeErase = FLASH_TYPEERASE_MASSERASE;
//	pEraseInit->Banks = FLASH_BANK_1;
//	pEraseInit->VoltageRange = FLASH_VOLTAGE_RANGE_3;
//}




//void FSMC_NAND_Test(void)
//{
//	HAL_NAND_StateTypeDef sta;	//0=reset,1=ready,2=busy,3=error
//	sta = HAL_NAND_GetState(&hnand1);
//	if(sta ==1)
//		printf("Nand Flash status is ready.\n\r");
//
//	printf("Nand Flash pagesize = %ld\n\r",hnand1.Config.PageSize);
//	printf("Nand Flash SpareAreaSize = %ld\n\r",hnand1.Config.SpareAreaSize);
//	printf("Nand Flash PlaneSize = %ld\n\r",hnand1.Config.PlaneSize);
//	printf("Nand Flash BlockSize = %ld\n\r",hnand1.Config.BlockSize);
//	printf("Nand Flash BlockNbr = %ld\n\r",hnand1.Config.BlockNbr);
//	printf("Nand Flash PlaneNbr = %ld\n\r",hnand1.Config.PlaneNbr);
//
////	NAND_AddressTypeDef addr ={0,0,0};
//	NAND_AddressTypeDef addr;
//	addr.Page = (uint16_t)(ADDR_FLASH_PAGE_0 & 0xFFFF);
//	addr.Plane= (uint16_t)(ADDR_FLASH_PLANE_0 & 0xFFFF);
//	addr.Block= (uint16_t)(ADDR_FLASH_BLOCK_0 & 0xFFFF);
//	for(int block_item =0; block_item <1024; block_item++)
//	{
//		HAL_NAND_Erase_Block(&hnand1, &addr);
//		addr.Block++;
//	}
//	printf("Erase_Mass is finished\n\r");
//
//	NAND_IDTypeDef info;
////	HAL_NAND_Reset(&hnand1);
////	HAL_Delay(500);
//	HAL_NAND_Read_ID(&hnand1, &info);
//	printf("Nand Flash ID = %02X-%02X-%02X-%02X\n\r",info.Maker_Id, info.Device_Id,info.Third_Id,info.Fourth_Id);
//
//	uint32_t memory_sta;
//	memory_sta = HAL_NAND_Read_Status(&hnand1);
//	printf("Nand Flash memory status = %lx\n\r",memory_sta);
//
//	uint8_t buffer_write[2 * 1024];
//	for(int i = 0; i < 2048; i++)
//	{
//		buffer_write[i] = i;
//	}
//
//	addr.Page = (uint16_t)(ADDR_FLASH_PAGE_0 & 0xFFFF);
//	addr.Plane= (uint16_t)(ADDR_FLASH_PLANE_0 & 0xFFFF);
//	addr.Block= (uint16_t)(ADDR_FLASH_BLOCK_63 & 0xFFFF);
//	HAL_StatusTypeDef ret = HAL_NAND_Write_Page_8b(&hnand1, &addr, buffer_write, 1);
//	if(ret == 0)
//		printf("write block63: OK\n\r");
//
//	uint8_t buffer[2 * 1024];
//	HAL_StatusTypeDef ret1 = HAL_NAND_Read_Page_8b(&hnand1, &addr, buffer, 1);
//	if(ret1 == 0)
//	{
//		printf("read block63: it should be N.\n\r");
//		for(int i = 0; i < 64; i++)
//		{
//			printf("%02X,",buffer[i]);
//		}
//		printf("\r\n");
//	}
//
//	addr.Page = (uint16_t)(ADDR_FLASH_PAGE_0 & 0xFFFF);
//	addr.Plane= (uint16_t)(ADDR_FLASH_PLANE_0 & 0xFFFF);
//	addr.Block= (uint16_t)(ADDR_FLASH_BLOCK_0 & 0xFFFF);
//	uint8_t buffer1[2 * 1024];
//	HAL_StatusTypeDef ret2 = HAL_NAND_Read_Page_8b(&hnand1, &addr, buffer1, 1);
//	if(ret2 == 0)
//	{
//		printf("\n\r read block0: It should all be 0xFF.\n\r");
//		for(int i = 0; i < 64; i++)
//		{
//			printf("%02X,",buffer1[i]);
//		}
//		printf("\r\n");
//	}
//
//}




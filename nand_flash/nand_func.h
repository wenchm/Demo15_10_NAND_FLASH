/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : nand_func.h
  * @brief          : Header for nand_flash.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 wenchm.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NAND_FUNC_H
#define __NAND_FUNC_H

#ifdef __cplusplus
extern "C" {
#endif


/* Private function declaration for Nand Flash */
HAL_StatusTypeDef FLASHEx_Erase_Mass(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError);
HAL_StatusTypeDef FLASHEx_Erase_Sectors(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError);
#ifdef __cplusplus
}
#endif

#endif /* __NAND_FUNC_H */


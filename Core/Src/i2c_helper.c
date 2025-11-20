/*
 * i2c_helper.c
 *
 *  Created on: Nov 20, 2025
 *      Author: benotter
 */

#include "i2c_helper.h"

#include "main.h"         // for HAL handles like hi2c2
#include <stdio.h>        // for printf
#include <stdint.h>       // for uint8_t, uint16_t types
#include "i2c.h"       // for uint8_t, uint16_t types



uint8_t i2c_read_one_val(uint8_t device_addr, uint8_t reg_addr) {
	uint8_t data_received = 0;
	HAL_StatusTypeDef ret = HAL_I2C_Mem_Read(&hi2c2, device_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, &data_received, 1, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		  printf("I2C_2: Memory Read Error %d\r\n", ret);
		  printf("HAL_I2C ErrorCode: 0x%08lX\r\n", hi2c2.ErrorCode);
		  printf("Device Address: 0x%02x\r\n", device_addr);
		  printf("Register Address: 0x%02x\r\n", reg_addr);
	  }
	return data_received;
}

void i2c_write_one_val(uint8_t device_addr, uint8_t reg_addr, uint8_t data_write) {
	HAL_StatusTypeDef ret = HAL_I2C_Mem_Write(&hi2c2, device_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, &data_write, 1, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		  printf("I2C_2: Memory Read Error %d\r\n", ret);
		  printf("HAL_I2C ErrorCode: 0x%08lX\r\n", hi2c2.ErrorCode);
		  printf("Device Address: 0x%02x\r\n", device_addr);
		  printf("Register Address: 0x%02x\r\n", reg_addr);
	  }
	return;
}


void i2c_read_x_vals(uint8_t device_addr, uint8_t reg_addr, uint8_t* buffer, int datapoints) {
	HAL_StatusTypeDef ret = HAL_I2C_Mem_Read(&hi2c2, device_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, buffer, datapoints, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		  printf("I2C_2: Memory Read Error %d\r\n", ret);
		  printf("HAL_I2C ErrorCode: 0x%08lX\r\n", hi2c2.ErrorCode);
		  printf("Device Address: 0x%02x\r\n", device_addr);
		  printf("Base Register Address: 0x%02x\r\n", reg_addr);
	  }
	return;
}




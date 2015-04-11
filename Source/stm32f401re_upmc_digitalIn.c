/**
  ******************************************************************************
  * @file    Pstl/Source/stm32f401re_upmc_digitalIn.c 
  * @author  Master1 Team
  * @version V1.0.0
  * @date    ??-December-2015
  * @brief   ???
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 UPMC</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f401re_upmc_digitalIn.h"

/* Private functions ---------------------------------------------------------*/

/**
  * @brief Initializes a default digital-in 
  * @GPIO_Pin: specifies the port bit to initialize. Possible values: 
  * 			  PINx, USER_BUTTON or ALLPIN, where x[0..15].
  * @retval ...
  */
void initDigitalIn(uint16_t GPIO_Pin) {	
	enableClock(GPIO_Pin);	
	createStruct(GPIO_Pin);
	initialiseStruct(GPIO_Pin);
}
	
/**
  * @brief ...
  * @GPIO_Pin: specifies the port bit to initialize. Possible values: 
  * 			  PINx, USER_BUTTON or ALLPIN, where x[0..15].
  * @retval ...
  */	
void createStruct(uint16_t GPIO_Pin) {
	GPIO_InitStruct.Pin   = GPIO_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;	
}			

/**
  * @brief ... 
  * @GPIO_Pin: specifies the port bit to initialize. Possible values: 
  * 			  PINx, USER_BUTTON or ALLPIN, where x[0..15].
  * @retval ...
  */
void initialiseStruct(uint16_t GPIO_Pin) {
	
	switch (GPIO_Pin) {

		case GPIO_PIN_0 :
		case GPIO_PIN_1 :
		case GPIO_PIN_2 :
		case GPIO_PIN_3 :
		case GPIO_PIN_4 : {
			HAL_GPIO_Init(GPIOB, &GPIO_InitStruct); // NOT GPIOB; to check!
			break;
		}
		
		case LED2_PIN : {
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
			break;
		}

		case GPIO_PIN_6 :
		case GPIO_PIN_7 :
		case GPIO_PIN_8 :
		case GPIO_PIN_9 :
		case GPIO_PIN_10 :
		case GPIO_PIN_11 :
		case GPIO_PIN_12 : {
			HAL_GPIO_Init(GPIOB, &GPIO_InitStruct); // NOT GPIOB; to check!
			break;
		}

		case USER_BUTTON_PIN : {
			HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
			break;
		}

		case GPIO_PIN_14 :
		case GPIO_PIN_15 : {
			HAL_GPIO_Init(GPIOB, &GPIO_InitStruct); // NOT GPIOB; to check!
			break;
		}
	}		
}

/**
  * @brief Gets the pin's state 
  * @GPIO_Pin: specifies the port bit to test. Possible values: PINx or 
  *            ALLPIN, where x[0..15].
  * Returns: 0 if the pin is active, 1 else.
  * @retval ...
  */
GPIO_PinState isActive(uint16_t GPIO_Pin) {

	switch (GPIO_Pin) {

		case GPIO_PIN_0 :
		case GPIO_PIN_1 :
		case GPIO_PIN_2 :
		case GPIO_PIN_3 :
		case GPIO_PIN_4 : {
			return !HAL_GPIO_ReadPin(GPIOB, GPIO_Pin); // NOT GPIOB; to check!
		}
		
		case LED2_PIN : {
			return !HAL_GPIO_ReadPin(GPIOA, GPIO_Pin);
		}

		case GPIO_PIN_6 :
		case GPIO_PIN_7 :
		case GPIO_PIN_8 :
		case GPIO_PIN_9 :
		case GPIO_PIN_10 :
		case GPIO_PIN_11 :
		case GPIO_PIN_12 : {
			return !HAL_GPIO_ReadPin(GPIOB, GPIO_Pin); // NOT GPIOB; to check!
		}

		case USER_BUTTON_PIN : {
			return !HAL_GPIO_ReadPin(GPIOC, GPIO_Pin);
		}

		case GPIO_PIN_14 :
		case GPIO_PIN_15 : {
			return !HAL_GPIO_ReadPin(GPIOB, GPIO_Pin); // NOT GPIOB; to check!
		}	
	}	

	return 0;
}

/************************ (C) COPYRIGHT UPMC *******************END OF FILE****/
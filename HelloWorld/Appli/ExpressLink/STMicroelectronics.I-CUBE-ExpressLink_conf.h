/**
  ******************************************************************************
  * File Name          : STMicroelectronics.I-CUBE-ExpressLink_conf.h
  * Description        : This file provides code for the configuration
  *                      of the STMicroelectronics.I-CUBE-ExpressLink_conf.h instances.
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STMICROELECTRONICS__I_CUBE_EXPRESSLINK_CONF__H__
#define __STMICROELECTRONICS__I_CUBE_EXPRESSLINK_CONF__H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/**
	MiddleWare name : STMicroelectronics.I-CUBE-ExpressLink.1.0.0
	MiddleWare fileName : STMicroelectronics.I-CUBE-ExpressLink_conf.h
	MiddleWare version :
*/
/*---------- EXPRESSLINK_USART_HANDLER  -----------*/
#define EXPRESSLINK_USART_HANDLER      huart2

/*---------- EXPRESSLINK_DEBUG  -----------*/
#define EXPRESSLINK_DEBUG      2

/*---------- EXPRESSLINK_RX_BUFFER_SIZE  -----------*/
#define EXPRESSLINK_RX_BUFFER_SIZE      128

/*---------- EXPRESSLINK_TX_BUFFER_SIZE  -----------*/
#define EXPRESSLINK_TX_BUFFER_SIZE      128

/*---------- EXPRESSLINK_AWS_IOT_ENDPOINT  -----------*/
#define EXPRESSLINK_AWS_IOT_ENDPOINT      "a1qwhobjtvew8t-ats.iot.us-west-1.amazonaws.com"

/*---------- EXPRESSLINK_WIFI_SSID  -----------*/
#define EXPRESSLINK_WIFI_SSID      "STTestN750"

/*---------- EXPRESSLINK_WIFI_PASSWORD  -----------*/
#define EXPRESSLINK_WIFI_PASSWORD      "9a1v2r73027"

/*---------- EXPRESSLINK_APN  -----------*/
#define EXPRESSLINK_APN      "My_APN"

#ifdef __cplusplus
}
#endif
#endif /*__ STMICROELECTRONICS__I_CUBE_EXPRESSLINK_CONF__H_H */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

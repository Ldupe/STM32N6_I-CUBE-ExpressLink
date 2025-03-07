/**
 ******************************************************************************
 * @file    STMicroelectronics.I-CUBE-ExpressLink.1.0.0
 * @brief   AWS ExpressLink Example
 ******************************************************************************
 * @attention
 *
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
 *
 ******************************************************************************
 */
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExpressLink.h"

#define MQTT_PUBLISH_TIME_BETWEEN_MS         ( 3000 )

#define TOPIC_INDEX                          1

#define NLOOPS                               100

char * response;

uint32_t loops = NLOOPS;

void MX_ExpressLink_Init(void)
{
  ExpressLink_event_t event;

#if EXPRESSLINK_DEBUG
    printf("[INFO] Starting Hello World\r\n");
#endif

  /* Detect if a ExpressLink module is present */
  do
  {
    HAL_Delay(ExpressLink_BOOT_DELAY);
    response = ExpressLink_Test();

    if(strstr(response, "OK") == NULL)
    {
  	  printf("[ERRR] Please make sure the ExpressLink module is plugged in and turned on!\r\n");
    }
  }while(strstr(response, "OK") == NULL);

#if EXPRESSLINK_DEBUG
    printf("[INFO] Resetting ExpressLink module\r\n");
#endif
  /* Reset the module */
  ExpressLink_Reset();

  do
  {
    event = ExpressLink_GetEvent(); /* Get event  */
   } while ((event.id == EXPRESSLINK_EVENT_ERROR) || (event.id == EXPRESSLINK_EVENT_NONE));

  ExpressLink_SetState(EXPRESSLINK_STATE_READY);

  /* Chack if it is a Wi-Fi or cellular module */
  response = ExpressLink_GetAPN();

  /* If Wi-Fi then set SSID and password */
  if(strstr(response, "OK") == NULL)
  {
#if EXPRESSLINK_DEBUG
    printf("[INFO] Wi-Fi\r\n");
#endif
    /* Set Wi-Fi SSID and password */
    ExpressLink_SetSSID      ((char *)&EXPRESSLINK_WIFI_SSID);
    ExpressLink_SetPassphrase((char *)&EXPRESSLINK_WIFI_PASSWORD);
  }
  else
  {
#if EXPRESSLINK_DEBUG
    printf("[INFO] Cellular\r\n");
#endif
  }

  ExpressLink_SetCustomName("STM32-EL-MX");

  /* Set AWS IoT Core endpoint */
  ExpressLink_SetEndpoint  ((char *)&EXPRESSLINK_AWS_IOT_ENDPOINT);

  /* Connect to AWS */
  response = ExpressLink_Connect();

  if(strcmp(response,"OK 1 CONNECTED\r\n") != 0)
  {
#if EXPRESSLINK_DEBUG
    printf("[ERROR] %s", response);
#endif

    ExpressLink_SetState(EXPRESSLINK_STATE_ERROR);

    NVIC_SystemReset();
  }

#if EXPRESSLINK_DEBUG
  printf("[INFO] Connected to AWS\r\n");
#endif

  ExpressLink_SetState(EXPRESSLINK_STATE_CONNECTED);

  /* Get the thing name */
  response = ExpressLink_GetThingName();

  response = ExpressLink_SetTopic     (TOPIC_INDEX    , response      );
}

void MX_ExpressLink_Process(void)
{
  ExpressLink_EventCallback(ExpressLink_GetEvent());

  if (ExpressLink_GetState() != EXPRESSLINK_STATE_CONNECTED)
  {
    ExpressLink_Disonnect();
    NVIC_SystemReset();
  }

#if EXPRESSLINK_DEBUG
  printf("[INFO] Sending MQTT message\r\n");
#endif

  ExpressLink_SendMessage(TOPIC_INDEX, "Hello world!");

  if(loops-- == 0)
  {
    ExpressLink_Disonnect();

#if EXPRESSLINK_DEBUG
    printf("[INFO] End of demo\r\n");
#endif

    while(1);
  }

  HAL_Delay(MQTT_PUBLISH_TIME_BETWEEN_MS);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

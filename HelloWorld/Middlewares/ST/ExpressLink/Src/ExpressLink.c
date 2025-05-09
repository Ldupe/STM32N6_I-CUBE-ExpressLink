/**
 ******************************************************************************
 * @file           : ExpressLink.c
 * @version        : v 1.0.0
 * @brief          : This file implements AWS ExpressLink driver
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * ththe "License"; You may not use this file except in compliance with the
 *                             opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "main.h"
#include "ExpressLink.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if defined(EXPRESSLINK_USART_LL)
#undef EXPRESSLINK_USART_HANDLER
#define EXPRESSLINK_USART_HANDLER (*EXPRESSLINK_USART_LL_HANDLER)
#else
extern UART_HandleTypeDef EXPRESSLINK_USART_HANDLER;
#endif

static int get_int  (char *string);
static int get_index(char* string, char c);

static volatile ExpressLink_state_t state = EXPRESSLINK_STATE_INIT;

static char command [EXPRESSLINK_TX_BUFFER_SIZE] = { 0 };
static char response[EXPRESSLINK_RX_BUFFER_SIZE] = { 0 };

#if defined( EXPRESSLINK_USART_LL)
#define HAL_UART_Transmit(handler, data, size, timeout_ms) LL_HAL_UART_Transmit(handler, data, size, timeout_ms)
#define HAL_UART_Receive(handler, data, size, timeout_ms)  LL_HAL_UART_Receive (handler, data, size, timeout_ms)

static HAL_StatusTypeDef LL_HAL_UART_Transmit(USART_TypeDef *USARTx, uint8_t *data, uint32_t size, uint32_t timeout_ms)
{
  uint32_t counter = 0;
  uint32_t initial_tick;

  if (size == 0)
  {
    return HAL_ERROR;
  }

  initial_tick = HAL_GetTick();

  /* Wait for TC flag to be raised for last char */
  while (!LL_USART_IsActiveFlag_TC(USARTx))
  {
    if ((HAL_GetTick() - initial_tick) >= timeout_ms)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Send characters one per one */
  while (counter < size)
  {
    initial_tick = HAL_GetTick();
    /* Wait for TXE flag to be raised */
    while (!LL_USART_IsActiveFlag_TXE(USARTx))
    {
      if ((HAL_GetTick() - initial_tick) >= timeout_ms)
      {
        return HAL_TIMEOUT;
      }
    }

    /* If last char to be sent, clear TC flag */
    if (counter == size - 1)
    {
      LL_USART_ClearFlag_TC(USARTx);
    }

    /* Write character in Transmit Data register. TXE flag is cleared by writing data in TDR register */
    LL_USART_TransmitData8(USARTx, data[counter++]);
  }

  return HAL_OK;
}

static HAL_StatusTypeDef LL_HAL_UART_Receive(USART_TypeDef *USARTx, uint8_t *data, uint32_t size, uint32_t timeout_ms)
{
  uint32_t counter = 0;
  uint32_t initial_tick;

  if (size == 0)
  {
    return HAL_ERROR;
  }

  while (counter < size)
  {
    initial_tick = HAL_GetTick();

    /* Wait for RXNE flag to be raised */
    while (!LL_USART_IsActiveFlag_RXNE(USARTx))
    {
      if ((HAL_GetTick() - initial_tick) >= timeout_ms)
      {
        return HAL_TIMEOUT;
      }
    }

    data[counter++] = LL_USART_ReceiveData8(USARTx);
  }

  return HAL_OK;
}
#endif /* STM32C0xx_LL_USART_H */

/******************************************************************************/
/**
 * @brief Handle the ExpressLink Event. This is a weak function and can be
 * redefined
 * @retval None
 */
__weak void ExpressLink_EventCallback(ExpressLink_event_t event)
{
  switch (event.id)
  {
  case EXPRESSLINK_EVENT_NONE:
    break;

  case EXPRESSLINK_EVENT_MESSAGE:
#if EXPRESSLINK_DEBUG
    printf("[INFO] Message receiced on topic %d\r\n", (int)event.param);
#endif
    break;

  case EXPRESSLINK_EVENT_STARTUP:
  {
#if EXPRESSLINK_DEBUG      
      printf("[INFO] Module started\r\n");
#endif

    ExpressLink_SetState(EXPRESSLINK_STATE_READY);
  }
    break;

  case EXPRESSLINK_EVENT_CONLOST:
  {
#if EXPRESSLINK_DEBUG
      printf("[ERROR] Connection lost\r\n");
#endif
    ExpressLink_SetState(EXPRESSLINK_STATE_ERROR);
  }
    break;

  case EXPRESSLINK_EVENT_OVERRUN:
  {
#if EXPRESSLINK_DEBUG
      printf("[ERROR] Overrun error\r\n");
#endif

    ExpressLink_SetState(EXPRESSLINK_STATE_ERROR);
  }
    break;

  case EXPRESSLINK_EVENT_OTA:
#if EXPRESSLINK_DEBUG
    printf("[INFO] OTA received\r\n");
#endif
    break;

  case EXPRESSLINK_EVENT_CONNECT:
#if EXPRESSLINK_DEBUG
    printf("[INFO] Connect event with Connection Hint %d\r\n", (int)event.param);
#endif
    break;

  case EXPRESSLINK_EVENT_CONFMODE:
#if EXPRESSLINK_DEBUG
    printf("[INFO] Conf mode\r\n");
#endif
    break;

  case EXPRESSLINK_EVENT_SUBACK:
#if EXPRESSLINK_DEBUG
    printf("[INFO] A subscription was accepted. Topic Index %d\r\n", (int)event.param);
#endif    
    break;

  case EXPRESSLINK_EVENT_SUBNACK:
#if EXPRESSLINK_DEBUG
    printf("[INFO] A subscription was rejected. Topic Index %d\r\n", (int)event.param);
#endif     
    break;

  case EXPRESSLINK_EVENT_SHADOW_INIT:
#if EXPRESSLINK_DEBUG
    printf("[INFO] Shadow[Shadow Index] interface was initialized successfully. Topic Index %d\r\n", (int)event.param);
#endif       
    break;

  case EXPRESSLINK_EVENT_SHADOW_INIT_FAILED:
#if EXPRESSLINK_DEBUG
    printf("[INFO] The SHADOW[Shadow Index] interface initialization failed. Topic Index %d\r\n", (int)event.param);
#endif 
    break;

  case EXPRESSLINK_EVENT_SHADOW_INIT_DOC:
#if EXPRESSLINK_DEBUG
    printf("[INFO] A Shadow document was received. Topic Index %d\r\n", (int)event.param);
#endif    
    break;

  case EXPRESSLINK_EVENT_SHADOW_UPDATE:
#if EXPRESSLINK_DEBUG
    printf("[INFO] A Shadow update result was received. Topic Index %d\r\n", (int)event.param);
#endif     
    break;

  case EXPRESSLINK_EVENT_SHADOW_DELTA:
#if EXPRESSLINK_DEBUG
    printf("[INFO] A Shadow delta update was received. Topic Index %d\r\n", (int)event.param);
#endif    
    break;

  case EXPRESSLINK_EVENT_SHADOW_DELETE:
#if EXPRESSLINK_DEBUG
    printf("[INFO] A Shadow delete result was received. Topic Index %d\r\n", (int)event.param);
#endif       
    break;

  case EXPRESSLINK_EVENT_SHADOW_SUBACK:
#if EXPRESSLINK_DEBUG
    printf("[INFO] A Shadow delta subscription was accepted. Topic Index %d\r\n", (int)event.param);
#endif      
    break;

  case EXPRESSLINK_EVENT_SHADOW_SUBNACK:
#if EXPRESSLINK_DEBUG
    printf("[INFO] A Shadow delta subscription was rejected. Topic Index %d\r\n", (int)event.param);
#endif       
    break;

  default:
#if EXPRESSLINK_DEBUG
    printf("[INFO] Other event received: %d\r\n", (int)event.id);
#endif
    break;
  }
}

/******************************************************************************/
/**
 * @brief Check ExpressLink module
 * @retval The ExpressLink Module response
 */
char* ExpressLink_Test(void)
{
  return expresslink_execute_command("AT\n", ExpressLink_COMMAND_TIMEOUT);
}


/**
 * @brief Reset the ExpressLink Module
 * @retval None
 */
void ExpressLink_Reset(void)
{
  if (strcmp(expresslink_execute_command("AT+RESET\n", ExpressLink_COMMAND_TIMEOUT), "OK\r\n") == 0)
  {
    state = EXPRESSLINK_STATE_INIT;
  }
  else
  {
    state = EXPRESSLINK_STATE_ERROR;
  }
}

/**
 * @brief Ask the ExpressLink Module to connect to AWS
 * @retval The ExpressLink Module response
 */
char* ExpressLink_Connect(void)
{
  return expresslink_execute_command("AT+CONNECT\n", 10 * ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Ask the ExpressLink Module to connect to AWS in asynchronous mode
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ConnectAsync(void)
{
  return expresslink_execute_command("AT+CONNECT!\n", ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Ask the ExpressLink Module to disconnect from AWS
 * @retval The ExpressLink Module response
 */
char* ExpressLink_Disonnect(void)
{
  return expresslink_execute_command("AT+DISCONNECT\n", ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Request to enter a low power mode
 * @param duration: This indicates the number of seconds before the module awakes automatically.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_Sleep(int duration)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SLEEP %d\n", duration);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Send a message on the specified topic
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SendMessage(int topicNumber, char *message)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SEND%d %s\n", topicNumber, message);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Subscribe to a topic
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SubscribeToTopic(int topicNumber)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SUBSCRIBE%d\n", topicNumber);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Unsubscribe from Topic
 * @retval The ExpressLink Module response
 */
char* ExpressLink_UnsubscribeFromTopic(int topicNumber)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+UNSUBSCRIBE%d\n", topicNumber);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/******************************************************************************/
/**
 * @brief Fetches the current state of the OTA process
 * @retval The ExpressLink Module response (OTA or HOTA)
 */
int ExpressLink_OTA_GetState(void)
{
	char *res;

	res =  expresslink_execute_command("AT+OTA?\n", ExpressLink_COMMAND_TIMEOUT);

  return get_int(res);
}

/**
 * @brief Allow the OTA operation to proceed
 * @retval The ExpressLink Module response (OTA or HOTA)
 */
char* ExpressLink_OTA_Accept(void)
{
  return expresslink_execute_command("AT+OTA ACCEPT\n", ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Authorize the ExpressLink module to apply the new image
 * @retval The ExpressLink Module response
 */
char* ExpressLink_OTA_Apply(void)
{
  return expresslink_execute_command("AT+OTA APPLY\n", ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief The host OTA operation is completed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_OTA_Close(void)
{
  return expresslink_execute_command("AT+OTA CLOSE\n", ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Reject the OTA.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_OTA_Flush(void)
{
  return expresslink_execute_command("AT+OTA FLUSH\n", ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Read HOTA data.
 * @retval Nomber of HOTA data returned by the module
 */
uint32_t ExpressLink_OTA_Read(ExpressLink_OTA_Data_t * OTA_Data, uint32_t byte_count)
{
  char *res;
  int index1 = 0;
  int index2 = 0;
  int index3 = 0;
  char dest[9];

  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+OTA READ %lu\n", byte_count);

  res =  expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);

  index1 = get_index(res + index1, ' ');
  res[index1] = '\0';
  index1++;

  index2 = index1 + get_index(res + index1, ' ');
  res[index2] = '\0';
  index2++;

  index3 = index2 + get_index(res + index2, ' ');
  res[index3] = '\0';
  index3++;

  sscanf(&res[index1], "%x", (int *)&OTA_Data->count);
  sscanf(&res[index3], "%x", (int *)&OTA_Data->crc);

  for(int i = 0; i < OTA_Data->count*2; i+=8)
  {
    strncpy(dest, &res[index2 + i], 8);
    dest[8]='\0';
    sscanf(dest, "%x",  (int *)&OTA_Data->data[i/8]);
    OTA_Data->data[i/8] = __REV(OTA_Data->data[i/8]);
  }

  return OTA_Data->count;
}

/**
 * @brief Moves the read pointer to an absolute address.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_OTA_Seek(uint32_t address)
{
	if(address == 0)
	{
		snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+OTA SEEK\n");
	}
	else
	{
		snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+OTA SEEK  %lu\n", address);
	}

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/******************************************************************************/
/**
 * @brief Set the module state
 * @retval None
 */
void ExpressLink_SetState(ExpressLink_state_t NewState)
{
  state = NewState;
}

/**
 * @brief Set AWS IoT Core endpoint
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetEndpoint(char *endpoint)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF Endpoint=%s\n", endpoint);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set a topic
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetTopic(int topicNumber, char *topic)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF Topic%d=%s\n", topicNumber, topic);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set the Wi-Fi SSID
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetSSID(char *ssid)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF SSID=%s\n", ssid);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set the Wi-Fi password
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetPassphrase(char *passphrase)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF Passphrase=%s\n", passphrase);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set Access Point Name (Cellular modules only)
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetAPN(char *apn)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF APN=%s\n", apn);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set the module in conf mode
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetConfMode(void)
{
  return expresslink_execute_command("AT+CONFMODE\n", 2 * ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set Defender period
 * @param period: The Device Defender upload period in seconds. (0 indicates the service is disabled.)
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetDefenderPeriod(int period)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF DefenderPeriod=%d\n", period);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set QoS level
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetQoS(int QoS)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF QoS=%d\n", QoS);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set the CustomName
 * @retval The ExpressLink Module response
 */
char* ExpressLink_SetCustomName(char *CustomName)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF CustomName=%s\n", CustomName);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}
/******************************************************************************/
/**
 * @brief Enable Shadow
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowEnable(void)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF EnableShadow=1\n");

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Disable Shadow
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowDisable(void)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF EnableShadow=0\n");

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set the Shadow ShadowToken
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowSetToken(int token)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF ShadowToken=%d\n", token);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Initialize communication with the Device Shadow service
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowInit(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW INIT\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d INIT\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Subscribe to a device shadow document
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowSubscribe(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW SUBSCRIBE\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d SUBSCRIBE\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief UNSUBSCRIBE
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowUnSubscribe(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW UNSUBSCRIBE\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d UNSUBSCRIBE\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Set a Custom defined named shadow
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowSetTopic(int topicNumber, char *topic)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF Shadow%d=%s\n", topicNumber, topic);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Retrieve a device shadow delta response
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowGetDelta(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW GET DELTA\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d GET DELTA\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief ExpressLink_ShadowDelete
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowDelete(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW DELETE\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d DELETE\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Request a Shadow delete response
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowGetDelete(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW GET DELETE\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d GET DELETE\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Request a Device Shadow document
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowDoc(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW DOC\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d DOC\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Retrieve a device shadow document
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowGetDoc(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW GET DOC\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d GET DOC\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Request a device shadow document update
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowUpdate(int index, char *new_state)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW UPDATE %s\n", new_state);
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d UPDATE %s\n", index, new_state);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Retrieve a device shadow update response
 * If the shadow index = 0, the Unnamed Shadow document is assumed.
 * @retval The ExpressLink Module response
 */
char* ExpressLink_ShadowGetUpdate(int index)
{
  if (index == 0)
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW GET UPDATE\n");
  }
  else
  {
    snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+SHADOW%d GET UPDATE\n", index);
  }

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/******************************************************************************/
/**
 * @brief Get the module state
 * @retval The module state
 */
ExpressLink_state_t ExpressLink_GetState()
{
  return state;
}

/**
 * @brief Get the time from the module
 * @retval The ExpressLink Module response
 */
char* ExpressLink_GetTime(void)
{
  return expresslink_execute_command("AT+TIME?\n", ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Get Connection details
 * @retval The ExpressLink Module response
 */
char* ExpressLink_GetConnection(void)
{
  return expresslink_execute_command("AT+CONNECT?\n", ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Get a specific configuration value from the module
 * @retval The ExpressLink Module response
 */
char* ExpressLink_GetConf(char *conf)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+CONF? %s\n", conf);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Get the thing name from the module
 * @retval The ExpressLink Module response
 */
char* ExpressLink_GetThingName(void)
{
  char *res;

  res = ExpressLink_GetConf((char*) &"ThingName");

  return &res[3];
}

/**
 * @brief Get the topic that generated an event
 * @retval The ExpressLink Module response
 */
void ExpressLink_GetTopic(char *topic)
{
  char *response;

  response = expresslink_execute_command("AT+GET\n", ExpressLink_COMMAND_TIMEOUT);

  strcpy(topic, &response[4]);
}

/**
 * @brief Get the received message
 * @retval The ExpressLink Module response
 */
uint32_t ExpressLink_GetMessage(MQTTPublishInfo_t *msg)
{
  int i = 0;
  HAL_StatusTypeDef USART_STATUS = HAL_OK;

  char *response;

  response = expresslink_execute_command("AT+GET\n", ExpressLink_COMMAND_TIMEOUT);

  strcpy(msg->pTopic, &response[4]);

  msg->payloadLength = 0;

  if (strlen(msg->pTopic) > 0)
  {
    do
    {
      USART_STATUS = HAL_UART_Receive(&EXPRESSLINK_USART_HANDLER, (uint8_t* )&msg->pPayload[i], 1, ExpressLink_COMMAND_TIMEOUT);
      i++;
    } while ((msg->pPayload[i - 1] != '\n') && (USART_STATUS != HAL_TIMEOUT));

    if (USART_STATUS == HAL_OK)
    {
      msg->payloadLength = strlen(msg->pPayload);
    }
  }

  return msg->payloadLength;
}

char* ExpressLink_GetMessageTopic(int index)
{
  snprintf(command, EXPRESSLINK_TX_BUFFER_SIZE, "AT+GET%d\n", index);

  return expresslink_execute_command(command, ExpressLink_COMMAND_TIMEOUT);
}

/**
 * @brief Get the latest event.
 * @retval The event number
 */
ExpressLink_event_t ExpressLink_GetEvent(void)
{
  
  static ExpressLink_event_t event;

  event.id = EXPRESSLINK_EVENT_NONE;
  char *res;
#if defined(ExpressLink_EVENT_GPIO_Port)
  GPIO_PinState val = GPIO_PIN_RESET;
  
  val = HAL_GPIO_ReadPin(ExpressLink_EVENT_GPIO_Port, ExpressLink_EVENT_Pin);

  if (GPIO_PIN_RESET != val)
#endif
  {
    res = expresslink_execute_command("AT+EVENT?\n", ExpressLink_COMMAND_TIMEOUT);
    
    if(strstr(res, "ERROR") != NULL)
    {
      event.id = EXPRESSLINK_EVENT_ERROR;
    }
    else if (strcmp(res, "OK") == 0)
    {
      event.id = EXPRESSLINK_EVENT_NONE;
    }
    else
    {
      event.id = (ExpressLink_event_id_t) get_int(res);
    }

    switch (event.id)
    {
    case EXPRESSLINK_EVENT_MESSAGE:
    case EXPRESSLINK_EVENT_CONNECT:
    case EXPRESSLINK_EVENT_SUBACK:
    case EXPRESSLINK_EVENT_SUBNACK:
    case EXPRESSLINK_EVENT_SHADOW_INIT:
    case EXPRESSLINK_EVENT_SHADOW_INIT_FAILED:
    case EXPRESSLINK_EVENT_SHADOW_INIT_DOC:
    case EXPRESSLINK_EVENT_SHADOW_UPDATE:
    case EXPRESSLINK_EVENT_SHADOW_DELTA:
    case EXPRESSLINK_EVENT_SHADOW_DELETE:
    case EXPRESSLINK_EVENT_SHADOW_SUBACK:
    case EXPRESSLINK_EVENT_SHADOW_SUBNACK:
      event.param = (ExpressLink_event_id_t) get_int(&res[5]);
      break;

    default:
      event.param = 0;
      break;
    }
  }

  return event;
}

/******************************************************************************/
/**
 * @brief Send a command to the module
 * @retval The ExpressLink Module response
 */
char* expresslink_execute_command(char *command, unsigned long timeout_ms)
{
  int i = 0;
  int command_size = strlen(command);
  HAL_StatusTypeDef USART_STATUS = HAL_OK;

  memset(response, 0, EXPRESSLINK_RX_BUFFER_SIZE);

#if EXPRESSLINK_DEBUG
  printf("%s", command);
#endif

  HAL_UART_Transmit(&EXPRESSLINK_USART_HANDLER, (uint8_t* )command, command_size, timeout_ms);

  do
  {
    USART_STATUS = HAL_UART_Receive(&EXPRESSLINK_USART_HANDLER, (uint8_t* )&response[i], 1, timeout_ms);
    i++;
  } while ((response[i - 1] != '\n') && (USART_STATUS != HAL_TIMEOUT));

  if(USART_STATUS == HAL_TIMEOUT)
  {
    memset  (response, 0, EXPRESSLINK_RX_BUFFER_SIZE);
    snprintf(response, EXPRESSLINK_TX_BUFFER_SIZE, "ERROR\r\n");
  }

#if (EXPRESSLINK_DEBUG == EXPRESSLINK_LOG_LEVEL_2)
  printf("%s", response);
#endif
  return response;
}

/**
 * @brief Get an int from a string
 * @retval The int value
 */
static int get_int(char *string)
{
  int val = 0;

  while (*string)
  {
    if (isdigit((int )*string))
    {
      val = (int) strtol(string, &string, 10);

      return val;
    }
    else
    {
      string++;
    }
  }

  return val;
}

/**
 * @brief Get the index of the first occurrence of a character in a string
 * @retval The character index in the string
 */
static int get_index(char* string, char c)
{
    char *e = strchr(string, c);

    if (e == NULL)
    {
        return -1;
    }

    return (int)(e - string);
}

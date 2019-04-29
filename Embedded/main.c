/**
  ******************************************************************************
  * @file    Display/LTDC_Paint/Src/main.c 
  * @author  MCD Application Team
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "save.h"
#include "color.h"
#include "color2.h"
#include "embedded_legf.h"
#include <stdlib.h>

/** @addtogroup STM32F4xx_HAL_Applications
  * @{
  */

/** @addtogroup LTDC_Paint
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
typedef enum {
  APPLICATION_IDLE = 0,  
  APPLICATION_RUNNIG    
}MSC_ApplicationTypeDef;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
USBH_HandleTypeDef  hUSBHost;
FATFS USBDISK_FatFs;  /* File system object for USB Disk logical drive */
FIL MyFile;           /* File object */
char USB_Path[4];     /* USB Disk logical drive path */

static uint32_t x = 0, y = 0;
static TS_StateTypeDef  TS_State;

const uint32_t aBMPHeader1[14]=         
{0x26E64D42, 0x0000000B, 0x00360000, 0x00280000, 0x02440000, 0x01A40000, 0x00010000, 
 0x00000018, 0xF5400000, 0x00000006, 0x00000000, 0x00000000, 0x00000000, 0x0000};

const uint32_t aBMPHeader2[14]=         
{0x13A64D42, 0x00000004, 0x00360000, 0x00280000, 0x01A40000, 0x00D40000, 0x00010000, 
 0x00000018, 0xF5400000, 0x00000006, 0x00000000, 0x00000000, 0x00000000, 0x0000};

/* Variable to save the state of USB */
MSC_ApplicationTypeDef Appli_state = APPLICATION_IDLE;

/* Private function prototypes -----------------------------------------------*/
static void GetPosition(void);
static void SystemClock_Config(void);


/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
     */
  HAL_Init();
  
  /* Configure the system clock to 168 MHz */
  SystemClock_Config(); 
  
  /* Configure LED1 and LED3 */
  BSP_LED_Init(LED1);
  BSP_LED_Init(LED3);
  
  /*##-1- LCD Initialization #################################################*/ 
  /* Initialize the LCD */ 
  BSP_LCD_Init();
  
  /* Background Layer Initialization */
  BSP_LCD_LayerDefaultInit(0, LCD_FRAME_BUFFER_LAYER0);
  
  /* Set Foreground Layer */
  BSP_LCD_SelectLayer(0);
  
  /* Enable the LCD */
  BSP_LCD_DisplayOn();
  
  /* Clear the LCD Background layer */
  BSP_LCD_Clear(LCD_COLOR_WHITE);
	
  /*##-2- Touch screen initialization ########################################*/
  Touchscreen_Calibration();
  
	legf_init();
	
	
	legf_refresh();
  /* Infinite loop */  
  while (1)
  {   
    GetPosition();
  }
}

		char uarticle[][256] = {"Pamietaj, ze", "Czasem nawet", "Wiedz, ze", "Nie warto rozmyslac o tym, ze", "Tylko", "Jedynie", "Warto rozmyslac o tym, ze", "Zrozum:", "To oczywiste, ze", "Musisz wiedziec jedno:", "Oto cala madrosc:", "Bo milosc - tak jak", "Albowiem", "Zdarza sie, ze", "Slyszano, ze", "Napisano bowiem:"}; 
		char noun[][256] = {"Bog", "wojownik", "czlowiek", "wszechswiat", "medrzec", "zebrak", "ludzkosc", "natura", "przyjaciel", "wrog", "twoj brat", "mistrz", "przyroda", "mnich", "nauczyciel", "uczen", "wedrowiec", "pielgrzym"}; 
		char verb[][256] = {"potrafi", "wie jak", "nie wie jak", "usiluje", "jest w stanie", "zdola", "moze", "probuje", "stara sie"}; 
		char larticle[][256] = {"zdobyc", "posiasc", "zyskac", "stracic", "zachowac", "utracic", "zmarnowac", "odzyskac"}; 
		char preposition[][256] = {"Sekret Wszechswiata", "skarb", "rozum", "bogactwo", "odwage", "milosc", "madrosc", "piekno", "dobro", "wiare", "nadzieje", "prawde", "szczescie", "spokoj", "rozsadek", "sens", "moc", "sile", "wladze"}; 
		char qoute[256];
			char qoute1[256];
/**
  * @brief  Configures and gets Touch screen position.
  * @param  None
  * @retval None
  */
static void GetPosition(void)
{    
 /* Get Touch screen position */
 BSP_TS_GetState(&TS_State); 
  /* Read the coordinate */
  x = Calibration_GetX(TS_State.x);
  y = Calibration_GetX(TS_State.y);
	if(TS_State.TouchDetected)
	{
		
		char touched_at[256];
		int btn = 0;
		if(Calibration_GetX(TS_State.x)>350)
		{
			btn = Calibration_GetX(TS_State.y)/54 + 1;
			int btn_id = btn + 2;
			if(btn > 2)
				btn_id++;
			comps[btn_id].ShapeValue.TextValues.BackgroundColor = rand()%0xFFFFFF;
		}
		comps[5].ShapeValue.TextValues.BackgroundColor = rand()%0xFFFFFF;
		

		int rand1 = rand()%(sizeof(uarticle)/256); 
		int rand2 = rand()%(sizeof(noun)/256);  
		int rand3 = rand()%(sizeof(verb)/256);  
		int rand4 = rand()%(sizeof(larticle)/256); 
		int rand5 = rand()%(sizeof(preposition)/256);
		
		sprintf(qoute1, "%s", uarticle[rand1]);
		sprintf(qoute, "%s %s %s %s.", noun[rand2], verb[rand3], larticle[rand4], preposition[rand5]);
		strcpy(comps[5].ShapeValue.TextValues.Text , qoute);
		strcpy(comps[10].ShapeValue.TextValues.Text , qoute1);
		
		legf_refresh();
		sprintf(touched_at, "Btn: %u Xw: %u Yw: %u", btn, Calibration_GetX(TS_State.x), Calibration_GetX(TS_State.y));
		BSP_LCD_DisplayStringAt(0, 0, (uint8_t *)touched_at, LEFT_MODE);
	}
   
}


/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and Activate PLL with HSE ad source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
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
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

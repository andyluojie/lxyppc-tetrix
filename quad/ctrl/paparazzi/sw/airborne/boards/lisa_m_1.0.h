#ifndef CONFIG_LISA_M_1_0_H
#define CONFIG_LISA_M_1_0_H

#define BOARD_LISA_M

#define AHB_CLK 72000000

/* Onboard LEDs */
/* red */
#ifndef USE_LED_1
#define USE_LED_1 1
#endif
#define LED_1_GPIO GPIOB
#define LED_1_GPIO_CLK RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO
#define LED_1_GPIO_PIN GPIO_Pin_4
#define LED_1_AFIO_REMAP GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST, ENABLE)

/* blue */
#ifndef USE_LED_2
#define USE_LED_2 1
#endif
#define LED_2_GPIO GPIOC
#define LED_2_GPIO_CLK RCC_APB2Periph_GPIOC
#define LED_2_GPIO_PIN GPIO_Pin_5
#define LED_2_AFIO_REMAP ((void)0)

/* blue */
#ifndef USE_LED_3
#define USE_LED_3 1
#endif
#define LED_3_GPIO GPIOC
#define LED_3_GPIO_CLK RCC_APB2Periph_GPIOC
#define LED_3_GPIO_PIN GPIO_Pin_2
#define LED_3_AFIO_REMAP ((void)0)

// GPIO pins
#ifndef USE_LED_4
#define USE_LED_4 1
#endif
#define LED_4_GPIO GPIOC
#define LED_4_GPIO_CLK RCC_APB2Periph_GPIOC
#define LED_4_GPIO_PIN GPIO_Pin_12
#define LED_4_AFIO_REMAP ((void)0)

#ifndef USE_LED_5
#define USE_LED_5 1
#endif
#define LED_5_GPIO GPIOC
#define LED_5_GPIO_CLK RCC_APB2Periph_GPIOC
#define LED_5_GPIO_PIN GPIO_Pin_10
#define LED_5_AFIO_REMAP ((void)0)


/* configuration for aspirin - and more generaly IMUs */
#define IMU_ACC_DRDY_RCC_GPIO         RCC_APB2Periph_GPIOB
#define IMU_ACC_DRDY_GPIO             GPIOB
#define IMU_ACC_DRDY_GPIO_PORTSOURCE  GPIO_PortSourceGPIOB



#define DefaultVoltageOfAdc(adc) (0.00485*adc)

/* Onboard ADCs */
/*
   ADC_1 PC3/ADC13
   ADC_2 PC0/ADC10
   ADC_3 PC1/ADC11
   ADC_4 PC5/ADC15
   ADC_6 PC2/ADC12
   BATT  PC4/ADC14
*/
#define BOARD_ADC_CHANNEL_1 ADC_Channel_13
#define BOARD_ADC_CHANNEL_2 ADC_Channel_10
#define BOARD_ADC_CHANNEL_3 ADC_Channel_11
// we can only use ADC1,2,3; the last channel is for bat monitoring
#define BOARD_ADC_CHANNEL_4 ADC_Channel_14

/* provide defines that can be used to access the ADC_x in the code or airframe file
 * these directly map to the index number of the 4 adc channels defined above
 * 4th (index 3) is used for bat monitoring by default
 */
#define ADC_1 0
#define ADC_2 1
#define ADC_3 2

/* allow to define ADC_CHANNEL_VSUPPLY in the airframe file*/
#ifndef ADC_CHANNEL_VSUPPLY
#define ADC_CHANNEL_VSUPPLY 3
#endif

/* GPIO mapping for ADC1 pins, overwrites the default in arch/stm32/mcu_periph/adc_arch.c */
// FIXME, this is not very nice, is also stm lib specific
#ifdef USE_AD1
#define ADC1_GPIO_INIT(gpio) {                  \
    (gpio).GPIO_Pin  = GPIO_Pin_3 | GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4; \
    (gpio).GPIO_Mode = GPIO_Mode_AIN;           \
    GPIO_Init(GPIOC, (&gpio));                  \
  }
#endif // USE_AD1



#define BOARD_HAS_BARO 1

#define USE_OPENCM3 1

// not needed with USE_OPENCM3:
//#define HSE_TYPE_EXT_CLK
//#define STM32_RCC_MODE RCC_HSE_ON
//#define STM32_PLL_MULT RCC_PLLMul_6

#define PWM_5AND6_TIMER TIM5
#define PWM_5AND6_RCC RCC_APB1Periph_TIM5
#define PWM5_OC 1
#define PWM6_OC 2
#define PWM_5AND6_GPIO GPIOA
#define PWM5_Pin GPIO_Pin_0
#define PWM6_Pin GPIO_Pin_1

#endif /* CONFIG_LISA_M_1_0_H */

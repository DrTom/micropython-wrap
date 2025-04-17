#define MICROPY_HW_BOARD_NAME       "WeAct Studio STM32H723"
#define MICROPY_HW_MCU_NAME         "STM32H723VGT6"
#define MICROPY_HW_FLASH_FS_LABEL   "WEACT_STM32H723"

#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_DAC       (1) //PA4 DAC1_OUT1 , PA5 DAC1_OUT2
#define MICROPY_HW_ENABLE_ADC       (1)
//#define MICROPY_HW_ENABLE_I2S       (1) // does not compile likely error in dma.c (works for F7)
//#define MICROPY_HW_ENABLE_USB       (1) // not here, see usb section
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_ENABLE_MMCARD    (0)
#define MICROPY_HW_ENABLE_CAN       (1)
#define MICROPY_HW_ENABLE_FDCAN     (1)
#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)

// Flash storage config
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)

#define FDCAN_FILTER_RANGE         ((uint32_t)0x00000000U) /*!< Range filter from FilterID1 to FilterID2                        */
#define FDCAN_FILTER_DUAL          ((uint32_t)0x00000001U) /*!< Dual ID filter for FilterID1 or FilterID2                       */
#define FDCAN_FILTER_MASK          ((uint32_t)0x00000002U) /*!< Classic filter: FilterID1 = filter, FilterID2 = mask            */
#define FDCAN_FILTER_RANGE_NO_EIDM ((uint32_t)0x00000003U) /*!< Range filter from FilterID1 to FilterID2, EIDM mask not applied */

// The board has an 25MHz HSE, the following gives 550MHz CPU speed
#define MICROPY_HW_CLK_PLLM (5)
#define MICROPY_HW_CLK_PLLN (110)
#define MICROPY_HW_CLK_PLLP (1)
#define MICROPY_HW_CLK_PLLQ (4)
#define MICROPY_HW_CLK_PLLR (2)
#define MICROPY_HW_CLK_PLLVCI (RCC_PLL1VCIRANGE_1)
#define MICROPY_HW_CLK_PLLVCO (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC (0)

// The USB clock is set using PLL3 by default unless reconfigured in USB section
#define MICROPY_HW_CLK_PLL3M (25)
#define MICROPY_HW_CLK_PLL3N (192)
#define MICROPY_HW_CLK_PLL3P (1)  // 240 Mhz
#define MICROPY_HW_CLK_PLL3Q (4)  // 48 Mhz
#define MICROPY_HW_CLK_PLL3R (2)
#define MICROPY_HW_CLK_PLL3VCI (RCC_PLL3VCIRANGE_1)
#define MICROPY_HW_CLK_PLL3VCO (RCC_PLL3VCOWIDE)
#define MICROPY_HW_CLK_PLL3FRAC (0)

// ??? see ARDUINO_NICLA_VISION/mpconfigboard.h for more info should be 2 , 3 or 4?
//#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_4

// The board has an external 32kHz crystal attached for RTC
//#define MICROPY_HW_RTC_USE_LSE              (1)


// UART #################################################

// UART1
#define MICROPY_HW_UART1_NAME   "F"
#define MICROPY_HW_UART1_TX  (pin_A9)  // Feedback?
#define MICROPY_HW_UART1_RX  (pin_A10) // Feedback?

// USART2
#define MICROPY_HW_UART2_NAME   "E"
#define MICROPY_HW_UART2_TX     (pin_A2) // A2,D5
#define MICROPY_HW_UART2_RX     (pin_A3) // A3,D6

// USART3
#define MICROPY_HW_UART3_NAME   "H"
#define MICROPY_HW_UART3_TX     (pin_D8) // B10,C10,D8
#define MICROPY_HW_UART3_RX     (pin_D9) // B11,C11,D9

// UART4
#define MICROPY_HW_UART4_NAME   "C"
#define MICROPY_HW_UART4_TX     (pin_A0) // A0,A12,B9,C10,D1
#define MICROPY_HW_UART4_RX     (pin_A1) // A1,A11,B8,C11,D0

// UART5, conflicts with Can2!
#define MICROPY_HW_UART5_NAME   "G"
#define MICROPY_HW_UART5_TX     (pin_B13) // B6,B13,C12
#define MICROPY_HW_UART5_RX     (pin_B12) // B5,B12,D2

// USART6
#define MICROPY_HW_UART6_NAME   "D"
#define MICROPY_HW_UART6_TX     (pin_C6) // C6
#define MICROPY_HW_UART6_RX     (pin_C7) // C7

// UART7
#define MICROPY_HW_UART7_NAME   "B"
#define MICROPY_HW_UART7_TX     (pin_E8) // A15,B4,E8
#define MICROPY_HW_UART7_RX     (pin_E7) // A8,B3,E7

// UART8
#define MICROPY_HW_UART8_NAME   "A"
#define MICROPY_HW_UART8_TX     (pin_E1) // E1
#define MICROPY_HW_UART8_RX     (pin_E0) // E0



// I2C /////////////////////////////////////////////////

#define MICROPY_HW_I2C1_SCL (pin_B8)  // B6, B8
#define MICROPY_HW_I2C1_SDA (pin_B9)  // B7, B9

#define MICROPY_HW_I2C2_SCL (pin_B10) // B10,
#define MICROPY_HW_I2C2_SDA (pin_B11) // B11,

#define MICROPY_HW_I2C3_SCL (pin_A8) // A8
#define MICROPY_HW_I2C3_SDA (pin_C9) // C9

#define MICROPY_HW_I2C4_SCL (pin_D12) // D12
#define MICROPY_HW_I2C4_SDA (pin_D13) // D13, B7, B9

// SPI buses /////////////////////////////////////////////////
#define MICROPY_HW_SPI1_NAME "SPIFLASH"
#define MICROPY_HW_SPI1_NSS  (pin_D6)  // FLASH CS
#define MICROPY_HW_SPI1_SCK  (pin_B3)  // FLASH CLK
#define MICROPY_HW_SPI1_MISO (pin_B4)  // FLASH MISO
#define MICROPY_HW_SPI1_MOSI (pin_D7)  // FLASH MOSI

#define MICROPY_HW_SPI2_NSS  (pin_B12) // UART5_RX
#define MICROPY_HW_SPI2_SCK  (pin_B13) // UART5_TX
#define MICROPY_HW_SPI2_MISO (pin_B14)
#define MICROPY_HW_SPI2_MOSI (pin_B15)

// SPI4 seems to be used for the LCD
#define MICROPY_HW_SPI4_NSS  (pin_E11)
#define MICROPY_HW_SPI4_SCK  (pin_E12)
#define MICROPY_HW_SPI4_MISO (pin_E13)
#define MICROPY_HW_SPI4_MOSI (pin_E14)


// disable internal flash
#define MICROPY_HW_QSPIFLASH_CS (pin_B6)
#define MICROPY_HW_QSPIFLASH_CS_PULL (GPIO_PULLUP)

#define MICROPY_HW_SPIFLASH_NSS  (pin_D6)  // FLASH CS
#define MICROPY_HW_SPIFLASH_NSS_PULL  (GPIO_PULLUP)


// FDCAN bus /////////////////////////////////////////////////
#define MICROPY_HW_CAN1_NAME  "FDCAN1"
#define MICROPY_HW_CAN1_TX    (pin_D1)
#define MICROPY_HW_CAN1_RX    (pin_D0)

#define MICROPY_HW_CAN2_NAME  "FDCAN2"
#define MICROPY_HW_CAN2_TX    (pin_B13)
#define MICROPY_HW_CAN2_RX    (pin_B12)



// SD Card SDMMC /////////////////////////////////////////////////
#define MICROPY_HW_SDCARD_SDMMC             (1)
#define MICROPY_HW_SDCARD_CK                (pin_C12) // default SDMMC1
#define MICROPY_HW_SDCARD_CMD               (pin_D2)  // default SDMMC1
#define MICROPY_HW_SDCARD_D0                (pin_C8)  // default SDMMC1
#define MICROPY_HW_SDCARD_D1                (pin_C9)  // default SDMMC1
#define MICROPY_HW_SDCARD_D2                (pin_C10) // default SDMMC1
#define MICROPY_HW_SDCARD_D3                (pin_C11) // default SDMMC1
#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_D4)  // default SDMMC1
#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_SET) // (GPIO_PIN_RESET)

#define MICROPY_HW_SDCARD_MOUNT_AT_BOOT     (1)

// USB config /////////////////////////////////////////////////
#define MICROPY_HW_ENABLE_USB               (1)
#define MICROPY_HW_RCC_HSI48_STATE          (RCC_HSI48_ON)
#define MICROPY_HW_RCC_USB_CLKSOURCE        (RCC_USBCLKSOURCE_HSI48)
//#define MICROPY_HW_USB_FS                   (1) // does not compile with this setting
#define MICROPY_HW_USB_HS                   (1)
#define MICROPY_HW_USB_HS_IN_FS             (1)
//#define MICROPY_HW_USB_VBUS_DETECT_PIN      (pin_A9)
//#define MICROPY_HW_USB_OTG_ID_PIN           (pin_A10)

// USER SWITCH /////////////////////////////////////////////////
// is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN                (pin_C13)
#define MICROPY_HW_USRSW_PULL               (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE          (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED            (1)

// LEDs /////////////////////////////////////////////////
// LED is active high.
#define MICROPY_HW_LED1             (pin_E3) // blue
#define MICROPY_HW_LED_OTYPE        (GPIO_MODE_OUTPUT_PP)
#define MICROPY_HW_LED_ON(pin)              (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)             (mp_hal_pin_low(pin))




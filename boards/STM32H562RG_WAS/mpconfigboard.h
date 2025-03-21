#define MICROPY_HW_BOARD_NAME               "WEACT_H562RG"
#define MICROPY_HW_MCU_NAME                 "STM32H562RG"
#define MICROPY_HW_FLASH_FS_LABEL           "STM32H562"


#define MICROPY_HW_ENABLE_ADC               (1)
#define MICROPY_HW_ENABLE_DAC               (1)
#define MICROPY_HW_ENABLE_RNG               (1)
#define MICROPY_HW_ENABLE_RTC               (1)
#define MICROPY_HW_ENABLE_SDCARD    	    (1)
#define MICROPY_HW_ENABLE_TIMER     	    (1)
#define MICROPY_HW_ENABLE_USB               (1)
#define MICROPY_HW_HAS_FLASH                (1)
#define MICROPY_HW_HAS_LCD          (0)
#define MICROPY_HW_HAS_MMA7660      (0)
#define MICROPY_HW_HAS_SWITCH               (1)
#define MICROPY_PY_PYB_LEGACY               (0)
// #define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)


# initially clock with 16 MHz HSE
# then change the frequency from micropthon to 250 MHz
# with machine.freq(250000000)

//#define MICROPY_HW_CLK_USE_BYPASS           (1)
#define MICROPY_HW_CLK_USE_HSE         	    (1)
#define MICROPY_HW_CLK_PLLM                 (4)
#define MICROPY_HW_CLK_PLLN                 (160)
#define MICROPY_HW_CLK_PLLP                 (2)
#define MICROPY_HW_CLK_PLLQ                 (2)
#define MICROPY_HW_CLK_PLLR                 (2)
#define MICROPY_HW_CLK_PLLVCI_LL            (LL_RCC_PLLINPUTRANGE_2_4)
#define MICROPY_HW_CLK_PLLVCO_LL            (LL_RCC_PLLVCORANGE_WIDE)
#define MICROPY_HW_CLK_PLLFRAC              (0)
// PLL3 with Q output at 48MHz for USB
// #define MICROPY_HW_CLK_USE_PLL3_FOR_USB
#define MICROPY_HW_CLK_PLL3M                (8)
#define MICROPY_HW_CLK_PLL3N                (192)
#define MICROPY_HW_CLK_PLL3P                (2)
#define MICROPY_HW_CLK_PLL3Q                (4)
#define MICROPY_HW_CLK_PLL3R                (2)
#define MICROPY_HW_CLK_PLL3FRAC             (0)
#define MICROPY_HW_CLK_PLL3VCI_LL           (LL_RCC_PLLINPUTRANGE_1_2)
#define MICROPY_HW_CLK_PLL3VCO_LL           (LL_RCC_PLLVCORANGE_MEDIUM)

// 5 wait states, according to Table 37, Reference Manual (RM0481 Rev 1)
#define MICROPY_HW_FLASH_LATENCY            FLASH_LATENCY_5

// There is an external 32kHz oscillator
#define MICROPY_HW_RTC_USE_LSE              (1)
#define RTC_ASYNCH_PREDIV           (127)
#define RTC_SYNCH_PREDIV            (256)
//#define MICROPY_HW_RTC_USE_BYPASS   (0)
#define MICROPY_HW_RTC_USE_US       (1)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

// UART config

#define MICROPY_HW_UART1_NAME   "UART1"
#define MICROPY_HW_UART1_TX                 (pin_A9)
#define MICROPY_HW_UART1_RX                 (pin_A10)

#define MICROPY_HW_UART2_NAME   "UART2"
#define MICROPY_HW_UART2_TX                 (pin_A2)
#define MICROPY_HW_UART2_RX                 (pin_A3)

#define MICROPY_HW_UART3_NAME   "UART3"
#define MICROPY_HW_UART3_TX                 (pin_C10)
#define MICROPY_HW_UART3_RX                 (pin_C11)

#define MICROPY_HW_UART4_NAME   "UART4"
#define MICROPY_HW_UART4_TX                 (pin_A12) // USB-DP Serial
#define MICROPY_HW_UART4_RX                 (pin_A11) // USB-DN Serial

#define MICROPY_HW_UART5_NAME   "UART5"
#define MICROPY_HW_UART5_TX                 (pin_B6)
#define MICROPY_HW_UART5_RX                 (pin_B5)

#define MICROPY_HW_UART6_NAME   "UART6"
#define MICROPY_HW_UART6_TX                 (pin_C6)
#define MICROPY_HW_UART6_RX                 (pin_C7)

#define MICROPY_HW_UART7_NAME   "UART7"
#define MICROPY_HW_UART7_TX                 (pin_B4)
#define MICROPY_HW_UART7_RX                 (pin_B3)

#define MICROPY_HW_UART11_NAME   "UART11"
#define MICROPY_HW_UART11_TX                (pin_A6)
#define MICROPY_HW_UART11_RX                (pin_A7)


// Connect REPL to UART4 which is provided on ST-Link USB interface
#define MICROPY_HW_UART_REPL                PYB_UART_4
#define MICROPY_HW_UART_REPL_BAUD           115200

// I2C buses
#define MICROPY_HW_I2C1_SCL (pin_B6)
#define MICROPY_HW_I2C1_SDA (pin_B7)
#define MICROPY_HW_I2C2_SCL (pin_B10)
#define MICROPY_HW_I2C2_SDA (pin_B11)

// SPI buses
#define MICROPY_HW_SPI1_NSS  (pin_A4)
#define MICROPY_HW_SPI1_SCK  (pin_A5)
#define MICROPY_HW_SPI1_MISO (pin_A6)
#define MICROPY_HW_SPI1_MOSI (pin_A7)
#define MICROPY_HW_SPI2_NSS  (pin_B12)
#define MICROPY_HW_SPI2_SCK  (pin_B13)
#define MICROPY_HW_SPI2_MISO (pin_B14)
#define MICROPY_HW_SPI2_MOSI (pin_B15)

// I2S buses
// #define MICROPY_HW_I2S2      (1)

// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN                (pin_C13)
#define MICROPY_HW_USRSW_PULL               (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE          (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED            (1)

// LEDs
#define MICROPY_HW_LED1                     (pin_B2) // Blue
#define MICROPY_HW_LED_ON(pin)              (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)             (mp_hal_pin_low(pin))

// SD card detect switch
#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_A8)
#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_SET)


// USB config
#define MICROPY_HW_USB_FS                   (1)
#define MICROPY_HW_USB_MAIN_DEV             (USB_PHY_FS_ID)


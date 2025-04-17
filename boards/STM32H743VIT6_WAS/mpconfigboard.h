#define MICROPY_HW_BOARD_NAME "WEACT_STM32H743"
#define MICROPY_HW_MCU_NAME "STM32H743VIT6"
#define MICROPY_HW_FLASH_FS_LABEL "STM32H743"

#define MICROPY_FATFS_EXFAT      (1)
#define MICROPY_HW_ENABLE_RTC    (1)
#define MICROPY_HW_ENABLE_RNG    (1)
#define MICROPY_HW_ENABLE_ADC    (1)
#define MICROPY_HW_ENABLE_DAC    (1)
#define MICROPY_HW_ENABLE_USB    (1)
#define MICROPY_HW_HAS_SWITCH    (1)
#define MICROPY_HW_HAS_FLASH     (1)
#define MICROPY_HW_ENABLE_SERVO  (1)
#define MICROPY_HW_ENABLE_TIMER  (1)
#define MICROPY_HW_ENABLE_SDCARD (1)
#define MICROPY_HW_ENABLE_MMCARD (0)

// Flash storage config
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)

// Clock config
#define MICROPY_HW_CLK_PLLM (5)
#define MICROPY_HW_CLK_PLLN (192)
#define MICROPY_HW_CLK_PLLP (2)
#define MICROPY_HW_CLK_PLLQ (4)
#define MICROPY_HW_CLK_PLLR (2)
#define MICROPY_HW_CLK_PLLVCI (RCC_PLL1VCIRANGE_1)
#define MICROPY_HW_CLK_PLLVCO (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC (0)

#define MICROPY_HW_CLK_PLL3M (25)
#define MICROPY_HW_CLK_PLL3N (240)
#define MICROPY_HW_CLK_PLL3P (2)
#define MICROPY_HW_CLK_PLL3Q (5)
#define MICROPY_HW_CLK_PLL3R (2)
#define MICROPY_HW_CLK_PLL3VCI (RCC_PLL3VCIRANGE_1)
#define MICROPY_HW_CLK_PLL3VCO (RCC_PLL3VCOWIDE)
#define MICROPY_HW_CLK_PLL3FRAC (0)

// Bus clock divider values
#define MICROPY_HW_CLK_AHB_DIV          (RCC_HCLK_DIV2)
#define MICROPY_HW_CLK_APB1_DIV         (RCC_APB1_DIV2)
#define MICROPY_HW_CLK_APB2_DIV         (RCC_APB2_DIV2)
#define MICROPY_HW_CLK_APB3_DIV         (RCC_APB3_DIV2)
#define MICROPY_HW_CLK_APB4_DIV         (RCC_APB4_DIV2)

// 32kHz crystal for RTC
#define MICROPY_HW_RTC_USE_LSE (1)
#define MICROPY_HW_RTC_USE_US  (0)

#if (MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE == 0)
// W25Q64 for storage
#define MICROPY_HW_QSPI_PRESCALER (2) // 100 MHz
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (26)
#define MICROPY_HW_SPIFLASH_SIZE_BITS (64 * 1024 * 1024)
#define MICROPY_HW_QSPIFLASH_CS (pin_B6)
#define MICROPY_HW_QSPIFLASH_SCK (pin_B2)
#define MICROPY_HW_QSPIFLASH_IO0 (pin_D11)
#define MICROPY_HW_QSPIFLASH_IO1 (pin_D12)
#define MICROPY_HW_QSPIFLASH_IO2 (pin_E2)
#define MICROPY_HW_QSPIFLASH_IO3 (pin_D13)

// SPI flash, block device config
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_IOCTL(op, arg) ( \
    (op) == BDEV_IOCTL_NUM_BLOCKS ? (MICROPY_HW_SPIFLASH_SIZE_BITS / 8 / FLASH_BLOCK_SIZE) : \
    (op) == BDEV_IOCTL_INIT ? spi_bdev_ioctl(&spi_bdev, (op), (uint32_t)&spiflash_config) : \
    spi_bdev_ioctl(&spi_bdev, (op), (arg)) \
    )
#define MICROPY_HW_BDEV_READBLOCKS(dest, bl, n) spi_bdev_readblocks(&spi_bdev, (dest), (bl), (n))
#define MICROPY_HW_BDEV_WRITEBLOCKS(src, bl, n) spi_bdev_writeblocks(&spi_bdev, (src), (bl), (n))
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY FLASH_LATENCY_2
#else
#define MICROPY_HW_QSPIFLASH_CS (pin_B6)
#define MICROPY_HW_QSPIFLASH_CS_PULL (GPIO_PULLUP)
#endif


// UART #################################################

// USART1
#define MICROPY_HW_UART1_NAME   "F"
#define MICROPY_HW_UART1_TX     (pin_A9)  // A9,B6,B14
#define MICROPY_HW_UART1_RX     (pin_A10) // A10,B7,B15

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


// I2C buses /////////////////////////////////////////////////
#define MICROPY_HW_I2C1_SCL (pin_B8)  // B6, B8
#define MICROPY_HW_I2C1_SDA (pin_B9)  // B7, B9

#define MICROPY_HW_I2C2_SCL (pin_B10) // B10,F0,H4
#define MICROPY_HW_I2C2_SDA (pin_B11) // B11,F1,H5

// C9 conflicts with SD
#define MICROPY_HW_I2C3_SCL (pin_A8) // A8,H7
#define MICROPY_HW_I2C3_SDA (pin_C9) // C9,H8
                                     //
// D12 conflicts with SD
#define MICROPY_HW_I2C4_SCL (pin_D12) // B6,B8,D12,F14
#define MICROPY_HW_I2C4_SDA (pin_D13) // B7,B9,D13,F15

// SPI buses /////////////////////////////////////////////////
#define MICROPY_HW_SPI1_NSS  (pin_A4) // A4,A15
#define MICROPY_HW_SPI1_SCK  (pin_A5) // A5,B3
#define MICROPY_HW_SPI1_MISO (pin_A6) // A6,B4
#define MICROPY_HW_SPI1_MOSI (pin_A7) // A7,B5,D7

#define MICROPY_HW_SPI2_NSS  (pin_B4) // A11,B4,B9,B12
#define MICROPY_HW_SPI2_SCK  (pin_D3) // A9,A12,B10,B13,D3
#define MICROPY_HW_SPI2_MISO (pin_B14) // B14,C2
#define MICROPY_HW_SPI2_MOSI (pin_B15) // B15,C1,C3

// SPI3 is used for the QSPI flash;
#define MICROPY_HW_SPI3_NSS  (pin_B6) // A4,A15
#define MICROPY_HW_SPI3_SCK  (pin_B3)  // C10,B3
#define MICROPY_HW_SPI3_MISO (pin_B4)  // B4,C11
#define MICROPY_HW_SPI3_MOSI (pin_B2)  // B2,B5,C12,D6

// SPI4 is used for the display
// pin_E10 LCD_LED
#define MICROPY_HW_SPI4_NSS (pin_E11)
#define MICROPY_HW_SPI4_SCK (pin_E12)
#define MICROPY_HW_SPI4_MOSI (pin_E14)
#define MICROPY_HW_SPI4_MISO (pin_E13)

// https://community.st.com/t5/embedded-software-mcus/issue-with-bootloader-on-stm32h743-using-boot0-and-inline/td-p/73183

// FDCAN bus /////////////////////////////////////////////////
#define MICROPY_HW_CAN1_NAME   "J"
#define MICROPY_HW_CAN1_TX (pin_A12) // PA12, D1, B9
#define MICROPY_HW_CAN1_RX (pin_A11) // PA11, D0, B8

// conflicts with UART5!
#define MICROPY_HW_CAN2_NAME   "G"
#define MICROPY_HW_CAN2_TX (pin_B13) // B13, B6
#define MICROPY_HW_CAN2_RX (pin_B12) // B12, B5


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



// USRSW
#define MICROPY_HW_USRSW_PIN (pin_C13) // K1 on the board.
#define MICROPY_HW_USRSW_PULL (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED (0)

// LEDs
#define MICROPY_HW_LED1 (pin_E3) // the only controllable LED on the board.
#define MICROPY_HW_LED_ON(pin) (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin) (mp_hal_pin_high(pin))


// USB config
#define MICROPY_HW_USB_FS (1)


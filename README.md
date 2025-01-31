micropython-wrap
================

Building MicroPython for the WAS STM32F405, and STM32H562 boards

Build:

    ./bin/build-was-stm32f405-with-docker

Hold the `BOOT0` button on the board and press the `RESET` button to enter the DFU mode.

Flashing the firmware:

    dfu-util -D firmwares/STM32F405RGT6_WAS_1.24.1.dfu


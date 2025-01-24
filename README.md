micropython-wrap
================

Building MicroPython for the WAS STM32F405 board:

    ./bin/build-was-stm32f405-with-docker

Hold the `BOOT0` button on the board and press the `RESET` button to enter the DFU mode.

Flashing the firmware:

    dfu-util -D micropython/ports/stm32/build-WAS_STM32F405/firmware.dfu


### Downloading the firmware from the board:

    dfu-util -U firmware.dfu

there might be many devices, try the `--list` option
    dfu-util --list

and look for the proer __alt__ nunber. Then use the `-a` option to specify the alt number.

    dfu-util -a 0 -U firmware.dfu


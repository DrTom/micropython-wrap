micropython-wrap
================

This project contains configurations and scripts for building MicroPython
via Docker for the following boards:

* [WAS STM32F405RGT6][WAS-STM32F405RGT6]
* [WAS STM32H562GT6][WAS-STM32H562GT6]
* [WAS STM32H743VIT6][WAS-STM32H743VIT6]

All of these board are not officially supported by MicroPython. The
configurations have been stiched together from various sources. The F4 and H7
boards are in a good state. There are a few probems with the H5 board, see
below.


### Building


    ./bin/build-was-stm32f405-with-docker

### Flashing

Hold the `BOOT` button during power up of the device  or when the device is
alredy powered up  hold the `BOOT` button and press the `RESET` button to enter
the DFU mode.

Flashing the firmware:

    dfu-util -D firmwares/STM32F405RGT6_WAS_1.24.1.dfu



WAS STM32F405RGT6
-----------------


### System

#### CPU

```
>>> import machine
>>> machine.freq()
(168000000, 168000000, 42000000, 84000000)
```

#### Memory

```
>>> import gc
>>> gc.mem_alloc()
55808
>>> gc.mem_free()
46544
```


#### Disk

```
>>> import os
>>>
>>> fi = os.statvfs('/flash')
>>> fi
(512, 512, 86, 35, 35, 0, 0, 0, 0, 255)
>>> print(f'total {fi[0]*fi[2]}')
total 44032
>>> print(f'free {fi[0]*fi[4]}')
free 17920
```


Notes: Limited Flash size on the F4, this
https://github.com/orgs/micropython/discussions/16518 seems interesting.



WAS STM32H562GT6
----------------



### System

There are a few things that seem to wrong or could be improved:

* CPU frequency shoulbe increased to 250MHz from 200MHz; currently
    the board crashes when trying to set the frequency to 250MHz.

* Bus frequency seems not to be set correctly which might cause the UART to
    misbehave: https://github.com/orgs/micropython/discussions/16679

* There should be more flash space available. The F4 board has only half the
    flash space but the filesystem reports roughtly the same amount of free space.



#### CPU

```
>>> import machine
>>> machine.freq()
(200000000, 200000000, 200000000, 200000000)
```


#### Memory

```
import gc
>>> gc.mem_alloc()
31200
>>> gc.mem_free()
547488
```

#### Disk

https://docs.micropython.org/en/latest/library/os.html#os.statvfs

```
>>> import os
>>> fi = os.statvfs('/flash')
>>> fi
(512, 512, 94, 37, 37, 0, 0, 0, 0, 255)
>>> print(f'total {fi[0]*fi[2]}')
total 48128
>>> print(f'free {fi[0]*fi[4]}')
free 18944

```

WAS STM32H743VIT6
-----------------

An almost plain MicroPython configuration for the WAS STM32H743VIT6 board. It
includes the `st7789` display driver. Note that this in particular **not
OpenMV MicroPython**.


The build for this board includes the [ST7789 display driver](https://github.com/russhughes/st7789_mpy). See
[jkorte's STM32H723VGT6 configuration][jkorte-STM32H723VGT6] for examples.

### See also

* https://github.com/orgs/micropython/discussions/16159
* https://github.com/jkorte-dev/micropython-board-STM32H723VGT6

[jkorte-STM32H723VGT6]: https://github.com/jkorte-dev/micropython-board-STM32H723VGT6
[WAS-STM32F405RGT6]: https://github.com/WeActStudio/WeActStudio.STM32F4_64Pin_CoreBoard
[WAS-STM32H562GT6]: https://github.com/WeActStudio/WeActStudio.STM32H5_64Pin_CoreBoard
[WAS-STM32H743VIT6]: https://github.com/WeActStudio/MiniSTM32H7xx

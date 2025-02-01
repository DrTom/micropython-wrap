micropython-wrap
================

Building MicroPython for the WAS STM32F405, and STM32H562 boards

Build:

    ./bin/build-was-stm32f405-with-docker

Hold the `BOOT0` button on the board and press the `RESET` button to enter the DFU mode.

Flashing the firmware:

    dfu-util -D firmwares/STM32F405RGT6_WAS_1.24.1.dfu



STM32F405RGT6 WAS
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



STM32H562GT6 WAS
----------------



### System

There are a few things that seem to wrong or could be improved:

* CPU frequency shoulbe increased to 250MHz from 200MHz; currently
    the board crashes when trying to set the frequency to 250MHz.

* Bus frequency seems not to be set correctly which might cause the UART to
    misbehave: https://github.com/orgs/micropython/discussions/16679

* There should be more flash space available.



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


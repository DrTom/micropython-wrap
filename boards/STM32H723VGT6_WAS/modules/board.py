
### PortA is used for UART8 ##########

class PortA:
    PORT="A"
    PIN1= "E1"
    TX="E1"
    PIN2= "E0"
    RX="E0"
    UART=8

class UART8(PortA):
    pass

### PortB is used for UART7 ##########

class PortB:
    PORT="B"
    PIN1= "E8"
    TX="E8"
    PIN2= "E7"
    RX="E7"
    UART=7

class UART7(PortB):
    pass

### PortC is used for UART4 ##########

class PortC:
    Port="C"
    PIN1= "A0"
    TX="A0"
    PIN2= "A1"
    RX="A1"
    UART=4

class UART4(PortC):
    pass


### PortD is used for UART6 ##########

class PortD:
    PORT="D"
    PIN1= "C6"
    TX="C6"
    PIN2= "C7"
    RX="C7"
    UART=6

class UART6(PortD):
    pass

### PortG is used for UART5 ##########

class PortG:
    PORT="G"
    PIN1="B13"
    TX="B13"
    PIN2="B12"
    RX="B12"
    UART=5
    CAN=2

class UART5(PortG):
    pass

class CAN2(PortG):
    pass


### PortH is used for UART3 ##########

class PortH:
    PORT="H"
    PIN1= "D8"
    TX="D8"
    PIN2= "D9"
    RX="D9"
    UART=3

class UART3(PortH):
    pass

### PortE is used for UART2 ##########

class PortE:
    PORT="E"
    PIN1= "A2"
    TX="A2"
    PIN2= "A3"
    RX="A3"
    UART=2

class UART2(PortE):
    pass

### PortF is used for UART1 ##########

class PortF:
    PORT="F"
    PIN1= "A9"
    TX="A9"
    PIN2= "A10"
    RX="A10"
    UART=1

class UART1(PortF):
    pass


### PortJ is used for CAN1 ##########

class PortJ:
    PORT="J"
    PIN1= "A12"
    TX="A12"
    PIN2= "A11"
    RX="A11"
    CAN=1

class CAN1(PortJ):
    pass
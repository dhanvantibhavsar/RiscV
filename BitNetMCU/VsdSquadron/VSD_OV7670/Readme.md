# Live OV7670  implementation on VSD Squadron mini
*will work on any Ch32v003F4 based board*

updated version of [https://github.com/dhanvantibhavsar/RiscV/tree/main/BitNetMCU/VsdSquadron/Arduino_Ov7670](https://github.com/dhanvantibhavsar/RiscV/tree/main/BitNetMCU/VsdSquadron/Arduino_Ov7670)

```mermaid
stateDiagram-v2
state OV7670_Data_PINS{D0 D1 D2 D3 D4 D5 D6 D7 } 
state OV7670_ControlPins{XCLK PCLK VS HS SDA SCL }
state OV7670{OV7670_Data_PINS OV7670_ControlPins }
state VSDSquadronMini{PC0 PC1 PC2 PC3 PC4 PC5 PC6 PC7 PD0 PD2 PD3 PD4 PA1 PA2 VSDSquadronMiniUART }

    D0 --> PC0
    D1 --> PA1
    D2 --> PA2
    D3 --> PC3
    D4 --> PC4
    D5 --> PC5
    D6 --> PC6
    D7 --> PC7
    SDA --> PC1
    SCL --> PC2
    VS --> PD4
    HS --> PD3
    XCLK --> PD2
    PCLK --> PD0

state VSDSquadronMiniUART{PD5 RX PD6 TX }
    PD5 --> RX
    PD6 --> TX

```

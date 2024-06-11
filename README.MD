# Real Time Implementation of Low-Bit Quntized Neural network on Risc-V microcontroller
- Created under:- VSDSquadron Mini Research Internship Program
- Created By:- Dhanvanti Bhavsar
- Duration :- 04 May 2024 to 11 June 2024

## Implementation Video
[![implementation Video](./BitNetMCU/images/final_real_time_implementation.mp4)](./BitNetMCU/images/final_real_time_implementation.mp4)
<video src="./BitNetMCU/images/final_real_time_implementation.mp4" controls ></video>

## Content
1. [Install RISCV toochain for RISC-V development](Task1)
2. [Identify various RISCV instruction types (R,I,S,B,U,J) ](Task2)
3. [Executing RV32I on verilog and verfying execution](Task3)
4. [Real Time Implementation of Low-Bit Quntized Neural network on Risc-V microcontroller](BitNetMCU)
    1. [Overview](./BitNetMCU/readme.md/#Overview)
    2. [Components Required](./BitNetMCU/readme.md/#components)
    3. [Project Flow](./BitNetMCU/readme.md/#flow-of-the-project)
    4. [Circuit Diagram](./BitNetMCU/readme.md/#circuit-connection-for-bitnetmcu-real-time)
    5. [BitNetMcu Implementation](./BitNetMCU/readme.md/#bitnetmcu-implementation-1)
        1. [Training Neural Network model](./BitNetMCU/readme.md/#training-neural-network-model)
        2. [Exporting Model weights to C file for using with VSD](./BitNetMCU/readme.md/#exporting-model-weights-to-c-file-for-using-with-vsd)
        3. [Testing Output prediction of model ](./BitNetMCU/readme.md/#testing-output-prediction-of-model)
        4. [Generating dll file for inference](./BitNetMCU/readme.md/#generating-dll-file-for-inference)
    6. [Uploading BitNetMCU to VSDSquadron and realtime implementation](./BitNetMCU/VsdSquadron/readme.md)
        1. [Overview](#overview)
        2. [ToolChain Installation](#toolchain-installation)
        3. [Demo implementation with test images stored on board while flashing](#demo-implementation-with-test-images-stored-on-board-while-flashing)
            1. [Implementation](#implementation)
            2. [Result](#result)
        4. [Real Time Implementation with USART communication with Arduino and OV7670 integration](#real-time-implementation-with-usart-communication-with-arduino-and-ov7670-integration)
            1. [State Diagram](#state-diagram)
            2. [Connection Diagram](#connection-diagram)
            3. [Installation](#installation)
            4. [Camera Capture and Testing](#camera-capture-and-testing)
            5. [Image Capturing, Comperssion and sending over Uart](#image-capturing-comperssion-and-sending-over-uart)
            6. [VSDImplementation](#vsdimplementation)

**Please Check underlying Readme.md files for further details of every task**

## Project structure
```
RISCV/
|-- Task1/                  # Install RISCV toochain for RISC-V development
|-- Task2/                 # Identify various RISCV instruction types
|-- Task3/                   # Execution and verification of RV32I on verilog
|-- images/                 # Images for Doucmentation on Tasks
|-- BitNetMCU/              # Real Time Implementation of BitNet on VSDSM
|-- |-- images/             # Images for Documentation on implementation
|-- |-- modeldata/          # Pre-trained models
|-- |-- runs/               # Previous Training run data
|-- |-- data/               # MNIST Dataset
|-- |-- VsdSquadron/        # BitNetMCU implementation on VSDSM(Realtime)
|-- |-- |-- Arduino_OV7670  # Arduino code to capture and send processed image
|-- |-- |-- Bitnetmcu_implementation # VSDSM code to predict image
|-- |
|-- |-- BitNetMCU.py               # Pytorch model and QAT classes
|-- |-- BitNetMCU_inference.c      # C code for inference 
|-- |-- BitNetMCU_inference.h      # Header file for C inference code
|-- |-- BitNetMCU_MNIST_test.c     # Test script for MNIST dataset
|-- |-- BitNetMCU_MNIST_test_data.h# MNIST test data in header format (generated)
|-- |-- BitNetMCU_model.h          # Model data in C header format (generated)
|-- |-- BitNetMCU_model_643216.h          # Model data in C header format for 64-32-16 layer network(generated)
|-- |-- BitNetMCU_model_323216.h          # Model data in C header format for 32-32-16 layer network(generated)
|-- |-- exportquant.py             # Script to convert trained model to quantized format
|-- |-- test_inference.py          # Script to test C implementation of inference
|-- |-- training.py                # Training script for the neural network
|-- |-- trainingparameters.yaml    # Configuration file for training parameters


```




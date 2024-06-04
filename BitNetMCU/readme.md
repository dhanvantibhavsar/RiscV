# Real Time Implementation of BitNetMCU
## Overview
This is a simple implementation of a low-bit quntized neural network on Risc-V microcontroller.
The project is based on the Risc-V microcontroller and MNIST dataset.

### Risc-V
- Board- VSD Squadron Mini
- Processor used- CH32V003F4U6 chip with 32-bit RISC-V core based on RV32EC instruction set

#### Low-bit quntized neural network

Neural network quantization is a powerful technique for deploying deep learning models on resource-constrained devices.\
By reducing the memory footprint and computational requirements of models, quantization enables efficient inference and improved privacy.

- Why Quantization?

Quntization is a easy way to compress the model. It can easily applied on existing model without loss of accuracy. 

Types of quantization-
1. Weight Quantization\
The weights of the neural network are reduced to fewer bits precision, typically 8-bits or 16-bits. 
2. Activation Quantization\
The activations of the neural network are also represented using fewer bits, following a similar approach to weight quantization. 
3. Post Training Quantization\
In post training qunatization the weights and activations are quantized to lower precision bits without need of retraining the model. 
4. Quantization Aware Training\
The quantized model is trained to minimize the accuracy loss due to quantization. This involves adjusting the learning rate, batch size, and other hyperparameters to optimize the performance of the quantized model.

#### MNIST dataset
The MNIST dataset is a collection of images of handwritten digits that is commonly used for training machine learning models.\

Key Features-

- The dataset consists of 60,000 training images and 10,000 testing images.\
- Each image is a 28x28 grayscale image.\
- The images are normalized to fit into a 28x28 pixel bounding box and anti-aliased, introducing grayscale levels.
- MNIST is widely used for training and testing in the field of machine learning, especially for image classification tasks.

#### Dataset Structure
The MNIST dataset is split into two subsets:

- Training Set: This subset contains 60,000 images of handwritten digits used for training machine learning models.
- Testing Set: This subset consists of 10,000 images used for testing and benchmarking the trained models.

#### Sample Image of the MNIST dataset
![sample Image](images\MNIST_dataset.png)

The example showcases the variety and complexity of the handwritten digits in the MNIST dataset, highlighting the importance of a diverse dataset for training robust image classification models.

### Components Required for BitNetMCU
- VSD Squadron Mini
- USB Cable
- Camera module(optional)

### Components Required for real time BitNetMCU
- VSD Squadron Mini
- USB Cable
- Camera module (arduino camera OV7670)
- jumper wires
- battery
- 7 segment display
- Breadboard
- push button

### Flow of the project
#### BitNetMCU Implementation
- Configuration
- Model Training
- Exporting the quantized model
- Testing the C-model
- Deploying the model on the VSD Squadron Mini
- Testing demo accuracy on VSD Squadron Mini

#### BitNetMCU real time Implementation
- Connecting the camera module to the VSD Squadron Mini
- Capturing images using the camera module
- Preprocessing the images
- Inferring detected digits using the model on the VSD Squadron Mini
- Displaying the output on the 7 segment display

### Circuit Connection for BitNetMCU
No hardware connections are required for BitNetMCU only we have to connect VSD squadron with computer using USB cable.
### Circuit Connection for BitNetMCU real time
The following connections are required for BitNetMCU real time implementation:
- Connect VCC of camera module to VCC of VSD Squadron Mini
- Connect GND of camera module to GND of VSD Squadron Mini
- Connect SCL of camera module to SCL of VSD Squadron Mini
- Connect SDA of camera module to SDA of VSD Squadron Mini
- Connect VCC of 7 segment display to VCC of VSD Squadron Mini
- Connect GND of 7 segment display to GND of VSD Squadron Mini
- Connect push button to VSD Squadron Mini
- Connect battery to VSD Squadron Mini










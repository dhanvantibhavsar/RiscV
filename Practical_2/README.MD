# Practical 2
## Identify various RISCV instruction types (R,I,S,B,U,J) 
### Reference used 
- [Technical specifications of RISCV](https://riscv.org/technical/specifications/)
- [Volume 1, Unprivileged Specification version 20240411 ]( https://drive.google.com/file/d/1uviu1nH-tScFfgrovvFCrj7Omv8tFtkp/view?usp=drive_link)
- [Volume 2, Privileged Specification version 20240411](https://drive.google.com/file/d/17GeetSnT5wW3xNuAHI95-SI1gPGd5sJ_/view?usp=drive_link)
## RISC-V Instruction Set Explanation
RISC-V is an open standard instruction set architecture (ISA) based on reduced instruction set computing (RISC) principles.
Different types of instruction 
1. R-type
2. I-type
3. S-type
4. B-type
5. U-type
6. J-type
### R-type (Register-Register)
 The "R-type" instructions in RISC-V are a type of instruction format used for arithmetic and logical operations. Let's break down what an R-type instruction looks like, provide a diagram to illustrate it, and offer an example.

#### R-Type Instruction Format:

In RISC-V, R-type instructions typically involve operations between two source registers and store the result in a destination register. Here's the general format:

| funct7 |  rs2   |  rs1   | funct3 |   rd   |  opcode|
| :------: |  :-----: |  :---:   | :------: |   :---:  |  :------:|
| 25-31  |  20-24  |  15-19   | 12-14  |   7-11   | 0-6|
- `opcode`-Specifies the operation to be performed.
- `rd`-Destination register.
- `funct3`and `funct7`-Additional function bits that help distinguish between different operations.
- `rs1`-Source register 1.
- `rs2`-Source register 2.
#### Here are some examples of R-type instructions with their funct3 and funct7 values:


- ADD (Addition)

``` 
Instruction: ADD rd, rs1, rs2
Opcode: 0110011
funct3: 000
funct7: 0000000
Binary Encoding: 0000000 00010 00001 000 00110 0110011
```

- SUB (Subtraction)
```
Instruction: SUB rd, rs1, rs2
Opcode: 0110011
funct3: 000
funct7: 0100000
Binary Encoding: 0100000 00010 00001 000 00111 0110011
```
- AND (Bitwise AND)

```
Instruction: AND rd, rs1, rs2
Opcode: 0110011
funct3: 111
funct7: 0000000
Binary Encoding: 0000000 00011 00001 111 01000 0110011
```
- OR (Bitwise OR)
```
Instruction: OR rd, rs1, rs2
Opcode: 0110011
funct3: 110
funct7: 0000000
Binary Encoding: 0000000 00101 00010 110 01001 0110011
```
- XOR (Bitwise XOR)
```
Instruction: XOR rd, rs1, rs2
Opcode: 0110011
funct3: 100
funct7: 0000000
Binary Encoding: 0000000 00100 00001 100 01010 0110011
```
- SLT (Set Less Than)
```
Instruction: SLT rd, rs1, rs2
Opcode: 0110011
funct3: 010
funct7: 0000000
Binary Encoding: 0000000 00100 00010 010 01011 0110011
```
- SRL (Shift Right Logical)
```
Instruction: SRL rd, rs1, rs2
Opcode: 0110011
funct3: 101
funct7: 0000000
Binary Encoding: 0000000 00010 01110 101 10000 0110011
```
- SLL (Shift Left Logical)
```
Instruction: SLL rd, rs1, rs2
Opcode: 0110011
funct3: 001
funct7: 0000000
Binary Encoding: 0000000 00010 00001 001 01111 0110011
```

#### I-type Instruction Format:

- The RISC-V I-type (Immediate-type) instruction format is used for instructions that involve immediate values (constants) as operands, where the immediate value is typically a small constant that is encoded within the instruction itself.


| imm[11:0] |  rs2   |  rs1   | funct3 |   rd   |  opcode|
| :------: |  :-----: |  :---:   | :------: |   :---:  |  :------:|
| 25-31  |  20-24  |  15-19   | 12-14  |   7-11   | 0-6|

- `opcode`: Specifies the operation to be performed.
- `rd, rs1`: Specify the destination register and the  source register, respectively.
- `funct3`: Specifies the particular variant of the operation.
- `imm`: Immediate value, which is a small constant encoded within the instruction.


#### Here are some examples of I-type instructions with their funct3 values:

- ADDI (Add Immediate)
```
Instruction: ADDI rd, rs1, imm
Opcode: 0010011
funct3: 000
Description: Adds the immediate value imm to the value in register rs1 and stores the result in register rd.
```
- SLTI (Set Less Than Immediate)
```
Instruction: SLTI rd, rs1, imm
Opcode: 0010011
funct3: 010
Description: Sets rd to 1 if the value in rs1 is less than the immediate value imm, otherwise sets rd to 0.
```
- ANDI (Bitwise AND Immediate)
```
Instruction: ANDI rd, rs1, imm
Opcode: 0010011
funct3: 111
Description: Performs a bitwise AND between the value in rs1 and the immediate value imm, storing the result in rd.
```
- ORI (Bitwise OR Immediate)
```
Instruction: ORI rd, rs1, imm
Opcode: 0010011
funct3: 110
Description: Performs a bitwise OR between the value in rs1 and the immediate value imm, storing the result in rd.
```
- XORI (Bitwise XOR Immediate)
```
Instruction: XORI rd, rs1, imm
Opcode: 0010011
funct3: 100
Description: Performs a bitwise XOR between the value in rs1 and the immediate value imm, storing the result in rd.
```
- LW (Load Word)
```
Instruction: LW rd, imm(rs1)
Opcode: 0000011
funct3: 010
Description: Loads a 32-bit word from memory at the address computed by adding the immediate value imm to the value in rs1, and stores the result in rd.
```


- The 32-bit encoding for this instruction would be:

|imm[11:0] | rs1 | funct3 | rd | opcode|
|---|---|---|---|---|
0000000001010 | 00010 | 000 | 00001 | 0010011


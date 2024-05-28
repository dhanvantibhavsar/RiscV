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


#### S-type Instruction Format:


In RISC-V, S-type instructions are used for storing data from a register to memory. They require a base address (in a register) and an offset (an immediate value) to determine the memory address where the data will be stored.

| imm[11:5] |  rs2   |  rs1   | funct3 |   imm[4:0]  |  opcode|
| :------: |  :-----: |  :---:   | :------: |   :---:  |  :------:|
| 25-31  |  20-24  |  15-19   | 12-14  |   7-11   | 0-6|

- `opcode`-Specifies the operation to be performed.
- `imm`- It contains the immediate value used as an offset for memory access.
- `funct3`-Additional function bits that help distinguish between different operations.
- `rs1`-Source register 1.
- `rs2`-Source register 2.

#### Example

```
SW x3, 20(x1)
```

This instruction stores the content of register x3 into memory at the address obtained by adding the contents of register x1 and the immediate offset 20.

- `SW`: This is the mnemonic for the Store Word operation.
- `x3`: This is the source register containing the data to be stored.
- `20`: This is the immediate offset, which specifies the displacement from the base address (x1 in this case).
- `x1`: This is the base register containing the base address.
So, this instruction instructs the processor to store the content of register `x3` into memory at the address x1 + 20.

### B-type instruction

B-type instructions perform conditional branching based on a comparison result. They use branch offsets (immediate values) to determine the target address.

| imm[12] imm[10:5] |  rs2   |  rs1   | funct3 |   imm[4:1] imm[11] |  opcode|
| :---------------: |  :-----:|  :---:   | :------: |   :---:  |  :------:|
| 25-31  |  20-24  |  15-19   | 12-14  |   7-11   | 0-6|

- `imm[12] imm[10:5]`: This field represents bits 25 to 31 and 7 to 11 of the instruction. Together, they encode a 13-bit signed immediate value. Bit 12 is the most significant bit (MSB), and bits 10 to 5 and 4 to 1 form the remaining bits of the immediate value.

- `rs2`: This field spans bits 20 to 24 of the instruction. It specifies the second source register whose content will be used for comparison.

- `rs1`: This field spans bits 15 to 19 of the instruction. It specifies the first source register whose content will be used for comparison.

- `funct3`: This field spans bits 12 to 14 of the instruction. It specifies the function code for the specific branch condition (e.g., BEQ for Branch if Equal).

- `imm[4:1] imm[11]`: This field represents bits 6 to 2 and 11 of the instruction. They are additional bits for the immediate value.

- `opcode`: This field spans bits 0 to 6 of the instruction. It specifies the opcode for the B-type instruction.

#### Example-
```
BNE x1, x2, loop
```
This instruction checks if the contents of register `x1`and `x2` are not equal. If they are not equal, it branches to the label loop. Otherwise, execution continues with the next instruction.

### U-type instruction

The U-type (Upper Immediate) instruction in RISC-V is used to load an immediate value into a register. This immediate value is encoded in the instruction itself, allowing for a larger range of immediate values than immediate-type instructions.

| imm[31:12] |   rd |  opcode|
| :----------|  :---:|  :---:|
| 12-31 |   7-11   | 0-6|

Let's break down each field:

- `imm[31:12]`: This field spans bits 12 to 31 of the instruction. It represents a 20-bit immediate value, which will be loaded into the upper bits of the destination register.
  
- `rd`: This field spans bits 7 to 11 of the instruction. It specifies the destination register where the immediate value will be loaded.
  
- `opcode`: This field spans bits 0 to 6 of the instruction. It specifies the opcode for the U-type instruction.

In summary, the U-type instruction allows for loading a 20-bit immediate value into the upper 20 bits of a register.

#### Example-
```
LUI x1, 1000
```
This instruction loads the immediate value 1000 into register x1. The immediate value is left-shifted by 12 bits and sign-extended to fill the 32-bit register x1. After execution, register x1 will contain the value 1000 shifted left by 12 bits (i.e., 1000 << 12).


### J-type instruction


The J-type (Jump) instruction in RISC-V is used for unconditional jumps to a target address. These instructions are typically used for implementing function calls, subroutine jumps, or unconditional branches.

| imm[20] |  imm[10:1]  |  imm[11]   | imm[19:12] |   rd |  opcode|
| :---------------: |  :-----:|  :---:   | :------: |   :---:  |  :------:|
| 25-31  |  20-24  |  15-19   | 12-14  |   7-11   | 0-6|

Let's break down each field:

- `imm[20]`: This field represents bit 31 of the instruction. It's the sign bit for the immediate value.
  
- `imm[10:1]`: This field spans bits 21 to 30 of the instruction. It represents a 10-bit immediate value, which encodes the target address.

- `imm[11]`: This field spans bits 20 to 20 of the instruction. It's an additional bit for the immediate value.

- `imm[19:12]`: This field spans bits 12 to 19 of the instruction. It's an additional eight bits for the immediate value.

- `rd`: This field spans bits 7 to 11 of the instruction. It specifies the destination register where the return address will be stored.

- `opcode`: This field spans bits 0 to 6 of the instruction. It specifies the opcode for the J-type instruction.

The J-type instruction allows for unconditional jumps to a target address, with the target address being formed by concatenating the immediate bits from various parts of the instruction.

#### Example-
```
JAL x1, target
```
This instruction jumps to the target address unconditionally and stores the return address (the address of the next instruction) into register x1. After executing this instruction, the program continues execution from the target address. The link register x1 will hold the address of the next instruction after the jump.

 #### Let's solve some examples-
```
ADD r6, r2, r1
```
This instruction is an R-type.This will add the contents of registers r2 and r1, and stores the result in register r6.
```
SUB r7, r1, r2
```
This instruction is an R-type.This will substract the contents of registers r2 and r1, and stores the result in register r7.
```
OR r9, r2, r5
```
This instruction is an R-type.This instruction computes the bitwise OR of the contents of registers r5 and r2, and stores the result in register r9.
```
XOR r10,r1, r4
```
This instruction is an R-type.This instruction computes the bitwise XOR of the contents of registers r4 and r1 and will store the result in r10.
```
SLT r11, r2,r4
```
This instruction is an R-type.This instruction sets r11 to 1 if the value in r2 is less than the value in r4, otherwise it sets r11 to 0.
```
ADDI r12, r4, 5
```
This instruction is an I-type. This instruction adds 5 to the contents of register r4 and store result in r12.
```
SW r3, r1, 2
```
It's an S-type (Store Type) instruction. This instruction stores the contents of register r3 into memory at the address formed by adding the contents of register r1 and the immediate offset value 2.
```
SRL r16, r14, r2
```
This instruction is an R-type. This instruction shifts the contents of register r14 right by the number specified in register r2 and stores the result in register r16.
```
BNE r0, r1, 20
```
A Shift Right Logical (SRL) operation. the instruction would perform a logical right shift on the value in register r1 by 3 bits and store the result in register r0.


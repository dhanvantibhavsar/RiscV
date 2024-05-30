# Practical I
## Install RISCV toochain using VSD
### Steps
1. Download the VDI file from [link provided](https://forgefunder.com/~kunal/riscv_workshop.vdi)
- make sure your drive has minimun atleast 100Gb space.
2. Download and install Oracle VirtualBox on your computer
3. Launch VirtualBox and click on the "New" button to create a new virtual machine. 
- Select OS-Linux 
- version-Ubuntu 18.04 
- RAM-4GB
- CPU-2
- existing hard disk file- donloaded VDI file
4. Start your vitual machine.
## Testing the toolchain using VDI 
### Write a C code to do the sum of n numbers

- Use the basic commands of linux to check the curent working directory, to list the files
- Use Vi editor to write the code 
- Use gcc compiler to compile the c code 
- Run the program using ./a.out
![Here is the output of the program.](../images/practical1/Screenshot%20(2).png)
### Compile the code using RISC-V toolchain
- Use the command `riscv64-unknown-elf-gcc -o sumof1ton sumof1ton.c`
- ![](../images/practical1/Screenshot%202024-05-24%20121854.png)
- See the instructions flow by doing some  calculations.
- ![](../images/practical1/Screenshot%202024-05-24%20123248.png)
- This is the first task.






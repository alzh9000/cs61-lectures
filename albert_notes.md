## ASM 1 Lecture 7 9/23
* For register names, "e" indicates 32-bit, while "r" indicates 64-bit. 
    * Ex: "rax" is the return value register that supports up to 64 bits, while "eax" is the return value register that only supports up to 32 bits.
    * Ex: "rdi" is the 64-bit version of the first argument, while "edi" is the 32 bit version.

* There are different kinds of MOV operations, depending on how many bytes or bits are being moved. 
    * Ex: MOVL will perform a MOV of 32 bits, so it's usually used for moving integers because an integer's size is 32 bits.

## Section 10/9
1. ints and longs are both stored using 4 bytes in x86 assembly.
2. If you see something like `(%rdi,%rax,4)` in assembly, that's probably doing something like accessing an index in an array. 


# Notes from Bomb Pset
for phase 5, I realized by looking at the values and addresses
that basically there was a keyword
as the first string
and i could input another string
any my 2nd string was supposed to have the first and last letter be the same as the first letter of the 1st string, the 2nd first and 2nd last letters be the same as the 2nd letter of the 1st string, etc.
so I deduced 2nd string was supposed to just be the first string + reverse(first string)
i don't rlly get the assembly that well
but I realized that sometimes registers hold addresses, in which case we want to use x/s $register and x/d $register, and you know this when the registers table shows that the value at the register looks like an address (it's really long), while when a register holds a value, you want to use print /d $register, though this isn't necessary since print /d $register shows the same information as the register values table in GDB
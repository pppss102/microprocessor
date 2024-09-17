# KTU Microprocessor pseudocode compiler

## Use instructions

Provide input path and output directory as command-line arguments:
- `Compiler.exe Test.txt OutputDirectory`

## syntax

Define the type of the Processor at the start of the file, N for natural, F for forced

- you must write the line of each line of code at the start
- comment by putting ;--Comment anywhere in the line
- To do multiple things in a single line, separate the functions by ;
- Do not put ; at the end of the line
- `12; LL1(E); CL1(F); --Shift E Left, F Cyclicly`

code is case insensitive

### ==========Register operations===========

For registers B-F assign by just stating the register, for example
`B = A`

A can only be assigned through operations:
- `A = A + B`
- `A = not A`
- `A = not B`
- `A = A + 1`
- `A = A - 1`
- `A = B + 1`
- `A = B - 1`
- `A = A xor B`

to do register shifts type the name of the shift, brackets, and separate the registers by commas, example:
`CL1(A, B, C, d)`

awailabale shifts LL1, LR1, AL1, AR1, CL1, CR1

### ==========Flags==========

Use flags using LS(flag)
`LS(AH); --example`

awailable flags: AH, AL, BH, BL, CH, CL, DH, DL, EH, EL, FH, FL, CNT (True if CNT = 0), ALU, 0 (for False)

### ==========Sequencing==========

You can define the next line by adding NEXT: lineNr anywhere in your code, for example:

`12; LS(AL); B = C; NEXT: 10`

By default the next line will be current Line + 1

- In case of Natural processor if flag is true it will go to the next line by default, if flag is false it will go to the programmer defined next line
- In case of Forced processor if flag is false it will go to the default next line, otherwise it will go to the defined next line + 1

### ==========Resetting==========

you can reset using RST, the same rules apply as for shifting

`RST(A, B, C, D, E, F, CNT, ROM, FLAG)`
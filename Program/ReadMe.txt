Use instructions:

1. Keep all your code as .txt files in the code folder, make sure to save them

2. Launch the Compiler, it's basic and won't cover for your mistakes

3. So far the compiler only works for Forced type microprocessor

4. The code will get compiled to the rezults folder as a new file that's named accordingly to yours

example code and result has been provided

syntax

you must write the line of each line of code at the start
comment by putting ;--Comment anywhere in the line(Compiler removes spaces and makes everything capitalized because I'm lazy and fuck you)
To do multiple things in a single line separate the functions by ;
Do not put ; at the end of the line
12; LL1(E); CL1(F); --Shift E Left, F Cyclicly

code is case insensitive

==========Register operations===========

For registers B-F assign by just stating the register, for example
B = A

A can only be assigned trough operations:
A = A + B (You can't do A = A + A because fuck you)
A = not A
A = not B
A = A + 1
A = A - 1
A = B + 1
A = B - 1
A = A xor B

to do register shifts type the name of the shift, brackets, and separate the registers by commas, example:
CL1(A, B, C, d)

awailabale shifts LL1, LR1, AL1, AR1, CL1, CR1

==========Flags==========

Use flags using LS(flag)
LS(AH) example

awailable flags: AH, AL, BH, BL, CH, CL, DH, DL, EH, EL, FH, FL, CNT (True if CNT = 0), ALU, 0 (for False)

==========Sequencing==========

You can define the next line by adding NEXT: lineNr anywhere in your code, for example:

12; LS(AL); B = C; NEXT: 10

By default the next line will be current Line + 1

If flag is false it will go to the default next line, otherwise it will go to the next line + 1 on a forced processor

==========Resetting==========

you can reset using RST, the same rules apply as for shifting

RST(A, B, C, D, E, F, CNT, ROM, FLAG)
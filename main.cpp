#include <iostream>
#include <string>
#include "Tests.h"
#include "Processor.h"
#include "ForcedLineStatement.h"
#include "Utils.h"

int main()
{
    ProcessorLanguageInterpreter code;

    code.AddLine("0;  B = Din");
    code.AddLine("1;  c = din");
    code.AddLine("2;  D,E = Din");
    code.AddLine("3;  A = B + 1");
    code.AddLine("4;  B = A");
    code.AddLine("5;  A = not C");
    code.AddLine("6;  A = A + B");
    code.AddLine("7;  B = A");
    code.AddLine("8;  A = A xor B; NEXT: 12");
    code.AddLine("9;  LL1(D);LR1(E); NEXT: 11");
    code.AddLine("10; A = A + D; NEXT: 9");
    code.AddLine("11; LS(CNT);NEXT: 12");
    code.AddLine("12; CNT--; LS(EL); NEXT: 9");
    code.AddLine("13; C = A");
    code.AddLine("14; RST(A, D, E, CNT)");
    code.AddLine("15; LS(BH); NEXT: 19");
    code.AddLine("16; A = A + 1");
    code.AddLine("17; B = A");
    code.AddLine("18; RST(A)");
    code.AddLine("19; A = not C; NEXT: 21");
    code.AddLine("20; A = not B; F = B; NEXT: 16");
    code.AddLine("21; A = A + 1");
    code.AddLine("22; D = A");
    code.AddLine("23; RST(A)");
    code.AddLine("24; A = not A");
    code.AddLine("25; E = A");
    code.AddLine("26; LS(CNT); NEXT: 28");
    code.AddLine("27; LL1(C, D, E); NEXT: 26");
    code.AddLine("28; CNT--; NEXT: 27");
    code.AddLine("29; RST(A, CNT)");
    code.AddLine("30; A = B; NEXT: 38");
    code.AddLine("31; CNT--");
    code.AddLine("32; LS(AH)");
    code.AddLine("33; CL1(E); NEXT: 36");
    code.AddLine("34; LL1(E)");
    code.AddLine("35; A = A + C");
    code.AddLine("36; LL1(A)");
    code.AddLine("37; LS(CNT)");
    code.AddLine("38; A = A + D; NEXT: 31");
    code.AddLine("39; LS(AH)");
    code.AddLine("40; CL1(E); NEXT: 42");
    code.AddLine("41; LL1(E)");
    code.AddLine("42; RST(A); LS(FH)");
    code.AddLine("43; A = E; NEXT: 45");
    code.AddLine("44; A = not E");
    code.AddLine("45; E = A");
    code.AddLine("46; done");

    code.PrintToConsole();

    std::string ending;
    std::cin >> ending;

    return 0;
}

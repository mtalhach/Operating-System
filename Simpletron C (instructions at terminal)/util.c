#include <stdio.h>
#include "simple.h"

//variables
int memory[SIZE];
int accumulator;
int instructionCounter;
int operationCode;
int operand;;

//functions
void readProgram(int program[]) {
    printf("* Simpletron execution begins *\n");
    printf("* Please enter your program one instruction *\n");
    printf("* (or data word) at a time. I will type the *\n");
    printf("* location number and a question mark (?).  *\n");
    printf("* You then type the word for that location. *\n");
    printf("* Type -9999 to stop entering your program. *\n");

    int location = 0;
    while (location < SIZE) {
        printf("%02d ? ", location);
        scanf("%d", &program[location]);
        if (program[location] == -9999) {
            break;
        }
        location++;
    }
    printf("* Program loading completed *\n\n");
}

void runProgram(int program[]) {
    printf("* Program execution begins *\n");
    instructionCounter = 0;
    while (instructionCounter < SIZE) {
        operationCode = program[instructionCounter] / 100;
        operand = program[instructionCounter] % 100;

        switch (operationCode) {
            case READ:
                printf("Enter an integer: ");
                scanf("%d", &memory[operand]);
                break;
            case WRITE:
                printf("%d\n", memory[operand]);
                break;
            case LOAD:
                accumulator = memory[operand];
                break;
            case STORE:
                memory[operand] = accumulator;
                break;
            case ADD:
                accumulator += memory[operand];
                break;
            case SUB:
                accumulator -= memory[operand];
                break;
            case DIV:
                accumulator /= memory[operand];
                break;
            case MUL:
                accumulator *= memory[operand];
                break;
            case BRANCH:
                instructionCounter = operand - 1;
                break;
            case BRANCHN:
                if (accumulator < 0) {
                    instructionCounter = operand - 1;
                }
                break;
            case BRANCHZ:
                if (accumulator == 0) {
                    instructionCounter = operand - 1;
                }
                break;
            case HALT:
                printf("* Simpletron execution terminate*\n");
                return;
            default:
                printf("* Invalid operation code *\n");
                printf("* Simpletron execution abnormally terminated *\n");
                return;
        }
        instructionCounter++;
    }

    printf("* Simpletron execution terminated without HALT instruction *\n");
}

#include <stdio.h>
#define MEMORY_SIZE 100

int memory[MEMORY_SIZE];
int accumulator;
int instructionCounter;
int operationCode;
int operand;

void readProgram(int program[]);
void runProgram(int program[]);

int main() {
    int program[MEMORY_SIZE];
    readProgram(program);
    runProgram(program);
    return 0;
}

void readProgram(int program[]) {
    printf("* Simpletron execution begins *\n");
    printf("* Please enter your program one instruction *\n");
    printf("* (or data word) at a time. I will type the *\n");
    printf("* location number and a question mark (?).  *\n");
    printf("* You then type the word for that location. *\n");
    printf("* Type -9999 to stop entering your program. *\n");

    int location = 0;
    while (location < MEMORY_SIZE) {
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
    while (instructionCounter < MEMORY_SIZE) {
        operationCode = program[instructionCounter] / 100;
        operand = program[instructionCounter] % 100;

        switch (operationCode) {
            case 10:
                printf("Enter an integer: ");
                scanf("%d", &memory[operand]);
                break;
            case 11:
                printf("%d\n", memory[operand]);
                break;
            case 20:
                accumulator = memory[operand];
                break;
            case 21:
                memory[operand] = accumulator;
                break;
            case 30:
                accumulator += memory[operand];
                break;
            case 31:
                accumulator -= memory[operand];
                break;
            case 32:
                accumulator /= memory[operand];
                break;
            case 33:
                accumulator *= memory[operand];
                break;
            case 40:
                instructionCounter = operand - 1;
                break;
            case 41:
                if (accumulator < 0) {
                    instructionCounter = operand - 1;
                }
                break;
            case 42:
                if (accumulator == 0) {
                    instructionCounter = operand - 1;
                }
                break;
            case 43:
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

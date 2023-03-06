#include <stdio.h>
#include "simple.h"

//variables
int memory[MEMORY_SIZE];
int accumulator;
int instructionCounter;
int instructionRegister;
int operationCode;
int operand;

//functions
void init() {
    printf("*** Welcome to Simpletron! ***\n"
           "*** Please enter your program instructions file ***");
}
 
FILE *file()
{
	FILE *fp;
    	fp= fopen("test.txt", "r");
    	if(!fp)
    		{
			printf("\n*** FILE NOT FOUND ***\n"
     			"*** Execution Terminated ***\n");
    		}
	return fp;
}



void loadInstructions(FILE *fp)
{
    printf("\n*** Loading File........ *** \n\n");
    int counter = 0;
    while (fscanf(fp, "%d", &memory[counter++]))
    	{
    		if(counter == MEMORY_SIZE) {
    			break;
    		};
    	}
}

void memoryDump() {
    printf("REGISTERS:\n");
    printf("%-20s %+05d\n","accumulator",accumulator);
    printf("%-22s  %02d\n","instructionCounter",instructionCounter);
    printf("%-20s %+05d\n","instructionRegister",instructionRegister);
    printf("%-22s  %02d\n","operationCode",operationCode);
    printf("%-22s  %02d\n\n","operand",operand);

    printf("MEMORY:\n");
    printf("   ");
    for(int i=0; i< ((MEMORY_SIZE+10) % MEMORY_SIZE); i++)
    	{
    		printf("    %02d ",i);
    	}
    	
    for(int i=0; i<MEMORY_SIZE; i++) {
        if(i % 10 == 0)
        	{
        		printf("\n%02d ",i);
        	}

        printf(" %+05d ",memory[i]);
    }
    printf("\n\n");
}

void compute() {
    if(instructionCounter >= MEMORY_SIZE)
    {
    	return;
    }
    instructionRegister = memory[instructionCounter];
    
    if(instructionRegister == 0)
    {
    	return;
    }
    operationCode = instructionRegister / MEMORY_SIZE;
    operand = instructionRegister % MEMORY_SIZE;

    switch (operationCode)
    {
        case READ:
            printf("Enter an integer => \n ? ");
            int input;
            scanf("%d",&input);
            
            if(input > 9999 || input < -9999)
            {
            	return compute();
            }
            memory[operand] = input;
            break;
            
        case WRITE:
            printf("Memory Location %02d: %+d \n",operand,memory[operand]);
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
            instructionCounter = operand-1;
            break;
            
        case BRANCHN:
            if(accumulator < 0){
            	instructionCounter = operand-1;
            }
            break;
            
        case BRANCHZ:
            if(accumulator == 0){
            	instructionCounter = operand-1;
            }
            break;
            
        case HALT:
            printf("*** Simpletron execution terminated ***\n");
            return;
            
        default:
            printf("*** INVALID INSTRUCTION ***");
            return;
    }
    instructionCounter++;
    memoryDump();
    compute();
}

void runSimpletron() {
    init();
    FILE *fp = file();

    if(file == NULL){
    	return;
    }
    loadInstructions(fp);

    printf("*** Program loading completed ***\n"
           "*** Program execution begins ***\n");

    compute();
}

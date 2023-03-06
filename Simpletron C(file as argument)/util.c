#include <stdio.h>
#include "simple.h"

/*
variables
*/
int memory[SIZE];  //simpletron contains 100-word memory
int accumulator;  //accumulator—“special register” in which information is put before the Simpletron uses that information in calculations or examines it in various ways.
int instructionCounter;  //work as a counter 
int instructionRegister; //transfer the next instruction to be performed from memory to a variable
int operationCode;  //specifying the operation to perform
int operand;  //the memory location containing the word to which the operation applies.


/*
Functions
*/

void init() {
    printf("*** Welcome to Simpletron! ***\n"
           "*** Please enter your program instructions file ***\n");
}
 
// Load file into memory 
FILE * loadFile(const char filename[])
{
	FILE *fp;
    	fp = fopen(filename, "r");
    	if(!fp)
    	{
		printf("\n*** FILE NOT FOUND ****\n"
     			"*** Execution Terminated ***\n");
    	}
	return fp;
}


// Load instructions from file into memory
void loadInstructions(FILE *file)
{
    printf("\nLoading Integers........\n");
    int counter = 0;
    while (fscanf(file, "%d", &memory[counter++]))
    	if(counter == SIZE){
    		break;
    	} 
}

// Print the contents of the memory
void memoryDump() {
    printf("REGISTERS:\n");
    printf("%-20s %+05d\n","accumulator",accumulator);
    printf("%-22s  %02d\n","instructionCounter",instructionCounter);
    printf("%-20s %+05d\n","instructionRegister",instructionRegister);
    printf("%-22s  %02d\n","operand",operand);
    printf("%-22s  %02d\n\n","operation",operationCode);

    printf("MEMORY:\n");
    printf("   ");
    for(int i=0; i< ((SIZE+10) % SIZE); i++)
        printf("    %02d ",i);
    for(int i=0; i<SIZE; i++) {
        if(i % 10 == 0)
            printf("\n%02d ",i);

        printf(" %+05d ",memory[i]);
    }
    printf("\n\n*** Memory Dumped ***\n");

}


void compute() {
		
    if(instructionCounter >= SIZE){
    	return;
    }
    
    //Fetch instruction
    instructionRegister = memory[instructionCounter];
    
    //Check for HALT instruction
    if(instructionRegister == 0){
    	 return;
    }
    
    //Decode instructions
    operand = instructionRegister % SIZE;
    operationCode = instructionRegister / SIZE;

    //Execute instruction
    switch (operationCode)
    {
        case READ:
            //Read integer from input
            printf("Enter an integer.\n ? ");
            int input;
            scanf("%d",&input);
            
            //Check for input limit
            if(input > 9999 || input < -9999){
            	 return compute();
            }
                
            //Store integer in memory location
            memory[operand] = input;
            break;
            
        case WRITE:
        //Print value stored in memory location
            printf("Memory Location %02d: %+d \n",operand,memory[operand]);
            break;

        case LOAD:
        //Load value from memory to accumulator
            accumulator = memory[operand];
            break;
        
        case STORE:
        //Store accumulator value in memory location
            memory[operand] = accumulator;
            break;

        case ADD:
        //Add value from memory location to accumulator
            accumulator += memory[operand];
            break;
            
        case SUB:
        //Subtract value from memory location from accumulator
            accumulator -= memory[operand];
            break;
            
        case DIV:
        //Divide accumulator by value in memory location
            accumulator /= memory[operand];
            break;
            
        case MUL:
        //Multiply accumulator by value in memory location
            accumulator *= memory[operand];
            break;

        case BRANCH:
        //Branch to the given memory location
            instructionCounter = operand-1;
            break;
            
        case BRANCHN:
        //Branch to the given memory location if accumulator is negative
            if(accumulator < 0) instructionCounter = operand-1;
            break;
            
        case BRANCHZ:
        //Branch to the given memory location if accumulator is zero
            if(accumulator == 0) instructionCounter = operand-1;
            break;
            
        case HALT:
        //Print message and terminate execution
            printf("*** Simpletron execution terminated ***\n");
            return;
            
        default:
        //Print message for invalid instruction
            printf("*** INVALID INSTRUCTION ***");
            return;
    }
    
    //Increment instruction counter and dump memory
    instructionCounter++;
    memoryDump();
    
    //Recursive call for next instruction
    compute();
}


//The main function to run the Simpletron program.

void runSimpletron(const char filename[]) {

	// Call the init function to initialize Simpletron
    	init();

	// Load the program instructions from the file
    	FILE *file = loadFile(filename);

    	if(file == NULL){
    		return;
    	}
    	loadInstructions(file);
    	
    	// Inform the user that the program has loaded and execution has started
    	printf("*** Program loading completed ***\n"
           	"*** Program execution begins ***\n");

	// Begin the Simpletron execution loop
    	compute();
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 3

// Structure to hold thread arguments
typedef struct {
    int row;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
} ThreadArgs;

// Function to calculate the square of a matrix row
void* calculateRowSquare(void* arg) {
    ThreadArgs* args = (ThreadArgs*) arg;
    int row = args->row;

    for (int col = 0; col < MATRIX_SIZE; col++) {
        int sum = 0;
        for (int k = 0; k < MATRIX_SIZE; k++) {
            sum += args->matrix[row][k] * args->matrix[k][col];
        }
        args->matrix[row][col] = sum;
    }

    pthread_exit(NULL);
}

// Function to print the matrix
void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printSquareMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%4d ", matrix[i][j]*matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 10) {
        fprintf(stderr, "Usage: %s <a1> <a2> <a3> <a4> <a5> <a6> <a7> <a8> <a9>\n", argv[0]);
        exit(1);
    }

    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int argIndex = 1;

    // Parse command line arguments and store them in the matrix
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = atoi(argv[argIndex++]);
        }
    }

    printf("Input matrix A is:\n");
    printMatrix(matrix);

    pthread_t threads[MATRIX_SIZE];
    ThreadArgs args[MATRIX_SIZE];

    // Create threads and allocate computation of each row to a thread
    for (int i = 0; i < MATRIX_SIZE; i++) {
        args[i].row = i;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            args[i].matrix[i][j] = matrix[i][j];
        }
        pthread_create(&threads[i], NULL, calculateRowSquare, (void*)&args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MATRIX_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("AxA matrix is:\n");
    printSquareMatrix(matrix);

    return 0;
}


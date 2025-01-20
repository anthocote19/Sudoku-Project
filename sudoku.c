#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0)
                printf(". ");
            else
                printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return 0;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return 0;
        }
    }

    return 1;
}

int solveSudoku(int grid[SIZE][SIZE]) {
    int row = -1, col = -1;
    int empty = 0;

    for (int i = 0; i < SIZE && !empty; i++) {
        for (int j = 0; j < SIZE && !empty; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                empty = 1;
            }
        }
    }

    if (!empty)
        return 1;

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return 1;

            grid[row][col] = 0;
        }
    }

    return 0;
}

void generateSudoku(int grid[SIZE][SIZE], int emptyCells) {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        int num = rand() % SIZE + 1;

        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
        }
    }

    solveSudoku(grid);

    for (int i = 0; i < emptyCells; i++) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        grid[row][col] = 0;
    }
}

int isComplete(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

int main() {
    int grid[SIZE][SIZE];
    int userGrid[SIZE][SIZE];
    int level;

    printf("Welcome to Sudoku! Choose a difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &level);

    int emptyCells;
    switch (level) {
        case 1:
            emptyCells = 20;
            break;
        case 2:
            emptyCells = 40;
            break;
        case 3:
            emptyCells = 55;
            break;
        default:
            printf("Invalid choice. Defaulting to Medium level.\n");
            emptyCells = 40;
    }

    generateSudoku(grid, emptyCells);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            userGrid[i][j] = grid[i][j];
        }
    }

    printf("Fill the grid by entering row, column, and number.\n");

    while (!isComplete(userGrid)) {
        printGrid(userGrid);

        int row, col, num;
        printf("Enter row (1-9), column (1-9), and number (1-9): ");
        scanf("%d %d %d", &row, &col, &num);

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        row--;
        col--;

        if (grid[row][col] != 0) {
            printf("You cannot change a pre-filled number.\n");
            continue;
        }

        if (isSafe(userGrid, row, col, num)) {
            userGrid[row][col] = num;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    printf("Congratulations! You completed the Sudoku!\n");
    printGrid(userGrid);

    return 0;
}

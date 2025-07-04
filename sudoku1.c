#include <stdio.h>
#include <stdbool.h>

bool isValid(int board[9][9], int row, int col, int num) {
    // Check row
    for (int i = 0; i < 9; ++i) 
    {
        if (board[row][i] == num) 
        {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; ++i) 
    {
        if (board[i][col] == num) 
        {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (board[startRow + i][startCol + j] == num) 
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int board[9][9]) 
{
    for (int row = 0; row < 9; ++row) 
    {
        for (int col = 0; col < 9; ++col) 
        {
            if (board[row][col] == 0) 
            {
                for (int num = 1; num <= 9; ++num) 
                {
                    if (isValid(board, row, col, num)) 
                    {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true; // Solution found
                        } 
                        else {
                            board[row][col] = 0; // Backtrack
                        }
                    }
                }
                return false; // No valid number found, backtrack
            }
        }
    }
    return true; // All cells filled, solution found
}

void printBoard(int board[9][9]) 
{
    for (int i = 0; i < 9; ++i) 
    {
        for (int j = 0; j < 9; ++j) 
        {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0 && j < 8) 
            {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < 8) 
        {
            printf("---------------------\n");
        }
    }
}

int main() {
    int board[9][9];
    printf("ENTER THE SUDOKO PUZZLE WITH 0 AS THE EMPTY PLACES:\n");

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
        {
           printf("Element [%d][%d] = ", i,j);
            scanf("%d",&board[i][j] );
            
        }
        
    }
    if (solveSudoku(board)) {
        printf("Solution:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
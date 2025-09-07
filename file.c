#include <stdio.h>
#include <stdlib.h>
//#include <"header.h">

// Function prototypes
void initializeBoard(int size);
void displayBoard(int size);
int checkWin(int size);
int checkDraw(int size);
void makeMove(int size, char playerSymbol);
void writeBoardToFile(int size);

// Global variables
char **board;  // 2D array to represent the game board
char currentPlayer = 'X';  // Variable to keep track of the current player ('X' or 'O')
int i = 0;  // Loop variable
int j = 0;  // Loop variable

int main() {
    int size;

    // Get board size from user
    printf("Enter board size: ");
    scanf("%d", &size);

    // Check if the entered board size is valid
    if (size < 3 || size > 10) {
        printf("Invalid board size. Please enter a size between 3 and 10.\n");
        return 1;
    }

    // Dynamically allocate memory for the game board
    board = (char **)malloc(size * sizeof(char *));
    for (i = 0; i < size; i++) {
        board[i] = (char *)malloc(size * sizeof(char));
    }

    // Initialize the game board
    initializeBoard(size);

    // Open a file for writing board state
    FILE *file = fopen("board_state.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fclose(file);

    // Main game loop
    while (!checkWin(size) && !checkDraw(size)) {
        displayBoard(size);

        // Make a move and write the board state to the file
        makeMove(size, (currentPlayer == 'X' ? 'X' : 'O'));
        writeBoardToFile(size);

        // Switch to the other player for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Display the final board state
    displayBoard(size);

    // Display the result of the game
    if (checkWin(size)) {
        // Determine the winning player
        if (currentPlayer == 'O') {
            currentPlayer = 'X';
        } else {
            currentPlayer = 'O';
        }
        printf("Player %c wins!\n", currentPlayer);
    } else {
        printf("It's a draw!\n");
    }

    // Free dynamically allocated memory
    for (i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

// Function to initialize the game board with empty spaces
void initializeBoard(int size) {
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the current state of the game board
void displayBoard(int size) {
    printf("\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won the game
int checkWin(int size) {
    int win = 0;

    // Check rows and columns for a win
    for (i = 0; i < size; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')) {
            win = 1;
            break;
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') ||
        (board[0][size - 1] == board[1][size - 2] && board[1][size - 2] == board[2][size - 3] && board[0][size - 1] != '-')) {
        win = 1;
    }

    return win;
}

// Function to check if the game is a draw
int checkDraw(int size) {
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }

    return 1;
}

// Function to make a move on the game board
void makeMove(int size, char playerSymbol) {
    int row, col;

    // Get the player's move
    printf("Move(%c): ", currentPlayer);
    scanf("%d %d", &row, &col);
    
    // Validate the move
    while (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != '-') {
        printf("Invalid move. Please try again.\n");
        printf("Move(%c): ", currentPlayer);
        scanf("%d %d", &row, &col);
    }

    // Update the game board with the player's move
    board[row][col] = playerSymbol;
}

// Function to write the current state of the game board to a file
void writeBoardToFile(int size) {
    FILE *file = fopen("board_state.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write the board state to the file
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fprintf(file, "%c ", board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");

    fclose(file);
}


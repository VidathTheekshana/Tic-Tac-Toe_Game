// Initialize the board with empty spaces
void initializeBoard(int size) {
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = '-';
        }
    }
}

// Display the current state of the board
void displayBoard(int size) {
    printf("\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if a player has won
int checkWin(int size) {
    int win = 0;

    for (i = 0; i < size; i++) {
        // Check rows and columns
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

// Check if the game is a draw
int checkDraw(int size) {
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] == '-') {
                return 0; // There is an empty space, game is not a draw yet
            }
        }
    }

    return 1; // All spaces are filled, game is a draw
}

// Make a move on the board
void makeMove(int size, char playerSymbol) {
    int row, col;

    // Get player's move
    printf("Move(%c): ", currentPlayer);
    scanf("%d %d", &row, &col);

    // Validate the move
    while (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != '-') {
        printf("Invalid move. Please try again.\n");
        printf("Move(%c): ", currentPlayer);
        scanf("%d %d", &row, &col);
    }

    // Update the board with the player's move
    board[row][col] = playerSymbol;
}

// Write the current board state to a file
void writeBoardToFile(int size) {
    FILE *file = fopen("board_state.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write each cell of the board to the file
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fprintf(file, "%c ", board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n"); // Separate moves with an empty line

    fclose(file);
}

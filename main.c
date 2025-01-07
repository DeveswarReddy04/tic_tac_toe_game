#include <stdio.h>

// Function declarations
void displayBoard();
int checkWinner();
void makeMove(int player);

// Global variables
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; // Initial board
char currentMarker;
int currentPlayer;

int main() {
    int winner = 0, moves = 0;
    printf("Welcome to Tic-Tac-Toe!\n\n");

    // Main game loop
    while (winner == 0 && moves < 9) {
        displayBoard();
        makeMove(currentPlayer);
        winner = checkWinner();
        moves++;
        currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player
    }

    displayBoard();

    // Display the result
    if (winner == 1)
        printf("Player 1 (X) wins!\n");
    else if (winner == 2)
        printf("Player 2 (O) wins!\n");
    else
        printf("It's a draw!\n");

    return 0;
}

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to make a move
void makeMove(int player) {
    int choice;
    currentMarker = (player == 1) ? 'X' : 'O';

    printf("Player %d (%c), enter your move (1-9): ", player, currentMarker);
    scanf("%d", &choice);

    // Map choice to board indices
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Validate the move
    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move. Try again.\n");
        makeMove(player); // Retry the move
    } else {
        board[row][col] = currentMarker; // Place the marker
    }
}

// Function to check for a winner
int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return (board[i][0] == 'X') ? 1 : 2;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return (board[0][i] == 'X') ? 1 : 2;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return (board[0][0] == 'X') ? 1 : 2;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return (board[0][2] == 'X') ? 1 : 2;

    // No winner yet
    return 0;
}

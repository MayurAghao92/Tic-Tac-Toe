#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if the current player has won the game
bool checkWin(const vector<vector<char>> &board, char player)
{
    // Check rows
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Check columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

// Function to play the Tic Tac Toe game
void playTicTacToe()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true)
    {
        // Print the board
        cout << "Current board:" << endl;
        printBoard(board);

        // Get player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Validate move
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
        {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update board
        board[row - 1][col - 1] = currentPlayer;

        // Check for win or draw
        if (checkWin(board, currentPlayer))
        {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        else if (checkDraw(board))
        {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    bool playAgain = true;
    while (playAgain)
    {
        playTicTacToe();
        cout << "Do you want to play again? (yes/no): ";
        string response;
        cin >> response;
        if (response != "yes")
            playAgain = false;
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}

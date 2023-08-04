//Group members:
// 222008524 TUYISHIME David
// 222006273 BYUKUSENGE Immaculee
// 222010802 NYODUSENGA Florence

#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;

class Power4Game {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    Power4Game() : board(ROWS, std::vector<char>(COLS, ' ')), currentPlayer('X') {}

    void printBoard() {
        std::cout << "  1 2 3 4 5 6 7" << std::endl;
        for (int i = 0; i < ROWS; ++i) {
            std::cout << "|";
            for (int j = 0; j < COLS; ++j) {
                std::cout << board[i][j] << "|";
            }
            std::cout << std::endl;
        }
        std::cout << "---------------" << std::endl;
    }

    bool isValidMove(int col) {
        return col >= 0 && col < COLS && board[0][col] == ' ';
    }

    void makeMove(int col) {
        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == ' ') {
                board[i][col] = currentPlayer;
                break;
            }
        }
    }

    bool checkWin() {
        // Check horizontally
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i][j + 1] == currentPlayer &&
                    board[i][j + 2] == currentPlayer &&
                    board[i][j + 3] == currentPlayer) {
                    return true;
                }
            }
        }

        // Check vertically
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j] == currentPlayer &&
                    board[i + 2][j] == currentPlayer &&
                    board[i + 3][j] == currentPlayer) {
                    return true;
                }
            }
        }

        // TODO: Check diagonals

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        while (true) {
            printBoard();

            int col;
            do {
                std::cout << "Player " << currentPlayer << ", enter column (1-7): ";
                std::cin >> col;
                col--;  // Adjust for 0-based indexing
            } while (!isValidMove(col));

            makeMove(col);
            
            if (checkWin()) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            } else if (isBoardFull()) {
                printBoard();
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    Power4Game game;
    game.play();
    return 0;
}

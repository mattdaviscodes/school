/*
 * Name: tictactoe.c
 * Purpose: Implement simple Tic Tac Toe clone to practice functions,
 *          arrays, and pointers.
 * Author: Matt Davis
 * Created: 11/14/17
 * Last Updated: 11/18/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 3

// Prototypes
void clear_table(int board[ROWS][ROWS]);
void generate_player2_move(int board[ROWS][ROWS], int *row, int *col);
bool check_table_full(int board[ROWS][ROWS]);
int check_three_in_a_row(int board[ROWS][ROWS]);
void display_table(int board[ROWS][ROWS]);
bool check_legal_option(int board[ROWS][ROWS], int row, int col);
void update_table(int board[ROWS][ROWS], int row, int col, int value);

void print_intro(void);
char int_to_symbol(int key);
int rand_0_2(void);
void init_rand(void);



int main(void)
{
    int board[ROWS][ROWS];
    int x, y, turn_counter = 0, winner = 0;

    // Initial setup
    init_rand();
    clear_table(board);
    print_intro();

    while (1) {
        display_table(board);

        winner = check_three_in_a_row(board);
        if (winner) {
            printf("Congratulations, Player %d wins!\n", winner);
            break;
        } else if (check_table_full(board)) {
            printf("Game over, no player wins.\n");
            break;
        }

        if (turn_counter % 2 == 0) {    // Player's turn

            do {
                printf("Player 1 enter your selection [row, col]: ");
                scanf("%d, %d", &x, &y);
                printf("\n");
            } while( !check_legal_option(board, x-1, y-1) );

            update_table(board, x-1, y-1, 1);

        } else {    // Computer's turn
            generate_player2_move(board, &x, &y);
            printf("Player 2 has entered [row,col]: %d,%d\n", x, y);
            printf("\n");

            update_table(board, x-1, y-1, 2);
        }


        turn_counter++;
    }

    return 0;
}

/*
 *  Function: print_intro
 *  ---------------------
 *      Prints a welcome message to the console.
 */
void print_intro(void)
{
    printf("This program plays the game of tic-tac-toe\n");
}

/*
 *  Function: clear_table
 *  ---------------------
 *      Clears the game board for a new game.
 *
 *      board: a 2d char array to be cleared
 */
void clear_table(int board[ROWS][ROWS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            board[i][j] = 0;
        }
    }
}

/*
 *  Function: generate_player2_move
 *  ---------------------
 *      Choses random moves on a game board and returns once a valid move
 *      is found.
 *
 *      board: a 2d char array to be printed
 *      row: int pointer to be filled with the x coordinate of generated move
 *      row: int pointer to be filled with the y coordinate of generated move
 */
void generate_player2_move(int board[ROWS][ROWS], int *row, int *col)
{
    bool legal;

    do {
        *row = rand_0_2() + 1;
        *col = rand_0_2() + 1;
        legal = check_legal_option(board, *row - 1, *col - 1);
    } while( !legal );
}

/*
 *  Function: check_table_full
 *  ---------------------
 *      Checks if game board is full (if all ints in board are non-zero)
 *
 *      return: true if full, else false
 */
bool check_table_full(int board[ROWS][ROWS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (board[i][j] == 0) {
                // Found an empty square
                return false;
            }
        }
    }

    // No empty squares found
    return true;
}

/*
 *  Function: check_three_in_a_row
 *  ---------------------
 *      Checks if either player controls a complete row, thus winning the game.
 *      A "row" in this sense constitues three contiguous spaces which may run
 *      horizontally, vertically, or diagonally.
 *
 *      return: 1 if the player wins, 2 if the computer wins, else 0
 */
int check_three_in_a_row(int board[ROWS][ROWS])
{
    int last;

    // Check rows first
    for (int i = 0; i < ROWS; i++) {
        last = 0;

        for (int j = 0; j < ROWS; j++) {

            // If the current cell is unowned or is not equal to the last seen
            // index, this row doesn't contain a win. Otherwise, update last to
            // the current index and check the next.
            if (board[i][j] == 0) {
                last = 0;
                break;
            } else if (j > 0 && board[i][j] != last) {
                last = 0;
                break;
            }

            last = board[i][j];
        }

        // If we make it to here, last == the index of the player owning
        // an entire row, thus winning. Return the index.
        if (last != 0) {
            return last;
        }
    }

    // Then check columns
    for (int i = 0; i < ROWS; i++) {
        last = 0;

        for (int j = 0; j < ROWS; j++) {

            if (board[j][i] == 0) {
                last = 0;
                break;
            } else if (j > 0 && board[j][i] != last) {
                last = 0;
                break;
            }
            last = board[j][i];
        }

        if (last != 0) {
            return last;
        }
    }

    // Finally, check diagonals
    last = 0;
    for (int i = 0; i < ROWS; i++) {

        if (board[i][i] == 0) {
            last = 0;
            break;
        } else if (i > 0 && board[i][i] != last) {
            last = 0;
            break;
        }
        last = board[i][i];
    }
    if (last != 0) {
        return last;
    }

    last = 0;
    for (int i = 0; i < ROWS; i++) {

        if (board[0 + i][(ROWS - 1) - i] == 0) {
            last = 0;
            break;
        } else if (i > 0 && board[0 + i][(ROWS - 1) - i] != last) {
            last= 0;
            break;
        }
        last = board[0 + i][(ROWS - 1) - i];
    }

    return last;
}

/*
 *  Function: update_table
 *  ---------------------
 *      Sets board[row][col] equal to value
 *
 *      board: a 2d char array to be printed
 *      row: int x coordinate of board
 *      col: in y coordinate of board
 *      val: int value to place at coords -- 1 or 2 (player or computer)
 */
void update_table(int board[ROWS][ROWS], int row, int col, int value)
{
    board[row][col] = value;
}

/*
 *  Function: display_table
 *  ---------------------
 *      Prints the current table state to the screen
 *
 *      board: a 2d char array to be printed
 */
void display_table(int board[ROWS][ROWS])
{
    printf("The current state of the game is:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%c ", int_to_symbol(board[i][j]));
        }
        printf("\n");
    }
    printf("\n");
}

/*
 *  Function: check_legal_option
 *  ---------------------
 *      Checks whether a move identified by board[row][col] is:
 *          - within the bounds of the board
 *          - unoccupied
 *
 *      board: a 2d char array to be printed
 *      row: int x-axis index to board
 *      col: int y-axis index to board
 *
 *      return: true if valid, else false
 */
bool check_legal_option(int board[ROWS][ROWS], int row, int col)
{
    _Bool valid = true;

    // If move is outside game bounds, invalid
    if (row + 1 > ROWS || col + 1 > ROWS) {
        valid = false;
    }

    // Check spot unoccupied
    if (board[row][col] != 0) {
        valid = false;
    }

    return valid;
}

/*
 *  Function: int_to_symbol
 *  ---------------------
 *      Converts an int 0-2 in the board array to the corresponding symbol.
 *          0 = _
 *          1 = X
 *          2 = O
 *
 *      key: an integer 0 through 2
 *
 *      return: char _, X, or O
 */
char int_to_symbol(int key)
{
    char symbol;

    switch (key) {
        case 0:
            symbol = '_';
            break;
        case 1:
            symbol = 'O';
            break;
        case 2:
            symbol = 'X';
            break;
    }

    return symbol;
}

/*
 *  Function: rand_0_2
 *  ---------------------
 *      Get a random number between 0 and 2.
 */
int rand_0_2(void)
{
    int num_generated;

    num_generated = rand() % 3;

    return num_generated;
}

/*
 *  Function: init_rand
 *  ---------------------
 *      Initialize a random number generator to be used throughout the program.
 */
void init_rand(void)
{
    time_t t;

    // Init random number generator
    srand((unsigned) time(&t));
}

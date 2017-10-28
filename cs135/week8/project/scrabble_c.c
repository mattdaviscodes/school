/*
 * Name: scrabble_c.c
 * Purpose: Implement simple Scrabble clone to practice functions, extra credit
 * Author: Matt Davis
 * Created: 10/27/17
 * Last Updated: 10/27/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define LETTERS_IN_ALPHABET 26
#define LETTERS_PER_DRAW 7
#define MAX_SIZE_WORD 7

// Prototypes
void generate_letter_set (int letter_set[], int size_letter_set, int num_letters);
int read_word (char word[], int max_size_word);
_Bool check_word (char word[], int size_word, int letter_set[], int size_letter_set);
int compute_word_value (char word[], int size_word);
void print_intro(void);
void print_outro(void);
void print_letters(int letter_set[], int size_letter_set);
void print_letters_error(int letter_set[], int size_letter_set);
void print_score(int score);
void populate_available_letters_array(int available_letters[], int size_available_letters);
void populate_letter_scores_array(int letter_scores[], int size_available_letters);
int prompt_continue(void);


int main(void)
{
    int size_word, score;
    char word[MAX_SIZE_WORD];

    // Play game
    print_intro();

    do {
        // Create and populate 'bag' of scrabble tiles
        int letter_set[LETTERS_IN_ALPHABET] = {0};
        generate_letter_set(letter_set, LETTERS_IN_ALPHABET, LETTERS_PER_DRAW);

        print_letters(letter_set, LETTERS_IN_ALPHABET);

        while (1) {
            size_word = read_word(word, MAX_SIZE_WORD);
            if (check_word(word, size_word, letter_set, LETTERS_IN_ALPHABET)) {
                score = compute_word_value(word, size_word);
                break;
            } else {
                print_letters_error(letter_set, LETTERS_IN_ALPHABET);
            }
        }

        print_score(score);
    } while(prompt_continue());

    print_outro();

    return 0;
}

/*
 * Generate a random set of letters.
 *
 * Simulates drawing letter tiles from a Scrabble bag. Some letters are more
 * common than others, but all have finite counts.
 */
void generate_letter_set (int letter_set[], int size_letter_set, int num_letters)
{
    int num_generated;
    time_t t;

    // Array to track how many of each tile are available
    int available_letters[LETTERS_IN_ALPHABET] = {0};
    populate_available_letters_array(available_letters, LETTERS_IN_ALPHABET);

    // Init random number generator
    srand((unsigned) time(&t));

    int i = 0;
    while (i < num_letters) {
        num_generated = rand() % 26;
        if (letter_set[num_generated] < available_letters[num_generated]) {
            letter_set[num_generated]++;
            i++;
        }
    }
}

/*
 * Prompt user for word and store.
 */
int read_word (char word[], int max_size_word)
{
    char c;
    int i = 0;

    printf("Enter your word: ");
    while (c = getchar()) {
        // Kill loop if enter or max size hit
        if (c == '\n' || i > max_size_word) {
            break;
        }
        word[i] = toupper(c);
        i++;
    }
    return i;
}

/*
 * Verify that word submitted by user is valid.
 *
 * Fails if word is blank (size == 0), or if the user played a letter they
 * did not draw.
 */
_Bool check_word (char word[], int size_word, int letter_set[], int size_letter_set)
{
    int letter_index;
    int copy_letter_set[LETTERS_IN_ALPHABET] = {0};

    // Prevent empty submissions
    if (size_word == 0) {
        return 0;
    }

    // Make copy of letter set to safely destroy in next loop
    for (int i = 0; i < size_letter_set; i++) {
        copy_letter_set[i] = letter_set[i];
    }

    // For each letter in word, reduce that letter's count in copy_letter_set
    // and then check if the reduced count is greater than 0. If so, that
    // letter is permitted. Otherwise, fail.
    for (int i = 0; i < size_word; i++) {
        letter_index = word[i] - 'A';
        if (--copy_letter_set[letter_index] < 0) {
            return 0;
        }
    }
    return 1;
}

/*
 * Compute the total point value of word submitted by user.
 */
int compute_word_value (char word[], int size_word)
{
    int letter_index, score = 0;
    int letter_scores[LETTERS_IN_ALPHABET] = {0};
    populate_letter_scores_array(letter_scores, LETTERS_IN_ALPHABET);

    for (int i = 0; i < size_word; i++) {
        letter_index = word[i] - 'A';
        score += letter_scores[letter_index];
    }
    return score;

}

/*
 * Helper - Print game welcome message.
 */
void print_intro(void)
{
    printf("This program plays the game of scrabble.\n");
}

/*
 * Helper - Print game exit message.
 */
void print_outro(void)
{
    printf("Thank you for playing.\n");
}

/*
 * Helper - Print user's drawn letters.
 */
void print_letters(int letter_set[], int size_letter_set)
{
    printf("Your letters are:");
    for (int i = 0; i < size_letter_set; i++) {
        for (int j = 0; j < letter_set[i]; j++) {
            printf(" %c", i + 'A');
        }
    }
    printf("\n");
}

/*
 * Helper - Print error message for invalid submission.
 */
void print_letters_error(int letter_set[], int size_letter_set)
{
    printf("The word is not valid. Use your letters:");
    for (int i = 0; i < size_letter_set; i++) {
        for (int j = 0; j < letter_set[i]; j++) {
            printf(" %c", i + 'A');
        }
    }
    printf("\n");
}

/*
 * Helper - Print word's total point value.
 */
void print_score(int score)
{
    printf("The value of your word is: %d\n", score);
}

/*
 * Sets available_letters to letter counts for a fresh game of Scrabble.
 */
void populate_available_letters_array(int available_letters[], int size_available_letters)
{
    char letter;

    for (int i = 0; i < size_available_letters; i++) {
        letter = i + 'A';
        switch (letter) {
            case 'J':
            case 'K':
            case 'Q':
            case 'X':
            case 'Z':
                available_letters[i] = 1;
                break;
            case 'B':
            case 'C':
            case 'F':
            case 'H':
            case 'M':
            case 'P':
            case 'V':
            case 'W':
            case 'Y':
                available_letters[i] = 2;
                break;
            case 'G':
                available_letters[i] = 3;
                break;
            case 'D':
            case 'L':
            case 'S':
            case 'U':
                available_letters[i] = 4;
                break;
            case 'N':
            case 'R':
            case 'T':
                available_letters[i] = 6;
                break;
            case 'O':
                available_letters[i] = 8;
                break;
            case 'A':
            case 'I':
                available_letters[i] = 9;
                break;
            case 'E':
                available_letters[i] = 12;
                break;
        }
    }
}

/*
 * Sets letter_scores to Scrabble score values for each letter.
 */
void populate_letter_scores_array(int letter_scores[], int size_available_letters)
{
    char letter;

    for (int i = 0; i < size_available_letters; i++) {
        letter = i + 'A';
        switch (letter) {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                letter_scores[i] = 1;
                break;
            case 'D':
            case 'G':
                letter_scores[i] = 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                letter_scores[i] = 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                letter_scores[i] = 4;
                break;
            case 'K':
                letter_scores[i] = 5;
                break;
            case 'J':
            case 'X':
                letter_scores[i] = 8;
                break;
            case 'Q':
            case 'Z':
                letter_scores[i] = 10;
                break;
        }
    }
}

/*
 * Ask if user would like to continue playing and return selection.
 */
int prompt_continue(void)
{
    char choice;

    while (1) {
        printf("Do you want to play again (Y/N): ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        while (getchar() != '\n');   // Hack to capture newline after Y or N

        if (choice == 'Y') {
            return 1;
        } else if (choice == 'N') {
            return 0;
        }
    }
}

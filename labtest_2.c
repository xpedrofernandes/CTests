/*
Program Description: This program is written in C, and creates a word guessing game, allowing the user to guess characters to try to reach the correct word "coding". The user can try up to 7 incorrect guesses. Correct guesses do not decrease the attempts counter. The program provides feedback, prompting the user if each guess is correct - in which case displays the position of the character - or not. It uses a while loop to allow the user to enter the guesses, and a function to check for correct characters. 

Author: Pedro Fernandes.

Date: 09th april 2024.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 7 
#define MAX_ATTEMPTS 7

// function signature
int checkChar(char[], char);

int main()
{
    char targetWord[SIZE] = "coding";
    char encryptedWord[SIZE] = "______";
    int attempts = MAX_ATTEMPTS;
    int i = 0;

    // place NULL character at the end of encryptedWord
    encryptedWord[SIZE-1] = '\0';

    // instructions
    printf("\nGUESS THE WORD!\n\nYou can guess up to 7 wrong characters.\nYou must guess one character at a time.\nWhen you guess a character correctly, it will display its position!\n\n");

    while (attempts > 0) // number of attempts starts at 7. We are going to decrement it only if a wrong guess is entered, until it gets to 0
    {
        char guess;

        // instructions
        printf("Enter your guess: ");
        scanf("%c", & guess); // get guess from user

        // clear buffer
        while(getchar() != '\n');

        // if guess is correct (analyzed by checkChar function)
        if (checkChar(targetWord, guess) == 0)
        {
            // iterate through the array until it finds the correct position of the character guessed, and substitute the underscore by it
            for (i = 0; i < SIZE; i++)
            {
                if (targetWord[i] == guess)
                {
                    encryptedWord[i] = guess;
                } // end if
            } // end for

            // display redacted version of the word "coding" with underscores and show the place where the character is situated
            printf("Correct guess. It is located here: %s\n\n", encryptedWord);

            // if user guesses all characters correctly, wins the game
            if (strcmp(encryptedWord, targetWord) == 0)
            {
                printf("VICTORY! You won! The word was: %s\n", targetWord);

                break; // break out of the loop
            } // end inner if
        } // end outer if

        // if guess is incorrect
        else 
        {
            attempts--; // one less attempt

            // display that guess is incorrect and the attempts remaining
            printf("%c is not in the word. Attempts remaining: %d\n\n", guess, attempts);

            // if user runs out of attempts, game over
            if (attempts == 0)
            {
                printf("GAME OVER! You ran out of attempts. The correct word is: %s\n", targetWord);

                break; // break out of the loop
            } // end if
        } // end else

    } // end while

    return 0; // end program
} // end main



int checkChar(char targetWord[], char guess)
{
    int i;

    // iterate through word to check if guess is in it
    for (i = 0; i <  SIZE; i++)
    {
        // if guess is correct
        if (targetWord[i] == guess)
        {
            return 0; // return 0 (true) and go back to main
        } // end if
    } // end for

    return 1; // return 1 (false) and go back to main
} // end checkChar()




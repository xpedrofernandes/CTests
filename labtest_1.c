/*
Program Description: This program creates a guessing game, in which the user has 5 attempts to correctly guess a number between 1 and 25, generated randomly. The user will know wether his guess is too low, too high or correct. The program will end after displays the guessing history of the user.

Author: Pedro Fernandes.

Date: 28th November 2023.

*/


#include <stdio.h>
#include <stdlib.h> // this header file is required for the rand() function
#include <time.h> // used in srand() for seeding purposes

#define MAX_ATTEMPTS 5

int main()
{
    int num = 0;
    int guessHistory[MAX_ATTEMPTS];
    int attempts = 0;
    int used_attempts;

    
    printf("Generating a random number between 1 – 25 \n\n");
    
    // seed the random number generator with a range 0 – large number
    srand(time(NULL));
    
    // num is assigned a random number between 1 – 10 
    num = (rand() % 25) + 1;
    
    // giving instructions to user
    printf("You have %d attempts to guess a number between 1 and 25:\n", MAX_ATTEMPTS);


    do // do while loop which will run until user reaches 5 attempts OR gets the number right
    {
        // asks user to enter a number for the attempt and reads the number
        printf("\n\nGuess %d. Enter a number:\n", attempts+1);
        scanf("%d", &guessHistory[attempts]);


        // if statements 
        if (guessHistory[attempts] < num) // if guess is less than target, prompt guess is too low
        {
            printf("Your guess is too low.\n");
            attempts++;
        } // end if

        else if(guessHistory[attempts] > num) // if guess is bigger than target, prompt guess is to high
        {
            printf("Your guess is too high.\n");
            attempts++;
        } // end else if

        else // if guess is correct, prompt victory message and break out of the loop to end the game
        {
            printf("\n\nYour guess is CORRECT! Congratulations!\n");
            attempts++;
            break;
        } // end else
        
    } // end do
    while (attempts < MAX_ATTEMPTS); // end do while


    // display a message if the user reaches 5 attempts AND does not get the target right
    if (attempts == MAX_ATTEMPTS && guessHistory[MAX_ATTEMPTS-1] != num)
    {
        printf("\n\nEnd of game. You couldn't get the number right.\n");
    } // end if


    // store the number of used attempts in a new variable, to be used when guess History is displayed
    used_attempts = attempts;


    // prompt instructions for user, that we are about to display the guess history
    printf("\n\nHere is your guess history:\n");

    // display the guess History. Note that the new variable (used_attempts) was created so we display only the guesses that were used, ie, if user only used 3 guesses, only display 3 guesses
    for (attempts = 0; attempts < used_attempts; attempts++)
    {
        printf("\nYour Guess number %d was: %d\n", attempts+1, guessHistory[attempts]);
    } // end for


    return 0;
    
} // end main
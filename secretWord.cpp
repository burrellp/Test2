/**********************************************************
 Author:                        Patrick Burrell
 Date Created:                  10/26/14
 Date Last Modified:            10/26/14
 File Name:                     secretWord.cpp
 
 Overview:
 This is a word guessing game designed for two players. 
 Player 1 enters a secret word while player 2 tries to guess
 it one letter at a time. After 10 incorrect guesses by player
 2 or a correctly guessed word, the game ends.
 
 Input:
 Player 1 will input a "secret word" consisting of only alpha
 characters. Player 2 will input one alpha character at a time
 for his or her guess.
 
 Output:
 After each guess, player 2 will be updated on his or her
 guesses remaining, progress on word, and missed guesses. 
 Player 2 will receive a congratulatory message if they correctly
 guess the word or a message that they lost if they run out of 
 guesses. The players will then be prompted to play again. 
 
 ************************************************************/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string testInput(string &word);
string testGuess(string &guess);

int main()
{
    char choice;
    string secretWord;
    string guess;
    string misses;
    int numGuesses = 10;
    
do
{
    
    
    // Introduce program
    cout << "Let's play the super secret word guessing game!" << endl
         << endl;
    
    // Prompt for secret word
    cout << "Player 1, enter your secret word: ";
    getline(cin, secretWord);
    
    // Call function to test that secret word is all letters
    testInput(secretWord);
    
    // Convert secret word to all uppercase for testing
    for (int i = 0; i < secretWord.length(); i++)
        toupper(secretWord.at(i));
    
    // Create string of the same length as the secret word
    // to use to diplay player 2's progress.
    string hiddenWord = secretWord;
    hiddenWord.assign(secretWord.length(), '*');
    
    // Clear screen
    cout << string(100, '\n');
    
    do
    {
        cout << "Player 2, enter your guess: ";
        cin >> guess;
        
        // Call function to test that guess is a single letter
        testGuess(guess);
        
        // Make guess uppercase for testing purposes
        toupper(guess.at(0));
        
        // String assign will print out an 'X' for every missed
        // guess
        string wrong;
        wrong.assign((10 - numGuesses), 'X');
        
        // String remaining will print out a - for every
        // guess remaining
        string remaining;
        remaining.assign(numGuesses, '-');
        
       
        // Do this if Player 2 guesses a letter that is in word
        if (int(secretWord.find(guess)) >= 0 ||
            secretWord.find(guess) <= secretWord.length())
            
        {
            
            for (int i = 0; i < secretWord.length(); i++)
            {
            
                if (secretWord.at(i) == guess.at(0))
                {
                    // Fill in correct guesses for display
                    hiddenWord.at(i) = secretWord.at(i);
                }
            }
            
            // Status display
            cout << "That letter is in the secret word!"
                 << endl << "Here is your progress so far:"
                 << endl << endl;
            
            
            cout << "Guesses:     " << wrong << remaining << " "
                 << numGuesses << " guesses remaining." << endl;
                
            cout << "Misses:      " << misses << endl;
                
            cout << "Secret word: " << hiddenWord << endl << endl;
            
            
            // Do this if Player 2 has guessed every letter
            if (hiddenWord.compare(secretWord) == 0)
            {
                cout << "Congratulations, you guessed the secret"
                << " word of " << secretWord << " with "
                << numGuesses << " guesses remaining!" << endl;
                
                break;
            }
        
        }
        
        // If player 2 guesses the same wrong letter twice
        else if (int(misses.find(guess)) >= 0 ||
                 misses.find(guess) <= misses.length())
       
        {
            cout << "You already guessed that letter."
                 << endl;
        }
        
        
        // If player 2 has correctly guessed all letters
        else if (hiddenWord.compare(secretWord) == 0)
        {
            cout << "Congratulations, you guessed the secret"
                 << " word of " << secretWord << " with "
                 << numGuesses << " guesses remaining!" << endl;
            
            // Exit loop if word has been guessed
            break;
            
        }
        
        // If player 2 guesses incorrectly
        else
            {
                numGuesses--;
                wrong.assign((10 - numGuesses), 'X');
                remaining.assign(numGuesses, '-');
                
                // Add incorrect guesses to display
                misses.append(guess);
                
                
                // Status display
                cout << "That letter is not in the secret word."
                     << endl << "Here is where you stand: "
                     << endl << endl;
                
                cout << "Guesses:     " << wrong << remaining << " "
                << numGuesses << " guesses remaining." << endl;
                
                cout << "Misses:      " << misses << endl;
                
                cout << "Secret word: " << hiddenWord << endl
                     << endl;

            }
    
            
    } while (numGuesses > 0);
    
    // Message for losers
    if (!(hiddenWord.compare(secretWord) == 0))
    cout << "YOU LOSE" << endl
         << "The secret word was " << secretWord
         << ". Better luck next time" << endl << endl;

    
    
    cout << "Would you like to play again (Y/N)? ";
    cin >> choice;
    
} while (toupper(choice) == 'Y');
    
    
    return 0;
    
}


/*****************************************************
 *                   testInput                       *
 * This function tests a user input to make sure it  *
 * contains only letters of the alphabet. It also    *
 * prompts the user for a new input when the original*
 * input fails the test.                             *
 ****************************************************/

string testInput(string &word)
{
    
    for (int i = 0; i < word.length(); i++)
    {
        // Test all characters for type alpha and take new
        // word if there are other character types
        while (i < word.length() && !(isalpha(word.at(i))))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Your word can only contain letters. "
                 << "Enter your secret word: ";
            cin >> word;
        }
               
    }
              
    return word;
            
}


/*****************************************************
 *                   testGuess                       *
 * This function tests a user input to make sure it  *
 * is a single alpha character. It alsoprompts the   *
 * user for a new input when the original input fails*
 * the test.                                         *
 ****************************************************/

string testGuess(string &guess)
{
    // Make sure guess is only a single character
    while (guess.length() > 1 || guess.length() <= 0
                           || !(isalpha(guess.at(0))))
        
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Your guess must be a single letter: ";
        cin >> guess;
    }
    
    return guess;
}


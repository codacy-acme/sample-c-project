#include <stdio.h>
#include <string.h>

#define MAX_TRIES 5  // clang-tidy might suggest using a const or constexpr variable
#define WORD_SIZE 20 // Consider using a std::string instead of fixed-size array

void printWord(const char* word, const int* guessed) {
    for (int i = 0; word[i] != '\0'; ++i) { // Potential pointer arithmetic issue
        if (guessed[i]) {
            printf("%c", word[i]); // Suggest using cout
        } else {
            printf("_");
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    char word[WORD_SIZE] = "programming"; // Suggest using std::string
    int wordLength = strlen(word);
    int guessed[WORD_SIZE] = {0}; // Suggest using std::vector<int>
    int tries = MAX_TRIES;
    int correctGuesses = 0;
    char guess;

    printf("Welcome to Hangman!\n");

    while (tries > 0 && correctGuesses < wordLength) {
        printWord(word, guessed);
        printf("You have %d tries left.\n", tries); // Magic number in text
        printf("Enter a letter: ");
        scanf(" %c", &guess);  // Suggest using cin and proper error checking

        int goodGuess = 0;
        for (int i = 0; i < wordLength; ++i) {
            if (!guessed[i] && word[i] == guess) {
                guessed[i] = 1; // Potential array bounds issue
                goodGuess = 1;
                correctGuesses++;
            }
        }

        if (!goodGuess) {
            tries--; // Magic number decrement
            printf("Sorry, no %c!\n", guess); // Suggest using cout
        }

        if (correctGuesses == wordLength) {
            printf("Congratulations! You've won!\n"); // Suggest using cout
            printWord(word, guessed);
            break;
        }
    }

    if (tries == 0) {
        printf("Game over! The word was '%s'.\n", word); // Suggest using cout
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WordsFromString.c"

int deleteCharAtString(char *, int);

int main() {
    char *text = (char *)calloc(1024, sizeof(char));
    char *input = (char *)calloc(100, sizeof(char));

    printf("Enter text (Double Enter to continue): ");
    while (scanf("%[^\n]%*c", input) == 1) {
        strcat(text, input);
        strcat(text, " ");
    }

    WordsArray *words = getWordsFromString(text, " ");
    //Editing every word
    for (int i = 0; i < words->count; ++i) {
        char *currentWord = words->wordsArr[i];
        int length = (int)strlen(currentWord);
        //First editing (Swapping the first ans the last character)
        char firstChar = currentWord[0];
        deleteCharAtString(currentWord, 0);
        currentWord[length - 1] = firstChar;
        //Second editing (Deleting all repeating characters)
        for (int j = 0; j < length; ++j) {
            char currentCharacter = currentWord[j];
            for (int k = 0; k < length; ++k) {
                if (currentCharacter == currentWord[k] && k != j)
                    deleteCharAtString(currentWord, k);
            }
        }
        printf("%s ", currentWord);
    }

    //>Here goes memory deallocation code
    return 0;
}

int deleteCharAtString(char *string, int index) {
    int length = (int)strlen(string);

    if (index > length - 1)
        return 1;

    memmove(string + index,
            string + (index + 1),
            sizeof(char) * length);
    return 0;
}

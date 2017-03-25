#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct WordsArray {
    int count;
    char **wordsArr;
} WordsArray;
WordsArray *getWordsFromString(char *, const char *);
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

    //>Here goes memory deallocation code< doyebatsa zdes
    return 0;
}

WordsArray *getWordsFromString(char *string, const char *separators) {
    char **words = (char **)malloc(sizeof(char *));
    int allocatedMemory = 1;
    int wordsCount = 0;

    const char *token = strtok(string, separators);
    for (; token; wordsCount++) {
        if (allocatedMemory < wordsCount + 1) {
            allocatedMemory *= 2;
            words = (char **)realloc(words, sizeof(char *) * allocatedMemory);
        }
        words[wordsCount] = (char *)malloc(sizeof(char) * strlen(token));
        strcpy(words[wordsCount], token);
        token = strtok(NULL, separators);
    }
    WordsArray *tempWords = (WordsArray *)malloc(sizeof(WordsArray));
    tempWords->count = wordsCount;
    tempWords->wordsArr = words;
    return tempWords;
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

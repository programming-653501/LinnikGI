#include <stdlib.h>
#include <string.h>

typedef struct WordsArray {
    int count;
    char **wordsArr;
} WordsArray;

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
        words[wordsCount] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(words[wordsCount], token);
        token = strtok(NULL, separators);
    }
    WordsArray *tempWords = (WordsArray *)malloc(sizeof(WordsArray));
    tempWords->count = wordsCount;
    tempWords->wordsArr = words;
    return tempWords;
}

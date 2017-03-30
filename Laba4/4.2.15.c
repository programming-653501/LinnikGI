#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "WordsFromString.c"

char *getStringFromFile(FILE *);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Wrong arguments!\n");
        exit(3);
    }

    FILE *dictionaryFile = fopen(argv[1], "r");
    FILE *textFile = fopen(argv[2], "r");

    if (!dictionaryFile) {
        printf("Error in reading the dictionary file\n");
        exit(1);
    } else if (!textFile) {
        printf("Error in reading the text file\n");
        exit(2);
    }

    char *textString = getStringFromFile(textFile);
    char *dictString = getStringFromFile(dictionaryFile);

    WordsArray *textWords = getWordsFromString(textString, " ,.\n\r");
    WordsArray *dictWords = getWordsFromString(dictString, " ,.\n\r");

    free(textString);
    free(dictString);
    textString = NULL;
    dictString = NULL;

    //Get every word in text to lower case
    for (int i = 0; i < textWords->count; ++i) {
        char *p = textWords->wordsArr[i];
        for ( ; *p; ++p) *p = (char)tolower(*p); //A very hitriy kod
    }

    for (int j = 0, currentWordCount = 0; j < dictWords->count; ++j, currentWordCount = 0) {
        for (int i = 0; i < textWords->count; ++i) {
            if (!strcmp(dictWords->wordsArr[j], textWords->wordsArr[i]))
                currentWordCount++;
        }
        if (currentWordCount) printf("%s: %d\n", dictWords->wordsArr[j], currentWordCount);
    }

    fclose(textFile);
    fclose(dictionaryFile);
    return 0;
}

char *getStringFromFile(FILE *file) {
    char tempChar;
    int allocatedMemory = 128;
    char *text = (char *)malloc(sizeof(char) * allocatedMemory);
    for (int i = 0; (tempChar = (char)fgetc(file)) != EOF; ++i) {
        if (i > allocatedMemory - 1) {
            allocatedMemory *= 2;
            text = realloc(text, sizeof(char) * allocatedMemory);
        }
        text[i] = tempChar;
    }
    return text;
}

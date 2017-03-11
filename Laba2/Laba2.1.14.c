#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define INPUT_FLUSH for (char c = (char)getchar(); c != '\n' && c != EOF; c = (char)getchar())
#define STARTING_YEAR 1900

typedef  struct tm tm;

void printDateWithFormat(const tm*, const char *);
int checkIfCreated(const tm*);
int strIsNumber(const char *);

int main() {
    int input = 0;
    char *inputStr = malloc(sizeof(char) * 3);
    tm *date = NULL;
    while (input <= 6) {
        printf("\n(1)Enter date\n(2)Show the date in DD MMMM YYYY format\n(3)Show date in dd.mm.yy format\n"
                       "(4)Show weekday and day in the year\n(5)Days from JC birthday\n(6)Info\n(99)Exit: ");

        //Checking input
        fgets(inputStr, 3, stdin);
        if (strIsNumber(inputStr))
            input = atoi(inputStr);
        else
            INPUT_FLUSH;

        switch (input) {
            case 1:
                if (!date) {
                    date = (tm *)calloc(1, sizeof(sizeof(tm)));
                }
                system("clear");
                printf("Enter the day(1 - 31), month (1 - 12) and year(> 1970): ");

                int tempDay = 0, tempMonth = 0, tempYear = 0;
                scanf("%d %d %d", &tempDay, &tempMonth, &tempYear);
                INPUT_FLUSH;
                system("clear");

                if (tempDay < 1 || tempDay > 31 || tempMonth < 1 || tempMonth > 12 || tempYear < 1970) {
                    printf("You picked the wrong date, fool!\n");
                    break;
                }

                date->tm_mday = tempDay;
                date->tm_mon = --tempMonth;
                date->tm_year = tempYear - STARTING_YEAR;

                //Lifehack
                time_t dateInTime = mktime(date);
                date = localtime(&dateInTime);
                break;
            case 2:
                if (!checkIfCreated(date)) { break; }
                printDateWithFormat(date, "%B %d %Y");
                break;
            case 3:
                if (!checkIfCreated(date)) { break; }
                printDateWithFormat(date, "%d.%m.%y");
                break;
            case 4:
                if (!checkIfCreated(date)) { break; }
                printDateWithFormat(date, "It's %A and it's the %j'th day in the year");
                break;
            case 5:
                if (!checkIfCreated(date)) { break; }

                int daysFromJCBD = date->tm_year * 365 + STARTING_YEAR * 365;
                system("clear");
                printf("Mr. Jesus Christ was born %d days ago.\n", daysFromJCBD);
                break;
            case 6:
                system("clear");
                printf("Copyright © 2017 Gleb Linnik. All rights reserved.\n");
                break;
            case 99:
                free(date);
                break;
        }
    }
    return 0;
}

void printDateWithFormat(const tm *date, const char *str) {
    char *string = (char *)malloc(sizeof(char) * 128);

    strftime(string, 128, str, date);

    system("clear");
    printf("%s", string);
    printf("\n");
    free(string);
}

int checkIfCreated(const tm *date) {
    if (!date) {
        system("clear");
        printf("Enter the date first!\n");
        return 0;
    }
    return 1;
}

int strIsNumber(const char *str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

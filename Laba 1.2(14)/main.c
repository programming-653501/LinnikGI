#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define ULL unsigned long long int

bool checkIfPrime(ULL);


int main() {
    ULL n = 0;

    printf("Enter n to which to count: (> 0 you will experience some problems, dude)");
    scanf("%llu", &n);

    printf("\n");

    for (ULL i = 1; ; ++i) {
        if (checkIfPrime((ULL)powl(2, i) - 1)) {
            ULL number = (ULL)powl(2, i - 1) * (pow(2, i) - 1);
            if (number >= n) break;
            printf("p:%llu %llu\n", i ,number);
        }
    }

    return 0;
}

bool checkIfPrime(ULL number) {
    if (number <= 1)
        return false;
    else if (number <= 3)
        return true;
    else if (number % 2 == 0 || number % 3 == 0)
        return false;
    ULL i = 5;
    while ((i * i) <= number) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

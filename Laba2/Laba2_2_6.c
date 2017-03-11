#include <stdio.h>
#include <math.h>

long double fact(int N);
long double row(int number, long double x, double E);

int main() {
    int x = 0;
    double E;
    printf("f(x) = sin(x)\n"
                   "Enter x and E (accuracy): ");
    scanf("%d %lf", &x, &E);

    double sinResult = sin(x);
    long double recRowResult = row(1, x, E);

    long double previous = 0;
    long double current = pow(-1, 0) * (pow(x, 2 * 0)/fact(2 * 0));
    long double iterResult = current;

    for (int counter = 2; fabsl(current > previous ? current - previous : previous - current) > E; counter++) {
        previous = current;
        current = pow(-1, counter - 1) * (pow(x, 2 * counter - 1)/fact(2 * counter - 1));
        iterResult += current;
    }

    printf("sin from math.h: %lf\n      "
                   "Recursive: %Lf\n      "
                   "Iterative: %Lf\n", sinResult, recRowResult, iterResult);

    return 0;
}

long double fact(int N) {
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

long double row(int number, long double x, double E) {
    static long double previous = 0;
    static long double current;
    current = pow(-1, number - 1) * (pow(x, 2 * number - 1)/fact(2 * number - 1));

    if (fabsl(current > previous ? current - previous : previous - current) < E) {
        return 0;
    } else {
        previous = current;
        return current + row(number + 1, x, E);
    }
}

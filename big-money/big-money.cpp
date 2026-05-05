#include <stdio.h>
#include <cstring>

int main() {    
    long double total_compute = 0;
    double transaction = 0;

    while (1) {
        if (scanf("%lf", &transaction) != 1) break;
        total_compute += transaction;
    }
    printf("%.2Lf\n", total_compute);
}
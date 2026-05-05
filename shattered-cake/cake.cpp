#include <iostream>
#include <cstdio>

int main() {
    int W, N, L;
    scanf("%i", &W);
    scanf("%i", &N);

    long long total_area = 0;
    int w, l;

    while (scanf("%i %i", &w, &l) == 2) {
        total_area += (long long)w * l;
    }

    L = total_area / W;

    printf("%lld\n", L);
    return 0;
}
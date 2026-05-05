#include <stdio.h>
#include <cstdlib>
#include <climits>

int main() {
    char line[1000];
    int min = INT_MAX, max = INT_MIN;
    int ret_val = 0;
    int value;

    char *ptr;
    char *end;

    while(true){
        ret_val = scanf("%[^\n]\n", line);
        if (ret_val != 1) break;

        ptr = line;

        while (*ptr != ' ' && *ptr != '\0') ptr++;
        
        while (*ptr != '\0') {
            value = strtol(ptr, &end, 10);
            if (ptr == end) break;
            if (value < min) {
                min = value;
            }
            if (value > max) {
                max = value;
            }
            ptr = end;
        }
    }
    printf("%d %d\n", min, max);
    return 0;
}
#include <iostream>
#include <cstring>

int main(){
    char buff[1000];
    int q, p;
    int total=0;
    while (1){
        scanf(" %[^\n]",buff);
        int rt = strcmp(buff, "TOTAL");
        if (rt==0) break;

        scanf("%d %d", &q, &p);

        total+=q*p;
    }

    int price;
    scanf("%d", &price);

    if (price<=total){
        printf("PAY\n");
    }else{
        printf("PROTEST\n");
    }

    return 0;
}
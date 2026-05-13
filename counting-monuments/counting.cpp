#include<stdio.h>
#include<set>
#include<string>
using namespace std;

int main(){
    set<string> monuments;
    char buf[250];

    while (scanf("%[^\n]\n", buf) == 1) {
        char *p = buf;
        while (*p != ' ') p++;
        if (monuments.find(p) == monuments.end()){
            monuments.insert(p);
        }
    }

    printf("%zu\n", monuments.size());
}
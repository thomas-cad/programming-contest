#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    char path[1000];

    scanf("%d", &N);
    scanf("%s", path);

    vector<string> tab;

    for (int i = 1; i <= N; i++) {  
        for (int j = 0; j + i <= N; j++) {
            tab.push_back(string(path + j, i));
        }
        for (int k = 0; k < tab.size(); k++){
            if (count(tab.begin(), tab.end(), tab[k]) > 1) {
                break;
            }
            if (k==tab.size()-1){
                printf("%d\n", i);
                return 0;
            }
        }
        tab.clear();
    }

    printf("%d\n", 1);
    return 0;
}
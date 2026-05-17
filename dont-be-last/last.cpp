#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    map<string, int> cows;
    cows.insert({"Bessie", 0});
    cows.insert({"Elsie", 0});
    cows.insert({"Daisy", 0});
    cows.insert({"Gertie", 0});
    cows.insert({"Annabelle", 0});
    cows.insert({"Maggie", 0});
    cows.insert({"Henrietta", 0});

    scanf("%d", &N);
    for (unsigned int i = 0; i < N; i++){
        char name[50];
        int milk;
        scanf("%s %d", name, &milk);
        cows[string(name)] += milk;
    }

    vector<pair<int, string>> v;
    for (auto& t : cows)
        v.push_back({t.second, t.first});

    sort(v.begin(), v.end());

    int M;
    M = v.begin()->first;

    string ret = "Tie";

    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->first > M) {
            auto next = it + 1;
            if (next != v.end() && next->first == it->first)
                ret = "Tie";
            else
                ret = it->second;
            break;
        }
    }

    printf("%s\n", ret.c_str());
}
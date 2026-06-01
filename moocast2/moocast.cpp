#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int,int>>> edges; // (poids, (u, v))
map<int, pair<int, int>> cows;

const int MAXN = 1000;

int repr[MAXN];

int find(int x) {
    if (repr[x] < 0) return x;
    return repr[x] = find(repr[x]); // compression de chemin
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;           // déjà dans le même ensemble
    if (repr[a] > repr[b]) swap(a, b);  // union par taille (a = plus grand)
    repr[a] += repr[b];
    repr[b] = a;
    return true;
}


int main(){
    int N;
    int x, y;
    int w;

    scanf("%d", &N);

    fill(repr, repr + N, -1);

    for (int i = 0; i<N; i++){
        scanf("%d %d", &x, &y);
        cows[i]={x, y};
    }

    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            w = (cows[i].first-cows[j].first)*(cows[i].first-cows[j].first)+(cows[i].second-cows[j].second)*(cows[i].second-cows[j].second);
            edges.push_back({w,{i,j}});
        }
    }

    sort(edges.begin(), edges.end());

    long long weight_mst = 0;
    int max_w = 0;

    for (auto [w, p] : edges){
        if (unite(p.first, p.second)){
            weight_mst += w;
            if (w>max_w) max_w=w;
        } 
    }
        
    printf("%d\n", max_w);

    return 0;
}
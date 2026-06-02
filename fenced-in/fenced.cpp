#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 2*2000+2;

int repr[MAXN*MAXN];

long long int a[MAXN], b[MAXN];

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
    vector<pair<long long int, pair<long long int,long long int>>> edges; 
    
    fill(repr, repr + MAXN * MAXN, -1);

    long long int A,B,n,m;

    scanf("%lld %lld %lld %lld", &A, &B, &n, &m);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld\n",a+i);
    }
    a[n+1] = A;
    sort(a,a+n+1);
    
    for(int i = 1 ; i <= m ; i++){
        scanf("%lld\n",b+i);
    }   
    b[m+1] = B ;
    sort(b,b+m+1);
    
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++) {
        if(i<n)
            edges.push_back(make_pair(b[j+1]-b[j], make_pair(i*MAXN+j,(i+1)*MAXN+j)));
        if(j<m)
            edges.push_back(make_pair(a[i+1]-a[i], make_pair(i*MAXN+j,i*MAXN+j+1)));
        }
    }
    
    sort(edges.begin(), edges.end());

    long long weight_mst = 0;
    for (auto [w, p] : edges)
        if (unite(p.first, p.second))
            weight_mst += w;

    printf("%lld\n",weight_mst);
    return 0;
}
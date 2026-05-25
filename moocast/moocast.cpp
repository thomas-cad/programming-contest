#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 200;

vector<int> graph[NMAX];
int max_ret = 0;

int state[NMAX];
const int NOT_VISITED = 0, IN_VISIT = 1, VISITED = 2;

void dfs(int node, int &k) {
    if (state[node] == NOT_VISITED) {
        state[node] = IN_VISIT;
        k++;
        for (auto v : graph[node]) {
            dfs(v, k);
        }
        state[node] = VISITED;
    }
}

int main(){

    int N;
    int x[NMAX], y[NMAX], p[NMAX];

    scanf("%d", &N);
    for (int i = 0; i<N; i++){
        scanf("%d %d %d", &x[i], &y[i], &p[i]);
    }

    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            if (i != j && (p[i]*p[i])>=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))){
                graph[i].push_back(j);
            }
        }
    }

    for (int i = 0; i<N; i++){
        fill(state, state + N, NOT_VISITED);
        int k = 0;
        dfs(i, k);
        if (max_ret < k) max_ret = k;
    }

    printf("%d\n", max_ret);
    return 0;
}
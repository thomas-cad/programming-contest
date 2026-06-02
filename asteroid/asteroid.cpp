#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int Tm = 2*500+2;

vector<int> adj[Tm];

int capa[Tm][Tm], flow[Tm][Tm];
bool visited[Tm];

const int source = 0;
const int target = 2*500 + 1;
const int INF = 1e9;

int dfs(int x, int max_flow) {
    if (visited[x]) return 0;
    if (x == target) return max_flow;
    visited[x] = true;
    for (int n : adj[x])
        if (flow[x][n] < capa[x][n]) {
            const int sub_flow = dfs(n, min(max_flow, capa[x][n] - flow[x][n]));
            if (sub_flow > 0) {
                flow[x][n] += sub_flow;
                flow[n][x] -= sub_flow;
                return sub_flow;
            }
        }
    return 0;
}

int main(){
    int K, N;

    scanf("%d %d", &N, &K);

    int R, C;

    for (int i = 1; i<=N; i++){
        adj[source].push_back(i);
        adj[i].push_back(source);
        capa[source][i]=1;
        adj[i+N].push_back(target);
        adj[target].push_back(i+N);
        capa[i+N][target]=1;
    }

    for (int i = 0; i<K; i++){
        scanf("%d %d", &R, &C);
        C+=N;
        adj[R].push_back(C);
        adj[C].push_back(R);              
        capa[R][C]=1;
    }

    int totalFlow = 0, curFlow = 1;

    while (curFlow > 0) {
        fill(visited, visited + Tm, false);
        curFlow = dfs(source, INF);
        totalFlow += curFlow;
    }

    printf("%d\n", totalFlow);

    return 0;
}
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int NMAX =40000;
vector<int> graph[NMAX];
int seen[NMAX] ;

int distB[NMAX], distE[NMAX], distP[NMAX];

void bfs(int start, int dist[NMAX]) {
    fill(seen, seen + NMAX, false);  // ← dans la fonction
    fill(dist, dist + NMAX, 0);
    vector<int> todo = {start};
    seen[start] = true ;
    dist[start] = 0;
    for(size_t id = 0 ; id < todo.size() ; id++){
        for(auto v : graph[todo[id]]){
            if(!seen[v]) {
                seen[v] = true;
                todo.push_back(v);
                dist[v] = dist[todo[id]] + 1;
            }
        }
    }
}

int main(){
    int B, E, P, N, M;

    int min_weight=INT_MAX;

    scanf("%d %d %d %d %d", &B, &E, &P, &N, &M);

    for (int i = 0; i<M; i++){
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    bfs(1, distB);
    bfs(2, distE);
    bfs(N, distP);

    for (int i = 1; i <= N; i++){
        int weight = distB[i]*B + distE[i]*E + distP[i]*P;
        if (weight<min_weight) min_weight = weight;
    }

    printf("%d\n", min_weight);

    return 0;
}
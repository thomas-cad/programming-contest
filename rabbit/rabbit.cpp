#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const int DMAX = 510;

bool garden[DMAX][DMAX];
bool seen [DMAX][DMAX];
pair <int, int> path[DMAX][DMAX];

pair <int, int> start, goal;

int DI[4] = {-1, 1, 0, 0};
int DJ[4] = {0, 0, -1, 1};

int main() {
    int C, R;
    scanf("%d %d", &C, &R);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            scanf(" %c", &c);
            switch (c) {
                case '.': garden[i][j] = true;  break;
                case '#': garden[i][j] = false; break;
                case 'R': garden[i][j] = true; start={i, j}; break;
                case 'D': garden[i][j] = true; goal={i, j}; break;
            }
        }
    }

    //BFS

    vector<pair<int, int>> todo = {start};
    seen[start.first][start.second] = true;

    path[start.first][start.second] = {-1, -1};

    for (size_t id = 0; id < todo.size(); id++){
        for (int k = 0; k<4; k++){
            int ci = todo[id].first;
            int cj = todo[id].second;

            int ni = ci + DI[k];
            int nj = cj + DJ[k];

            if (ni >= 0 && ni < R && nj >= 0 && nj < C   // dans la grille
                && garden[ni][nj]                          // pas un mur
                && !seen[ni][nj]) {                        // pas déjà visité

                seen[ni][nj] = true;
                path[ni][nj] = {ci, cj};           // on mémorise d'où on vient
                todo.push_back({ni, nj});
            }
        }
    }

    char DC[] = {'U', 'D', 'L', 'R'};    
    char dir[510*510];
    int len = 0;

    int di = goal.first;
    int dj = goal.second;

    while(path[di][dj] != make_pair(-1, -1)){
        int ppi = path[di][dj].first;
        int ppj = path[di][dj].second;

        for (int k = 0; k < 4; k++) {
            if (ppi + DI[k] == di && ppj + DJ[k] == dj) {
                dir[len++] = DC[k];
                break;
            }
        }
        di = ppi;
        dj = ppj;
    }

    for (int i = len-1; i >= 0; i--){
        printf("%c", dir[i]);
    }
    printf("\n");
    
    return 0;
}

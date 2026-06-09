#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int NMAX=1005;
const int TMAX=1000;
int mooney[NMAX];
vector<pair<int, int>> roads;
int dp[TMAX+5][NMAX];

int main(){
    int N, M, C;

    scanf("%d %d %d", &N, &M, &C);

    for (int i = 1; i <= N; i++){
        scanf("%d", &mooney[i]);     
    }

    int a, b;

    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        roads.push_back({a,b});
    }

    for (int n = 1; n <= N; n++){
        for (int t=0; t<TMAX; t++){
            dp[t][n]=INT32_MIN;
        }    
    }

    dp[0][1]=0;

    for (int t=0; t<TMAX; t++){
        for (auto [u, v] : roads){
            if (dp[t][u] > INT32_MIN){
                dp[t+1][v] = max(dp[t+1][v], dp[t][u] + mooney[v]);
            }
        }
    } 

    long long best = 0;                       
    for (int t = 1; t <= TMAX; t++){
        if (dp[t][1] > INT32_MIN){            
            long long profit = dp[t][1] - (long long)C * t * t;
            best = max(best, profit);
        }
    }
    printf("%lld\n", best);

    return 0;
}
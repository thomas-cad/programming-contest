#include <iostream>

const int NMAX = 510;

long long int lengths[NMAX];
long long int prefix[NMAX];
long long int dp[NMAX][NMAX];

long long sommeSegment(int i, int j){
    return prefix[j+1] - prefix[i];
}

int main(){
    int N;

    scanf("%d", &N);

    prefix[0]=0;

    for (int i = 0; i < N; i++){
        scanf("%lld", &lengths[i]);
        prefix[i+1] = prefix[i] + lengths[i];  
    }

    for (int i = 0; i < N; i++) dp[i][i] = 0;

    for (int len = 2; len <= N; len++){
        for (int i = 0; i + len - 1 < N; i++){
            int j = i + len - 1;
            long long min = INT64_MAX;
            for (int k = i; k < j; k++){
                long long candidat = dp[i][k] + dp[k+1][j] + sommeSegment(i, j);
                if (candidat < min) min = candidat;
            }
            dp[i][j] = min;
        }
    }

    printf("%lld\n", dp[0][N-1]);

    return 0;
}   


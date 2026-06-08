#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX=10001, KMAX=1000;
int cows[NMAX];
long long int dp[NMAX];

int main(){
    int N, K;

    scanf("%d %d", &N, &K);

    for (int i=1; i<=N; i++){
        scanf("%d", &cows[i]);
    }

    dp[0]=0;

    for (int i=1; i<=N; i++){
        long long int val = INT64_MIN;
        long long int val_i=INT64_MIN;
        for (int k=1; k<=K && k<=i; k++){
            if (cows[i-k+1]>val) val = cows[i-k+1];
            if (val_i<(val*k+dp[i-k])) val_i=val*k+dp[i-k];
        }
        dp[i]=val_i;
    }

    printf("%lld\n", dp[N]);

    return 0;
}
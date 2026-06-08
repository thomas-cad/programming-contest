#include <iostream>
#include <algorithm>

using namespace std;

// 0 : Hook, 1 : Papier, 2 : Scissor

const int NMAX= 100000, KMAX=21;
int r[NMAX];
int dp[NMAX][KMAX][3];

int win(int c, int f){
    if (c == f) return 0;
    if ((f + 1) % 3 == c) return 1; 
    return 0;
}

int main(){
    int K, N;

    scanf("%d %d", &N, &K);

    for (int i=0; i<N; i++){
        char r_val;

        scanf(" %c", &r_val);

        switch (r_val)
        {
        case 'H':
            r[i]=0;
            break;
        
        case 'P':
            r[i]=1;
            break;
        
        case 'S':
            r[i]=2;
            break;
        }
    }

    for (int g=0; g<3; g++)
        for (int k=0; k<=K; k++)
            dp[0][k][g]=win(g, r[0]);

    for (int i=1; i<N; i++){
        for (int g=0; g<3; g++){
            for (int k=0; k<=K; k++){
                int cas1 = dp[i-1][k][g];

                int cas2 = INT16_MIN;
                if (k>=1){
                    for (int l = 0; l < 3; l++) {  
                        if (l != g)                 
                            cas2 = max(cas2, dp[i-1][k-1][l]);
                    }
                }

                dp[i][k][g] = max(cas1, cas2) + win(g, r[i]);
            }
        }
    }

    int rt_val=INT16_MIN;

    for (int k=0;k<=K;k++){
        for (int g=0; g<3; g++){
            if (dp[N-1][k][g]>rt_val) rt_val=dp[N-1][k][g];
        }
    }

    printf("%d\n", rt_val);

    return 0;
}
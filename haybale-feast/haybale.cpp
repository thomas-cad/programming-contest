#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;

int main(){
    int n;
    long long M;
    scanf("%d %lld", &n, &M);

    vector<long long> F(n), S(n);
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &F[i], &S[i]);

    deque<int> dq;            
    long long sum = 0;       
    int l = 0;
    long long ans = LLONG_MAX;

    for (int r = 0; r < n; r++) {
        sum += F[r];
        while (!dq.empty() && S[dq.back()] <= S[r]) dq.pop_back();
        dq.push_back(r);

        while (sum - F[l] >= M) {
            sum -= F[l];
            if (dq.front() == l) dq.pop_front();  // l sort : si c'etait le max, on l'enleve
            l++;
        }

        if (sum >= M)
            ans = min(ans, S[dq.front()]);
    }

    printf("%lld\n", ans);
    return 0;
}
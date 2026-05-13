#include <stdio.h>
#include <set>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    set<pair<int,int>> rooms;
    for (int i = 0; i < N; i++) {
        int c;
        scanf("%d", &c);
        rooms.insert({c, i});
    }

    for (int i = 0; i < M; i++) {
        int r;
        scanf("%d", &r);
        auto it = rooms.lower_bound({r, 0});
        if (it == rooms.end()) {
            printf("-1\n");
        } else {
            printf("%d\n", it->second);
            rooms.erase(it);
        }
    }
}

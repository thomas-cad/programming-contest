#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    map<string, int> cnt;
    char buf[25];

    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        cnt[string(buf)]++;
    }

    for (auto& p : cnt) {
        if (p.second * 2 > n) {
            printf("%s\n", p.first.c_str());
            return 0;
        }
    }

    printf("NONE\n");
    return 0;
}

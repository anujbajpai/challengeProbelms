#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef vector<pair<int, int> > VPI;

int cmp(const pair<int, int> &A, const pair<int, int> &B) {
    if(A.second < B.second)
        return 1;
    return 0;
}

int possibleBombs(const VPI kingInterval, int N) {
    int Count = 1;
    int currentFinal = kingInterval[0].second;
    for(int i = 1; i < N; i++) {
        if(currentFinal < kingInterval[i].first) {
            Count++;
            currentFinal = kingInterval[i].second;
        }
    }
    return Count;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        VPI kingInterval;
        for(int i = 0; i < N; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            kingInterval.push_back(make_pair(x, y));
        }
        sort(kingInterval.begin(), kingInterval.end(), cmp);
        printf("%d\n", possibleBombs(kingInterval, N));
    }
    return 0;
}

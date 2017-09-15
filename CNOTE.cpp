#include <cstdio>
#include <vector>
#define PF(x) printf("%d ", x);

using namespace std;

typedef vector<pair<int, int> > VPI;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int X, Y, K, N;
        scanf("%d%d%d%d", &X, &Y, &K, &N);
        VPI notes;
        for(int i = 0; i < N; i++) {
            int P, C;
            scanf("%d%d", &P, &C);
            notes.push_back(make_pair(P, C));
        }
        int flag = 0;
        for(int i = 0; i < N; i++) {
            if (notes[i].first >= (X-Y) && notes[i].second <= K) {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("LuckyChef\n");
        else
            printf("UnluckyChef\n");
    }
}

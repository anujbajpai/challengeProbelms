#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, cnt = 0;
        scanf("%d", &N);
        vector<int> A(N);
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        for(int i = 0; i < N; i++) {
            if(i == 0) {
                if (A[0] != A[1])
                    cnt++;
            }
            else if(i == N - 1) {
                if (A[N - 2] != A[N - 1])
                    cnt++;
            }
            else {
                if (A[i] != A[i - 1] || A[i] != A[i + 1])
                    cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

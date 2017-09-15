#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int T;

    scanf("%d", &T);
    while(T--) {
        int N, sum = 0, temp = 0;
        scanf("%d", &N);
        vector<int> B(N+1);
        for(int i = 1; i <= N; i++) {
            scanf("%d", &B[i]);
            if (B[i])
                temp++;
            sum += B[i];
        }
         if ((sum <= (100 + temp - 1)) && ((sum - 100) >= 0))
            printf("YES\n");
         else
            printf("NO\n");
    }
    return 0;
}

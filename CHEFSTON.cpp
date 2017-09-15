#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        long long int N, K;
        scanf("%lld%lld", &N, &K);
        vector<long long int> A(N+1), B(N+1);
        for(long long int i = 0; i < N; i++)
            scanf("%lld", &A[i]);
        for(long long int i = 0; i < N; i++)
            scanf("%lld", &B[i]);
        long long int Max = ((K / A[0]) * B[0]);
        for (long long int i = 0; i < N; i++) {
            if (((K / A[i]) * B[i]) > Max)
                Max = ((K / A[i]) * B[i]);
        }
        printf("%lld\n", Max);
    }
    return 0;
}

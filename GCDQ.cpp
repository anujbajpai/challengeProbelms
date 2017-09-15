#include <cstdio>
#include <vector>
using namespace std;

int HCF (int dvdnt, int div) {
    if (div)
        HCF(div, dvdnt % div);
    else
        return dvdnt;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, Q;
        scanf("%d%d", &N, &Q);
        vector<int> A(N+1);
        for(int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
        vector<int> prefixGcd(N+1), suffixGcd(N+1);
        int temp = A[1];
        for(int i = 1; i <= N; i++) {
            temp = HCF(A[i], temp);
            prefixGcd[i] = temp;
        }
        int temp1 = A[N];
        for(int i = N; i >= 1; i--) {
            temp1 = HCF(A[i], temp1);
            suffixGcd[i] = temp1;
        }
        while(Q--) {
            int L, R, answer;
            scanf("%d%d", &L, &R);
            if((L-1) <1)
                answer = HCF(suffixGcd[R+1], suffixGcd[R+1]);
            else if((R + 1) > N)
                answer = HCF(prefixGcd[L-1], prefixGcd[L-1]);
            else
                answer = HCF(prefixGcd[L-1], suffixGcd[R+1]);
            printf("%d\n", answer);
        }
    }
    return 0;
}

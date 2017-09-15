#include <iostream>
#include <cstdio>
#define llt long long int

using namespace std;

int isBitSet(int mask, int K) {
    return ((mask & (1 << K)) != 0);
}

int getSubset(llt *A, int N) {
    int Count = 0;
    llt B[N];
    for(int i = 1; i < (1 << N); i++) {
        int top = 0, flag = 0;
        for(int j = 0; j < N; j++) {
            if(isBitSet(i, j)) {
                if(A[j] < 0) {
                    B[top++] = A[j];
                } else {
                    if (top > 0) {
                        if (B[top - 1] + A[j] != 0) {
                            flag = 1;
                            break;
                        } else
                            top--;
                    } else {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (!flag && !top)
            Count++;
    }
    return (Count + 1);
}

int main() {
    int N;
    scanf("%d", &N);
    llt A[N];
    for(int i = 0; i < N; i++)
        scanf("%lld", &A[i]);
    printf("%d", getSubset(A, N));
    return 0;
}

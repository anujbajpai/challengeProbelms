#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define llt long long int

using namespace std;

int isBitSet(int mask, int k) {
    return ((mask & (1 << k)) != 0);
}

int makeSubset(llt *A, int N, llt S) {
    llt finalCount = 0;
    for(int i = 1; i < (1 << N); i++) {
        llt Cnt = 0;
        for (int j = 0; j < N; j++) {
            if (isBitSet(i, j))
                Cnt += A[j];
        }
        if (Cnt == S)
            finalCount++;
    }
    return finalCount;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, K, flag = 0;
        scanf("%d%d", &N, &K);
        llt A[N], Count = 0;
        for(int i = 0; i < N; i++)
            scanf("%lld", &A[i]);
        for(int i = 0; i < N; i++)
            Count += A[i];
        llt sanskar = Count / K;
        if((Count % K) || N < K)
            flag = 1;
        else {
            if(makeSubset(A, N, sanskar) < K)
                flag = 1;
        }
        if (flag == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}


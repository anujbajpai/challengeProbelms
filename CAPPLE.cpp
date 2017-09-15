#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        int A[N];
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        sort(A, A + N);
        int Count = 0;
        for(int i = 0; i < N - 1; i++) {
            if (A[i] != A[i + 1])
                Count++;
        }
        printf("%d\n", Count + 1);
    }
    return 0;
}

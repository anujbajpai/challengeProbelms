#include <iostream>
#include <cstdio>
#include<algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main () {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, K;
        scanf("%d%d", &N, &K);
        int A[N + 1];
        for(int k = 0; k < N; k++)
            scanf("%d", &A[k]);
        vector<int> V, flag, Final;
        for(int g = 0; g < N; g++) {
            V.push_back(0);
        }
        for(int g = 0; g < N; g++) {
            flag.push_back(0);
        }
        for(int j = 1; j <= pow(2,N); j++) {
            int result = 0;
            for(int i = 0; i < N; i++) {
                int Q;
                Q = j / (pow(2, N) / pow(2, i+1));
                result = ( A[i] * flag[i] ) ^ result;
                if (Q != V[i]) {
                    if (flag[i] == 0)
                        flag[i] = 1;
                    else
                        flag[i] = 0;
                    V[i] = Q;
                }
                else
                    V[i] = Q;
            }
            result = result ^ K;
            Final.push_back(result);
        }
        sort (Final.begin(), Final.end(), greater<int>());
        printf("%d\n", Final[0]);
    }
    return 0;
}

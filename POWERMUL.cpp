#include <iostream>
#include <cstdio>

using namespace std;

long long int pow(int a, int b) {
    long long int result = 1;
    while(b) {
       if(b & 1)
            result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}

int fun(int n) {
    int power, mul = 1;
    for(int i = 1; i <= n; i++) {
        power = pow(i, i);
        mul = mul * power;
    }
    return mul;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, MOD, Q, final;
        scanf("%d%d%d", &N, &MOD, &Q);
        while(Q--) {
            int r1, r2, r3, Q1;
            scanf("%d", &Q1);
            r1 = fun(N);
            r2 = fun(Q1);
            r3 = fun(N - Q1);
            int result = r1/ (r2 * r3) % MOD;
            printf("%d\n", result);
        }
    }

    return 0;
}

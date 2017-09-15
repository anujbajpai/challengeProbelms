#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int num;
        scanf("%d", &num);
        int cnt = 0;
        for (int i = 1; i <= num/2; i++) {
            if (num % i == 0)
                cnt += i;
        }
        cnt += num;
        printf("%d\n", cnt);
    }
    return 0;
}

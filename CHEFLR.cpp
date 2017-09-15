#include <iostream>
#include <cstdio>
#include <string.h>
#define MOD 1000000007

using namespace std;

int main () {
    int T;
    char str[100010], c;
    scanf("%d", &T);
    while (T--) {
        scanf ("%c%s", &c, str);
        int len = strlen(str);
        int n = 1;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                if (str[i] == 'l')
                    n *= 2;
                else
                    n = (n * 2) + 2;

            }
            else {
                if (str[i] == 'l')
                    n = (n * 2) - 1;
                else
                    n = (n * 2) + 1;
            }
            n %= MOD;
        }
        printf("%d\n", n);
    }

    return 0;
}

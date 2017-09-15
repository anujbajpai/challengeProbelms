#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int t;
    scanf("%d", &t);
    while(t--) {
        int i = 2048, cnt = 0, num, qnt;
        scanf("%d", &num);
        if(num >= i) {
            qnt = num / i;
            cnt = cnt + qnt;
            num = num % i;
        }
        i = 2048;
        while (num) {
            if (i <= num) {
                cnt++;
                num = num - i;
                i = i / 2;
            }
            else
                i = i / 2;
        }
        printf ("%d\n", cnt);
    }
}

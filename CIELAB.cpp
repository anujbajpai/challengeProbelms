#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int a, b, e, d, c;
    scanf("%d%d", &a, &b);
    c = a - b;
    e = c / 10;
    d = c % 10;
    if (d != 1)
        d = 1;
    else
        d = 2;
    e = e * 10 + d;
    printf("%d", e);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main () {
    int t, cost, cnt = 0;
    char str[101];
    scanf("%d", &t);
    while (t--) {
    gets (str);
    scanf ("%d", &cost);
    printf ("%s %d\n", str, cost);
    int digitarray[10], digit;
    for (int i = 0; i < 10; i++)
        digitarray[i] = 0;
    while (cost) {
        digit = cost % 10;
        cost = cost / 10;
        digitarray[digit]++;
    }
    if (digitarray[0] != 0 || digitarray[1] != 0 || digitarray[2] != 0 || digitarray[4] != 0 || digitarray[6] != 0 || digitarray[7] != 0 || digitarray[9] != 0)
        int c = 0;
    else if (digitarray[8] >= digitarray[5] && digitarray[5] >= digitarray[3])
        cnt++;
    else
        int c = 0;


    }
    printf("%d\n", cnt);
    return 0;
}

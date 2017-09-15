#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main () {
    int test;
    scanf("%d", &test);
    while(test--) {
        float a, b, c;
        int X[3], Y[3], R;
        scanf("%d", &R);
        for (int i = 0; i <= 2; i++) {
            scanf("%d%d", &X[i], &Y[i]);
        }
        a=sqrt((X[1] - X[0] )*(X[1] - X[0] ) + (Y[1] - Y[0])*(Y[1] - Y[0]));
        b=sqrt((X[2] - X[0] )*(X[2] - X[0] ) + (Y[2] - Y[0])*(Y[2] - Y[0]));
        c=sqrt((X[2] - X[1] )*(X[2] - X[1] ) + (Y[2] - Y[1])*(Y[2] - Y[1]));
        if (a <=R) {
            if (b <= R || c <= R)
                printf("yes");
            else
                printf("no");
        }
        else if(b <= R && c <= R)
            printf("yes");
        else
            printf("no");
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <limits.h>
#define SF(a) scanf("%d", &a);
#define PF(d) printf("%d ", d);
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define EFOR(i, a, v) for(int i = a; i <= v; i++)

using namespace std;

int HCF (int dvdnt, int div) {
    if (div)
        HCF(div, dvdnt % div);
    else
        return dvdnt;
}
int main () {
    int test;
    SF(test);
    while (test--) {
        int len;
        SF(len);
        int arr[len];
        FOR(j, 0, len)
            SF(arr[j])
        int answer = arr[0], i = 0;
        while (i < len-1) {
            answer = HCF(answer, arr[++i]);
            //PF(answer)
        }
        FOR(l, 0, len) {
        if (answer != 1)
            arr[l] /= answer;
        }
        FOR(l, 0, len)
            PF(arr[l])
            printf("\n");
    }
    return 0;
}

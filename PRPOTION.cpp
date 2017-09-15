#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void half(int arr1[], int len1) {
    for (int i = 1; i <= len1; i++)
        arr1[i] /= 2;
}

int main () {
    int test;
    scanf("%d", &test);
    while(test--) {
        int R, G, B, M;
        scanf("%d%d%d%d", &R, &G, &B, &M);
        int RED[R+1], GREEN[G+1], BLUE[B+1];
        for (int i = 1; i <= R; i++)
            scanf("%d", &RED[i]);
        for (int i = 1; i <= G; i++)
            scanf("%d", &GREEN[i]);
        for (int i = 1; i <= B; i++)
            scanf("%d", &BLUE[i]);
        sort (RED+1, RED+R+1);
        sort (GREEN+1, GREEN+G+1);
        sort (BLUE+1, BLUE+B+1);
        int maX = 0;
        while(M--) {
            maX = max(RED[R], (max(GREEN[G], BLUE[B])));
            if (maX == RED[R])
                half(RED, R);
            else if (maX == GREEN[G])
                half(GREEN, G);
            else
                half(BLUE, B);
        }
        maX = max(RED[R], (max(GREEN[G], BLUE[B])));
        printf("%d\n", maX);
    }
    return 0;
}

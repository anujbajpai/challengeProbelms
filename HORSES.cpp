#include <iostream>
#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int main () {
    int test;
    scanf("%d", &test);
    while(test--) {
        int len, diff = INT_MAX, temp;
        scanf("%d", &len);
        int a[len];
        for (int i = 0; i < len; i++)
            scanf("%d", &a[i]);
        sort(a+0, a+len);          // heap sort
        for (int i = 0; i < len - 1; i++) {
            int j = i + 1;
            temp = a[j++] - a[i];
            if (temp < diff)
                diff = temp;
        }
            printf("%d ", diff);
             printf("\n");
    }

    return 0;
}

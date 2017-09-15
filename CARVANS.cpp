#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int test;
    scanf("%d", &test);
    while(test--) {
        int cars[10001],Count = 1, len, hold;
        scanf("%d", &len);
        for(int i = 0; i < len; i++)
            scanf("%d", &cars[i]);
        for (int i = 1; i < len; i++) {
            if (cars[i] <= cars[i - 1])
                Count++;
            else {
                hold = cars[i - 1];
                cars[i - 1] = cars[i];
                cars[i] = hold;
            }
        }
        printf("%d\n", Count);
    }
    return 0;
}

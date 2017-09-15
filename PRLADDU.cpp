#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int test;
    scanf("%d", &test);
    while(test--) {
        int len;
        scanf("%d", &len);
        int arr[len+1], dino[len + 1], j = 0;
        for (int i = 1; i <= len; i++)
            scanf("%d", &arr[i]);
        for (int i = 1; i <= len; i++)
            dino[i] = 0;
        for (int i = 1; i <= len; i++) {
            if (arr[i] < 0)
                dino[++j] = i;
        }
        int k = 1, dist = 0;
        for (int i = 1; i <=len; i++) {
            if (arr[dino[k]] == 0)
                k++;
            if (arr[i] > 0) {
                while(arr[i]) {
                    if (arr[dino[k]] + arr[i] > 0) {
                        arr[i] += arr[dino[k]];
                        int c = dino[k] - i;
                        if(c < 0)
                            c = c * -1;
                        dist += c * arr[dino[k]] * -1;
                        k++;
                    }
                    else {
                        int c = dino[k] - i;
                        if (c < 0)
                            c = c * -1;
                        dist += c * arr[i];
                        arr[dino[k]] += arr[i];
                        arr[i] = 0;
                    }
                }
            }
        }
        printf("%d\n", dist);
    }
    return 0;
}

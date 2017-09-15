#include <iostream>
#include <cstdio>
#define PF(a) printf("%d\n", a);

using namespace std;

int main () {
    int test;
    scanf("%d", &test);
    while(test--) {
        int arr[11], minimum = 10, minimumIndex, prevValue ;
        for(int i = 0; i <= 9; i++)
            scanf("%d", &arr[i]);
        for(int j = 1; j <= 9; j++) {
            if (arr[j] < minimum) {
                minimum = arr[j];
                minimumIndex = j;
            }
        }
        if (minimum == 0) {
            PF(minimumIndex);
        }
        else if (arr[0] < minimum) {
            int t =arr[0] + 1, add = 1;
            for(int i = 1; i <= t; i++)
                add = add * 10;
            int asd;
            asd = add * minimum;
            PF(add);
        }
        else {
            prevValue = minimumIndex;
            int target = minimum + 1, k = 0, ten = 1;
            while(target --) {
                prevValue = ten * k + prevValue;
                ten = ten * 10;
                k = minimumIndex;
            }
            PF(prevValue);
        }
    }
    return 0;
}



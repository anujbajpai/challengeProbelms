#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;

int main () {
    int test;
    scanf("%d", &test);
    while(test--) {
        int num, target, flag = 0,  finaldiff = 0, maX = INT_MIN;
        scanf("%d%d", &num, &target);
        int col[num];
        for (int i = 0; i < num; i++ )
            scanf("%d", &col[i]);
        for (int i = 0; i < num; i++ ) {
            if(col[i] > maX)
                maX = col[i];
        }
        for (int i = 0; i < num; i++ ) {
            int diff = maX - col[i];
            finaldiff = finaldiff + diff;
        }
        if (finaldiff < target) {
            if((target - finaldiff) % num == 0)
                flag = 1;
            else
                flag = 0;
        }
        else if (finaldiff == target)
            flag = 1;
        else {
              flag = 0;
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

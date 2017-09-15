#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        char str[100010];
        int arr[124], temp, cnt = 0;
        for(int i = 0; i < 124; i++)
            arr[i] = 0;
        scanf("%s", &str);
        for(int i = 0; i < strlen(str); i++ ) {
            temp = str[i];
            arr[temp]++;
            if(arr[temp] < 2)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

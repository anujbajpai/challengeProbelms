#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int rows, value[101][101];
        scanf("%d", &rows);
        for(int i = 0; i <rows; i++) {
            for(int j = 0; j <= i; j++) {
                scanf("%d", &value[i][j]);
            }
        }
        void half(int i) {
            if(i > 3) {
                arr[m++] = sum;
                return 1;
            }
            else if(j < c){

                sum = sum + value[i][j];
                j++;
                return half(i + 1)
            }
            else if()
        }
    return 0;
}

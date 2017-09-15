#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int T,countnum=0,N;
    scanf("%d %d",&T,&N);
    while(T--) {
        int num;
        scanf("%d", &num);
        if(num%N==0)
            countnum++;
    }
    printf("%d",countnum);
    return 0;
}

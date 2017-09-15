#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int chkprm(int num2) {
    for(int j = 2; j < sqrt (num2); j++) {
        if(num2 % j == 0)
            return 0;
    }
    return 1;
}

int chkpldr (int num1) {
    int c,d=0,r;
    int temp=num1;
  while(temp!=0)
  {
     r=temp%10;
     d=d*10+r;
     temp/=10;
  }
  if(d==num1) {

        c=chkprm(num1);

        return c;
  }
    return 0;
}

int main () {
    int num,a,m;
    scanf("%d", &num);
    for(m=num;m!=0;m++) {
        a=chkpldr(m);
        if(a) {
            printf("%d",m);
            break;
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;

void display(int maxm3,int sarr2[]) {
    int maxs = INT_MIN,c,m;
    for(m=1;m<=maxm3;m++) {
        if(sarr2[m] > maxs) {
        maxs=sarr2[m];
        c=m;
        }
    }
    printf("%d %d\n", c, maxs );
}

void operate(int sarr1[],int farr2[],int len2,int maxm2) {
    int k;
    for(k=1;k<=len2;k++)
        sarr1[farr2[k]]++;
    display(maxm2,sarr1);
}


void intlz(int maxm1,int farr1[],int len1) {                                   //initialize 2nd array  with 0
    int sarr[maxm1],j;
    for(j=1;j<=maxm1;j++)
        sarr[j]=0;
    operate(sarr,farr1,len1,maxm1);
}

void getdata(int len) {
                                           //input values in a
    int maxm = INT_MIN,i,farr[101];
    for(i=1;i<=len;i++) {
        scanf("%d",&farr[i]);
        if(farr[i] > maxm)
            maxm = farr[i];
    }
    intlz(maxm,farr,len);
}

int main () {
    int T,lent;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&lent);
        getdata(lent);
    }
    return 0;
}

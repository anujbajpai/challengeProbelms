#include <iostream>
#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int mini;

int getmin (int C1[],int lenght) {
    int k = -1, j = 1;
    mini = INT_MAX;
    while (j < lenght) {
        if(C1[j]<mini && C1[j] != -1) {
            mini = C1[j];
            k=j;
        }
        j++;
        cout<<"j "<<j<<endl<<"k "<<k<<endl;
    }
    return k;
}

int main () {
    long long int T[100010], N, M;
    int height, i = 1, C[100010];
    scanf("%lld%lld%d", &N,&M, &height);
    while (height--) {
        long long int x;
        int y;
        scanf("%lld %d", &x, &y);
        T[i] = x;
        C[i] = y;
        i++;
    }
     long long int cost=0,v=0,v1=0;
     int len=i,k1 = -1, check=1;
     long long int tcls = N * M;
     while (tcls!=v1) {
        cout<<tcls<<endl<<v1<<endl;
        if (tcls-v1< 0) {
           long long int r = tcls-v1;
            cost += (v+r)*mini;//mini

            v1 += r;
            cout<<"g1 "<<v1<<endl;
        }
        else if(v1<tcls) {
            k1=getmin(C,len);
            cout<<"k1 "<<k1<<endl;
            if (k1 == -1) {
                check = 0;
                break;
            }
            v=T[k1];
            cout<<"v "<<v<<endl;
            v1 += v;
            if(v1<=tcls)
                cost=cost+v*C[k1];
            C[k1]=-1;
            cout<<"g2 "<<v1<<endl;
        }
        else
            continue;
    }
    if(check)
        printf("%lld\n",cost);
    else
        printf("Impossible\n");
    return 0;
}

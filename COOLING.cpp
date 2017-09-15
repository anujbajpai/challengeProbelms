#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;

int main () {
    int T,i,j,racks[101],pie[101];
    scanf("%d", &T);
    while(T--){
        int len;
        scanf("%d", &len);
        for(i=0;i<len;i++)
            scanf("%d", &pie[i]);
        for(j=0;j<len;j++)
            scanf("%d", &racks[j]);
        int cnt=0;
        for(i=0;i<len;i++) {
            int maxm=INT_MAX,k=len+1;
            for(j=0;j<len;j++) {
                if(racks[j] >= pie[i]) {
                    if(racks[j] < maxm) {
                            maxm=racks[j];
                            k=j;
                            racks[k]=0;
                            cnt++;
                    }

                }
            }
            /*if(k<len) {
                racks[k]=0;
                cnt++;
            }*/
        }
        printf("%d\n",cnt);
    }
    return 0;
}

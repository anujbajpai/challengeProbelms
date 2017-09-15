#include<iostream>
#include<cstdio>
#include <string.h>

using namespace std;

int main() {
    int T,len,a,cnt=0,p=-1,f,l=0,k=0;
    char str[401],arr1[400];
    scanf("%d", &T);
    while (T--){
    scanf("%s", &str);
    len=strlen(str);
    for(int i = 0; i < len; i++) {
        a=str[i];
        if (a >= 97 && a <=122 || a>=65 && a<=90 )
            printf("%c", str[i]);
        else if (a==40) {
             f=0;
             k++;
        }
        else if(a==41) {
            l++;
           while(f){
            printf("%c",arr1[p--]);
            f--;
           }
        }
        else if(a>=42 && a<=47||a==94) {
            ++f;
            arr1[++p]=str[i];

        }
    }
    if(k==l)
    while(p>=0){
        printf("%c",arr1[p]);
        p--;
    }
    printf("\n");
    }
    return 0;
}

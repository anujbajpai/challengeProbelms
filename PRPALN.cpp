#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
#include <limits.h>
#define SF(a) scanf("%d", &a);
#define PF(a) printf("%d\n", a);
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define EFOR(i, a, b) for(int i = a; i<= b; i++)

using namespace std;

int fun(int p, int q, char str1[], int cnt1) {
    while(p < q) {
        if(str1[p] != str1[q]) {
            cnt1++;
            q--;
            p++;
            //cout<<"p-->"<<p<<endl<<"q-->>"<<q<<endl;
            //cout<<"cnt-->>"<<cnt1<<endl;
        }
        else {
            p++;
            q--;
        }
    }
    return cnt1;
}

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int C, len, cnt = 0, i = 0, temp, j, flag = 1;
        char str[100010];
        scanf("%c%s", &C, str);
        len = strlen(str) - 1;
        while(i < len) {
            if(str[i] == str[len]) {
                i++;
                len--;
                //cout<<"-->>1"<<endl;
            }
            else if( (i + 1) < len && (len - 1) > i && str[i] == str[len - 1] && str [i + 1] != str[len]  ) {
                cnt++;
                i++;
                len -= 2;
                //cout<<"->2"<<endl;
            }
            else if((i + 1) < len && (len - 1) > i && str[i] != str[len - 1] && str [i + 1] == str[len] ) {
                cnt++;
                i += 2;
                len--;
                //cout<<"->3"<<endl;
            }
            else if((i + 1) < len && (len - 1) > i && str[i] == str[len - 1] && str [i + 1] == str[len] ) {
                cnt++;
                //cout<<"->4"<<endl;
                j = len - 1;
                temp = fun(i, j, str, cnt);
                //cout<<"temp"<<temp<<endl;
                if(temp > 1) {
                    i = i + 1;
                    //cout<<"i "<<str[i]<<endl<<"len "<<len<<endl;
                    cnt = fun(i, len, str, cnt);
                }
                else
                    cnt = temp;
                //cout<<"f1 "<<cnt<<endl;
                break;
            }
            else if( (i + 1) < len && (len - 1) > i && str[i] != str[len - 1] && str [i + 1] != str[len]) {
                flag = 0;
                //cout<<"last"<<endl;
                break;
            }
            else {
                i++;
                len--;
                //cout<<"T"<<endl;
                continue;
            }
        }
        if(cnt <= 1 && flag != 0)
            cout<<"YES"<<endl;
        else if(flag == 0)
            cout<<"NO"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

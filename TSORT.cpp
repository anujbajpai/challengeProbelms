#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxi 1000001

using namespace std;

int main () {
    int i,T,arr[maxi],j;
    scanf("%d", &T);
    for(i = 0; i < T; i++)
        scanf("%d", &arr[i]);
    for(i=2;i<=T;i++) {
        j=i-1;
        while(j>=0) {
            if(arr[j] < arr[j-1])
                swap (arr[j-1],arr[j]);
            else
                j--;
        }
    }
    return 0;
    }



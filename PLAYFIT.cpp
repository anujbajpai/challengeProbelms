#include <iostream>
#include <cstdio>
#define MAX 100001

using namespace std;

int goals[MAX];

int main() {
    int T;
    scanf ("%d" ,&T);
    while(T--) {
        int maxDif = 0, len;
        scanf ("%d", &len);
        for(int i = 0; i < len; i++)
            scanf ("%d", &goals[i]);
        int mini = goals[0];
        for(int i = 1; i < len; i++) {
            if(goals[i] < mini)
                mini = goals[i];
            else {
                if((goals[i]- mini) > maxDif)
                    maxDif = goals[i] - mini;
            }
        }
        if (maxDif <= 0)
           printf("UNFIT\n");
        else
            printf ("%d\n", maxDif);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#define SF(a) scanf("%d", &a);
#define PF(a) printf("%d\n", a);
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define EFOR(i, a, b) for(int i = a; i<= b; i++)

using namespace std;

int main () {
    int t;
    SF(t)
    while(t--) {
        int teleph, tcandle;
        scanf("%d%d", &teleph, &tcandle);
        int eleph[teleph+1], k = 1, currentcandle = tcandle;
        //PF(teleph)
        EFOR(i, 1, teleph) {
            SF(eleph[k++])
            //PF(eleph[k-1])
        }
        //PF(teleph)


        //PF(currentcandle)
        EFOR(i, 1, teleph) {
            currentcandle = currentcandle - eleph[i];
            if (currentcandle < 0) {
                printf("No\n");
                break;
            }
           // PF(currentcandle)
        }
        //PF(currentcandle)
        if (currentcandle >= 0)
            printf("Yes\n");
    }
    return 0;
}

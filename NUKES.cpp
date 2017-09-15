#include <iostream>
#include <cstdio>
#define SF(a, b, c) scanf("%d%d%d", &a, &b, &c);
#define PF(a) printf("%d ", a);
#define FOR(i, a, b) for(int i = a; i <b; i++)
#define EFOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int main () {
        int particles, limit, chambers;
        SF(particles, limit, chambers)
        int nuke[chambers + 1], chamberpost = 0;
        EFOR(p, 0, chambers)
            nuke[p] = 0;
        EFOR(p, 1, particles) {
            nuke[chamberpost]++;
            if (nuke[chamberpost] > limit) {
                while(nuke[chamberpost] > limit) {
                    nuke[chamberpost] = 0;
                    chamberpost++;
                    nuke[chamberpost]++;
                }
                chamberpost = 0;
            }
        }
        FOR(p, 0, chambers)
            PF(nuke[p])
            printf("\n");
    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#define VI vector<int>

using namespace std;

int findOwner(VI &owner, int x) {
    if(owner[x] == x) {
        return x;
    }
    else {
        int result = findOwner(owner, owner[x]);
        owner[x] = result;
        return result;
    }
}

void solveQueryOne(const VI &S, VI &owner, int x, int y) {
    int X = findOwner(owner, x);
    int Y = findOwner(owner, y);
    if(X == Y) {
        printf("Invalid query!\n");
        return;
    }
    int bestDish1 = S[X], bestDish2 = S[Y];
    if(bestDish1 > bestDish2) {
        owner[Y] = X;
    } else if(bestDish1 < bestDish2){
        owner[X] = Y;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, Q;
        scanf("%d", &N);
        VI S(N+1), owner(N+1);
        for (int i = 1; i <= N; i++)
            scanf("%d", &S[i]);
        for(int i = 1; i <= N; i++)
            owner[i] = i;
        scanf("%d", &Q);
        while(Q--) {
            int type;
            scanf("%d", &type);
            if (type == 0) {
                int x, y;
                scanf("%d%d", &x, &y);
                solveQueryOne(S, owner, x, y);
            }
            else {
                int x;
                scanf("%d", &x);
                printf("%d\n", findOwner(owner, x));
            }
        }
    }
    return 0;
}

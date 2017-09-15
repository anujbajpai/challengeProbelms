#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, S, sum = 0;
        float mid;
        scanf("%d %d", &N, &S);
        int expense[N];
        for(int i = 0; i < N; i++) {
            scanf("%d", &expense[i]);
            sum += expense[i];
        }
        float sum_f = sum;
        mid = S/2;
        if(mid >= sum_f)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

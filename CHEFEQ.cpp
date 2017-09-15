#include <cstdio>
#include <vector>
#define MAX 100010

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, maxRepeat = 0;
        scanf("%d", &N);
        vector <int> A(MAX, 0);
        for(int i = 1; i <= N; i++) {
            int temp;
            scanf("%d", &temp);
            A[temp]++;
            if(maxRepeat < A[temp])
                maxRepeat = A[temp];
        }
        printf("%d\n", (N - maxRepeat));
    }
    return 0;
}

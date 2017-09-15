#include<cstdio>
#define MAX 100003

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    char str[MAX];
    while(T--) {
        scanf("%s", str);
        int N;
        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
        }
        printf("%s\n", str);
    }
    return 0;
}

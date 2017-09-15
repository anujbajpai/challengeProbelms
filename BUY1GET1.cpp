#include <iostream>
#include <cstdio>
#include <string>
#include <limits>
#define SF(a) scanf("%c", &a);
#define PF(a) printf("%c\n", a);
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define EFOR(i, a, b) for(int i = a; i<= b; i++)

using namespace std;

int main () {
    int test;
    scanf("%d", &test);
    int c, b[123], add, mul;
    while(test--) {
        string a;
         int totalCost = 0;
        cin>>a;
        EFOR(i, 0, 122)
            b[i] = 0;
        for (int i = 0; a[i] != '\0'; i++) {
            c = a[i];
            b[c]++;

        }
        EFOR(i, 65, 122) {
            if (b[i]) {
                mul = b[i] / 2;
                add = b[i] % 2;
                totalCost = totalCost + mul + add;
            }
        }
        printf("%d\n", totalCost);
    }
    return 0;
}

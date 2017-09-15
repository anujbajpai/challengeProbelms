#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int T;
    char C;
    scanf("%d%c", &T, &C);
    while(T--) {
        string S;
        int subCnt = 0, finalCnt = 0;
        getline(cin, S);
        for(int i = 0; S[i] != '\0'; i++) {
            if(!(i % 2)) {
                if (S[i] != '+')
                    subCnt++;
            }
            else {
                if (S[i] != '-')
                    subCnt++;
            }
            finalCnt++;
        }
        printf("%d\n", min((finalCnt - subCnt), subCnt));
    }
    return 0;
}

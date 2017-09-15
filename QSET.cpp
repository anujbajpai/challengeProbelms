#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void findAllPossibleSum(int N, vector<char> &storeSum, vector<bool> elements, int A[]) {
    for(int i = 1; i <= N; i++) {
        if(elements[i] == true) {
            vector<int> temp;
            temp.push_back(A[i]);
            //printf("%d ", A[i]);
            //printf("\n");
            for(vector<char>::iterator j = storeSum.begin(); j != storeSum.end(); j++) {
                //printf("%d ", *j+A[i]);
                temp.push_back(*j + A[i]);
            }
            int sizeOfTemp = temp.size();
            for(int k = 0; k < sizeOfTemp; k++) {
                storeSum.push_back(temp[k]);
            }
        }
    }
}

int main() {
    int N, M;
    char C;
    scanf("%d%d%c", &N, &M, &C);
    int A[N+1];
    for(int i = 1; i <= N; i++)
        scanf("%c", &A[i]);
    while(M--) {
        vector<int> Q(1);
        vector<char> storeSum;
        int T, L, R;
        scanf("%d%d%d", &T, &L, &R);
        Q.push_back(T);
        Q.push_back(L);
        Q.push_back(R);
        if(Q[1] == 1)
            A[Q[2]] = Q[3];
        else {
            vector<bool> elements(N+1, false);
            for(int x = L; x <= R; x++)
                elements[x] = true;
            findAllPossibleSum(N, storeSum, elements, A);
            vector<int>::iterator i;
            int Counter = 0;
           // for(vector<int>::iterator itr = storeSum.begin(); itr != storeSum.end(); itr++)
             //   printf("%d ", *itr);
            for(vector<char>::iterator itr = storeSum.begin(); itr != storeSum.end(); itr++) {
                if(*itr % 3 == 0)
                    Counter++;
            }
            printf("%d\n", Counter);

        }
    }


    return 0;
}

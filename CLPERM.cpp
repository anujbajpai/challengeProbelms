#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void findAllPossibleSum(int N, set<int> &storeSum, vector<bool> elements) {
    for(int i = 1; i <= N; i++) {
        if(elements[i] == true) {
            vector<int> temp;
            temp.push_back(i);
            for(set<int>::iterator j = storeSum.begin(); j != storeSum.end(); j++) {
                temp.push_back(*j + i);
            }
            int sizeOfTemp = temp.size();
            for(int k = 0; k < sizeOfTemp; k++) {
                storeSum.insert(temp[k]);
            }
        }
    }
}

int Count(set<int> storeSum) {
    int Countr = 1;
    for(set<int>::iterator itr = storeSum.begin(); itr != storeSum.end(); itr++) {
        if(*itr != Countr)
            break;
        else
            Countr++;
    }
    return Countr;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, K, missing;
        scanf("%d%d", &N, &K);
        vector<bool> elements(N+1, true);
        set<int> storeSum;
        if (K == 0){
            if((((N*(N+1)) / 2)+1) % 2 == 0)
                printf("Mom\n");
          else
                printf("Chef\n");
        }
        else {
            while(K--) {
                scanf("%d", &missing);
                elements[missing] = false;
            }
            findAllPossibleSum(N, storeSum, elements);
            int Counter = Count(storeSum);
            if(Counter % 2 == 0)
                printf("Mom\n");
            else
                printf("Chef\n");
        }
    }
    return 0;
}

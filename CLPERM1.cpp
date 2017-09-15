#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

void isAllPossible(ll N) {
    ll Sum = (N * (N + 1)) / 2;
    if((Sum + 1) % 2) {
        printf("Chef\n");
    } else {
        printf("Mom\n");
    }
}

ll firstImpossibleNumber(int K, vector<int> isMissing, ll N) {
    ll sum2 = 0, sum1, last;
    for(int k = 0; k < K; k++) {
        ll NUM = isMissing[k] - 1;
        sum1 = (NUM * (NUM + 1)) / 2;
        sum1 -= sum2;
        if(sum1 < isMissing[k]){
            return isMissing[k];
        }
        sum2 += isMissing[k];
    }
    last = isMissing[isMissing.size() - 1];
    ll remainSum = ((N * (N + 1)) - (last * (last + 1))) / 2;
    sum1 += remainSum;
    return sum1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int K;
        ll N;
        scanf("%lld%d", &N, &K);
        vector<int> isMissing;
        for(int i = 0; i < K; i++) {
            int x;
            scanf("%d", &x);
            isMissing.push_back(x);
        }
        if(!K) {
            isAllPossible(N);
        } else {
            sort(isMissing.begin(), isMissing.end());
            ll result = firstImpossibleNumber(K, isMissing, N);
            //printf("%lld", result);
            if(result > N) {
                result += 1;
            }
            if(result % 2 == 0)
                printf("Mom\n");
            else
                printf("Chef\n");
            }
    }
    return 0;
}

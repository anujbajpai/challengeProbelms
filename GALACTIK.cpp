#include <cstdio>
#include <vector>
#include <iostream>
#include <limits.h>
#define PF(x) printf("%d\n", x)


using namespace std;

typedef vector<int> VI;
typedef vector<pair<int, int> > VPI;

int findRpt(int child, VI &rpt) {
    if (rpt[child] == child)
        return child;
    rpt[child] = findRpt(rpt[child], rpt);
    return rpt[child];
}

void doUnion(int R1, int R2, int temp1, int temp2, VI cost, VI &rpt) {
    if (cost[R1] >= 0 && cost[R2] >= 0) {
        if (cost[R1] > cost[R2])
            rpt[R1] = rpt[temp2];
        else
            rpt[R2] = rpt[temp1];
    }
    else if (cost[R1] >= 0 && cost[R2] < 0) {
        rpt[R2] = rpt[temp1];
    }
    else if (cost[R1] < 0 && cost[R2] >= 0) {
        rpt[R1] = rpt[temp2];
    }
    else {
        rpt[R1] = rpt[temp2];
    }
}

void addSum(VI check, VI rpt, VI cost, int N, int minCost) {
    int sum = 0, flag = 0, cnt = 0;
    for (int i = 1; i <= N; i++) {
        int represent = findRpt(i, rpt);
        if (!check[represent]) {
            if (cost[represent] >= 0) {
                if (flag == 0) {
                    if(minCost == cost[represent]) {
                        flag = 1;
                        check[represent]++;
                        continue;
                    }
                }
                sum +=  minCost + cost[represent];
                check[represent]++;
            }
            else {
                cnt++;
                check[represent]++;
                if((cnt == 1 && flag == 1) || (cnt > 1)) {
                    sum = -1;
                    break;
                }
            }
        }
    }
    PF(sum);
}

int main() {
    int N, M, minCost = INT_MAX;
    scanf("%d%d", &N, &M);
    VPI sets;
    VI cost(N+1), rpt(N+1), check(N+1, 0);
    for(int i = 1; i <= N; i++)
        rpt[i] = i;
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        sets.push_back(make_pair(a, b));
    }
    for(int i = 1; i <= N; i++) {
        scanf("%d", &cost[i]);
        if ((cost[i] < minCost) && (cost[i] >= 0))
            minCost = cost[i];
    }
    for(int i = 0; i < M; i++) {
        int rpt1 = findRpt(sets[i].first, rpt);
        int rpt2 = findRpt(sets[i].second, rpt);
        doUnion(rpt1, rpt2, sets[i].first, sets[i].second, cost, rpt);
    }
    addSum(check, rpt, cost, N, minCost);
    return 0;
}

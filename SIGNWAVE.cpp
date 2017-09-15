#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

void addArray (vector<long long int> newA, vector<long long int> &Final) {
    if (Final.size() == 0) {
        for(int i = 0; i < newA.size(); i++)
            Final.push_back(newA[i]);
    }
    else {
        long long int C = 0;
        for( int i = 0; i < newA.size(); i++) {
            long long int sum = newA[i] + Final[i] + C;
            C = 0;
            Final[i] = sum % 10;
            sum = sum / 10;
            if (sum > 0) {
                C = sum;
            }
        }
        int temp = newA.size();
        while ( C > 0) {
            if (temp == Final.size()) {
                Final.push_back(C);
                C = 0;
            }
            else {
                C = Final[temp] + C;
                Final[temp++] = C % 10;
                C = C / 10;
            }
        }
    }
}

vector<long long int> powCalculate (int power) {
    vector<long long int> A;
    A.push_back(2);
    if (power > 1) {
        for (int i = 2; i <= power; i++) {
            long long int k = 0, C  = 0;
            for(vector<long long int>::iterator itr = A.begin(); itr != A.end(); itr++) {
                long long int ans = A[k] * 2 + C;
                C = 0;
                A[k] = ans % 10;
                ans = ans / 10;
                k++;
                if (ans > 0) {
                    if(k >= A.size()) {
                        A.push_back(ans);
                        break;
                    }
                    else
                        C = ans;
                }
            }
        }
    }
    return A;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int S, C, K;
        scanf("%d%d%d", &S, &C, &K);
        int countS = 0, countC = 0;
        if ( C == 0 ) {
            vector<long long int> B, result;
            if (S - K > 0) {
                for (int g = 1; g <= S - K; g++) {
                    B = powCalculate(g);
                    addArray(B, result);
                }
                long long int num = 3, cnt = 0;
                while(num) {
                    if (cnt == result.size()) {
                        result.push_back(num);
                        num = 0;
                    }
                    else {
                        num = result[cnt] + num;
                        result[cnt++] = num % 10;
                        num = num / 10;
                    }
                }
                for(int itr = result.size() - 1; itr >= 0 ; itr--)
                    cout<<result[itr];
                    cout<<endl;
            }
            else if (S == K && S > 0)
                cout<<3<<endl;
            else
                cout<<0<<endl;
        }
        else {
            if (S > 0 && S >= K) {
                int temp;
                countS = 3;
                for (int i = 1; i <= S - K; i++)
                    countS += pow(2, i);
                //printf("%d\n", countS);
            }
            if (C > 0 && K >= 1) {
                int temp;
                if (S < C) {
                    if ( K == 1) {
                        if (S == 0)
                            temp = 1;
                        else
                            temp = S;
                        for (int i = temp; i <= C; i++)
                            countC += pow(2, i);
                    }
                    else if (K <= S) {
                        countC = pow(2, (S - K + 1));
                    }
                    else
                        countC = 0;
                }
                else if (S > C) {
                    if (((S - K) < C) && (S >= K) )
                        countC = pow(2, (S - K + 1));
                }
                else {
                    if (S >= K)
                        countC = pow(2, (S - K + 1));
                }
            }
            int result = countC + countS;
            printf("%d\n", result);
        }

    }
    return 0;
}

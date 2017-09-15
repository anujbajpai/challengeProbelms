#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

void mul (long long int N, long long int P) {
    vector<long long int> A;
    if (P == 1)
        A.push_back(N);
    else {
        for (long long int i = 2; i <= P; i++) {
            long long int k = 0, C  = 0;
            for(vector<long long int>::iterator itr = A.begin(); itr != A.end(); itr++) {
                long long int ans = A[k] * N + C;
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
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        long long int type, boys = 0, girls = 0;
        char C;
        scanf("%lld%c", &type, &C);
        string s;
        getline(cin, s);
        for(long long int i = 0; s[i] != '\0'; i++ ) {
            long long int ascii = s[i];
            if(ascii == 66)
                boys++;
            else
                girls++;
        }
        vector<long long int> total(boys+girls), actual(boys+girls);
        long long int cost = 0;
        for(long long int i = 0; i < actual.size(); i++) {
            if(i%2)
                actual[i] = 0;
            else
                actual[i] = 1;
        }
        for(long long int i = 0; i < actual.size(); i++) {
            long long int temp = s[i];
            if(temp == 66)
                total[i] = 1;
            else
                total[i] = 0;
        }
        long long int cnt1 = 0, cnt2 = 0;
        vector<long long int> one, zero;
        for(long long int i = 0; i < actual.size(); i++) {
            if (total[i] != actual[i]) {
                if (total[i] != 1) {
                    zero.push_back(i);
                    cnt1++;
                }
                else {
                    one.push_back(i);
                    cnt2++;
                }
            }
        }
        if (cnt1 == 0 && cnt2 == 0)
            cost = 0;
        else {
            if (cnt1 == cnt2) {
                if (type == 0)
                    cost = cnt1;
                else {
                    for(long long int i = 0; i < one.size(); i++) {
                        if(one[i] > zero[i])
                            cost += mul((one[i] - zero[i]), type);
                        else
                            cost += mul((zero[i] - one[i]), type);
                    }
                }
            }
            else
                cost = -1;
        }
        for(long long int i = 0; i < actual.size(); i++) {
            if(i%2)
                actual[i] = 1;
            else
                actual[i] = 0;
        }
        long long int cnta1 = 0, cnta2 = 0, costa = 0;
        vector<long long int> onea, zeroa;
        for(long long int i = 0; i < actual.size(); i++) {
            if (total[i] != actual[i]) {
                if (total[i] != 1) {
                    zeroa.push_back(i);
                    cnta1++;
                }
                else {
                    onea.push_back(i);
                    cnta2++;
                }
            }
        }
        if (cnta1 == 0 && cnta2 == 0)
            costa = 0;
        else {
            if (cnta1 == cnta2) {
                if (type == 0)
                    costa = cnta1;
                else {
                    for(long long int i = 0; i < onea.size(); i++) {
                        if(onea[i] > zeroa[i])
                            costa += mul((onea[i] - zeroa[i]), type);
                        else
                            costa += mul((zeroa[i] - onea[i]), type);
                    }
                }
            }
            else
                costa = -1;
        }
        //cout<<coasta<<" "<<cost<<endl;

        if (costa == -1 && cost == -1) {
            cout<<-1<<endl;
        }
        else {
            if (costa == -1)
                cout<<cost<<endl;
            else if(cost == -1)
                cout<<costa<<endl;
            else if (costa < cost)
                cout<<costa<<endl;
            else
                cout<<cost<<endl;
        }
    }
    return 0;
}


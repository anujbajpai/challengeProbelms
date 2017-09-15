#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        long long int N, M, sum = 0, i = 0;
        cin>>N>>M;
        for(i; i <N-1; i++)
            sum +=pow(2,i);
        i += M;
        sum += pow(2,i);
        cout<<sum<<endl;
    }
    return 0;
}

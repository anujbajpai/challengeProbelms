#include <iostream>

using namespace std;

/*
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,b, res = 0, m = 0;
        cin>>n>>b;
        for(int i = n/b; i >= 0; i--) {
            res = (n-(b*i))*i;
            if(m < res)
                m = res;
        }
        cout<<m<<endl;
    }
    return 0;
}
*/
int main() {
    int t;
    cin>>t;
    while(t--) {
        long long int n,b;
        cin>>n>>b;
        long long int c = n/b;
        long long int d = c/2;
        long long int x = (n-((d+1)*b))*(d+1);
        long long int y = (n-(d*b))*(d);
        if(x > y)
            cout<<x;
        else
            cout<<y;
        cout<<endl;
    }
    return 0;
}

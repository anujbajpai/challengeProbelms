#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct trainer {
    int entry;
    int lecture;
    int sadlevel;
};

bool compare(trainer const& lhs, trainer const& rhs) {
    if(lhs.sadlevel != rhs.sadlevel)
        return lhs.sadlevel < rhs.sadlevel;
}

int main () {
    int t;
    cin>>t;
    while(t--) {
        int n,d,res = 0, total = 0;
        cin>>n>>d;
        vector<trainer> obj(n);
        vector<int> days(d);
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &obj[i].entry, &obj[i].lecture,&obj[i].sadlevel);
            res +=obj[i].lecture*obj[i].sadlevel;
        }
        sort(obj.begin(), obj.end(), &compare);
        for(int i = n-1; i >=0; i--) {
            int day_entry = obj[i].entry, lectures = 0;
            while(lectures < obj[i].lecture && day_entry <= d) {
                if(!days[day_entry-1]) {
                    days[day_entry-1] = i;
                    lectures++;
                    total += obj[i].sadlevel;
                }
                day_entry++;
            }
        }
        cout<<res-total<<endl;
    }

    return 0;
}














/*
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,d, store = 0, res = 0, total = 0;
        cin>>n>>d;
        vector<vector<int> > v;

        for(int i = 0; i < n; i++ ) {
            vector<int> vv;
            for(int j = 0; j < 3; j++) {
                int d;
                cin>>d;
                if(j == 2)
                    total+= d*vv[1];
                vv.push_back(d);
            }
            v.push_back(vv);
        }

        for(int i = 0; i < d; i++) {

            int  maxres = 0, flag = 0;
            for(int j = 0; j < n; j++) {

                if(v[j][0] <= (i+1) && v[j][1]> 0 && v[j][2] > maxres) {
                    maxres = v[j][2];
                    store = j;
                    flag = 1;
                }
            }
            if(flag){
                v[store][1]--;
                res += v[store][2];
            }
        }

        cout<<total-res<<endl;
    }
    return 0;
}*/

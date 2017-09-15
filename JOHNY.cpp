#include <iostream>


using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int siz;
        cin>>siz;
        int arr[siz+1];
        for(int i = 1; i <= siz; i++) {
            cin>>arr[i];
        }
        int key;
        cin>>key;
        int store = arr[key];
        for(int i = 1; i < siz; i++) {
            for(int j = i+1; j <= siz; j++) {
                if ( arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        for(int i = 1;i <= siz; i++ ) {
            if(arr[i] == store)
                cout<<i<<endl;
        }
    }
    return 0;
}

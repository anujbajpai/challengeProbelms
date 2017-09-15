#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main () {
    int t;
    char c;
    scanf("%d%c", &t, &c);
    //char space;
    //cin>>space;
    while(t--) {
        string s, buffer;
        int i = 0;
        getline(cin,s);
        while(s[i]) {
            if(s[i] == ' ') {
                if(buffer[0] >= 97 && buffer[0] <= 122){
                    printf("%c. ",toupper(buffer[0]));
                    //cout<<"efefefe"<<endl;
                }
                else
                    cout<<buffer[0]<<". ";
                buffer.clear();

            }
            else {
                buffer += s[i];
                //cout<<buffer<<" ";
            }
            i++;
        }
        if(buffer[0] >= 97 && buffer[0] <= 122)
            buffer[0] = toupper(buffer[0]);
        for(int j = 1; buffer[j] != '\0'; j++) {
            if(buffer[j] >= 65 && buffer[j] <= 90)
                buffer[j] = tolower(buffer[j]);
        }
        cout<<buffer;
        //buffer[0] = '\0';
        cout<<endl;
    }
    return 0;
}


#include <iostream>
#include <cstdio>

using namespace std;

int convert(int N) {
    int Count = 0;
    while(N != 1) {
        N >>= 1;
        Count++;
    }
    return Count;
}

int storeQuotient(int A[], int N)  {
    int k = 0;
    while(N) {
        A[k++] = N;
        N >>= 1;
    }
    return k;
}
int Search (int A[], int N, int Len) {
    int flag = 0, i;
    for(i = 0; i < Len; i++) {
        if(A[i] == N) {
            flag = 1;
            break;
        }
    }
    return (flag == 1) ? i : -1;
}

int main() {
    int Q, flag = 0;
    scanf("%d", &Q);
    while(Q--) {
        char str[4];
        scanf("%s", str);
        int x, y, black = 0, red = 0;
        if(str[1] != 'i') {
            scanf("%d%d", &x, &y);
            int C1 = 0, C2 = 0, a, arr[40], arr1[40];
            C1 = convert(x);
            C2 = convert(y);
            ((C1 & 1) == 0) ? black++ : red++;
            int L1 = storeQuotient(arr, x);
            int L2 = storeQuotient(arr1, y);
            ((C2 & 1) == 0) ? black++ : red++;
            int hey = 0, tempo;
            if(x < y) {
                while(hey < L1) {
                    tempo = Search(arr1, arr[hey], L2);
                    if(tempo != -1)
                        break;
                    hey++;
                }
            } else {
                while(hey < L2) {
                    tempo = Search(arr, arr1[hey], L1);
                    if(tempo != -1)
                        break;
                    hey++;
                }
            }
            int  total = hey + tempo - 1;
            if (black == 2) {
                    red += total / 2 + 1;
                black += total / 2;
            }
            else if(red == 2) {
                    black += total / 2 + 1;
                red += total / 2;
            }
            else {
                black += total / 2;
                red += total / 2;
            }
        }
        if (str[1] == 'i')
            flag++;
        else if (str[1] == 'r') {
            if(flag % 2 == 0)
                cout<<red<<endl;
            else
                cout<<black<<endl;
        }
        else if(str[1] == 'b') {
            if(flag % 2 == 0)
                cout<<black<<endl;
            else
                cout<<red<<endl;
        }
        else
            continue;
    }
    return 0;
 }

#include <iostream>
#include <cstdio>
#define MAX 100002
using namespace std;

int arr[MAX], add = 0, finalindex;

int main () {
    int elements, querysize, value;
    char enter, m;
    scanf("%d%d", &elements, &querysize);
    for (int i = 1; i <= elements; i++)
        scanf("%d", &arr[i]);
    while (querysize--) {
        scanf("%c%c%d", &enter, &m, &value);
        if (m == 'R') {
            finalindex = value + add;
            if (finalindex < 1)
                finalindex += elements;
            else if (finalindex > elements)
                finalindex -= elements;
            printf ("%d\n", arr[finalindex]);
        }
        else if(m == 'A') {
            add -= value;
            if (add < 1)
                add = add + elements;
        }else {
            add += value;
            if (add > elements)
                add -= elements;
        }
    }
    return 0;
}

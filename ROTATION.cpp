#include <iostream>
#include <cstdio>
#define MAX 100002
using namespace std;

int arr[MAX];

void fun1(int arr3[], int kk1, int len7) {
    int c1 = 1 - kk1, i = 1, w;
    if (c1 < 1)
        c1 += len7;
    int cont7 = 0;
    int f7 = 1;
    int devi = arr3[i];
    while (cont7 < len7) {
        w = arr3[c1];
        arr3[c1] = devi;
        cont7++;
        if (c1 == f7) {
            i += 1;
            f7 = i;
            if (i < 1)
                i += len7;
            c1 = i - kk1;
            if(c1 < 1)
                c1 = c1 + len7;
            w = arr3[i];
        }
        else {
            c1 -= kk1;
            if (c1 < 1)
                c1 += len7;
        }
        devi = w;
    }
}

void func(int arr2[], int kk, int lenght) {
    int i = 1, dev = arr2[i], f = 1, cont = 0, t, c = 1 + kk;
    while(cont < lenght) {
      t=arr2[c];
      arr2[c] = dev;
      cont++;
      if (c == f) {
        i += 1;
        f = i;
        if ( i > lenght)
            i -= lenght;
        c = i + kk;
        t = arr2[i];
    }
      else {
        c += kk;
        if (c > lenght)
            c -= lenght;
      }
      dev = t;
    }
}

void rightshift(int arr1[], int k1, int len) {
    int l = 1, t, d, dev = arr1[l], cnt = 0;
    d = l + k1;
    if (d > len)
        d -= len;
    while (cnt < len) {
        t = arr1[d];
        cnt++;
        arr1[d] = dev;
        d += k1;
        if (d > len)
            d -= len;
        dev = t;
    }
}

int leftshift(int arr2[], int k2, int len1) {
    int y, j = 1, cnt1 = 0, c, dev = arr2[j];
    c = j - k2;
    if (c < 1) {
        c += len1;
    }
    while (cnt1 < len1){
        y = arr2[c];
        cnt1++;
        arr2[c] = dev;
        c -= k2;
        if (c < 1) {
            c += len1;
        }
        dev = y;
    }
}

int main () {
    int elements, querysize, value;
    char enter, m;
    scanf("%d%d", &elements, &querysize);
    for (int i = 1; i <= elements; i++)
        scanf("%d", &arr[i]);
    while (querysize--) {
        scanf("%c%c%d", &enter, &m, &value);
        if (m == 'R')
            printf ("%d\n", arr[value]);
        else if(m == 'A') {
            if (elements % 2 == 0)
                func(arr, value, elements);
            else
                rightshift(arr, value, elements);
        }else {
            if (elements % 2 == 0)
                fun1(arr, value, elements);
            else
                leftshift(arr, value, elements);
        }
    }
    return 0;
}

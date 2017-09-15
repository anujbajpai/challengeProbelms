#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;

int main () {
    int len1, Max, len2, len3, c = 150001, interlist[c], finallist[c], j= 0;
    scanf("%d%d%d", &len1, &len2, &len3);
    int list1[len1], list2[len2], list3[len3];
    for (int i = 0; i < len1; i++)
        scanf("%d", &list1[i]);
    for (int i = 0; i < len2; i++)
        scanf("%d", &list2[i]);
    for (int i = 0; i < len3; i++)
        scanf("%d", &list3[i]);
    for (int i = 0; i < c; i++)
        interlist[i] = 0;
    for (int i = 0; i < len1; i++)
        interlist[list1[i]]++;
    for (int i = 0; i < len2; i++)
        interlist[list2[i]]++;
    for (int i = 0; i < len3; i++)
        interlist[list3[i]]++;
    if (list1[len1-1] <= list2[len2 -1])
        Max = list2[len2-1];
    else
        Max = list1[len1-1];
    if (Max  <= list3[len3-1])
        Max = list3[len3-1];
    for (int i = 0; i <= Max; i++) {
        if (interlist[i] > 1)
            finallist[j++] = i;
    }
    for (int i = 0; i <= j-1; i++)
        printf("%d\n", finallist[i]);
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
        int totaljobs;
        scanf("%d", &totaljobs);
        int arr[totaljobs];
        for (int i = 1; i <= totaljobs; i++)
            arr[i] = 0;
        int jobsdone;
        scanf("%d", &jobsdone);
        int jobsdoneindex[jobsdone], j = 1;
        int c = jobsdone;
        while (c--)
            scanf("%d", &jobsdoneindex[j++]);
        for (int k = 1; k <= jobsdone; k++)
            arr[jobsdoneindex[k]] = 1;
        int cnt = 0, m = 1, n = 1, arr1[totaljobs], arr2[totaljobs];
        for (int i = 1; i <= totaljobs; i++) {
            if (arr[i] == 0) {
                cnt++;
                if(cnt % 2 != 0)
                    arr1[m++] = i;
                else
                    arr2[n++] = i;
            }
        }
        for (int p = 1; p < m; p++)
            printf("%d ", arr1[p]);
        printf("\n");
        for (int p = 1; p < n; p ++)
            printf ("%d ", arr2[p]);
        printf("\n");
    }
    return 0;
}

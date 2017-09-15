#include<iostream>
#include<cstdio>

using namespace std;

int main () {
    float tbal;
    int wdw;
    scanf("%d %f",&wdw, &tbal);
    if(wdw % 5==0&&tbal-wdw-0.50>=0.00&&wdw!=0)
        printf("%0.2f",tbal-wdw-0.50);
    else
        printf("%0.2f",tbal);
    return 0;
}

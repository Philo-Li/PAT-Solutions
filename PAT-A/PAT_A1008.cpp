#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <queue>
using namespace std;
//A1008 Elevator
const int maxn = 100010;
const int MOVEUP = 6, MOVEDOWN = 4, STAY = 5;
int main(){
    int N, time = 0;
    scanf("%d", &N);
    int a[maxn] = {0};
    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
        if(a[i] > a[i - 1]) time = time + MOVEUP * (a[i] - a[i - 1]);
        else time = time + MOVEDOWN * (a[i - 1] - a[i]);
        time += STAY;
    }

    printf("%d", time);
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
// A 1055 The World's Richest
struct Person{
    char name[10];
    int age;
    int worth;
}P[100010];

bool cmp(Person a, Person b){
    if(a.worth != b.worth) return a.worth > b.worth;
    else if(a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%s %d %d", P[i].name, &P[i].age, &P[i].worth);
    }
    sort(P, P + N, cmp);
    bool flag = false;
    for(int i = 0; i < K; i++){
        int M, Amin, Amax;
        scanf("%d %d %d", &M, &Amin, &Amax);
        printf("Case #%d:\n", i + 1);
        for(int i = 0; i < N; i++){
            if(P[i].age >= Amin && P[i].age <= Amax){
                printf("%s %d %d\n", P[i].name, P[i].age, P[i].worth);
                flag = true; M--;
            }
            if( M == 0) break;
        }
        if(!flag) { printf("None\n"); }
        flag = false;
    }

    system("pause");
    return 0;
}


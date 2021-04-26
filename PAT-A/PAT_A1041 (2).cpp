#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
struct student{
    long long num_1; //准考证号
    int num_2;  //试机座位
    int num_3;  //考试座位
    student(){}
};

int main(){
    int N = 0, M = 0, check[1001] = {0}; 
    char str[30];
    scanf("%d", &N);
    student S[1001];
    for(int i = 0; i < N; i++){
        scanf("%lld %d %d", &S[i].num_1, &S[i].num_2, &S[i].num_3);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &check[i]);
        for(int j = 0; j < N; j++){
            if(S[j].num_2 == check[i]){
                printf("%lld %d\n", S[j].num_1, S[j].num_3);
            }
        }
    }
    system("pause");
    return 0;
}
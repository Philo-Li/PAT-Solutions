#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
//A1012 The Best Rank
struct Student{
    int id;
    int score[4];
}S[2010];
char course[4] = { 'A', 'C', 'M', 'E'};
int Rank[1000000][4] = {0};
//Rank不能用小写rank，一定要在main函数前初始化。
//妈的就是这个折腾了好久
int now;
bool cmp(Student a, Student b){
    return a.score[now] > b.score[now];
}
//Rank 要记录ID啊
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    //[1]: A_score [2]:C_score [3]:M_score [4]:E_score
    //[5] A_Rank, [6] C_Rank [7] M_Rank [8]E_Rank
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &S[i].id, &S[i].score[1], &S[i].score[2], &S[i].score[3]);
        S[i].score[0] = S[i].score[1] + S[i].score[2] + S[i].score[3];
    }
    for(now = 0; now < 4; now++){
        //对不同科目分别排名
        sort(S, S + N, cmp);
        Rank[S[0].id][now] = 1;
        for(int j = 1; j < N; j++){
            if(S[j - 1].score[now] == S[j].score[now]) Rank[S[j].id][now] = Rank[S[j - 1].id][now];
            else Rank[S[j].id][now] = j + 1; //排名记录
        }
    }
    int query;
    for(int i = 0; i < M; i++){
        scanf("%d", &query);
        if(Rank[query][0] != 0) { //find
            int sub = 0;
            for(int k = 0; k < 4; k++ ){ //find min Rank
                if(Rank[query][sub] > Rank[query][k]) {
                    sub = k;
                }
            }
            printf("%d %c\n", Rank[query][sub], course[sub]);
        }
        else printf("N/A\n");
    }
    system("pause");
    return 0;
}

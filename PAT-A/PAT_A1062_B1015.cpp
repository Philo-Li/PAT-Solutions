#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Person{
    char id[9];
    int virtue;
    int talent;
    int rank;
}P[100000];
int L, H;
bool cmp(Person a, Person b){
    int total_a = a.virtue + a.talent;
    int total_b = b.virtue + b.talent;
    if(a.rank == b.rank) {
        if(total_a != total_b) return total_a > total_b;
        else if(a.virtue != b.virtue) return a.virtue > b.virtue;
        else return strcmp(a.id, b.id) < 0;
    }
    else return a.rank < b.rank;
    
}
int main(){
    int N, M = 0;
    scanf("%d %d %d", &N, &L, &H);
    for(int i = 0; i < N; i++){
        int virtue, talent;
        char id[9];
        scanf("%s %d %d", id, &virtue, &talent);
        if(virtue >= L && talent >= L){
            strcpy(P[M].id, id);
            P[M].virtue = virtue;
            P[M].talent = talent;
            if(virtue >= H && talent >= H) P[M].rank = 1; //sages
            else if(virtue >= H && talent < H) P[M].rank = 2; //nobleman
            else if(virtue < H && talent < H && virtue >= talent) P[M].rank = 3; //fool man
            else P[M].rank = 4;//small man
            M++;
        }
    }
    sort(P, P + M, cmp);
    printf("%d\n", M);
    for(int i = 0; i < M; i++){
        printf("%s %d %d\n", P[i].id, P[i].virtue, P[i].talent);
    }
    system("pause");
    return 0;
}
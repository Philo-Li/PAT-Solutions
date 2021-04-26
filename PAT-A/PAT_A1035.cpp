#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//replace 1 (one) by @, 0 (zero) by %, l by L, and O by o
//There is 1 account and no account is modified
int main(){
    int N, cnt = 0, num[1000];
    char map[][2] = {{'1','@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'} };
    char id[1000][11], password[1000][11];
    bool flag = false;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s %s", id[i], password[i]);
        for(int j = 0; j < strlen(password[i]); j++){
            for(int k = 0; k < 4; k++){
                if(password[i][j] == map[k][0]){
                    password[i][j] = map[k][1];
                    flag = true;
                }
            }
        }
        if(flag){
            num[cnt++] = i; flag = false;
        }
    }
    if(cnt == 0) {
        if(N == 1) printf("There is %d account ", N);
        else printf("There are %d accounts ", N);
        printf("and no account is modified\n");
    }
    else{
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; i++){
            printf("%s %s\n", id[num[i]], password[num[i]]);
        }
    }
    system("pause");
    return 0;
}
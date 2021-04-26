#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    char S[100][257], word[257], key[257];
    int N, cnt = 0;
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i ++){
        gets(S[i]);
    }
    for(int i = 0; i < strlen(S[0]); i++) word[i] = S[0][i];
    for(int i = 1; i < N; i++){
        int len = min_len(strlen(word), strlen(S[i]));
        for(int j = 0; j < len; j++){
            for(int k = 0; k < len; k++){
                while(S[i][k] == word[k]){
                    key[cnt++] = word[k];
                }
            }
        }
    }

    system("pause");
    return 0;
}
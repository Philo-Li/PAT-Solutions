#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

int Shuffle(int S[], int move[]){
    int temp[54] = {0}, j = 0;
    for(int i = 0; i < 54; i++){
        temp[i] = S[i];
    }
    for(int i = 0; i < 54; i++){
        j = move[i] - 1;
        S[j] = temp[i];
    }
    return 0;
}

int main(){
    char map[5] = {'S', 'H', 'C', 'D', 'J'};
    int S[54] = {0};
    int N, move[54] = {0};
    scanf("%d", &N);
    for(int i = 0, k = 0; i < 54; i++){
        if(i % 13 == 0 && i != 0) k++;  // create the Set
        S[i] = i % 13 + 1 + k * 100; // 101 = S1, 201 = H1, 301 = C1 etc.
        scanf("%d", &move[i]);
    }
    for(int i = 0; i < N; i++){
        Shuffle(S, move);  //Shuffle the cards
    }
    for(int i = 0; i < 54; i++){
        int k = S[i] / 100;
        printf("%c%d", map[k], S[i] % 100);
        if(i + 1 < 54) printf(" ");
        // if((i + 1) % 10 == 0) printf("\n");
    }
    system("pause");
    return 0;
}
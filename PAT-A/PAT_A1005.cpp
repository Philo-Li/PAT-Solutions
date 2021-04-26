#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    char N[101];
    char map[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int sum = 0, r[10], cnt = 0;
    scanf("%s", N);
    for(int i = 0; i < strlen(N); i++){
        sum = sum + (int)N[i] - 48;
    }
    do{
        r[cnt++] = sum % 10;
        sum = sum / 10;
    }while(sum != 0);
    for(int i = cnt - 1; i >= 0; i--){
        printf("%s", map[r[i]]);
        if(i > 0) printf(" ");
    }
    system("pause");
    return 0;
}
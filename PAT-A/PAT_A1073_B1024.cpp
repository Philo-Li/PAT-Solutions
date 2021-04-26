#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//+1.23400E-03 -> 0.00123400
//-1.2E+10 -> -12000000000
//+0E+0 -> 0
//+3.13E+002 -> 313
int main(){
    char N[10010], R[10010];
    int cnt = 0, E = 0;
    bool flag = true;
    scanf("%s", N);
    
    for(int i = 1; i < strlen(N); i++){
        if(N[i] != '.' && N[i] != 'E'){
            R[cnt++] = N[i];
        }
        if(N[i] == 'E'){
            i++;
            if(N[i] == '-') {flag = false; i++;}
            else i++;
            for(int j = i; j < strlen(N); j++){
                int temp = (int)(N[j] - 48);
                E = E + temp;
                if(j + 1 < strlen(N)) E = E * 10;
            }
            break;
        }
    }
    if(cnt == 1 && E == 0) printf("%c\n", R[0]); 
    else if(E == 0){
        if(N[0] == '-') printf("-");
        for(int i = 0; i < cnt; i++){
            printf("%c", R[i]);
            if(i == 0) printf(".");
        }
    }
    else if(!flag){
        if(N[0] == '-') printf("-");
        printf("0");
        if(E!=0) printf(".");
        for(int j = 0; j < E - 1; j++) printf("0");
        for(int i = 0; i < cnt; i++){
            printf("%c", R[i]);
            if(E == 0 && i == 0) printf(".");
        }
    }
    else{
        if(N[0] == '-') printf("-");
        for(int i = 0; i < cnt; i++){
            printf("%c", R[i]);
            if(i == E && i + 1 < cnt) printf(".");
        }
        if( E >= cnt){
            for(int i = 0; i < E - cnt + 1; i++){
                printf("0");
            }
        }
    }
    system("pause");
    return 0;
}
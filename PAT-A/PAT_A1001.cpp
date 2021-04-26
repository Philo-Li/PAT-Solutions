#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    int a, b, s[1001] = {0};
    scanf("%d %d", &a, &b);
    a = a + b;
    if(a == 0) printf("0\n");
    else {
        if( a < 0) {
            printf("-");
            a = - a;
        }
        int cnt = 0;
        do{
            s[cnt++] = a % 10;
            a = a / 10;
        }while(a != 0);
        for(int i = cnt - 1; i >= 0; i--){
            printf("%d", s[i]);
            if(i % 3 == 0 && i != 0) printf(",");
        }
    }

    system("pause");
    return 0;
}
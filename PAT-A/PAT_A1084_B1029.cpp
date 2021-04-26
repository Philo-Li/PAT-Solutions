#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
// A 1084_B 1029 Broken Keyboard
// 7_This_is_a_test
// _hs_s_a_es
int hashs(char a){
    if(a >= 'a' && a <= 'z') return (int)(a - 'a');
    else if(a >= 'A' && a <= 'Z') return (int)(a - 'A');
    else if(a == '_') return 36;
    else return (int)(a - '0') + 26;
}
int main(){
    char s1[100], s2[100];
    bool hashtables1[37] = {false}, hashtables2[37] = {false};
    scanf("%s %s", s1, s2);
    for(int i = 0; i < strlen(s1); i++){
        int h = hashs(s1[i]);
        hashtables1[h] = true;
    }
     for(int i = 0; i < strlen(s2); i++){
        int h = hashs(s2[i]);
        hashtables2[h] = true;
    }
    bool print[37] = {false};
    for(int i = 0; i < strlen(s1); i++){
        int h = hashs(s1[i]);
        if(hashtables1[h] == true && hashtables2[h] == false){
            if(print[h] == false){
                char a = s1[i];
                if(a >= 'a' && a <= 'z') a = a - 'a' + 'A';
                printf("%c", a);
                print[h] = true;
            }
        }
    }
    system("pause");
    return 0;
}


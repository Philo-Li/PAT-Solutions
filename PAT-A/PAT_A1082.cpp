#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define change(x)  ((int)(x) - 48)
//被搞死
int main(){
    char N[11];
    char map1[][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char map2[][10] = {"", "Shi", "Bai", "Qian"};
    char map3[][10] = {"Wan", "Yi"};
    scanf("%s", N);
    int len = strlen(N), cnt = 0;
    bool output = false, meet_0 = false;
    if(N[0] == '-'){
        for(int i = 0; i < len; i++) N[i] = N[i+1];
        len--;
        printf("fu ");
        output = true;
    }
    //int temp = (int)N[0] - 48;
    if(len == 1) { //when N has 1 digit
        if(N[0] == '0') printf("%s", map1[0]);
        else{
            printf("%s", map1[change(N[0])]); 
        }
    }
    else if(len == 2) { // when N has 2 digits
        if(N[0] != '1') printf("%s %s", map1[change(N[0])], map2[1]);
        else printf("%s", map2[1]);
        if(N[1] != '0') printf(" %s", map1[change(N[1])]);
    }
    else{ // when N has more than 2 digits
        for(int i = 0, j = len; i < len; i++, j--){
            if(i == 0){ // output the first dight
                printf("%s", map1[change(N[i])]);
            }
            else{ //output the rest digits with specific format 
                if(change(N[i]) != 0){ //when second time not 0
                    if(cnt != 0){
                        printf(" %s", map1[0]); //output 0
                        cnt = 0;
                    }
                    printf(" %s", map1[change(N[i])]);
                }
                else if(change(N[i]) == 0){ //first meet 0
                    cnt++;
                }
            }
            if(cnt == 0 && (j - 1) % 4 != 0) {
                printf(" %s", map2[(j - 1) % 4]);
            }
            if(j == 9) printf(" %s", map3[1]);
            if(j == 5) printf(" %s", map3[0]);
        }
    }
    system("pause");
    return 0;
}
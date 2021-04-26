#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
//A1100_B1044 Mars Numbers
#include <string>
#include <cctype>
using namespace std;
string a[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct",
"nov", "dec" };
string b[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy",
"lok", "mer", "jou" };
//我原本就是按照这个想法做的，但是，没找好规律直接下手真的太难了
void func1(string s) {
    int len = s.length(), num = 0;
    for (int i = 0; i < len; i++)
        num = num * 10 + (s[i] - '0');
    if (num / 13) {
        cout << b[num / 13];
        if (num % 13) cout << ' ' << a[num % 13];
    } else {
        cout << a[num % 13];
    }
}
void func2(string s) {
    int len = s.length(), num = 0;
    if (len == 4) {
        cout << 0;
        return;
    }
    else if (len == 3) {
        for (int i = 1; i <= 12; i++) {
            if (s == a[i]) {
                cout << i;
                return;
            }
            if (s == b[i]) {
                cout << i * 13;
                return;
            }
        }
    }
    else {
        string temp1 = s.substr(0, 3), temp2 = s.substr(4, 3);
        for (int i = 1; i <= 12; i++) {
            if (temp1 == b[i]) num += i * 13;
            if (temp2 == a[i]) num += i;
        }
        cout << num;
    }
    return;
}
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (isdigit(s[0]))
            func1(s);
        else
            func2(s);
        cout << endl;
    }
    return 0;
}
// 打表的好麻烦
// string mars1[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
// string mars2[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
// int n;
// string numTostr[170];
// map<string, int> strTonum;
// void init(){
//   for(int i = 0; i < 13; i++){
//     numTostr[i] = mars1[i];//个位：0-12， 十位：0
//     strTonum[mars1[i]] = i;
//     numTostr[i * 13] = mars2[i];//个位：0 十位：0-12
//     strTonum[mars2[i]] = i * 13;
//   }
//   for(int i = 1; i < 13; i++){
//     for(int j = 1; j < 13; j++){
//       string str = mars2[i] + ' ' + mars1[j];
//       numTostr[i * 13 + j] = str;
//       strTonum[str] = i * 13 + j;
//     }
//   }
// }
// int main(){
//   init();
//   scanf("%d%*c", &n);
//   string temp;
//   // getchar();
//   for(int i = 0; i < n; i++){
//     int num = 0;
//     getline(cin, temp);
//     if(temp[0] >= '0' && temp[0] <= '9'){//earth number
//       for(int i = 0; i < temp.length(); i++){
//         num = num * 10 + (temp[i] - '0');
//       }
//       cout << numTostr[num] << endl;
//     }else{// mars number
//       cout << strTonum[temp]<< endl;
//     }
//   }
//   return 0;
// }

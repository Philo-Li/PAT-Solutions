#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
//A1050 String Subtraction

int main(){
    string str, key;
    getline(cin, str);
    getline(cin, key);
    int len = str.length();
    for(int i = 0; i < len; i++){
      if(key.find(str[i]) == string::npos){
        printf("%c", str[i]);
      }
    }
    return 0;
}

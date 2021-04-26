// #include <string>
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//   string str;
//   vector<string> ans;
//   getline(cin, str);
//   for(int i = 0; i < str.length();i++){
//     string temp;
//     while(i < str.length() && str[i] != ' ') temp += str[i++];
//     ans.push_back(temp);
//   }
//   for(int i = ans.size() - 1; i >= 0; i--){
//     cout << ans[i];
//     if(i != 0) cout << ' ';
//   }
//   return 0;
// }


#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char str[81][81];
    int cnt = 0;
    while( scanf("%s", str[cnt]) != EOF){
        cnt++;
    }
    for(int i = cnt - 1; i >= 0; i--){
        printf("%s", str[i]);
        if(i > 0) printf(" ");
    }
    printf("\n");
    return 0;
}

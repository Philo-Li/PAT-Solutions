#include <string>
#include <map>
#include <iostream>
using namespace std;
int main(){
  string A;
  map<char, int> m;
  cin >> A;
  for(int i = 0; i < A.length(); i++){
    m[A[i]]++;
  }
  for(auto it = m.begin(); it != m.end(); it++){
    cout << it->first << ":" << it->second << endl;
  }
  return 0;
}

// 方法2：
// #include <iostream>
// #include <cstdio>
// #include <string>
// using namespace std;
// int main(){
//     string A;
//     int num[10] = {0};
//     cin >> A;
//     for(int i = 0; i < A.length(); i++){
//         int k = A[i] - 48;
//         num[k]++;
//     }
//     for(int i = 0; i < 10; i++){
//         if(num[i] > 0){
//             printf("%d:%d\n", i, num[i]);
//         }
//     }
//     return 0;
// }

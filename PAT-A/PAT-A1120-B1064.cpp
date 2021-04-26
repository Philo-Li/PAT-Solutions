#include <string>
#include <iostream>
#include <map>
using namespace std;
int main(){
  int n, cnt = 0;
  string temp;
  map<int, int> m;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int sum = 0;
    cin >> temp;
    for(int j = 0; j < temp.length(); j++) sum = sum + (int)(temp[j] - '0');
    m[sum]++;
  }
  printf("%d\n", m.size());
  for(auto it = m.begin(); it != m.end(); it++, cnt++){
    if(cnt != 0) printf(" ");
    printf("%d", it->first);
  }
  return 0;
}

// #include <cstdio>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// int main() {
//   int n, num = 0;
//   bool h[50] = {false};
//   scanf("%d", &n);
//   for(int i = 0, temp, sum; i < n; i++, sum = 0){
//     scanf("%d", &temp);
//     while(temp!=0){
//       sum = sum + temp % 10;
//       temp /= 10;
//     }
//     if(h[sum] == false){
//       num++;
//       h[sum] = true;
//     }
//   }
//   printf("%d\n", num);
//   int flag = 0;
//   for(int i = 1; i < 50; i++){
//     if(h[i]) {
//       if(flag != 0) printf(" ");
//       printf("%d", i);
//       flag++;
//     }
//   }
//   return 0;
// }

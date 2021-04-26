#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
//A1044 Shopping in Mars -2nd
int main() {//这题根本用不着二分法
  int n, m, d[100010], minsum = 0x7FFFFFFF, tempsum = 0;
  map<int, int> ans;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++){
    scanf("%d", &d[i]);
  }
  for(int i = 1, j = 1; j <= n; j++){
    tempsum += d[j];
    while(tempsum >= m){
      if(tempsum < minsum && tempsum >= m){
        minsum = tempsum;
        ans.clear();
        ans[i] = j;
      }else if(tempsum == minsum) ans[i] = j;
      tempsum -= d[i++];
    }
  }
  for(auto it = ans.begin(); it != ans.end(); it++){
    cout << it->first << "-" << it->second << endl;
  }
  return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> sum, resultArr;
// int n, m;
// void Func(int i, int &j, int &tempsum) {
//     int left = i, right = n;
//     while(left < right) {
//         int mid = (left + right) / 2;
//         if(sum[mid] - sum[i-1] >= m)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     j = right;
//     tempsum = sum[j] - sum[i-1];
// }
// int main() {
//     scanf("%d%d", &n, &m);
//     sum.resize(n+1);
//     for(int i = 1; i <= n; i++) {
//         scanf("%d", &sum[i]);
//         sum[i] += sum[i-1];
//     }
//     int minans = sum[n];
//     for(int i = 1; i <= n; i++) {
//         int j, tempsum;
//         Func(i, j, tempsum);
//         if(tempsum > minans) continue;
//         if(tempsum >= m) {
//             if(tempsum < minans) {
//                 resultArr.clear();
//                 minans = tempsum;
//             }
//             resultArr.push_back(i);
//             resultArr.push_back(j);
//         }
//     }
//     for(int i = 0; i < resultArr.size(); i += 2)
//         printf("%d-%d\n", resultArr[i], resultArr[i+1]);
//     return 0;
// }

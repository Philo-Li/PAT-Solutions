#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
//A1057 Stack
const int maxn = 100010, sqrN = 316;
int n, t, block[sqrN] = {0}, table[maxn] = {0};
string str;
stack<int> st;
void Push(int x){
  st.push(x);
  block[x / sqrN]++;
  table[x]++;
}
void Pop(){
  int x = st.top();
  st.pop();
  block[x / sqrN]--;
  table[x]--;
  printf("%d\n", x);
}
void PeekMedian(int k){
  int sum = 0, index = 0;
  while(sum + block[index] < k) sum += block[index++];
  int num = index * sqrN;
  while(sum + table[num] < k) sum += table[num++];
  printf("%d\n", num);
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    getchar();
    cin >> str;
    if((str == "Pop" || str == "PeekMedian") && st.empty()){
      printf("Invalid\n");
      continue;
    }
    if(str == "Pop"){
      Pop();
    }else if(str == "Push"){
      scanf(" %d", &t);
      Push(t);
    }else if(str == "PeekMedian"){
      int k = (st.size() + 1) / 2;
      PeekMedian(k);
    }
  }
  return 0;
}
//利用树状数组
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <string>
// #include <iostream>
// #include <stack>
// #include <algorithm>
// using namespace std;
// //A1057 Stack
// #define lowbit(i) ((i) & -(i))
// const int maxn = 100010, sqrN = 316;
// int n, t, c[maxn] = {0};
// string str;
// stack<int> st;
// void upDate(int x, int v){
//   for(int i = x; i < maxn; i += lowbit(i)){
//     c[i] += v;
//   }
// }
// int getSum(int x){
//   int sum = 0;
//   for(int i = x; i > 0; i -= lowbit(i)){
//     sum += c[i];
//   }
//   return sum;
// }
// void PeekMedian(){
//   int l = 1, r = maxn, mid, k = (st.size() + 1) / 2;
//   while(l < r){
//     mid = (l + r) / 2;
//     if(getSum(mid) >= k) r = mid;
//     else l = mid + 1;
//   }
//   printf("%d\n", l);
// }
// int main() {
//   scanf("%d", &n);
//   for(int i = 0; i < n; i++){
//     getchar();
//     cin >> str;
//     if((str == "Pop" || str == "PeekMedian") && st.empty()){
//       printf("Invalid\n");
//       continue;
//     }
//     if(str == "Pop"){
//       printf("%d\n", st.top());
//       upDate(st.top(), -1);
//       st.pop();
//     }else if(str == "Push"){
//       scanf(" %d", &t);
//       st.push(t);
//       upDate(t, 1);
//     }else if(str == "PeekMedian"){
//       PeekMedian();
//     }
//   }
//   return 0;
// }

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;
//A1010 Radix
long long n1, n2, tag, d, low, high, mid, ans = -1;
int maxe = 2;
string str1, str2;
int getnum(char a){ return isdigit(a) ? a - '0' : a - 'a' + 10; }
long long change(string a, int d){
  long long temp = 0;
  for(int i = 0; i < a.length(); i++){
    temp = temp * d + getnum(a[i]);
  }
  return temp;
}
int main() {
  cin >> str1 >> str2 >> tag >> d;
  if(tag == 2) swap(str1, str2);
  n1 = change(str1, d);
  low = getnum(*max_element(str2.begin(), str2.end())) + 1;//下界是最小数字+1
  high = max(low, n1);
  while(low <= high){
    mid = (low + high) / 2;
    n2 = change(str2, mid);
    // printf("n1:%lld n2:%lld left:%lld mid:%lld right:%lld\n", n1, n2, low, mid, high);
    if(n1 < n2 || n2 < 0) high = mid - 1;
    else if(n1 == n2){
      ans = mid; break;
    }
    else low = mid + 1;
  }
  if(ans != -1) printf("%lld\n", ans);
  else printf("Impossible\n");
  return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <cstring>
// #include <cstdio>
// #include <iostream>
// #include <string>
// #include <cctype>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// //A1010 Radix
// long long convert(string n, long long radix) {
//     long long sum = 0;
//     int index = 0, temp = 0;
//     for (auto it = n.rbegin(); it != n.rend(); it++) {
//         temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
//         sum += temp * pow(radix, index++);
//     }
//     return sum;
// }
// long long find_radix(string n, long long num) {
//     char it = *max_element(n.begin(), n.end());
//     long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;//+1
//     long long high = max(num, low);
//     while (low <= high) {//等号
//         long long mid = (low + high) / 2;
//         long long t = convert(n, mid);//如果n是mid进制，转为十进制
//         if (t < 0 || t > num) high = mid - 1;//十进制的n比num大
//         //说明进制太大，上界变小
//         else if (t == num) return mid;
//         //如果十进制的n比num小，则说明进制太小，下界变大
//         else low = mid + 1;
//     }
//     return -1;
// }
// int main() {
//     string n1, n2;
//     long long tag = 0, radix = 0, result_radix;
//     cin >> n1 >> n2 >> tag >> radix;
//     result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
//     if (result_radix != -1) {
//         printf("%lld", result_radix);
//     } else {
//         printf("Impossible");
//     }
//     return 0;
// }
//
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
//A1108 Finding Average B1054 求平均值
int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf",temp);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++) {
            if(a[j] != b[j]) flag = 1;
        }
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(cnt > 1) {
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
    // printf("The average of %d numbers is ", cnt);//注意number 和 numbers
    // if(cnt == 0) printf("Undefined\n");
    // else printf("%.2lf\n", sum / cnt);
    return 0;
}
// 有一个测试点没过。。。
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <string>
// #include <cctype>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// // B1054 求平均值
// int main(){
//   double sum = 0.0;
//   int n, validNum = 0;
//   scanf("%d", &n);
//   getchar();
//   for(int i = 0; i < n; i++){
//     string temp, s, tempcp;
//     int hasdot = 0, valid = 1, idx = 0;
//     cin >> temp;
//     tempcp = temp;
//     if(temp[0] == '-') temp.erase(temp.begin());
//     int len = temp.length();
//     for(int j = 0; j < len; j++){
//       if((!isdigit(temp[j]) && temp[j] != '.') || hasdot > 1){
//         valid = 0;
//         break;
//       }
//       if(temp[j] == '.'){
//         hasdot++; idx = j;
//       }
//       if(isdigit(temp[j]) || temp[j] == '.'){
//         s+=temp[j];
//       }
//     }
//     if(valid == 1 && hasdot == 1 && (idx < s.length() - 3 || idx > s.length() - 2)) valid = 0;
//     if(valid){
//       double a = stod(tempcp);
//       if(a < -1000 || a > 1000) valid = 0;
//     }
//     if(valid == 0){
//       cout << "ERROR: " << tempcp << " is not a legal number" << endl;
//     }else{
//       sum += stod(tempcp); validNum++;
//     }
//   }
//   if(validNum == 1) {
//       printf("The average of 1 number is %.2lf", sum);
//   } else if(validNum > 1) {
//       printf("The average of %d numbers is %.2lf", validNum, sum / validNum);
//   } else {
//       printf("The average of 0 numbers is Undefined");
//   }
//   return 0;
// }

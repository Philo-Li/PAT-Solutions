#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    int N, T1[3], T2[3];//T1:Signin_Time, T2:Signout_Time
    int early[2], late[2];//early:{id, time}, late:{id, time}
    char P[10001][16];
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s %d:%d:%d %d:%d:%d", P[i], &T1[0], &T1[1],&T1[2], &T2[0], &T2[1], &T2[2]);
        int Time_in = T1[0]* 3600 +T1[1] * 60 + T1[0];
        int Time_out = T2[0]* 3600 +T2[1] * 60 + T2[0];
        if(i == 0){
            early[0] = i; early[1] = Time_in;
            late[0] = i; late[1] = Time_out;
        }
        else{
            if(early[1] > Time_in){
                early[0] = i; early[1] = Time_in;
            }
            if(late[1] < Time_out){
                late[0] = i; late[1] = Time_out;
            }
        }
    }
    printf("%s %s\n", P[early[0]], P[late[0]]);
    system("pause");
    return 0;
}

// 2nd
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <string>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// //A1006 Sign In and Sign Out
// int main() {
//   int n, mintime = 24 * 3600, maxtime = -1;
//   string ans1, ans2, id;
//   scanf("%d", &n);
//   for(int i = 0; i < n; i++){
//     int hh1, mm1, ss1, hh2, mm2, ss2;
//     cin >> id;
//     scanf("%d:%d:%d %d:%d:%d", &hh1, &mm1, &ss1, &hh2, &mm2, &ss2);
//     int temp1 = hh1 * 3600 + mm2 * 60 + ss1, temp2 = hh2 * 3600 + mm2 * 60 + ss2;
//     if(mintime > temp1){
//       mintime = temp1;
//       ans1 = id;
//     }
//     if(maxtime < temp2){
//       maxtime = temp2;
//       ans2 = id;
//     }
//   }
//   cout << ans1 << " " << ans2 << endl;
//   return 0;
// }

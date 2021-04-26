#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main() {
  int m, n, s, flag = 0;
  string temp;
  map<string, int> h;
  scanf("%d%d%d", &m, &n, &s);
  int next = s;
  for(int i = 1; i <= m; i++){
    cin >> temp;
    if(i == next){
      if(h.find(temp) == h.end()){
        h[temp] = 1;
        cout << temp << endl;
        next += n;
        flag = 1;
      } else next++;
    }
  }
  if(flag == 0) cout << "Keep going..." << endl;
  return 0;
}


// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// using namespace std;
// int main(){
//   int m, n, s, cnt = 0, j = 0;
//   string temp;
//   vector<string> ans;
//   map<string, int> mm;
//   cin >> m >> n >> s;
//   getchar();
//   while(cnt++ < m){
//     getline(cin, temp);
//     if(cnt >= s){
//       if(j == 0){
//         if(mm.find(temp) == mm.end()){
//           ans.push_back(temp);
//           mm[temp] = 1;
//         }
//         else j--;
//       }
//       j = (j + 1) % n;
//     }
//   }
//   for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
//   if(ans.size() == 0) cout << "Keep going..." << endl;
//   return 0;
// }

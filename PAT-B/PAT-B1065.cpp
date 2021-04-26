// #include <cstdio>
// #include <map>
// #include <set>
// using namespace std;
// int main() {
//   int n, m, id1, id2;
//   map<int, int> couple;
//   set<int> ans;
//   scanf("%d", &n);
//   for(int i = 0; i < n; i++){
//     scanf("%d %d", &id1, &id2);
//     couple[id1] = id2;
//     couple[id2] = id1;
//   }
//   scanf("%d", &m);
//   for(int i = 0; i < m; i++){
//     scanf("%d", &id1);
//     id2 = couple[id1];
//     // 新来的客人在此派对中找到了对象，将对方名字从名单中抹去，否则将其加入名单
//     if(!ans.empty() && ans.find(id2) != ans.end()) ans.erase(ans.find(id2));
//     else ans.insert(id1);
//   }
//   printf("%d\n", ans.size());
//   for(auto it = ans.begin(); it != ans.end(); it++){
//     if(it != ans.begin()) printf(" ");
//     printf("%05d", *it);
//   }
//   return 0;
// }

#include <cstdio>
#include <map>
#include <set>
using namespace std;
int main(){
  int n, m, id1, id2;
  map<int, int> couple, present;
  set<int> ans;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &id1, &id2);
    couple[id1] = id2;
    couple[id2] = id1;
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d", &id1);
    present[id1] = 1; // 记录每个出现的客人编号
  }
  for(auto it = present.begin(); it != present.end(); it++){
    id1 = it->first;
    id2 = couple[id1];
    if(couple.find(id1) == couple.end() || !present[id2]) ans.insert(id1);//客人没有对象或者对象没来就加入清单
  }
  printf("%d\n", ans.size());
  for(auto it = ans.begin(); it != ans.end(); it++){
    if(it != ans.begin()) printf(" ");
    printf("%05d", *it);
  }
  return 0;
}

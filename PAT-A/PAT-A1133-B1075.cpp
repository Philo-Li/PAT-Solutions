// #include <vector>
// #include <cstdio>
// using namespace std;
// struct Node{
//   int address, data, next;
// }LNode[100010];
// int main(){
//   vector<int> first, second, last;
//   int now, n, k, t;
//   scanf("%d %d %d", &now, &n, &k);
//   for(int i = 0; i < n; i++){
//     scanf("%d", &t);
//     LNode[t].address = t;
//     scanf("%d %d", &LNode[t].data, &LNode[t].next);
//   }
//   while(now != -1){
//     if(LNode[now].data < 0)first.push_back(now);
//     else if(LNode[now].data > k) last.push_back(now);
//     else second.push_back(now);
//     now = LNode[now].next;
//   }
//   for(int i = 0; i < second.size(); i++) first.push_back(second[i]);
//   for(int i = 0; i < last.size(); i++) first.push_back(last[i]);
//   for(int i = 0; i < first.size(); i++){
//     if(i == first.size() - 1) printf("%05d %d -1", first[i], LNode[first[i]].address);
//     else printf("%05d %d %05d\n", first[i], LNode[first[i]].address, first[i + 1]);
//   }
//   return 0;
// }

#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int A[100010], D[100010], n, k, pos, now, next, temp;
  vector<int> first, second, last;
  scanf("%d %d %d", &pos, &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d %d %d",&now, &temp, &next);
    A[now] = next;
    D[now] = temp;
  }
  while(pos != -1){
    if(D[pos] < 0) first.push_back(pos);
    else if(D[pos] > k) last.push_back(pos);
    else second.push_back(pos);
    pos = A[pos];
  }
  for(int i = 0; i < second.size(); i++) first.push_back(second[i]);
  for(int i = 0; i < last.size(); i++) first.push_back(last[i]);
  for(int i = 0; i < first.size(); i++){
    if(i == first.size() - 1) printf("%05d %d -1", first[i], D[first[i]]);
    else printf("%05d %d %05d\n", first[i], D[first[i]], first[i + 1]);
  }
  return 0;
}

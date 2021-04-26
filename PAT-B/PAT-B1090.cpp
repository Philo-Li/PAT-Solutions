#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 100000;
int main(){
  int N, M, x, y;
  vector<int> G[maxn];
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for(int i = 0; i < M; i++){
    int k, id, valid = 1;
    set<int> s;
    cin >> k;
    for(int j = 0; j < k; j++){
      cin >> id;
      for(int l = 0; valid == 1 && l < G[id].size(); l++){
        if(s.find(G[id][l]) != s.end()) valid = 0;
      }
      s.insert(id);
    }
    if(valid == 0) cout << "No\n";
    else cout << "Yes\n";
  }
  return 0;
}

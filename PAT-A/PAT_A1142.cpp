#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
//A1142 Maximal Clique
int n, m, q, k, G[210][210];
bool isclique(vector<int> temp){
  for(int j = 0; j < temp.size(); j++){
    for(int p = j + 1; p < temp.size(); p++){
      if(G[temp[j]][temp[p]] == 0){ return false; }
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    G[a][b] = G[b][a] = 1;
  }
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    vector<int> temp;
    int t, hash[210] = {0};
    bool flagclique = true, flagmaxclique = false;
    scanf("%d",&k);
    for(int j = 0; j < k; j++){
      scanf("%d", &t);
      temp.push_back(t);
      hash[t] = 1;
    }
    flagclique = isclique(temp);
    if(flagclique == true){
      for(int j = 1; j <= n; j++){
        if(hash[j] == 0){
          temp.push_back(j);
          flagmaxclique = isclique(temp);
          temp.erase(temp.end() - 1);
          if(flagmaxclique == true){
            printf("Not Maximal\n");
            break;
          }
        }
      }
    }
    if(flagmaxclique == false && flagclique == true) printf("Yes\n");
    else if(flagclique == false) printf("Not a Clique\n");
  }
  return 0;
}

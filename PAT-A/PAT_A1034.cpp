#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
//A1034 Head of a Gang
const int maxn = 2010;
map<int, string> intToString;
map<string, int> stringToInt, Gang;
int G[maxn][maxn] = {{0}}, weight[maxn] = {0};
int n, k, numperson = 0;
bool visit[maxn] = {false};
void dfs(int nowvisit, int& head, int& numMember, int& totalValue){
  numMember++;
  visit[nowvisit] = true;
  if(weight[nowvisit] > weight[head]) head = nowvisit;
  for(int i = 0; i < numperson; i++){
    if(G[nowvisit][i] > 0){
      totalValue += G[nowvisit][i];
      G[nowvisit][i] = G[i][nowvisit] = 0;
      if(visit[i] == false){
        dfs(i, head, numMember, totalValue);
      }
    }
  }
}
int change(string a){
  if(stringToInt.find(a) != stringToInt.end()){
    return stringToInt[a];
  }else{
    stringToInt[a] = numperson;
    intToString[numperson] = a;
    return numperson++;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    string a, b;
    int w;
    cin >> a >> b >> w;
    int a1 = change(a), b1 = change(b);
    G[a1][b1] += w;
    G[b1][a1] += w;
    weight[a1] += w;
    weight[b1] += w;
  }
  for(int i = 0; i < numperson; i++){
    if(visit[i] == false){
      int head = i, numMember = 0, totalValue = 0;
      dfs(i, head, numMember, totalValue);
      if(numMember > 2 && totalValue > k){
        Gang[intToString[head]] = numMember;
      }
    }
  }
  cout << Gang.size() << endl;
  map<string, int>::iterator it;
  for(it = Gang.begin(); it != Gang.end(); it++){
    cout << it->first << " " << it->second << endl;
  }
  return 0;
}

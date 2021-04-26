#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;
struct School{
  double score = 0;
  int cnt = 0, sum;
  string name;
}S[100010];
bool cmp(School a, School b){
  if(a.sum != b.sum) return a.sum > b.sum;
  else if(a.cnt != b.cnt) return a.cnt < b.cnt;
  else return a.name < b.name;
}
int main(){
  int n, t, score, cnt = 0;
  char tag;
  string sch;
  map<string, int> m;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    cin >> tag >> t >> score >> sch;
    for(int j = 0; j < sch.length(); j++){
      if(isupper(sch[j])) sch[j] = tolower(sch[j]);
    }
    if(m.find(sch) == m.end()){
      S[cnt].name = sch;
      m[sch] = cnt++;
    }
    if(tag == 'B') S[m[sch]].score += 1.0 * score / 1.5;
    else if(tag == 'A') S[m[sch]].score += 1.0 * score;
    else S[m[sch]].score += 1.5 * score;
    S[m[sch]].cnt++;
  }
  for(int i = 0; i < cnt; i++) S[i].sum = (int)S[i].score;
  sort(S, S + cnt, cmp);
  printf("%d\n", cnt);
  for(int i = 0, r = 0; i < cnt; i++){
    if(i > 0 && S[i].sum != S[i-1].sum) r = i;
    cout << r + 1 << " " + S[i].name;
    printf(" %d %d\n", S[i].sum, S[i].cnt);
  }
  return 0;
}

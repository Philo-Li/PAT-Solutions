#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
//A1056 Mice and Rice
int weight[1001] = {0}, np, ng;
queue <int> race;
struct mouse{
  int w;
  int r;
}mouse[1001];
int main(){
  scanf("%d%d", &np, &ng);
  for(int i = 0; i < np; i++){
    scanf("%d", &mouse[i].w);
  }
  for(int i = 0; i < np; i++){
    int temp;
    scanf("%d", &temp);
    race.push(temp);
  }
  int maxw = race.front(), len = np, group;
  while(len != 1){
    group = (len % ng == 0 ? len / ng : len / ng + 1);
    for(int i = 0; i < group; i++){
      maxw = race.front();
      for(int cnt = 0; cnt < ng; cnt++, len--){
        if(len == 0) break;
        if(mouse[maxw].w < mouse[race.front()].w) maxw = race.front();
        mouse[race.front()].r = group + 1;
        race.pop();
      }
      race.push(maxw);
    }
    len = race.size();
  }
  mouse[race.front()].r = 1;
  race.pop();
  for(int i = 0; i < np; i++){
    if(i != 0) printf(" ");
    printf("%d", mouse[i].r);
  }
  return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//A1091 Acute Stroke
const int maxm = 1286, maxn = 128, maxl = 60;
int m, n, l, t, ans = 0;
int X[] = {0, 0, 0, 0, 1, -1};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {1, -1, 0, 0, 0, 0};
int pixmap[maxm][maxn][maxl];
bool inq[maxm][maxn][maxl] = {{{false}}};
struct Node{
  int x, y, z;
}node;

bool judge(int x, int y, int z){
  if(x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0) return false;
  if(pixmap[x][y][z] == 0 || inq[x][y][z] == true) return false;
  return true;
}

int BFS(int x, int y, int z){
  queue <Node> Q;
  int cnt = 0;
  // if(judge(x, y, z)) cnt++;
  node.x = x, node.y = y, node.z = z;
  Q.push(node);
  inq[x][y][z] = true;
  while(!Q.empty()){
    Node top = Q.front();
    Q.pop();
    cnt++;
    for(int i = 0; i < 6; i++){
      int newx = top.x + X[i];
      int newy = top.y + Y[i];
      int newz = top.z + Z[i];
      if(judge(newx, newy, newz)){
        node.x = newx, node.y = newy, node.z = newz;
        Q.push(node);
        inq[newx][newy][newz] = true;
      }
    }
  }
  if(cnt >= t) return cnt;
  else return 0;
}
int main() {
  scanf("%d%d%d%d", &m, &n, &l, &t);
  for(int i = 0; i < l; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < n; k++){
        scanf("%d", &pixmap[j][k][i]);
      }
    }
  }
  for(int z = 0; z < l; z++){
    for(int x = 0; x < m; x++){
      for(int y = 0; y < n; y++){
        if(pixmap[x][y][z] == 1 && inq[x][y][z] == false){
          ans += BFS(x, y, z);
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}

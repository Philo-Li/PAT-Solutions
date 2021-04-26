#include <cstdio>
int main(){
  int n, m, a, b, x, temp[505];
  scanf("%d %d %d %d %d", &m, &n, &a, &b, &x);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &temp[j]);
      if(temp[j] >= a && temp[j] <= b) temp[j] = x;
    }
    for(int j = 0; j < n; j++){
      if(j != 0) printf(" ");
      printf("%03d", temp[j]);
    }
    printf("\n");
  }
  return 0;
}

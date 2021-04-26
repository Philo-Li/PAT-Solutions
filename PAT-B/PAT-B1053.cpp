#include <cstdio>
int main(){
  int N, D, possible_vacant = 0, vacant = 0;
  double e, temp;
  scanf("%d %lf %d", &N, &e, &D);
  for(int i = 0; i < N; i++){
    int k, cnt = 0;
    scanf("%d", &k);
    for(int j = 0; j < k; j++){
      scanf("%lf", &temp);
      if(temp < e) cnt++;
    }
    if(cnt * 2 > k){
      if(k > D) vacant ++;
      else possible_vacant ++;
    }
  }
  printf("%.1f%% %.1f%%", 100.0 * possible_vacant / N, 100.0 * vacant / N);
  return 0;
}

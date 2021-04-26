#include <cstdio>
#include <algorithm>
using namespace std;
int N, S1[110], S2[110];
bool issame(int a[], int b[]){
  int i = 0;
  while(i < N && a[i] == b[i]) i++;
  return i == N;
}
void mergesort(){
  bool flag = false;
  for(int step = 2; !flag && step / 2 < N; step *= 2){
    if(issame(S1, S2) == true) flag = true;
    for(int i = 0; i < N; i+=step){
      sort(S1 + i, S1 + min(i + step, N));
    }
  }
}
int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++){ scanf("%d", &S1[i]); }
  for(int i = 0; i < N; i++){ scanf("%d", &S2[i]); }
  int i, j;
  for (i = 0; i < N - 1 && S2[i] <= S2[i + 1]; i++);
  for (j = i + 1; S1[j] == S2[j] && j < N; j++);
  if (j == N) {
    printf("Insertion Sort\n");
    sort(S1, S1 + i + 2);
  }else{
    printf("Merge Sort\n");
    mergesort();
  }
  for(int i = 0; i < N; i++){
    if(i != 0) printf(" ");
    printf("%d", S1[i]);
  }
  return 0;
}

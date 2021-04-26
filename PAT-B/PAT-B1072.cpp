#include <iostream>
#include <string>
using namespace std;
int main(){
  int N, M, check[10010] = {0}, item, total_stu = 0, total_item = 0;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    cin >> item;
    check[item] = 1;
  }
  for(int i = 0; i < N; i++){
    string name;
    int k, cnt = 0;
    cin >> name >> k;
    for(int j = 0; j < k; j++){
      cin >> item;
      if(check[item] == 1){
        if(cnt == 0) cout << name << ":";
        printf(" %04d", item);
        cnt++;
      }
    }
    if(cnt > 0) printf("\n");
    total_stu = (cnt > 0) ? total_stu + 1 : total_stu;
    total_item += cnt;
  }
  printf("%d %d\n", total_stu, total_item);
  return 0;
}

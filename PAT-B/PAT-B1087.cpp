# include <iostream>
# include <map>
using namespace std;
int main(){
  int n, cnt = 0;
  map <int, int> m;
  cin >> n;
  for(int i = 1; i <= n; i++){
    int key = i / 2 + i / 3 + i / 5;
    m[key]++;
    if(m[key] == 1) cnt++;
  }
  cout << cnt;
  return 0;
}

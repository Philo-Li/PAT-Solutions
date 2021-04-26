#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
  int N, Z = 0, cnt = 0, weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
  char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
  cin >> N;
  for(int i = 0; i < N; i++, Z = 0){
    string id;
    bool valid = true;
    cin >> id;
    for(int j = 0; valid && j < id.length() - 1; j++){
      if(isdigit(id[j]) == false) valid = false;
      if(valid) Z = Z + weight[j] * (int)(id[j] - '0');
    }
    Z = Z % 11;
    if(id[17] != M[Z]) valid = false;
    if(valid == false){
      cnt++;
      cout << id <<endl;
    }
  }
  if(cnt == 0) cout << "All passed" << endl;
  return 0;
}

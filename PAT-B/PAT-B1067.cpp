#include <iostream>
#include <string>
using namespace std;
int main(){
  int N, cnt = 0;
  string password, temp;
  cin >> password >> N;
  getchar();
  getline(cin, temp);
  while(temp != "#"){
    cnt++;
    if(temp == password){
      cout << "Welcome in" << endl;
      break;
    } else{
      cout << "Wrong password: " << temp << endl;
      if(cnt >= N){
        cout << "Account locked" << endl;
        break;
      }
    }
    getline(cin, temp);
  }
  return 0;
}

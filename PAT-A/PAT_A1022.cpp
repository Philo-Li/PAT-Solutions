#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
//A1022 Digital Library
int id, n, m;
string title, author, keyword, publisher, year, temp;
// map<string, set<int> > titlemap, authormap, keywordmap, publishermap, yearmap;
map<string, set<int> > allmap[6];
void findbook (int tag, string q){
  int flag = 0;
  for(auto it = allmap[tag][q].begin(); it != allmap[tag][q].end(); it++){
    printf("%07d\n", *it);//易错
    flag = 1;
  }
  if(!flag) printf("Not Found\n");
}
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &id);
    getchar();//不能少
    for(int j = 1; j <= 5; j++){
      if(j == 3){
        while(cin >> temp){
          allmap[j][temp].insert(id);
          char c = getchar();
          if(c == '\n') break;
        }
      }else{
        getline(cin, temp);
        allmap[j][temp].insert(id);
      }
    }
  }
  scanf("%d", &m);
  int tag;
  for(int i = 0; i < m; i++){
    scanf("%d: ", &tag);
    getline(cin, temp);
    cout << tag << ": " << temp << endl;
    findbook(tag, temp);
  }
  return 0;
}

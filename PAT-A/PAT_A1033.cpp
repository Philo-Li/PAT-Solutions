#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
//A1033 To Fill or Not to Fill
//能到达的加油站中优先去第一个价格比当前价格低的加油站，加的油能到就行
//没有更低价格的就先加满油，再选择能到的中价格最便宜的
struct Station{
   double price;//价格
   double x;//与起点的距离
}station[505];
bool cmp(Station a, Station b){
  return a.x < b.x;
}
const int INF = 1000000000;
int main(){
    double capcity, distance, miles, money = 0.0;
    int sta_num;
    scanf("%lf %lf %lf %d", &capcity, &distance, &miles, &sta_num);
    double MAX = capcity * miles;
    for(int i = 0; i < sta_num; i++){
      scanf("%lf %lf", &station[i].price, &station[i].x);
    }
    station[sta_num].price = 0.0;     //设置终点价格为0
    station[sta_num].x = distance;    //设置终点距离
    sort(station, station + sta_num, cmp); //所有加油站按距离远近排序
    if(station[0].x != 0) {           //出发点没有加油站，返回最远距离0
      printf("The maximum travel distance = 0.00\n");
      return 0;
    }
    int now = 0;          //当前加油站编号
    double nowTank = 0;   //目前油箱剩余油量
    while(now < sta_num){  //每次循环都会选出下一个需要到达的加油站
      int k = -1;         //最低油价的加油站编号
      double priceMin = INF;    //最低油价
      // 寻找能到达的加油站里价格最低的
      for(int i = now + 1; i <= sta_num && station[i].x - station[now].x <= MAX; i++){
        if(station[i].price < priceMin){
          priceMin = station[i].price;
          k = i;
          if(priceMin < station[now].price) break;
        }
      }
      if(k == -1) break; //满油找不到任何一个加油站，退出循环
      double need = (station[k].x - station[now].x) / miles; //到达指定加油站需要加的油量
      if(priceMin < station[now].price){ //油价低于当前的，加一点油能到就行
        if(nowTank < need){
          money += (need - nowTank) * station[now].price;
          nowTank = 0;
        } else nowTank -= need;
      } else{  //油价不比当前的低，加满，先去了再看
        money += (capcity - nowTank) * station[now].price;
        nowTank = capcity - need;
      }
      now = k; //到达加油站
    }//到达终点或者永远到不了退出循环
    if(now == sta_num) printf("%.2f\n", money);
    else printf("The maximum travel distance = %.2f\n", station[now].x + MAX);
    return 0;
}

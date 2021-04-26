#include <cstdio>
#include <cmath>
using namespace std;
long int gcd(long int a, long int b){ return b == 0 ? abs(a) : gcd(b, a % b);}
void print(long int &a, long int &b){
  if(a < 0) printf("(");
  long int temp = gcd(a, b);
  a /= temp;
  b /= temp;
  if(a % b == 0) printf("%ld", a/b);
  else{
    if(a / b != 0) printf("%ld ", a/b);
    printf("%ld/%ld", (a / b < 0) ? (- a % b) : a % b , b);
  }
  if(a < 0) printf(")");
}
int main(){
  long int a1, b1, a2, b2, c1, c2;
  char op[] = {'+', '-', '*', '/'};
  scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
  for(int i = 0; i < 4; i++){
    print(a1, b1);
    printf(" %c ", op[i]);
    print(a2, b2);
    printf(" = ");
    if(i == 0){
      c1 = a1 * b2 + a2 * b1;
      c2 = b1 * b2;
    }else if(i == 1){
      c1 = a1 * b2 - a2 * b1;
      c2 = b1 * b2;
    }else if(i == 2){
      c1 = a1 * a2;
      c2 = b1 * b2;
    }else if(i == 3){
      if(a2 == 0) printf("Inf");
      else{
        c1 = a1 * b2;
        c2 = abs(b1 * a2);
        if(a2 < 0) c1 = - c1;
      }
    }
    if(i !=3 || (i == 3 && a2 != 0) ) print(c1, c2);
    printf("\n");
  }
  return 0;
}

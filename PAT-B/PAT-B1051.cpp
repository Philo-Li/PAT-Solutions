#include <cstdio>
#include <cmath>
int main(){
  double R1, P1, R2, P2, A, B;
  scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
  A = R1 * R2 * (cos(P1) * cos(P2) - sin(P1) * sin(P2));
  B = R1 * R2 * (cos(P1) * sin(P2) + sin(P1) * cos(P2));
  if(A < 0 && A > -0.005) printf("0.00");
  else printf("%.2f", A);
  if(B < 0 && B > -0.005) printf("+0.00i\n");
  else if(B >= 0) printf("+%.2fi\n", B);
  else printf("%.2fi\n", B);
  return 0;
}

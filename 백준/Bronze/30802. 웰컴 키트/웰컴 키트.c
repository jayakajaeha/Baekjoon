#include <stdio.h>

int main() {
  int n, t, p;
  int s[6];
  scanf("%d", &n);
  for (int i = 0; i < 6; i++) {
    scanf("%d", &s[i]);
  }
  scanf("%d %d", &t, &p);
  int shirtNum = 0;
  for (int i = 0; i < 6; i++) {
    shirtNum += (s[i] / t + 1 - (s[i] % t == 0));
  }
  printf("%d\n%d %d", shirtNum, n / p, n % p);
  return 0;
}
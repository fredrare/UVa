#include <stdio.h>
int main(){
  int a,b;
  while(scanf("%i %i",&a,&b)!=EOF){
    printf("%i\n",a>=b?a:b);
  }
  return 0;
}

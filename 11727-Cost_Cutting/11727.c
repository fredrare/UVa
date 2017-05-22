#include <stdio.h>
int main(){
  int n,max,min,sum,x,i=0,j;
  scanf("%i",&n);
  while(i++<n){
    j=2;
    scanf("%i",&min);
    sum=max=min;
    while(j--){
      scanf("%i",&x);
      x>max?max=x:x<min?min=x:1;
      sum+=x;
    }
    printf("Case %i: %i\n",i,sum-max-min);
  }
  return 0;
}

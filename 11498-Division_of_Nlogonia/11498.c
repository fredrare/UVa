#include <stdio.h>
int main(){
  int n,ox,oy,x,y;
  while(scanf("%i",&n),n){
    scanf("%i %i",&ox,&oy);
    while(n--){
      scanf("%i %i",&x,&y);
      if(x==ox || y==oy)
        printf("divisa\n");
      else{
        printf("%s%s\n",y>oy?"N":"S",x>ox?"E":"O");
      }
    }
  }
  return 0;
}

#include <stdio.h>
int main(){
  int n;
  long int a,b;
  scanf("%i",&n);
  while(n--){
    scanf("%li%li",&a,&b);
    printf("%c\n",a==b?'=':a>b?'>':'<');
  }
  return 0;
}

#include <cstdio>
#include <unordered_map>
int main(){
  int n,k,m,sum,i;
  char c;
  scanf("%i",&n);
  while(n--){
    std::unordered_map<char,int> mapa;
    sum=0;
    scanf("\n%i",&k);
    while(k--){
      scanf("\n%c",&c);
      scanf(" %i",&mapa[c]);
    }
    scanf("\n%i\n",&m);
    while(m--){
      while(scanf("%c",&c),c!='\n'){
        sum+=mapa[c];
      }
    }
    printf("%.2f$\n",sum*1.0/100);
  }
  return 0;
}

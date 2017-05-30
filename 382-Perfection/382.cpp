#include <iostream>
#include <cstdio>
#include <string>
std::string fill(int n){
  std::string str=std::to_string(n);
  while(str.length()<5)
    str=" "+str;
  return str;
}
int main(){
  int n,i,sum,max;
  std::string str="PERFECTION OUTPUT\n";
  while(scanf("%i",&n),n){
    sum=i=1;
    max=n;
    if(n!=1){
      while(++i<max){
        if(n%i==0){
          max=n/i;
          sum+=i+(max!=i?max:0);
        }
      }
      str+=fill(n)+"  ";
      if(sum==n)
        str+="PERFECT\n";
      else if(sum<n)
        str+="DEFICIENT\n";
      else
        str+="ABUNDANT\n";
    } else
      str+="    1  DEFICIENT\n";
  }
  std::ios_base::sync_with_stdio(false);
  str+="END OF OUTPUT\n";
  std::cout<<str;
  return 0;
}

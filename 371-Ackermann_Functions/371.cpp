#include <iostream>
#include <cstdio>
#include <cstdlib>
#define limit 1000000
int *map=(int*)calloc(limit,sizeof(int));
int func(long int n){
  if(n==1)
    return 1;
  int ans;
  if(n%2)
    n=3*n+1;
  else
    n=n/2;
  if(n>=limit)
    return func(n)+1;
  if(map[n]==0)
    map[n]=func(n);
  ans=map[n]+1;
  return ans;
}
int main(){
  long int i,j;
  int max,sum,maxi;
  std::string str="";
  while(scanf("%li%li",&i,&j),i||j){
    max=-1;
    if(i>j)
      i^=j^=i^=j;
    str+="Between "+
      std::to_string(i)+" and "+std::to_string(j)+
      ", ";
    while(i<=j){
      sum=i==1?3+i++:func(i++);
      if(sum>max){
        max=sum;
        maxi=i;
      }
    }
    str+=std::to_string(maxi-1)+
      " generates the longest sequence of "+
      std::to_string(max-1)+" values.\n";
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}

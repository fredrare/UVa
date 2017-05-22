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
  map[n]?1:map[n]=func(n);
  ans=map[n]+1;
  return ans;
}
int main(){
  long int i,j;
  int max,sum;
  std::string str="";
  while(scanf("%li%li",&i,&j)!=EOF){
    max=-1;
    str=str+std::to_string(i)+" "+std::to_string(j)+" ";
    if(i>j){
      i^=j;
      j^=i;
      i^=j;
    }
    while(i<=j){
      sum=func(i++);
      sum>max?max=sum:1;
    }
    str=str+std::to_string(max)+"\n";
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}

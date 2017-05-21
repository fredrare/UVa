#include <cstdio>
#include <iostream>
#include <cstdlib>
int main(){
  int n,*val,*numbers,i,pos;
  bool ans;
  std::string str="";
  while(scanf("%i",&n)!=EOF){
    val=(int*)calloc(n,sizeof(int));
    numbers=(int*)malloc((n-1)*sizeof(int));
    ans=true;
    scanf("%i",&numbers[0]);
    for(i=1;i<n;i++){
      scanf("%i",&numbers[i]);
      pos=abs(numbers[i-1]-numbers[i]);
      if(pos<n && pos)
        val[pos-1]++;
      else
        ans=false;
    }
    free(numbers);
    for(i=0;i<n-1 && ans;i++)
      ans=val[i]==1&&ans;
    str=str+(ans?"J":"Not j")+"olly\n";
    free(val);
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}

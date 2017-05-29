#include <iostream>
#include <cstdio>
#include <cstring>
int main(){
  int val,temp,i,len;
  char l[20];
  std::string str="";
  while(scanf("\n%s",l)!=EOF){
    temp=0;
    len=strlen(l);
    for(i=0;i<len;i++){
      switch(l[i]){
        case 'B':case 'F':case 'P':case 'V':
          val=1;
          break;
        case 'C':case 'G':case 'J':case 'K':case 'Q':case 'S':case 'X':case 'Z':
          val=2;
          break;
        case 'D':case 'T':
          val=3;
          break;
        case 'L':
          val=4;
          break;
        case 'M':case 'N':
          val=5;
          break;
        case 'R':
          val=6;
          break;
        default:
          val=0;
          break;
      }
      if(val==0)
        temp=0;
      else if(val!=temp){
        temp=val;
        str+=std::to_string(val);
      }
    }
    str+="\n";
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}

#include <iostream>
#include <cstdio>
int main() {
  int n,correct,pos;
  std::string str="";
  char c,*stack;
  scanf("%i ",&n);
  while(n--) {
    stack=(char*)calloc(129,pos=correct=1);
    while(scanf("%c",&c),c!='\n') {
      if(correct) {
        if(c==']') {
          if(stack[--pos]!='[')
            correct=0;
        } else if(c==')') {
          if(stack[--pos]!='(')
            correct=0;
        } else
          stack[pos++]=c;
      }
    }
    free(stack);
    if(correct && pos==1)
      str+="Yes\n";
    else
      str+="No\n";
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}

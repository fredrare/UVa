#include <iostream>
#include <cstdio>
#include <stack>
int main() {
  int n,len,i,correct,p1,p2;
  std::string str="";
  char c;
  scanf("%i ",&n);
  while(n--){
    std::stack<int> st;
    correct=1;
    st.push(p1=p2=0);
    while(scanf("%c",&c),c!='\n'){
      if(correct){
        switch(c){
          case '(':
            st.push(1);
            p1++;
            break;
          case '[':
            st.push(2);
            p2++;
            break;
          case ']':
            if(st.top()==2){
              st.pop();
              p2--;
            }else
              correct=0;
            break;
          case ')':
            if(st.top()==1){
              st.pop();
              p1--;
            }else
              correct=0;
            break;
        }
      }
    }
    if(correct && p1==0 && p2==0)
      str+="Yes\n";
    else
      str+="No\n";
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}

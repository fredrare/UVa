#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char *s=malloc(100000),*t=malloc(100000);
  int i,j,ns,nt;
  while(scanf(" %s %s",s,t)!=EOF){
    nt=strlen(t);
    for(i=0,j=0;i<nt;i++)
      s[j]==t[i]?j++:1;
    printf("%s\n",j==strlen(s)?"Yes":"No");
  }
  return 0;
}

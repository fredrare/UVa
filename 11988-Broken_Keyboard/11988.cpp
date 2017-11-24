#include <cstdio>
#include <list>
using namespace std;
int main(){
  list<char> line;
  list<char>::iterator it;
  char c=0;
  while(c != EOF && scanf("%c",&c) != EOF){
    it = line.begin();
    while(c != '\n'){
      if(c == '[')
        it = line.begin();
      else if(c == ']')
        it = line.end();
      else
        line.insert(it, c);
      scanf("%c",&c);
    }
    for(it = line.begin(); it != line.end(); it++)
      printf("%c",*it);
    printf("\n");
    line.clear();
  }
  return 0;
}

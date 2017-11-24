#include <cstdio>
#include <list>
#include <cstring>
using namespace std;
int main(){
  char buffer[100001];
  list<char> line;
  list<char>::iterator it;
  int length;
  while(scanf("%s",buffer) != EOF){
    it = line.begin();
    length=strlen(buffer);
    for(int i = 0; i < length; i++){
      if(buffer[i] == '[')
        it = line.begin();
      else if(buffer[i] == ']')
        it = line.end();
      else
        line.insert(it, buffer[i]);
    }
    for(it = line.begin(); it != line.end(); it++)
      printf("%c",*it);
    printf("\n");
    line.clear();
  }
  return 0;
}

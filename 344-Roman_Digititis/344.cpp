#include <iostream>
#include <cstdio>
#include <cstdlib>
int** roman=(int**)malloc(5*sizeof(int*));
int* size(int n){
  int* array=(int*)calloc(5,sizeof(int));
  if(n==100){
    array[4]=1;
    return array;
  }
  for(int i=0;i/2<2;n/=10,i+=2){
    if(n%10<4)
      array[0+i]+=n%10;
    else if(n%10==4){
      array[0+i]++;
      array[1+i]++;
    }else if(n%10==5)
      array[1+i]+=1;
    else if(n%10<9){
      array[1+i]++;
      array[0+i]+=n%5;
    } else if(n%10==9){
      array[2+i]+=1;
      array[0+i]+=1;
    }
  }
  return array;
}
int* recursive(int n){
  int* array=(int*)calloc(5,sizeof(int)),*array2;
  for(int i=0;i<5;i++)
    array[i]+=roman[i][n];
  if(n==0||array[0]||array[1]||array[2]||array[3]||array[4])
    return array;
  else{
    array2=size(n);
    for(int i=0;i<5;i++)
      array[i]+=array2[i];
    free(array2);
    array2=recursive(n-1);
    for(int i=0;i<5;i++){
      array[i]+=array2[i];
      roman[i][n]=array[i];
    }
    free(array2);
  }
  return array;
}
int main() {
  for(int i=0;i<5;i++)
    roman[i]=(int*)calloc(101,sizeof(int));
  int n,*array;
  std::string str="";
  while(scanf("%i",&n),n){
    array=recursive(n);
    str+=std::to_string(n)+
      ": "+std::to_string(array[0])+" i, "+
      std::to_string(array[1])+" v, "+
      std::to_string(array[2])+" x, "+
      std::to_string(array[3])+" l, "+
      std::to_string(array[4])+" c\n";
    free(array);
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}

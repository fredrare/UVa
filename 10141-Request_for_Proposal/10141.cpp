#include <iostream>
#include <cstdio>
#include <cstring>
int main(){
  int req,rfp,i=1,met,max,j;
  float price,min;
  std::string st="";
  char bestname[81],s[81];
  while(scanf("\n%i %i",&req,&rfp),req||rfp){
    while(req--)
      scanf("\n%*[^\n]");
    getchar();
    scanf("%80[^\n]",bestname);
    scanf("%f %i\n",&min,&max);
    for(j=0;j<max;j++)
      scanf("\n%*[^\n]");
    while(--rfp){
      getchar();
      scanf("%80[^\n]",s);
      scanf("\n%f %i",&price,&met);
      if(met>max||(met==max&&price<min)){
        max=met;
        min=price;
        strcpy(bestname,s);
      }
      while(met--)
        scanf("\n%*[^\n]");
    }
    st+="RFP #"+std::to_string(i++)+"\n"+bestname+"\n\n";
  }
  st.pop_back();
  std::cout<<st;
  return 0;
}

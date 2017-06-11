#include <iostream>
#include <cstdio>
#include <cstdlib>
struct Node{
  int x;
  struct Node* left;
  struct Node* right;
};
int main(){
  struct Node** list;
  struct Node* node;
  struct Node* ptr;
  int b,s,l,r,i;
  std::string str="";
  while(scanf("%i%i",&s,&b),s||b){
    list=(struct Node**) malloc(s*sizeof(struct Node*));
    node=(struct Node*) malloc(sizeof(struct Node));
    node->left=NULL;
    for(i=0;i<s;i++){
      ptr=(struct Node*) malloc(sizeof(struct Node));
      node->x=i+1;
      node->right=ptr;
      ptr->left=node;
      ptr->right=NULL;
      list[i]=node;
      node=ptr;
    }
    while(b--){
      scanf("%i%i",&l,&r);
      if(l>1 && list[l-1]->left!=NULL){
        if(r<s && list[r-1]->right!=NULL){
          list[l-1]->left->right=list[r-1]->right;
          list[r-1]->right->left=list[l-1]->left;
        } else if(list[l-1]->left!=NULL)
          list[l-1]->left->right=NULL;
      } else if(r<s && list[r-1]->right!=NULL)
        list[r-1]->right->left=NULL;
      if(l>1 && list[l-1]->left!=NULL)
        str+=std::to_string(list[l-1]->left->x)+" ";
      else
        str+="* ";
      if(r<s && list[r-1]->right!=NULL)
        str+=std::to_string(list[r-1]->right->x)+"\n";
      else
        str+="*\n";
    }
    str+="-\n";
    for(i=0;i<s;i++)
      free(list[i]);
    free(list);
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}

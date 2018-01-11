#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *letters = "abcdefghijklmnopqrstuvwxyz";
char** diamond;
int **test;
void fill(int n,
    int top, int left,
    int bottom, int right){
  int i, j, size, pos, aux, *ptri, *ptrj, auxtop, auxleft;
  size = 2 * n - 1;
  ptri = n < bottom ? &n : &bottom;
  auxleft = size - right;
  if(left < auxleft)
    auxleft = left;
  auxtop = size - bottom;
  for(i = top < auxtop ? top : auxtop; i < *ptri; i++){
    aux = n - 1 - i;
    if(!diamond[i])
      diamond[i] = (char*) calloc(size, 1);
    ptrj = aux < right ? &aux : &right;
    for(j = auxleft;
        j < *ptrj; j++)
      diamond[i][j] = '.';
    ptrj = n < right ? &n : &right;
    if(aux > auxleft){
      j = aux;
      pos = n - 1;
    }else{
      j = auxleft;
      pos = n - 1 - auxleft + aux;
    }
    while(j < *ptrj)
      diamond[i][j++] = letters[(pos--) % 26];
    aux = n + i;
    ptrj = aux < right ? &aux : &right;
    if(n > auxleft){
      j = n;
      pos = n - i;
    }else{
      j = auxleft;
      pos = auxleft - i;
    }
    while(j < *ptrj)
      diamond[i][j++] = letters[(pos++) % 26];
    ptrj = size < right ? &size : &right;
    for(j = aux; j < *ptrj; j++)
      diamond[i][j] = '.';
  }
  for(i = (n > top ? n : top); i < bottom; i++){
    if(!diamond[i])
      diamond[i] = (char*) malloc(size + 1);
    memcpy(diamond[i], diamond[size - i - 1], size + 1);
  }
}
int main(){
  int n, row1, col1, row2, col2, size, i, j, count = 1;
  int top, bottom, left, right;
  while(scanf("%d%d%d%d%d", &n, &row1, &col1, &row2, &col2), n){
    size = 2 * n - 1;
    diamond = (char**) calloc(size, sizeof(char*));
    if(row2 - row1 + 1< size){
      top = row1 % size;
      bottom = (row2 + 1) % size;
    }else{
      top = 0;
      bottom = size;
    }
    if(col2 - col1 + 1< size){
      left = col1 % size;
      right = (col2 + 1) % size;
    }else{
      left = 0;
      right = size;
    }
    if(top > bottom){
      if(left > right){
        fill(n, top, left, size, size);
        fill(n, top, 0, size, right);
        fill(n, 0, left, bottom, size);
        fill(n, 0, 0, bottom, right);
      }else{
        fill(n, top, left, size, right);
        fill(n, 0, left, bottom, right);
      }
    }else{
      if(left > right){
        fill(n, top, left, bottom, size);
        fill(n, top, 0, bottom, right);
      }else
        fill(n, top, left, bottom, right);
    }
    printf("Case %d:\n", count++);
    for(i = row1; i <= row2; i++){
      for(j = col1; j <= col2; j++)
        printf("%c", diamond[i%size][j%size]);
      printf("\n");
    }
    for(i = 0; i < size; i++){
      if(diamond[i])
        free(diamond[i]);
    }
    free(diamond);
  }
  return 0;
}

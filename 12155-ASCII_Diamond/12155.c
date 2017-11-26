#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *letters = "abcdefghijklmnopqrstuvwxyz";
char** diamond;
void fill(int n,
    int top, int left,
    int bottom, int right){
  int i, j, size, pos, aux;
  size = 2 * n - 1;
  for(i = (top < (size - bottom) ? top : (size - bottom));
      i < n && i < bottom; i++){
    aux = n - 1 - i;
    if(!diamond[i])
      diamond[i] = (char*) calloc(size, 1);
    for(j = left; j < aux && j < right; j++)
      diamond[i][j] = '.';
    for(j = (aux > left ? aux : left),
        pos = n - 1 - (j > left ? 0 : left - aux);
        j < n && j < right; j++, pos--)
      diamond[i][j] = letters[pos%26];
    aux = n + i;
    for(j = (n > left ? n : left),
        pos = n - i + (j > left ? 0 : left - n);
        j < aux && j < right; j++, pos++)
      diamond[i][j] = letters[pos%26];
    for(j = aux; j < size && j < right; j++)
      diamond[i][j] = '.';
  }
  for(i = (n > top ? n : top); i < bottom; i++){
    diamond[i] = (char*) malloc(size + 1);
    memcpy(diamond[i], diamond[size - i - 1], size + 1);
  }
}
int main(){
  int n, row1, col1, row2, col2, size, i, j, aux, pos, count = 1;
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

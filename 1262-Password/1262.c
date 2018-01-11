#include <stdio.h>
#include <stdlib.h>
#define ROWS 6
#define COLS 5
char **pass;
int *length;
void insert (char c, int col) {
  int i, end = length [col];
  for (i = 0; i < end; i++) {
    if (c < pass [col] [i])
      break;
    else if (c == pass [col] [i])
      return;
  }
  while (end > i)
    pass [col] [end + 1] = pass [col] [--end];
  pass [col] [i] = c;
  length [col] ++;
}
int main () {
  char **grid;
  char *ans;
  char c;
  int t, k, i, j, aux, mod;
  grid = (char**) malloc (COLS * sizeof (char*));
  pass = (char**) malloc (COLS * sizeof (char*));
  for (i = 0; i < COLS; i++) {
    pass [i] = (char*) malloc (ROWS * sizeof (char));
    grid [i] = (char*) malloc (ROWS * sizeof (char));
  }
  ans = (char*) calloc (ROWS + 1, sizeof (char));
  ans [COLS + 1] = '\0';
  scanf ("%i", &t);
  while (t--) {
    length = (int*) calloc (ROWS, sizeof (int));
    scanf ("%i ", &k);
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++)
        scanf ("%c ", &grid [j] [i]);
    }
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
        scanf ("%c ", &c);
        for (aux = 0; aux < ROWS; aux++) {
          if (c == grid [j] [aux])
            insert (c, j);
        }
      }
    }
    for (aux = 1, i = 0; i < COLS; i++)
      aux *= length [i];
    if (k-- > aux) printf ("NO\n");
    else {
      for (i = COLS - 1; i >= 0; i--){
        mod = k % length [i];
        ans [i] = pass [i] [mod];
        k /= length [i];
      }
      printf ("%s\n", ans);
    }
    free (length);
  }
  return 0;
}

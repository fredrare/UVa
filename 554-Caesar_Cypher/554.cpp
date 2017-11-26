#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <regex>
using namespace std;
int matches(string s, regex e)
{
    auto begin = sregex_iterator(
        s.begin(), s.end(), e);
    auto end = sregex_iterator();
    return distance(begin, end);
}
int main(){
  string dictionary = "";
  char *word = (char*) malloc (21);
  char *ciphertext = (char*) malloc (251);
  char **plaintext = (char**) malloc (27 * sizeof (char*));
  int max = -1, index, count;
  int *space = (int*) calloc (2, sizeof (int));
  int length, i, j;
  scanf ("%s", word);
  dictionary += word;
  while (scanf ("%s", word), strncmp (word, "#", 1))
    dictionary += "|" + string (word);
  scanf (" %[A-Z ]s", ciphertext);
  length = strlen (ciphertext) - 1;
  for (i = 0; i < 27; i++){
    plaintext[i] = (char*) malloc (length + 1);
    for (j = count = 0; j < length; j++, count++){
      plaintext[i][j] = (ciphertext[j] - 64 + i) % 27;
      if (plaintext[i][j]){
        if (plaintext[i][j] > 0)
          plaintext[i][j] += 64;
        else
          plaintext[i][j] = 64 + i;
      } else {
        plaintext[i][j] = ' ';
        if (space[0]) {
          space[0] = space [1];
          space[1] = j;
        } else
          space[0] = space[1] = j;
        if (count > 60){
          plaintext[i][space[0]] = '\n';
          count = space[1] - space [0] - 1;
        }
      }
    }
    if (count > 60)
      plaintext[i][space[0]] = '\n';
    count = matches (string (plaintext[i]), regex (dictionary));
    if (count > max){
      max = count;
      index = i;
    }
  }
  plaintext[index][length] = '\0';
  printf ("%s\n", plaintext[index]);
  return 0;
}


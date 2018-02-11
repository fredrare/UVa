#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<string> answers;

string sum (string x, string y) {
  if(x.length() < y.length())
    x.swap(y);
  for (int i = x.length() - y.length(); i > 0; i--)
    y = to_string(0) + y;
  string answer = string();
  string::iterator begin = x.begin();
  int aux = 0;
  for (string::iterator i = x.end() - 1, j = y.end() - 1; i >= begin; i--, j--){
    aux += *i - '0' + *j  - '0';
    answer = to_string(aux % 10) + answer;
    aux /= 10;
  }
  if (aux)
    answer = to_string(aux) + answer;
  return answer;
}

string multiply (string x, string y) {
  if(x.length() < y.length())
    x.swap(y);
  string answer, line;
  answer = "0";
  int aux, zeroes = 0;
  string::iterator ybegin = y.begin(), xbegin = x.begin();
  for(string::iterator j = y.end() - 1; j >= ybegin; j--, zeroes++) {
    line = string();
    aux = 0;
    for (string::iterator i = x.end() - 1; i >= xbegin; i--) {
      aux += (*i - '0') * (*j - '0');
      line = to_string(aux % 10) + line;
      aux /= 10;
    }
    if (aux)
      line = to_string(aux) + line;
    for (int j = 0; j < zeroes; j++)
      line += "0";
    answer = sum(answer, line);
  }
  return answer;
}

string factorial(int x) {
  if (x < 2)
    return "1";
  else if (answers[x] != "")
    return answers[x];
  return answers[x] = multiply(factorial(x-1), to_string(x));
}

int main () {
  answers.reserve(1001);
  int x;
  while (scanf("%i", &x) != EOF)
    cout << x << "!\n" << factorial(x) << endl;
  return 0;
}


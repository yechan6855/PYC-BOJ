#include <iostream>
#include <cstring>
using namespace std;

char *big(char *a, char *b)
{
  for (int i = 0; i < strlen(a); i++)
  {
    if (a[i] < b[i])
      return b;
    if (a[i] > b[i])
      return a;
  }
  return a;
}

void subtract(char *a, char *b)// 나눗셈은 뺄셈을 여러번하는 연산이다.

{
  for (int i = 0; i < strlen(b); i++)
  {
    a[i] = a[i] - b[i] + '0';
  }
  for (int i = strlen(b) - 1; i >= 0; i--)
  {
    if (a[i] < '0')
    {
      a[i] += 10;
      a[i - 1]--;
    }
  }
}

void devidesubtract(char *a, char *b, char *q, int index)
{
  q[index] = '0';
  while (a[index - 1] > '0' || big(a + index, b) == a + index)
  {
    subtract(a + index, b);
    ++q[index];
  }
}

void devide(char *a, char *b, char *q)
{
  int index = 0;
  int digit = strlen(a) - strlen(b);

  while (index <= digit)
    devidesubtract(a, b, q, index++);

  q[index] = '\0';
}

int main()
{
  char a[1001];
  char b[1001];
  char q[1001];
  int qi = 0, ai = 0;
  cin >> a >> b;
  devide(a, b, q);

  while (q[qi] == '0')
    qi++;
  while (a[ai] == '0')
    ai++;

  if (q[0] == '\0')
  {
    q[0] = '0';
    q[1] = '\0';
  }

  if (a[ai] == '\0')
    ai--;

  if (q[qi] == '\0')
    qi--;

  cout << q + qi << '\n';
  cout << a + ai << '\n';
  return 0;
}
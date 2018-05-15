#include <stdio.h>

#define NUMCOL 3
#define MAXLINE 1000

int detab(char input[]);

int main()
{
  char str[MAXLINE];
  int x = detab(str);
  
  if(x < MAXLINE-1 && x > 0)
    printf("%s\n", str);

  else
    printf("invalid input\n");

  return 0;
}

int detab(char input[])
{
  int i = 0, x;
  char c;
 
  while(i < MAXLINE-1 && (c = getchar()) != EOF)
    {
      x = i;
      if(c == '\t')
	for(; i < x + NUMCOL; ++i)
	    input[i] = ' ';
      else
      {
	input[i] = c;
	++i;
      }
    }
  
  input[i] = '\0';

  return i;
}

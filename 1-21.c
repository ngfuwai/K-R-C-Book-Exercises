#include <stdio.h>

#define NUMCOL 3
#define MAXLINE 1000

int entab(char str[]);

int main()
{
  char str[MAXLINE];
  int x = entab(str);
  
  if(x < MAXLINE - 1 && x > 0)
    printf("%s\n", str);

  else
    printf("invalid input\n"); // note that newline is a character

  return 0;
}

int entab(char str[])
{
  int i = ctr = 0;
  char c;

  while(i < MAXLINE - 1 && (c = getchar()) != EOF)
    {
      if(c == ' ')
	  ++ctr;

      if(ctr == NUMCOL)
	{
	  i -= NUMCOL-1;
	  str[i] = '\t';
	  ctr = 0;
	}

      else
	str[i] = c;

      ++i;
    }

  str[i] = '\0';

  return i;
}


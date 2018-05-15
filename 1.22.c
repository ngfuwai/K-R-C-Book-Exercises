#include <stdio.h>

#define NUMCOL 5      //length of line
#define MAXLINE 10000

int fold(char str[]);

int main()
{
  char str[MAXLINE];

  int x = fold(str);
  
  if(x < MAXLINE - 1 && x > 0)
    printf("%s\n", str);

  else
    printf("invalid input\n");

  return 0;
}

int fold(char str[])
{
  int i = 0, x = -1, ctr = 0; // x is the index of last tab or space
  char c;

  while(i < MAXLINE - 1 && (c = getchar()) != EOF)
    {
      
      if(c == ' ' || c == '\t' || c == '\n')
       x = i;

      if(c == '\n')
	ctr = 0;
      
      if(ctr == NUMCOL)
	{
	  if(x < i - NUMCOL)
	    {
	      str[i] = '\n';
	      ++i;
	      str[i] = c;
	      ctr = 1;
	    }
	  else
	    {
	      str[x] = '\n';
	      ctr = i - x;

	      if(x != i)
		  str[i] = c;
		
	    }
	}

      else
	{
	  str[i] = c;
	  ++ctr;
	}
      
      ++i;
    }
  str[i] = '\0';
      return i;
}

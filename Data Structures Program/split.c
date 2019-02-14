#include <stdio.h>
#include <string.h>

int main ()
{
  char str[20];
  char * pch;
  //printf ("Splitting string \"%s\" into tokens:\n",str);
  //scanf("%s",str);
  fgets(str, 20, stdin);
  pch = strtok (str," ");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ");
  }
  return 0;
}
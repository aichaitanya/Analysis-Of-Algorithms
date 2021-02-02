#include<stdio.h>
#include<conio.h>

int naive(char txt[100],char pat[100]);

void main()
{
  char txt[100],pat[100];
  int status;
  clrscr();
  printf("Enter the main string : ");
  gets(txt);
  printf("Enter the pattern string : ");
  gets(pat);
  status=naive(txt,pat);
  if(status==0)
     printf("\nPattern is not found.");
  else
     printf("\n\nPattern found %d times.",status);
  getch();
}

int naive(char txt[100],char pat[100])
{
  int n,m,i,j,cnt=0,tmp=0;
  n = strlen(txt);
  m = strlen(pat);
  for(i=0;i<=n-m;i++)
  {
    tmp++;
    for(j=0;j<m;j++)
    {
       if(txt[i+j]!=pat[j])
	 break;
    }
    if(j==m)
    {
       printf("\nPattern is found at position %d",tmp);
       cnt++;
    }
  }
  return cnt;
}

/*

OUTPUT :

Enter the main string : today is wednesday and good day
E/nter the pattern string : day

Pattern is found at position 3
Pattern is found at position 16
Pattern is found at position 29

Pattern found 3 times.

*/
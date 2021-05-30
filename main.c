#include <stdio.h>
#include <string.h>
#define MAX_DATES 100

struct str
{
  int date;
  int month;
  int year;
} dat[MAX_DATES];
 
int main(void)
{
  FILE *read;
  int i = 0, n, min_year;
 
  read = fopen("f.txt","rt");
  while (!feof(read))
  {
    fscanf(read,"%d.%d.%d", &dat[i].date, &dat[i].month, &dat[i].year);
    i++;
  }

  fclose(read);
  n = i++;
 
  min_year = dat[0].year;
  for (i = 1; i < n; i++)
  {
    if (dat[i].year < min_year)
      min_year = dat[i].year;
  }
 
  printf("Minimal year in file f.txt — %d\n", min_year);
}
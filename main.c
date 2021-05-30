#include <stdio.h>
#include <string.h>

struct str {int day, month, year;} date[100];

int main (void)
{
  FILE *f, *g;
  int i = 0, n, min_year;

  f = fopen("f.txt", "rt");
  while (!feof(f))
  {
    fscanf(f,"%d.%d.%d", &date[i].day, &date[i].month, &date[i].year);
    i++;
  }

  fclose(f);
  n = i++;

  min_year = date[0].year;
  for (i = 1; i < n; i++)
  {
    if (date[i].year < min_year)
      min_year = date[i].year;
  }

  g = fopen("g.txt", "w");
  fprintf(g, "%d", min_year);
  printf("MInimal year is written to the file g.txt\n");
}
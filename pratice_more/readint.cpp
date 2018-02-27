#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN        32

void print(int *keys, int len)
{
  int i;

  for (i = 1; i <= len; i++)
    printf("%d\t", keys[i]);

  printf("\n");
}

int main()
{
  FILE *fp;
  int keys[MAX_LEN];
  int len = 0, i;

  fp = fopen("D:\\test.txt", "r");
  if (!fp){
    printf("Can not open input file.\n");
    exit(-1);
  }

  i = 1;
  while ( !feof(fp) )
    fscanf(fp, "%d", &keys[i++]);
  len = i - 1;

  print(keys, len);
  fclose(fp);

  getchar();
  
  return 0;
}

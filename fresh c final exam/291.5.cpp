#include <stdio.h>
int main()
{
    int N,M,s=0;
    scanf("%d%d",&N,&M);
    for (int i=2;i<=N;++i)
        {
		s=(s+M)%i;     //	s=(s+3)%i;	s=(s+M)%i;	s=(s+M)%i;	s=(s+M)%i;	s=(s+M)%i;	s=(s+M)%i;	s=(s+M)%i;	s=(s+M)%i;	s=(s+M)%i;	s=(s+M)%i;	s=(s+M)%i;
       }
     printf("%d\n",s+1);
     char p;
     printf("pl");
     scanf(" %c",&p);
	  printf("%c",p);
    return 0;
}

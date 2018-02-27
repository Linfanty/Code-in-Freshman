#include<cstdio>
#include<cstring>
main()
{
    char s[5]="abc" ;
	char t[5]="qwe";
	while(*s)
	s++;
	//while(*t!='\0')
	{
		*s++=*t++;
	//	s++;
	//	t++;
	}
//	*s='\0';
	
//	ctrcmp();
	printf("%s %s\n",s-4,s);
}

#include<stdio.h>

/*struct count
{int count;
int count2;
}count[];
*/

void select(long int a[],int begin,int n)
{int i,t,min;
if(begin==n-1)
return;
min=begin;
for(i=begin+1;i<n;i++)
                      if(a[i]<a[min])
                      min=i;
t=a[begin];a[begin]=a[min];a[min]=t;
select(a,begin+1,n);
     }

void quick_sort(long int s[], int l, int r)
{
    if (l < r)
    {
              //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                            j--; 
            if(i < j)
                            s[i++] = s[j];
                    
            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                            i++; 
            if(i < j)
                            s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ����
        quick_sort(s, i + 1, r);
    }
}
 
main()
{ char ch;
  int a[100],min,i,j,t;
  FILE * in;
  FILE * out;
  if((in=fopen("D:\\in.txt","r"))==NULL)
		{printf("NO!");} 
  if((out=fopen("D:\\out.txt","w"))==NULL)
         {printf("NO!"); }
  
  //fscanf(in,"%d",&a[0]);
                          /*����*/
  fscanf(in,"%d",&a[0]);
  long int n=a[0];
    
  for(i=0;i<n;i++)
 {fscanf(in,"%d",&a[i]);}   
   // fread(&a[0],sizeof(in),n,in);
  fclose(in);
  
  //n=a[0]     
                                          //select(a,0,n);
                                          quick_sort(a,0,n-1);
   /*                       �ǵݹ� ѡ������
    for(i=1;i<n;i++)
    {    min=i;
        for(j=i+1;j<n;j++)
        if(a[j]<a[min])
        min=j;           //��ֹ����
        t=a[i];a[i]=a[min];a[min]=t;
    }
 */
 
                      
                          /*ͳ��
  int q,w,count;
  
for(i=1,i<n;i++)
{    for(j=i+1;j<n;j++)
     {if(a[i]==a[j])
     count++;
     else break;}                          
}

����*/


int sum,w;

 for (i=sum=0;i<n;i++)     //ͳ�Ʋ�ͬ���ֵĸ��� 
       if (a[i+1]!=a[i]) sum++;
   for (w=1,i=0,j=0;i<sum;i++,j++) //��ͳ�Ʊ���� 
   {
       while (a[j+1]==a[j]) {w++; j++;}
       fprintf(out,"%d %d%s",a[j],w,(j!=n-1? "\n":""));
       /*����  */    printf("%d %d%s",a[j],w,(j!=n-1? "\n":""));
       w=1;
   }
   fclose(out);


        
        getchar();
                          
  /*���*/        
 //   for(i=0;i<n;i++)      
 // {fprintf(out,"%d%s",a[i],(i==n-1? "":"\n"));} 
                                      // fwrite(&a[0],sizeof(out),n,out); 
             
 //               fclose(out);    


}

 
 /*while(!feof(in))
 putc(getc(in),out);
 fclose(in);
 fclose(out);
 */  

   
   
/*    {while((ch=fgetc(fp))!=EOF)
       putchar(ch);
        fclose(fp);
		}
	else{printf("ERROR!");}
 getchar();
*/

//system("pause");


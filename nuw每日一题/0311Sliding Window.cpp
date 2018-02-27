#include<stdio.h>
#include<iostream>

using namespace std;
int a[1000005], d[1000005], l, r, n, k;
int main()
{
	freopen("in.txt","r",stdin);
    while(scanf("%d%d", &n, &k) != EOF)
    {
    	
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        l = r = 0;
        /*
		for(int i = 1; i <= n; i++)     //求最小值
        {
        	
            while(l != r && a[i] <= a[d[r - 1]]) r--;
            d[r++] = i;
            
            while(i - d[l] >= k) l++;
            
            if(i >= k || i == n) 
			printf("%d%c", a[d[l]], i == n ? '\n' : ' ');
            
        }
        
        */
        l = r = 0;
        
		
		for(int i = 1; i <= n; i++)     //求最大值
        {
            while(l != r && a[i] >= a[d[r - 1]])
			 r--;
            //cout<<r<<"  " ;
			d[r++] = i;
            
            while(i - d[l] >= k) l++;
            
            if(i >= k || i == n) 
			printf("%d  %d  %d  %d%c",i,  l , d[l], a[d[l]], i == n ? '\n' : ' ');
			printf("\n");
        }
    }
    
    return 0;
}

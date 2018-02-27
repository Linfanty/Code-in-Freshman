#include <stdio.h>  
#include <stdlib.h>  
  
int cmp(const void *a, const void *b)  
{  
    return *(int *)a - *(int *)b;  
}  
  
int pretend_1(int *, int);  
int pretend_2(int *, int);  
void print_1(int *, int);  
void print_2(int *, int);  
  
int main()  
{  
    int n, i, temp, total, t1, t2;  
    int save[1000][2], t;  
    int p[1000];  
    while(scanf("%d\n", &n) != EOF) {  
        for(i = 0; i < n; i++) {  
            scanf("%d", p+i);  
        }  
        qsort(p, n, sizeof(int), cmp);  
        /*for(i = 0; i < n; i++) { 
            printf("%d ", p[i]); 
        } 
        printf("\n");*/  
        if(n == 1) {  
            printf("%d\n", p[0]);  
            printf("%d\n", p[0]);  
        }  
        else if(n == 2) {  
            printf("%d\n", p[1]);  
            printf("%d %d\n", p[0], p[1]);  
        }  
        else if(n == 3) {  
            printf("%d\n", p[2] + p[0] + p[1]);  
            printf("%d %d\n", p[0], p[2]);  
            printf("%d\n", p[0]);  
            printf("%d %d\n", p[0], p[1]);  
        } else {  
            temp = n;  
            total = 0;  
            t = 0;  
            while(temp >= 4) {  
                if((t1 = pretend_1(p, temp)) > (t2 = pretend_2(p, temp))) {  
                    total += t2;  
                    save[t][0] = temp;  
                    save[t++][1] = 2;  
                } else {  
                    total += t1;  
                    save[t][0] = temp;  
                    save[t++][1] = 1;  
                }  
                temp -= 2;  
            }  
            if(temp == 3) {  
                total += p[2] + p[1] + p[0];  
            }  
            else if(temp == 2) {  
                total += p[1];  
            }  
            else if(temp == 1) {  
                total += p[0];  
            }  
            printf("%d\n", total);  
            for(i = 0; i < t; i++) {  
                if(save[i][1] == 1) {  
                    print_1(p, save[i][0]);  
                } else {  
                    print_2(p, save[i][0]);  
                }  
            }  
            if(temp == 3) {  
                printf("%d %d\n", p[0], p[2]);  
                printf("%d\n", p[0]);  
                printf("%d %d\n", p[0], p[1]);  
            }  
            else if(temp == 2) {  
                printf("%d %d\n", p[0], p[1]);  
            }  
        }   
    }  
    return 0;  
}  
  
int pretend_1(int *p, int n)  
{  
    return p[1] + p[0] + p[n-1] + p[1];  
}  
  
int pretend_2(int *p, int n)  
{  
    return p[n-1] + p[0] + p[n-2] + p[0];  
}  
  
void print_1(int *p, int n)  
{  
    printf("%d %d\n", p[0], p[1]);  
    printf("%d\n", p[0]);  
    printf("%d %d\n", p[n-2], p[n-1]);  
    printf("%d\n", p[1]);  
}  
  
void print_2(int *p, int n)  
{  
    printf("%d %d\n", p[0], p[n-1]);  
    printf("%d\n", p[0]);  
    printf("%d %d\n", p[0], p[n-2]);  
    printf("%d\n", p[0]);  
}  

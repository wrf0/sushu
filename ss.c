#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10000001//设置数组大小号
#define N 1000000//选择计算的范围
int prime[MAX];
int main()
{
    FILE *fp;
    fp = fopen("sushu.txt", "wt");
    int i,j, num= 0;
    prime[num] =2;//登记素数2
#pragma omp parallel for 
for(i=3; i<=N; i+=2)//开始计算3开始的素数
 {
  for(j=3; j<=sqrt(i); j+=2)
         if( i%j==0 ) 
    break;
       if( j>sqrt(i) )
     prime[++num] = i;//把素数存入数组
   fprintf(fp, "%d ", i);
 }
  printf("%d内共有%d个素数：\n",N,num+1);//打印素数个数
 return 0;
}



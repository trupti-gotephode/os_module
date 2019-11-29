#include<stdio.h>
#include <pthread.h>
int *sum=0;
int *a=10;
int *b=20;
void* addthread(void* data1,void* data2)
{  
   sum=(int*)data1 + (int*)data2;
   return sum; 
}
   int main()
{
pthread_t id;

pthread_create(&id,NULL,addthread,&a,&b);
pthread_join(id,sum);

return 0;
}

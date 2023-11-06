#include <stdio.h>
void Insert(int A[],int n) 
 { 
    int i=n,temp; 
   temp=A[i]; 
    while(i>1 && temp>A[i/2]) 
    { 
     A[i]=A[i/2]; 
     i=i/2; 
    } 
   A[i]=temp; 
  } 
int Delete(int A[],int n) 
 { 
   int i,j,x,temp,val; 
   val=A[1]; 
   x=A[n]; 
   A[1]=A[n]; 
   A[n]=val; 
   i=1;j=i*2; 
   while(j<=n-1) 
    { 
     if(j<n-1 && A[j+1]>A[j]) 
     j=j+1; 
     if(A[i]<A[j]) 
     { 
      temp=A[i]; 
      A[i]=A[j]; 
      A[j]=temp; 
      i=j; 
      j=2*j; 
     } 
     else
     break; 
    } 
   return val; 
 } 

int main() { 
int n;
printf("enter the number of elements:");
scanf("%d",&n);
 int A[n+1];
  A[0]=0;
  int i;
 for( i=1;i<=n;i++)
 {
  printf("enter the  element %d:",i);
  scanf("%d",&A[i]);
 }
 for(i=2;i<=n;i++) 
 Insert(A,i); 
 printf("max heap is:");
 for(i=1;i<=n;i++) 
 printf("%d ",A[i]); 
 printf("\n"); 
 int root=A[1];
 Delete(A,root);
 printf("deleted root:%d",root);

 for(i=2;i<=n;i++) 
 Insert(A,i);
  for(i=1;i<=n;i++) 
 printf("%d ",A[i]); 
 printf("\n");
 
 
 return 0; 
} 
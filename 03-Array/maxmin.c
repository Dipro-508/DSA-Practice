#include<stdio.h>
int main(){
int a[100],n,i,mx,mn;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&a[i]);
mx=mn=a[0];
for(i=1;i<n;i++){
if(a[i]>mx)mx=a[i];
if(a[i]<mn)mn=a[i];}
printf("Maximum=%d\nMinimum=%d",mx,mn);}
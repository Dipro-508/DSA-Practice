#include<stdio.h>
#define M 5
int q[M],f=-1,r=-1;
void enq(){
int x;
if((r+1)%M==f){printf("Overflow\n");return;}
printf("Value: ");
scanf("%d",&x);
if(f==-1)f=r=0;
else r=(r+1)%M;
q[r]=x;}
void deq(){
if(f==-1){printf("Underflow\n");return;}
printf("Deleted:%d\n",q[f]);
if(f==r)f=r=-1;
else f=(f+1)%M;}
void peek(){
if(f==-1){printf("Empty\n");return;}
printf("Front:%d\n",q[f]);}
void display(){
int i;
if(f==-1){printf("Empty\n");return;}
i=f;
while(1){
printf("%d ",q[i]);
if(i==r)break;
i=(i+1)%M;}
printf("\n");}
int main(){
int c;
while(1){
printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nChoice:");
scanf("%d",&c);
if(c==1)enq();
else if(c==2)deq();
else if(c==3)peek();
else if(c==4)display();
else if(c==5)break;
else printf("Wrong Choice\n");}
return 0;}
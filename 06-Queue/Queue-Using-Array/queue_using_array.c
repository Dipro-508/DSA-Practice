#include<stdio.h>
#define M 100
int q[M],f=-1,r=-1;
void enq(){
int x;
if(r==M-1){printf("Overflow\n");return;}
printf("Value: ");
scanf("%d",&x);
if(f==-1)f=0;
q[++r]=x;
}
void deq(){
if(f==-1||f>r){printf("Underflow\n");return;}
printf("Deleted:%d\n",q[f++]);
if(f>r)f=r=-1;
}
void peek(){
if(f==-1){printf("Empty\n");return;}
printf("Front:%d\n",q[f]);
}
void display(){
int i;
if(f==-1){printf("Empty\n");return;}
for(i=f;i<=r;i++)printf("%d ",q[i]);
printf("\n");
}
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
else printf("Wrong Choice\n");
}
return 0;
}
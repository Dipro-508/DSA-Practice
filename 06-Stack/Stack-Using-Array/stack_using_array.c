#include<stdio.h>

// Defining
#define M 100
int s[M],t=-1;

// Push
void push(){
int x;
if(t==M-1){printf("Overflow\n");return;}
printf("Value: ");
scanf("%d",&x);
s[++t]=x;}

// Pop
void pop(){
if(t==-1){printf("Underflow\n");return;}
printf("Deleted:%d\n",s[t--]);}

// Peek
void peek(){
if(t==-1){printf("Empty\n");return;}
printf("Top:%d\n",s[t]);}

// Display
void display(){
int i;
if(t==-1){printf("Empty\n");return;}
for(i=t;i>=0;i--)printf("%d ",s[i]);
printf("\n");}

// Main Function
int main(){
int c;
while(1){
printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nChoice:");
scanf("%d",&c);
if(c==1)push();
else if(c==2)pop();
else if(c==3)peek();
else if(c==4)display();
else if(c==5)break;
else printf("Wrong Choice\n");}
return 0;}
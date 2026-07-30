#include<stdio.h>
#include<stdlib.h>
struct n{
int d;
struct n*nx;
};
struct n*h=NULL;
void ib(){
struct n*p=(struct n*)malloc(sizeof(struct n)),*t;
printf("Value: ");
scanf("%d",&p->d);
if(h==NULL){
h=p;
p->nx=h;
return;
}
t=h;
while(t->nx!=h)t=t->nx;
p->nx=h;
t->nx=p;
h=p;
}
void ie(){
struct n*p=(struct n*)malloc(sizeof(struct n)),*t;
printf("Value: ");
scanf("%d",&p->d);
if(h==NULL){
h=p;
p->nx=h;
return;
}
t=h;
while(t->nx!=h)t=t->nx;
t->nx=p;
p->nx=h;
}
void db(){
struct n*p,*t;
if(h==NULL){
printf("Empty\n");
return;
}
if(h->nx==h){
printf("Deleted:%d\n",h->d);
free(h);
h=NULL;
return;
}
t=h;
while(t->nx!=h)t=t->nx;
p=h;
printf("Deleted:%d\n",p->d);
h=h->nx;
t->nx=h;
free(p);
}
void de(){
struct n*p,*q;
if(h==NULL){
printf("Empty\n");
return;
}
if(h->nx==h){
printf("Deleted:%d\n",h->d);
free(h);
h=NULL;
return;
}
p=h;
while(p->nx!=h){
q=p;
p=p->nx;
}
printf("Deleted:%d\n",p->d);
q->nx=h;
free(p);
}
void display(){
struct n*p;
if(h==NULL){
printf("Empty\n");
return;
}
p=h;
do{
printf("%d ",p->d);
p=p->nx;
}while(p!=h);
printf("\n");
}
int main(){
int c;
while(1){
printf("\n1.Insert Begin\n2.Insert End\n3.Delete Begin\n4.Delete End\n5.Display\n6.Exit\nChoice:");
scanf("%d",&c);
if(c==1)ib();
else if(c==2)ie();
else if(c==3)db();
else if(c==4)de();
else if(c==5)display();
else if(c==6)break;
else printf("Wrong Choice\n");
}
return 0;
}
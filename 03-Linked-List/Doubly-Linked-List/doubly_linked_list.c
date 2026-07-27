#include<stdio.h>
#include<stdlib.h>
struct n{
struct n*pr;
int d;
struct n*nx;};
struct n*h=NULL;
void ib(){
struct n*p=(struct n*)malloc(sizeof(struct n));
printf("Value: ");
scanf("%d",&p->d);
p->pr=NULL;
p->nx=h;
if(h)h->pr=p;
h=p;}
void ie(){
struct n*p=(struct n*)malloc(sizeof(struct n)),*t;
printf("Value: ");
scanf("%d",&p->d);
p->nx=NULL;
if(h==NULL){
p->pr=NULL;
h=p;
return;}
t=h;
while(t->nx)t=t->nx;
t->nx=p;
p->pr=t;}
void db(){
struct n*p;
if(h==NULL){
printf("Empty\n");
return;}
p=h;
printf("Deleted:%d\n",p->d);
h=h->nx;
if(h)h->pr=NULL;
free(p);}
void de(){
struct n*p;
if(h==NULL){
printf("Empty\n");
return;}
if(h->nx==NULL){
printf("Deleted:%d\n",h->d);
free(h);
h=NULL;
return;}
p=h;
while(p->nx)p=p->nx;
printf("Deleted:%d\n",p->d);
p->pr->nx=NULL;
free(p);}
void display(){
struct n*p=h;
if(p==NULL){
printf("Empty\n");
return;}
while(p){
printf("%d ",p->d);
p=p->nx;}
printf("\n");}
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
else printf("Wrong Choice\n");}
return 0;}
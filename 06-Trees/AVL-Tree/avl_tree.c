#include<stdio.h>
#include<stdlib.h>

// Node
struct n{
int d,h;
struct n*l,*r;
};

int mx(int a,int b){
return a>b?a:b;
}

int ht(struct n*p){
return p?p->h:0;
}

struct n*nn(int x){
struct n*p=malloc(sizeof(struct n));
p->d=x;
p->h=1;
p->l=p->r=NULL;
return p;
}

// Right Rotation
struct n*rr(struct n*y){
struct n*x=y->l;
struct n*t=x->r;

x->r=y;
y->l=t;

y->h=mx(ht(y->l),ht(y->r))+1;
x->h=mx(ht(x->l),ht(x->r))+1;

return x;
}

// Left Rotation
struct n*lr(struct n*x){
struct n*y=x->r;
struct n*t=y->l;

y->l=x;
x->r=t;

x->h=mx(ht(x->l),ht(x->r))+1;
y->h=mx(ht(y->l),ht(y->r))+1;

return y;
}

int bf(struct n*p){
return p?ht(p->l)-ht(p->r):0;
}

// AVL Insert
struct n*ins(struct n*p,int x){

if(!p)return nn(x);

if(x<p->d)
p->l=ins(p->l,x);

else if(x>p->d)
p->r=ins(p->r,x);

else
return p;

p->h=mx(ht(p->l),ht(p->r))+1;

int b=bf(p);

if(b>1&&x<p->l->d)
return rr(p);

if(b<-1&&x>p->r->d)
return lr(p);

if(b>1&&x>p->l->d){
p->l=lr(p->l);
return rr(p);
}

if(b<-1&&x<p->r->d){
p->r=rr(p->r);
return lr(p);
}

return p;
}

// Traversals
void pre(struct n*p){
if(p){
printf("%d ",p->d);
pre(p->l);
pre(p->r);
}
}

void in(struct n*p){
if(p){
in(p->l);
printf("%d ",p->d);
in(p->r);
}
}

void post(struct n*p){
if(p){
post(p->l);
post(p->r);
printf("%d ",p->d);
}
}

int main(){

struct n*rt=NULL;

int n,x,i;

printf("How many nodes: ");
scanf("%d",&n);

printf("Enter values: ");

for(i=0;i<n;i++){
scanf("%d",&x);
rt=ins(rt,x);
}

printf("\nPreorder : ");
pre(rt);

printf("\nInorder  : ");
in(rt);

printf("\nPostorder: ");
post(rt);

printf("\n");

return 0;
}
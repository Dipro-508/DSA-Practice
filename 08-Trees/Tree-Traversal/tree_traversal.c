#include<stdio.h>
#include<stdlib.h>

// Node
struct n{
int d;
struct n*l,*r;
};

// Create Node
struct n*nn(int x){
struct n*p=(struct n*)malloc(sizeof(struct n));
p->d=x;
p->l=p->r=NULL;
return p;
}

// BST Insert
struct n*ins(struct n*t,int x){
if(t==NULL)return nn(x);
if(x<t->d)t->l=ins(t->l,x);
else if(x>t->d)t->r=ins(t->r,x);
return t;
}

// Preorder
void pre(struct n*t){
if(t){
printf("%d ",t->d);
pre(t->l);
pre(t->r);
}
}

// Inorder
void in(struct n*t){
if(t){
in(t->l);
printf("%d ",t->d);
in(t->r);
}
}

// Postorder
void post(struct n*t){
if(t){
post(t->l);
post(t->r);
printf("%d ",t->d);
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
#include<stdio.h>
#include<stdlib.h>

// Node
struct n{
    int d;
    struct n *l,*r;
};

// Create Node
struct n*nn(int x){
    struct n*p=malloc(sizeof(struct n));
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

// Inorder
void in(struct n*t){
    if(t){
        in(t->l);
        printf("%d ",t->d);
        in(t->r);
    }
}

// Searching
struct n*sea(struct n*t,int x){
    if(t==NULL||t->d==x)return t;
    if(x<t->d)return sea(t->l,x);
    return sea(t->r,x);
}

// Minimum
struct n*mn(struct n*t){
    while(t->l)t=t->l;
    return t;
}

// Maximum
struct n*mx(struct n*t){
    while(t->r)t=t->r;
    return t;
}

// Deletion
struct n*del(struct n*t,int x){

    if(t==NULL)return t;

    if(x<t->d)t->l=del(t->l,x);

    else if(x>t->d)t->r=del(t->r,x);

    else{

        if(t->l==NULL){

            struct n*p=t->r;
            free(t);
            return p;
        }

        else if(t->r==NULL){

            struct n*p=t->l;
            free(t);
            return p;
        }

        struct n*p=mn(t->r);
        t->d=p->d;
        t->r=del(t->r,p->d);
    }

    return t;
}

int main(){

    struct n *rt=NULL,*p;
    int n,x,s,d;

    printf("How many numbers? ");
    scanf("%d",&n);

    printf("Enter %d numbers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        rt=ins(rt,x);
    }

    printf("Inorder : ");
    in(rt);

    printf("\nEnter value to search: ");
    scanf("%d",&s);

    p=sea(rt,s);

    if(p)
        printf("Found");
    else
        printf("Not Found");

    printf("\nMin=%d",mn(rt)->d);
    printf("\nMax=%d",mx(rt)->d);

    printf("\nEnter value to delete: ");
    scanf("%d",&d);

    rt=del(rt,d);

    printf("After Delete : ");
    in(rt);

    return 0;
}
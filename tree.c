#include "tree.h"
#include<stddef.h>
void createTree(TreeType *t){
   *t=NULL;
}
int EmptyTree(TreeType t){
      return (!t); // t == NULL
}
int FullTree(TreeType t){
    return 0;
}
void Inorder(TreeType t,void(*pvisit)(EntryType*)){
    if(t){
    Inorder(t->left,pvisit);
    (*pvisit)(&(t->info));
    Inorder(t->right,pvisit);
    }
}
void preorder(TreeType t,void(*pvisit)(EntryType)){
    if(t){
    (*pvisit)(t->info);
    preorder(t->left,pvisit);
    preorder(t->right,pvisit);
    }
}
void postorder(TreeType t,void(*pvisit)(EntryType)){
    if(t){
     postorder(t->left,pvisit);
     postorder(t->right,pvisit);
     (*pvisit)(t->info);}
}
int Size(TreeType t){
    if(t)
       return (1+Size(t->left)+Size(t->right));
    return 0;
}
int Height(TreeType t){
    if(t)
       return Height(t->left)>Height(t->right)?1+Height(t->left):1+Height(t->right);
       //return 1+max(Height(t->left),Height(t->right));
    return 0;
}
void Clear(TreeType *t){
     if(*t){
        Clear(&(*t)->left);
        Clear(&(*t)->right);
        free(*t);
        *t=NULL;
     }
}
void Insert(TreeType *t,EntryType item){
    NodeTree *p=(NodeTree *)malloc(sizeof(NodeTree));
    p->info=item;
    p->left=NULL;
    p->right=NULL;
    if(!(*t))*t=p;
    else{
    NodeTree *pre,*cur;
     cur=*t;
     while(cur){
        pre=cur;
        if(item<cur->info)
            cur=cur->left;
        else
            cur=cur->right;
     }
     if(item<pre->info)
        pre->left=p;
     else
        pre->right=p;
    }
}
void DeletNode(TreeType *pt){
  NodeTree *q=*pt;
  if(!q->right)*pt=q->left;
  else if(!q->left)*pt=q->right;
  else{  // have two chilInsert(&t,15)dren
        NodeTree *r=NULL;
        q=q->left;  // max right in left swap whith node
        while(q->right){
             r=q;
             q=q->right;
        }
        (*pt)->info=q->info;
        if(r)
            r->right=q->left;
        else (*pt)->left=q->left;
        free(q);
  }
}
int Delete(TreeType *t,EntryType k){
    int found=0; NodeTree *q=*t,*r=NULL;
    while(q&&!(found =(k==q->info)))
    {
        r=q;
        if(k<q->info)
            q=q->left;
        else
            q=q->right;
    }
    if(found){
        if(!r)DeletNode(t);
        else if(k<r->info)DeletNode(&r->left);
        else DeletNode(&r->right);
        }
    return found;
}
// BST
int search_BST(TreeType t,EntryType k){
   NodeTree *q;
   q=t;   int found=0;
   while(q){
     if(k<q->info)q=q->left;
     else if(k>q->info)q=q->right;
     else {found=1;break;}
   }
return found;
}
//binary search tree (BST) sort tree
//but binary tree not sort tree

int search_binary_tree(TreeType t,EntryType k){
    static int c=0;
    if(t){
       if(t->info==k)c=1;
    search_binary_tree(t->left,k);
    search_binary_tree(t->right,k);
    return c;
    }
}

int leaves_count(TreeType t){
    if(!(t))
        return 0;
    if(!t->right&&!t->left)
        return 1;
    return leaves_count(t->left)+ leaves_count(t->right);
}

void printLevel(TreeType t){
int h=Height(t),i;
for(i=1;i<=h;i++)
{
    givenLevel(t,i);
    printf("\n");
}
}
void givenLevel(TreeType t,int level){
  if(!t)
    return;
  if(level==1)
    printf("%d ",t->info);
  else if(level>1)
  {
      givenLevel(t->left,level-1);
      givenLevel(t->right,level-1);
  }
}

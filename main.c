#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tree {
	int id;
	int weight;
	struct tree *left, *right;
} tree;



void push_tree(tree **T,int id)
{
  tree *ptr=(tree*)malloc(sizeof(tree));
  ptr->id=id;
  ptr->left=NULL;
  ptr->right=NULL;
  int w=rand()%3;
  if (w==0)
   ptr->weight=-1;
  if (w==1)
   ptr->weight=0;
  if (w==2)
   ptr->weight=1;

  if ((*T)==NULL)
  {
    *T=ptr;
    return;
  }
    tree *tmp=*T;
    while (1==1)
    {

      if (id<tmp->id)
      {
          if (tmp->left==NULL)
          {
              tmp->left=ptr;
              return;
          }
            tmp=tmp->left;
      }
      else
      {
        if (tmp->right==NULL)
          {
              tmp->right=ptr;
              return;
          }
        tmp=tmp->right;
      }
    }
}

void del (tree **T,int del_id)
{
   tree *del_link=*T;
   tree *parent;
   while (del_id!=del_link->id)
   {
       if (del_id<del_link->id)
       {
        parent=del_link;
        del_link=del_link->left;
       }
       else
       {
        parent=del_link;
        del_link=del_link->right;
       }
   }
   if ((del_link->left==NULL)&&(del_link->right==NULL))
   {
       if (parent->left == del_link)
       parent->left=NULL;
       else
       parent->right=NULL;
       free(del_link);
       return;
   }
   if (del_link->left==NULL)
   {
       if (parent->left == del_link)
       parent->left=del_link->right;
       else
       parent->right=del_link->right;
       return;
   }
   if (del_link->right==NULL)
   {
       if (parent->left == del_link)
       parent->left=del_link->left;
       else
       parent->right=del_link->left;
       return;
   }
   tree *min=del_link->right;
   while (min->left!=NULL)
    min=min->left;
    printf("%d\n",min->id);
    int t=min->id,w=min->weight;
   del(T,t);
   del_link->id=t;
   del_link->weight=w;


}


void show(tree *t, int n) {
    char s[10];
    itoa(n*3 ,s, 10);
    char ss[] = "%";
    strcat(ss, s);
    strcat(ss, "d(%d)\n"); //ss=Ф% число d\nФ
	if (t != NULL)
    {
		show(t->left, n + 1);
		printf(ss, t->id,t->weight);
		show(t->right, n + 1);
	}

}

void poz_leaves(tree *T,tree *parent)
{
    if (T==NULL)
        return;
    if ((T->left==NULL)&&(T->right==NULL)&&(T->weight>=0))
    printf("%d(%d)\n",T->id,T->weight);
    poz_leaves(T->left,T);
    poz_leaves(T->right,T);
}


void main()
{
  tree *T=NULL;
  int N=10,id,n;
  for(int i=0;i<N;i++)
    push_tree(&T,abs(rand()%100));
  while (n!=5)
  {
      printf("1. Show tree\n");
      printf("2. Add element\n");
      printf("3. Delete element\n");
      printf("4. Show leaves with not negative weights\n");
      printf("5. Exit\n");
      scanf("%d",&n);
      switch(n)
      {
      case 1:
       show(T,4);
       break;
      case 2:
        printf("Enter element ID\n");
        scanf("%d",&id);
        push_tree(&T,id);
        break;
      case 3:
        printf("Enter element ID\n");
        scanf("%d",&id);
        del(&T,id);
        break;
      case 4:
          poz_leaves(T,NULL);
          break;
      }
  }
}


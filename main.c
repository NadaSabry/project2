#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main()
{
    TreeType t;
    createTree(&t);
    //printf("%d\n",EmptyTree(t));
//    Insert(&t,36);
//    Insert(&t,45);
//    Insert(&t,23);
//    Insert(&t,115);
//    Insert(&t,98);
//    Insert(&t,41);
//    Insert(&t,39);
//    Insert(&t,69);
//    Insert(&t,76);

    Insert(&t,10);
    Insert(&t,5);
    Insert(&t,15);
    Insert(&t,13);
    Insert(&t,7);
    Insert(&t,2);
    Insert(&t,9);
    Insert(&t,6);
    Insert(&t,11);
    Insert(&t,20);


//    Delete(&t,45);
//    Delete(&t,89);
//    Delete(&t,36);
    void print (EntryType *x){
      printf("%d \n",*x);
    }
    void increment(EntryType *x)
    {
        (*x)++;
    }
      Inorder(t,print);
      printf("\n");

      printLevel(t);

      printf("%d",Height(t));

   //   printf("%d\n",NumberLeaves(&t));
 //     printf("%d....\n",Search(t,50));

  //  preorder(t,print);
 //   postorder(t,print);

    return 0;
}

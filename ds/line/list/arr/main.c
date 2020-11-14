#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"
int main(){
    datatype arr[] = {12,23,34,45,56};
    datatype arr1[] = {78,89,12,23};
    int i = 0,err = 111;

    sqlist *list = NULL;
    sqlist_create1(&list);
    if(list == NULL){
        fprintf(stderr,"list sqlist_create1() failed!\n");
        exit(1);
    }

    sqlist *list1 = NULL; 
    list1 = sqlist_create();
    if(list1 == NULL){
        fprintf(stderr,"list1 sqlist_create() failed!\n");
        exit(1);
    }

    //插入list
    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++){
        err = sqlist_insert(list,0,&arr[i]);
        if(err != 0){
            if(err == -1)    
                fprintf(stderr,"the arr is full\n");
            else if(err == -2)
                fprintf(stderr,"the pos you want to insert is wrong\n");
            else 
                fprintf(stderr,"other error!!!\n");
            
            exit(1);
        }
    }

    //插入list1
    for(i = 0; i < sizeof(arr1)/sizeof(*arr1); i++){
        sqlist_insert(list1,0,&arr1[i]);
    }


    sqlist_display(list);
    sqlist_display(list1);
    sqlist_union(list,list1);
#if 0
    sqlist_display(list);

    sqlist_delete(list,1);

    sqlist_display(list);

#endif

    sqlist_display(list);

    sqlist_destroy(list);
    sqlist_destroy(list1);

    exit(0);
}

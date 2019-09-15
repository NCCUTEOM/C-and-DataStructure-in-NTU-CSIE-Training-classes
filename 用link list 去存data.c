#include<stdio.h>
#include<stdlib.h>

struct _node{     
    //資料型態 變數名稱;
    int data;
    struct _node *next;
};  
typedef struct _node node;
int main(){
	
	int main()
{
    int input[] = {11,22,33,44,55,-1};
    int i = 0;
    node *head=NULL, *ptr, *p4d;
    int value;
    
    while(1){
        //scanf("%d", &value);
        value = input[i]; i++;
        if(value == -1)
            break;
        if(head==NULL){
            head = (node *)malloc(sizeof(node));
            printf("head => %d\n", head);
            ptr = head; 
            ptr->data = value;
            ptr->next = NULL;           
        }
        else{
            head = (node *)malloc(sizeof(node));
            printf("head => %d\n", head);
            head->data = value;
            head->next = ptr;
            ptr = head;                       
        }
    }       
ptr = head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
    //release
    ptr = head;
    while(ptr!=NULL){
        p4d = ptr->next;
        free(ptr);
        ptr = p4d;
    }
  
      return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

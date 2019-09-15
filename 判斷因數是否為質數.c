#include<stdio.h>
#include<stdlib.h>




struct _node{
	int data;
	struct _node *next;
	struct _node *previous;
};
typedef struct _node node;

int is_prime(int check){
	int k;
	if(check ==1 || check ==2){
		return 1;
	}
	else{
	
		for(k=2;k<check;k++){
			if(check%k ==0){
				return 0;
				break;
			}
		
		}
	}
}


int main(){
	int number,i;
	node *head=NULL, *ptr,*tail;

	scanf("%d",&number);
	
	ptr = head;
//	previous = NULL;

	for(i=1;i<=number/2;i++){
	
	
	if(number%i ==0){
	
	
	
        if ( ptr == NULL ){/*指標ptr是否是NULL */
                
            
                head = (node *)malloc(sizeof(node)); 
                head->previous = NULL;

                ptr = head;
                ptr->data = i; 
                ptr->next = (node *)malloc(sizeof(node));
                ptr = ptr->next;
                ptr->previous = head;
                ptr->next = NULL;
        }
		
		else{
                node *tmp;
                ptr->data = i; 
                ptr->next = (node *)malloc(sizeof(node));
                tmp = ptr;
                ptr = ptr->next;
                ptr->previous = tmp;
                ptr->next = NULL;
                
                
        }    
		
	}
	}	
	ptr->data = number;
	tail = ptr;
	
	
	
   	
	   
   	char qkey;
   	while(1){
   		
   	printf("輸入h:前序列印\n");
	printf("輸入t:反序列印\n");
	printf("輸入q:exit...\n");
   	
	scanf("%c",&qkey);
	switch(qkey){
	
   	
   	case 'h':
	
		ptr = head;
		while(ptr!=NULL){
    	  	printf("%d ", ptr->data);
      		if(is_prime(ptr->data) ==0){
      			printf("NO\n");
   			}
   			else{
		   	printf("YES\n");
			}
		   
      	
       		ptr = ptr->next;
    	
		}
    break;
    case 't':
	
    	ptr = tail;
    	while(ptr!=NULL){
    	  	printf("%d ", ptr->data);
      		if(is_prime(ptr->data) ==0){
      			printf("NO\n");
   			}
   			else{
		   	printf("YES\n");
			}
		   
      	
       		ptr = ptr->previous;
    	
		}
	break;
    	
	
	case 'q':
		return 0;
	}
	}

//	return 0;
}

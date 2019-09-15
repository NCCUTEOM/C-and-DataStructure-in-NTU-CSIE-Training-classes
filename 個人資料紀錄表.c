#include<stdio.h>
#include<stdlib.h>


struct _node{     
    //資料型態 變數名稱;
    char name[10];
    char mail[30];
    char number[10];
    struct _node *next;
};  
typedef struct _node node;

int length (node *head ) /* 此函數計算節點之鏈結長度 */
{
	int num=0;
	node *ptr = head;
	while (ptr != NULL){
		num ++;
		ptr = ptr->next;
	}
return num;
}

void freenode (node *p) /* 此函數將節點還給記憶體 */
{
free(p);
}

node *getnode () {/* 此函數產生一個新節點 */
	node *p;
	p = (node *) malloc(sizeof(node));
	/* malloc 會動態地配置大小為sizeof 的記憶體*/
	/* sizeof 會傳回一個型態為node之值*/
	if ( p == NULL){
		printf ("記憶體不足");
		exit(1);
	}
	return p;
}

node *find_node(node*, char* );

node *delete_node(node *head, node *ptr){
	node *previous; /* 指向前一節點 */
	if ( ptr == head ) /* 是否是串列開始 */
		/* 第一種情況: 刪除第一個節點 */
	{
	head = head->next;
	}	
	else{
		previous = head;
		while ( previous->next != ptr ) /* 找節點ptr的前節點 */
		previous = previous->next;
			if ( ptr->next == NULL ) /* 是否是串列結束 */
			/* 第二種情況: 刪除最後一個節點 */
			previous->next = NULL; /* 最後一個節點 */
			else
			/* 第三種情況: 刪除中間節點 */
			previous->next = ptr->next; /* 圖(3)之步驟(1) */
			}
			freenode(ptr); /* 此函數將節點歸還給記憶體 */
			return(head);
}

node *insert_node (node *head, node *ptr, node input){
				node *new_node; /* 新節點指標變數 */
				new_node = getnode(); /* 建立新節點,取得一個可用節點 */
				*new_node = input; /* 建立節點內容 */
				new_node->next = NULL; /* 設定指標初值 */
				if ( ptr == NULL ) /* 指標ptr是否是NULL */
				{
				/* 第一種情況: 插入第一個節點 */
				new_node->next = head; /* 新節點成為串列開始 */
				head = new_node;
				}
				else
				{
					if ( ptr->next == NULL ) /* 是否是串列結束 */
						/* 第二種情況: 插入最後一個節點 */
					ptr->next = new_node; /* 最後指向新節點 */
					else
					{
						/* 第三種情況: 插入成為中間節點 */
						new_node->next = ptr->next; /* (3) 新節點指向下一節點 (3)*/
						ptr->next = new_node; /* 節點ptr指向新節點 (4)*/
					}
				}
	return (head);
}
	
	int main(){
	

    int i = 0;
    node *head=NULL, *ptr,input,*p4d;
    char op;
   	char compare[10];

    
    while(1){
    //	printf("i 新增\nd 刪除\nf 尋找\nq 離開\ng 長度\nl 列印\n");
    	scanf(" %c",&op);
    	
    	switch(op){
		
    		case 'i':
    			scanf(" %s",&input.name);
				scanf(" %s",&input.mail);
				//fgets(input.name,sizeof(input.name),stdin);
    			scanf(" %s",&input.number);
				
				ptr = head;
				if(head==NULL){
					head=insert_node(head, NULL, input);
				}
				else {
					while(ptr->next != NULL)
						ptr = ptr->next;
						head=insert_node(head, ptr, input);
				}
    			
    			
    		break;

			case 'd':
				scanf(" %s",compare);
			
					ptr = find_node(head, compare);
					if(ptr != NULL){
						head = delete_node(head, ptr);
						printf("Delete ok\n");
					}
					else
						printf("Can not delete\n");
					
    			
    			
    		break; 
			
			case 'f':
				scanf(" %s",compare);
				ptr = find_node(head, compare);
				if(ptr != NULL){
					printf("found\n");
					printf("%s\n", ptr->name);
        			printf("%s\n",ptr->mail);
        			printf("%010d\n\n",atoi(ptr->number));
        		}
				else
					printf("Not found\n");
    			
    			
    		break;
			
			case 'q':
				return 0;
    			
    			
    		break;
			
			case 'g':
				printf("%d\n",length(head));
    			
    			
    		break;
			
			case 'l':
				ptr = head;
   				while(ptr!=NULL){
        			printf("%s\n", ptr->name);
        			printf("%s\n",ptr->mail);
        			printf("%010d\n\n",atoi(ptr->number));
        			ptr = ptr->next;
        		}
        		
        	break;
    
    			
    			
   		
    		
    		
    	}	
       
        
    }       
    sys("PAUSE");

    
    //release
    ptr = head;
    while(ptr!=NULL){
        p4d = ptr->next;
        free(ptr);
        ptr = p4d;
    }

      return 0;
}
	
	
	
	
	
node *find_node(node *head, char compare[]){

	node *ptr;
	ptr = head; /* 指向串列起始 */
	
	while ( ptr != NULL ) /* 走訪串列 */{
		if(strcmp(ptr->name,compare )==0 ){ /* 找尋data */
			return ptr;
		} /* 找到 (ptr != NULL)*/
		
		ptr = ptr->next; /* 指向下一節點 */
	}
		return ptr; /* 找不到 (ptr == NULL)*/
	
}
	
	
	
	
	
	

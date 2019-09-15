#include<stdio.h>
#include<stdlib.h>


struct _node{     
    //��ƫ��A �ܼƦW��;
    char name[10];
    char mail[30];
    char number[10];
    struct _node *next;
};  
typedef struct _node node;

int length (node *head ) /* ����ƭp��`�I���쵲���� */
{
	int num=0;
	node *ptr = head;
	while (ptr != NULL){
		num ++;
		ptr = ptr->next;
	}
return num;
}

void freenode (node *p) /* ����ƱN�`�I�ٵ��O���� */
{
free(p);
}

node *getnode () {/* ����Ʋ��ͤ@�ӷs�`�I */
	node *p;
	p = (node *) malloc(sizeof(node));
	/* malloc �|�ʺA�a�t�m�j�p��sizeof ���O����*/
	/* sizeof �|�Ǧ^�@�ӫ��A��node����*/
	if ( p == NULL){
		printf ("�O���餣��");
		exit(1);
	}
	return p;
}

node *find_node(node*, char* );

node *delete_node(node *head, node *ptr){
	node *previous; /* ���V�e�@�`�I */
	if ( ptr == head ) /* �O�_�O��C�}�l */
		/* �Ĥ@�ر��p: �R���Ĥ@�Ӹ`�I */
	{
	head = head->next;
	}	
	else{
		previous = head;
		while ( previous->next != ptr ) /* ��`�Iptr���e�`�I */
		previous = previous->next;
			if ( ptr->next == NULL ) /* �O�_�O��C���� */
			/* �ĤG�ر��p: �R���̫�@�Ӹ`�I */
			previous->next = NULL; /* �̫�@�Ӹ`�I */
			else
			/* �ĤT�ر��p: �R�������`�I */
			previous->next = ptr->next; /* ��(3)���B�J(1) */
			}
			freenode(ptr); /* ����ƱN�`�I�k�ٵ��O���� */
			return(head);
}

node *insert_node (node *head, node *ptr, node input){
				node *new_node; /* �s�`�I�����ܼ� */
				new_node = getnode(); /* �إ߷s�`�I,���o�@�ӥi�θ`�I */
				*new_node = input; /* �إ߸`�I���e */
				new_node->next = NULL; /* �]�w���Ъ�� */
				if ( ptr == NULL ) /* ����ptr�O�_�ONULL */
				{
				/* �Ĥ@�ر��p: ���J�Ĥ@�Ӹ`�I */
				new_node->next = head; /* �s�`�I������C�}�l */
				head = new_node;
				}
				else
				{
					if ( ptr->next == NULL ) /* �O�_�O��C���� */
						/* �ĤG�ر��p: ���J�̫�@�Ӹ`�I */
					ptr->next = new_node; /* �̫���V�s�`�I */
					else
					{
						/* �ĤT�ر��p: ���J���������`�I */
						new_node->next = ptr->next; /* (3) �s�`�I���V�U�@�`�I (3)*/
						ptr->next = new_node; /* �`�Iptr���V�s�`�I (4)*/
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
    //	printf("i �s�W\nd �R��\nf �M��\nq ���}\ng ����\nl �C�L\n");
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
	ptr = head; /* ���V��C�_�l */
	
	while ( ptr != NULL ) /* ���X��C */{
		if(strcmp(ptr->name,compare )==0 ){ /* ��Mdata */
			return ptr;
		} /* ��� (ptr != NULL)*/
		
		ptr = ptr->next; /* ���V�U�@�`�I */
	}
		return ptr; /* �䤣�� (ptr == NULL)*/
	
}
	
	
	
	
	
	

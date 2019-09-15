#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BTreeNode
{
    char name1[10];
	char number1[10];
    struct BTreeNode *left;
    struct BTreeNode *right;
};
typedef struct BTreeNode node;

void print_inorder(node *ptr){
	if(ptr != NULL){
		print_inorder(ptr->left);
		printf("Name: %s\n",ptr->name1);
		printf("Phone: %s\n",ptr->number1);
	//	puts("");
		print_inorder(ptr->right);
	}	
}
void print_preorder(node *ptr){
	if(ptr != NULL){
		printf("Name: %s\n",ptr->name1);
		printf("Phone: %s\n",ptr->number1);
	//	puts("");

		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}	
}

void print_postorder(node *ptr){
	if(ptr != NULL){
	
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		printf("Name: %s\n", ptr->name1);
		printf("Phone: %s\n",ptr->number1);
	//	puts("");

	}	
}

node *find_node(node *ptr, char name[]){
	while(ptr != NULL){
		if(strcmp(ptr->name1,name)==0)
			return ptr;
		else{
			if(strcmp(ptr->name1,name)>0)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
	}
	return NULL;
}


void releaseBTree(node *ptr)
{
    if(ptr != NULL)
    {
        releaseBTree(ptr->left);
        releaseBTree(ptr->right);
        free(ptr);
    }
}
/*node *search_node(node *ptr, int value)
{
    node *temp;
 
    if(ptr != NULL)
    {
    	printf("%d ",ptr->data);
        //?????????????
        if(ptr->data == value)
            return ptr;
        else
        {
            temp = search_node(ptr->left, value);
            if(temp != NULL)
                return temp;
            temp = search_node(ptr->right, value);
            if(temp != NULL)

                return temp;
        }
    }
    return NULL;
}
*/
// ��Y�Ȥ����`�I
node *find_parent(node *ptr, char name[], int *pos)
{
	node *parent;

	parent = ptr;	// �qptr�}�l��
	*pos = 0;
	while(ptr != NULL)	
	{
		if(strcmp(ptr->name1,name)==0)	// ���ؼ�
			return parent;		// �^�Ǧ��`�I�����`�I
		else
		{
			parent = ptr;
			if(strcmp(ptr->name1,name)>0)
			{
				*pos = -1;			// ptr�bparent���l��
				ptr = ptr->left;	// ������
			}
			else
			{
				*pos = 1;			// ptr�bparent�k�l��
				ptr = ptr->right;	// ���k��
			}
		}
	}
	return NULL;	// �䤣��
}

// �R���`�I
node *delete_node(node *root, char name[]){
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = find_parent(root, name, &pos);	// �qroot�}�l,��value�����`�I
	if(parent != NULL)	// �����, �ǳƧR��
	{
		switch(pos)	// �P�_�ثe�`�I�b���`�I����Υk��
		{
			case -1:
				ptr = parent->left;
				break;
			case 1:
				ptr = parent->right;
				break;
			case 0:
				ptr = parent;
				break;
		}
		if(ptr->left == NULL)		// ���p1: �`�I�S�����l�� �p�G�n�R���O�ڸ`�I
		{
			if(parent == ptr)	// �p�G�n�R���O�ڸ`�I
				root = root->right;
			else				// ��L
			{
				if( pos == 1 )
				{
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I���k�`�I
					parent->right = ptr->right;
				}
				else
				{
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I���k�`�I
					parent->left = ptr->right;
				}
			}
			free(ptr);
		}
		else if(ptr->right == NULL)	// ���p2: �`�I�S���k�l��
		{
			if(parent != ptr)
			{
				if( pos == 1 )
				{
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I�����`�I
					parent->right = ptr->left;
				}
				else
				{
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I�����`�I
					parent->left = ptr->left;
				}
			}
			else
				root = root->left;
			free(ptr);
		}
		else						// ���p3: �`�I�����k�l��
		{
			parent = ptr;
			next = ptr->left;	// ����N�Inext, �qptr����}�l��
			if(next->right != NULL){
			
				while(next->right != NULL)	// �����l�`�I���k�l���̤j�ȷ���N�I
				{
					parent = next;		// parent��next�����`�I
					next = next->right;
				}
				parent->right = next->left;
				
				strcpy(ptr->number1,  next->number1);
				strcpy(ptr->name1,  next->name1); 
 
				
			}
			else{ 
				strcpy(ptr->number1,  next->number1);
				strcpy(ptr->name1,  next->name1); 
				// ���N!!
				parent->left = next->left;
			} 
			free(next);
		}
			
				
		
			 
	}
				
		
		
	return root;	// �^�Ǧ���
}



node *insert_node(node *root, char name[],char number[])
{
    node *new_node;
    node *current;
    node *parent;

    new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name1 ,name);
    strcpy(new_node->number1 ,number);

    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL)
    {
        root = new_node; //return new_node;
    }
    else
    {
        current = root;
        while(current != NULL)
        {
            parent = current;
            if(strcmp(current->name1,name)>0)
                current = current->left;
            else
                current = current->right;
        }
        if(strcmp(parent->name1, name)>0)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}






int main(){
    node *ptr,*root = NULL;
    char name[10];
    char number[10];
    char qkey;
    
  while(1){
    /*	puts("1 insert");
   	puts("2 list inorder");
   	puts("3 list preorder");
   	puts("4 list postorder");
   	puts("8 quit");*/
   	scanf("%c",&qkey);
   	switch(qkey){
   		case 'i':
			scanf(" %s",name);
			scanf(" %s",number);
	//		printf("%s\n",name);
	//		printf("%s\n",number);   			
			
   			
   			root = insert_node(root,name,number);
   			break;
   		case 'f':
			scanf(" %s",name);
			ptr = find_node(root, name);
			if(ptr != NULL){
			
				printf("found:\nName: %s\nPhone: %s\n", ptr->name1,ptr->number1);
			}
			else
				printf("Not found\n");
   			break;
   		case 'd':
			scanf(" %s",name);
   			ptr = find_node(root, name);
			if(ptr != NULL){
			
		    	root = delete_node(root,name);
		    	printf("delete %s ok\n",name);
		    }
   			else
   				printf("Cannot delete\n");
   			break;
   		case 'l':
   			print_inorder(root);
   			puts("");
   			break;
   		case 'm':
   			print_preorder(root);
   			puts("");
   			break;
   		case 'n':
   			print_postorder(root);
   			puts("");
   			break;
   		case 'q':
   			releaseBTree(root);
   			return 0;
   		}

   			
	}
	  
}

 


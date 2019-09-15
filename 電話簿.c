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
// 找某值之父節點
node *find_parent(node *ptr, char name[], int *pos)
{
	node *parent;

	parent = ptr;	// 從ptr開始找
	*pos = 0;
	while(ptr != NULL)	
	{
		if(strcmp(ptr->name1,name)==0)	// 找到目標
			return parent;		// 回傳此節點之父節點
		else
		{
			parent = ptr;
			if(strcmp(ptr->name1,name)>0)
			{
				*pos = -1;			// ptr在parent左子樹
				ptr = ptr->left;	// 往左找
			}
			else
			{
				*pos = 1;			// ptr在parent右子樹
				ptr = ptr->right;	// 往右找
			}
		}
	}
	return NULL;	// 找不到
}

// 刪除節點
node *delete_node(node *root, char name[]){
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = find_parent(root, name, &pos);	// 從root開始,找value之父節點
	if(parent != NULL)	// 有找到, 準備刪除
	{
		switch(pos)	// 判斷目前節點在父節點左邊或右邊
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
		if(ptr->left == NULL)		// 情況1: 節點沒有左子樹 如果要刪的是根節點
		{
			if(parent == ptr)	// 如果要刪的是根節點
				root = root->right;
			else				// 其他
			{
				if( pos == 1 )
				{
					//要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的右節點
					parent->right = ptr->right;
				}
				else
				{
					//要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的右節點
					parent->left = ptr->right;
				}
			}
			free(ptr);
		}
		else if(ptr->right == NULL)	// 情況2: 節點沒有右子樹
		{
			if(parent != ptr)
			{
				if( pos == 1 )
				{
					//要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的左節點
					parent->right = ptr->left;
				}
				else
				{
					//要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的左節點
					parent->left = ptr->left;
				}
			}
			else
				root = root->left;
			free(ptr);
		}
		else						// 情況3: 節點有左右子樹
		{
			parent = ptr;
			next = ptr->left;	// 找取代點next, 從ptr左邊開始找
			if(next->right != NULL){
			
				while(next->right != NULL)	// 往左子節點之右子樹找最大值當取代點
				{
					parent = next;		// parent為next之父節點
					next = next->right;
				}
				parent->right = next->left;
				
				strcpy(ptr->number1,  next->number1);
				strcpy(ptr->name1,  next->name1); 
 
				
			}
			else{ 
				strcpy(ptr->number1,  next->number1);
				strcpy(ptr->name1,  next->name1); 
				// 取代!!
				parent->left = next->left;
			} 
			free(next);
		}
			
				
		
			 
	}
				
		
		
	return root;	// 回傳此樹
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

 


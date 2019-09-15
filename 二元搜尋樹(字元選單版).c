#include<stdio.h>
#include<stdlib.h>
struct BTreeNode
{
    int data;
    struct BTreeNode *left;
    struct BTreeNode *right;
};
typedef struct BTreeNode node;

void print_inorder(node *ptr){
	if(ptr != NULL){
		print_inorder(ptr->left);
		printf("%d ", ptr->data);
		print_inorder(ptr->right);
	}	
}
void print_preorder(node *ptr){
	if(ptr != NULL){
		printf("%d ", ptr->data);
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}	
}
void print_postorder(node *ptr){
	if(ptr != NULL){
	
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		printf("%d ", ptr->data);
	}	
}

node *find_node(node *ptr, int value)
{
while(ptr != NULL)
{
if(ptr->data == value)
return ptr;
else
{
if(ptr->data > value)
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
node *search_node(node *ptr, int value)
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

// 找某值之父節點
node *find_parent(node *ptr, int value, int *pos)
{
	node *parent;

	parent = ptr;	// 從ptr開始找
	*pos = 0;
	while(ptr != NULL)	
	{
		if(ptr->data == value)	// 找到目標
			return parent;		// 回傳此節點之父節點
		else
		{
			parent = ptr;
			if(ptr->data > value)
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
node *delete_node(node *root, int value){
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = find_parent(root, value, &pos);	// 從root開始,找value之父節點
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
				ptr->data = next->data;
			}
			else{ 
				ptr->data = next->data;
				// 取代!!
				parent->left = next->left;
			} 
			free(next);
		}
			
				
		
			 
	}
				
		
		
	return root;	// 回傳此樹
}



node *insert_node(node *root, int value)
{
    node *new_node;
    node *current;
    node *parent;

    new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
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
            if(current->data > value)
                current = current->left;
            else
                current = current->right;
        }
        if(parent->data > value)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}






int main(){
    node *ptr,*root = NULL;
    int value;
    char qkey;
    
  while(1){
    puts("1 insert");
   	puts("2 list inorder");
   	puts("3 list preorder");
   	puts("4 list postorder");
   	puts("8 quit");
   	scanf("%c",&qkey);
   	switch(qkey){
   		case 'i':
   			scanf("%d",&value);
   			root = insert_node(root, value);
   			break;
   		case 'f':
   			scanf("%d",&value);
			ptr = find_node(root, value);
			if(ptr != NULL)
				printf("found: %d\n", ptr->data);
			else
				printf("Not found\n");
   			break;
   		case 'd':
   			scanf("%d",&value);
   			ptr = find_node(root, value);
			if(ptr != NULL){
			
		    	root = delete_node(root,value);
		    	printf("delete %d ok\n",value);
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

 


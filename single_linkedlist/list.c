#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct _node{
	void * data;
	struct node *next;
};
typedef struct _node node_t;
typedef struct _node * node_p;

node_p new_list(void){
	node_p node= malloc(sizeof(node_t));
	assert(node!=NULL);
	node->data = NULL;
	node->next = NULL;
	return node;
}

node_p new_node(void *data){
	node_p node = malloc(sizeof(node_t));
	assert(node!=NULL);
	node->data = data;
	node->next = NULL;
	return node;
}

int free_list(node_p head){
	node_p iterator = head, temp;
	while(iterator){
		temp = iterator;
		iterator = iterator->next;
		free(iterator);
	}
	return iterator;
}

node_p list_append(node_p head, void *data){
	node_p iterator = head;
	while(iterator->next != NULL){
		iterator = iterator->next;
	}
	iterator->next = new_node(data);
	return head;
}

node_p list_prepend(node_p head, void *data){
	node_p iterator = head;
	head = new_node(data);
	head->next = iterator;
	return head;
}

node_p list_for_each(node_p head, int (*func)(void *)){
	node_p iterator = head->next;
	while(iterator){
		func(iterator->data);
		iterator = iterator->next;
	}
}
node_p list_find_node(node_p head, node_p node){
}

node_p list_delete(node_p head, node_p node){
}

int print_list_ele(void *data){
	int number = *(int *)data;
	printf("%d\n", number);
	return 0;
}

int main(int argc, char *argv[]){
	node_p mylist = new_list();
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	for(int i=0; i< (sizeof(array)/sizeof(array[0])); i++){
		list_append(mylist, &array[i]);
	}
	list_for_each(mylist, print_list_ele);
	return 0;
}

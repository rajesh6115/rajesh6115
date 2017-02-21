#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct _node{
	void * data;
	struct _node* next;
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

int list_free(node_p head){
	node_p iterator = head, temp;
	while(iterator){
		temp = iterator;
		iterator = iterator->next;
		free(temp);
	}
	return 0;
}

node_p list_tail(node_p head){
	node_p iterator = head;
	while(iterator->next != NULL){
		iterator = iterator->next;
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
	if(data == NULL){
		return 0;
	}
	int number = *(int *)data;
	printf("%d\n", number);
	return 0;
}

int free_list_ele(void *data){
	if(data == NULL){
		return 0;
	}
	free(data);
	return 0;
}

int list_find_circular(node_p head){
	node_p fast = head;
	node_p slow = head;
	if(head == NULL || head->next == NULL){
		return 0;
	}
	do{
		if(fast->next->next){
			fast = fast->next->next;
			slow = slow->next;
			if(slow == fast){
				return 1;
			}
		}else{
			break;
		}
	}while(fast->next && slow->next);
	return 0;
}
int main(int argc, char *argv[]){
	if(argc < 2){
		fprintf(stderr, "USAGE: %s <numbers>\n", argv[0]);
		return -1;
	}
	node_p mylist = new_list();
	int *data = NULL;
	for(int i=1; i < argc; i++){
		data = malloc(sizeof(int));
		*data = atoi(argv[i]);
		list_append(mylist, data);
	}
	/*
	//int array[] = {1,2,3,4,5,6,7,8,9,10};
	int array[] = {1};
	for(int i=0; i< (sizeof(array)/sizeof(array[0])); i++){
		list_append(mylist, &array[i]);
	}
	*/
	node_p mytail = list_tail(mylist);
	mytail->next = mylist;
	printf("List is %s\n", list_find_circular(mylist)? "CIRCULAR":"NOT CIRCULAR");
	mytail->next = NULL;
	list_for_each(mylist, print_list_ele);
	list_for_each(mylist, free_list_ele);
	list_free(mylist);
	return 0;
}

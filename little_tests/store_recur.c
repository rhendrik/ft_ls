#include "test.h"

node *create_list()
{
	node *head;
	head = NULL;
	return (head);
}

int add_node(node **head, DIR *dir)
{
	node *current;
	node *new_node;

	current = head;
	new_node = malloc(sizeof(node));
	if (!new_node)
	{
		ft_putstr("ERR: memory alloc\n");
		return (-1);
	}
	new_node->dp = readdir(dir);
	new_node->next = NULL;
	if(!head)
	{
		*head = new_node;
		return (0);
	}
	else
	{
		new_node -> next = current;
		*head = new_node;
	}
	return (0);
}

void storedir(const char *name)
{
	DIR *dir;
	char *path;
	struct node *head;

	if (!(dir = opendir(name)))
		return ;
	head = create_list();

}

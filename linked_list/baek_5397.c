#include <stdio.h>
#include <stdlib.h>

typedef	char	list_data;

typedef struct		s_node
{
	list_data		data;
	struct s_node	*next;  // next node address
	struct s_node	*before;  // before node address
}					t_node;

typedef	struct	s_list
{
	t_node		*head;  // head node of list
	t_node		*cur;  // current node of list
	t_node		*tail;  // tail node of list
}				t_list;



void		list_init(t_list *list)
{
	list->head = (t_node *)malloc(sizeof(t_node));  // make dummy node
	list->head->next = NULL;
	list->cur = list->head;
	list->tail = list->head;
}

void		list_remove(t_list *list)
{
	t_node		*remem_node;

	remem_node = list->cur;  // remember node to be deleted
	
	// connection before node and next node
	list->cur->before->next = list->cur->next;
	if (list->cur->next)  // if next node exist,
		list->cur->next->before = list->cur->before;
	else
		list->cur->next = NULL;
	
	// current node reset
	list->cur = list->cur->before;
	
	free(remem_node);
	remem_node = NULL;
}

void		list_insert_tail(t_list *list, list_data data)
{	
	t_node	*new_node;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	
	// insert node
	new_node->next = NULL;
	if (!list->head->next)  // if node is not exist, 
	{
		new_node->before = list->head;
		list->head->next = new_node;
	}
	else  // if node is exist,
	{
		new_node->before = list->tail;
		list->tail->next = new_node;
	}
	list->tail = new_node;
}

void		list_insert_cur(t_list *list, list_data data)
{
	t_node	*new_node;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	
	// insert node
	new_node->next = list->cur->next;
	new_node->before = list->cur;
	list->cur->next->before = new_node;
	list->cur->next = new_node;
	list->cur = list->cur->next;
}



void		cursor_move_left(t_list *list)
{
	if (list->cur != list->head)
		list->cur = list->cur->before;
}

void		cursor_move_right(t_list *list)
{
	if (list->cur != list->tail)
		list->cur = list->cur->next;
}

void		delete_char(t_list *list)
{
	if (list->cur == list->tail)
		list->tail = list->tail->before;
	if (list->cur != list->head)
		list_remove(list);
}

void		insert_char(t_list *list, char c)
{
	if(list->cur == list->tail)
	{
		list_insert_tail(list, c);
		list->cur = list->tail;  // current node reset
	}
	else
		list_insert_cur(list, c);
}

void		show_list(t_list *list)
{
	list->cur = list->head;
	
	while (list->cur != list->tail)
	{
		list->cur = list->cur->next;
		printf("%c", list->cur->data);
	}
	printf("\n");
}

void	free_all(t_list *list)
{
	list->cur = list->head;
	
	while (list->cur != list->tail)
	{
		list->cur = list->cur->next;
		free(list->cur->before);
		list->cur->before = NULL;
	}
	free(list->cur);
	list->cur = NULL;
}

void		key_logger(char *str)
{
	t_list	list;  // dummy double linked list
	int	i;
	
	list_init(&list);  // list reset
	
	i = -1;
	while (str[++i])
	{
		if (str[i] == '<')
			cursor_move_left(&list);
		else if (str[i] == '>')
			cursor_move_right(&list);
		else if (str[i] == '-')
			delete_char(&list);	
		else
			insert_char(&list, str[i]);
	}
	
	show_list(&list);
	free_all(&list);
}



int			main(void)
{
	char	str[1000001];
	int		count;
	int 	i;
	
	scanf("%d", &count);
	getchar();  // remove the enter in the buffer
	
	i = -1;
	while (++i < count)
	{
		scanf("%s", str);
		getchar();
		key_logger(str);
	}
}

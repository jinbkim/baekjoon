#include <stdio.h>
#include <stdlib.h>

typedef	int	list_data;

typedef struct		s_node
{
	list_data		data;
	struct s_node	*before;
	struct s_node	*next;
}					t_node;

typedef int (*comp_func)(list_data, list_data);

typedef struct		s_list
{
	t_node			*head;
	t_node			*cur;
	comp_func		f;
}					t_list;

typedef	struct	s_al_graph
{
	int			vertex_num;
	int			edge_num;
	int			*visit_info;
	t_list		*list;  // adjacent list
}				t_al_graph;

#define QUEUE_SIZE 100

typedef	int	queue_data;

typedef	struct	s_queue
{
	int			front;
	int			rear;
	queue_data	q_arr[QUEUE_SIZE];
}				t_queue;



int			func1(list_data d1, list_data d2)
{
	return (d2 - d1);
}

void		list_init(t_list *list, comp_func f)
{
	list->head = (t_node *)malloc(sizeof(t_node));  // make dummy node
	list->head->next = NULL;
	list->f = f;
}

void		list_insert_comp(t_list *list, list_data data)
{	
	t_node	*new_node;
	t_node	*cur;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	
	// find position
	cur = list->head;  // head : starting point
	// repeat when priority of data is lower then next node
	while (cur->next && list->f(data, cur->next->data) < 0)
		cur = cur->next;

	// connection
	new_node->next = cur->next;
	if (cur->next)  // if cur is not tail
		cur->next->before = new_node;
	new_node->before = cur;
	cur->next = new_node;
}

int			list_next_node(t_list *list, list_data *data)
{
	if (list->cur->next == NULL)
		return (0);
	list->cur = list->cur->next;
	*data = list->cur->data;
	return (1);
}



void	queue_init(t_queue *q)
{
	q->front = -1;
	q->rear = -1;
}

int			queue_is_empty(t_queue *q)
{
	if (q->front == q->rear)
		return (1);
	return (0);
}

void	enter_queue(t_queue *q, queue_data data)
{
	q->q_arr[++(q->rear)] = data;
}

queue_data	delete_queue(t_queue *q)
{
	return (q->q_arr[++(q->front)]);
}



void		ft_memset(void *ptr, int value, size_t num)
{
	int	*arr;
	int i;
	
	arr = (int *)ptr;
	i = -1;
	while (++i < (int)(num / sizeof(int)))
		arr[i] = value;
}

void		graph_init(t_al_graph *graph, int vertex_num)
{
	int	i;
	
	graph->list = (t_list *)malloc(sizeof(t_list) * vertex_num);
	graph->visit_info = (int *)malloc(sizeof(int) * vertex_num);
	ft_memset(graph->visit_info, 0, sizeof(int) * vertex_num);  // reset visit history to 0
	graph->vertex_num = vertex_num;
	graph->edge_num = 0;
	
	i = -1;
	while (++i < vertex_num)
		list_init(&(graph->list[i]), func1);  // list reset
}

void		add_edge(t_al_graph *graph, int from, int to)
{
	list_insert_comp(&(graph->list[from]), to);
	list_insert_comp(&(graph->list[to]), from);
	(graph->edge_num)++;
}

int			visit_vertex(t_al_graph *graph, int vertex)
{
	if (!graph->visit_info[vertex])
	{
		graph->visit_info[vertex] = 1;
		//printf("%d ", vertex + 1);
		return (1);
	}
	return (0);
}

void		free_all(t_al_graph *graph)
{
	list_data	data;
	int			i;
	
	i = -1;
	while (++i < graph->vertex_num)
	{
		graph->list[i].cur = graph->list[i].head;  // head : starting point
		while (list_next_node(&(graph->list[i]), &data))
			free(graph->list[i].cur->before);
		free(graph->list[i].cur);
	}
	free(graph->list);
	free(graph->visit_info);
}



int			bfs_graph(t_al_graph *graph, int vertex)
{
	t_queue	q;
	int		next_vertex;
	int		result;
	
	queue_init(&q);  // queue reset
	
	visit_vertex(graph, vertex);
	result = 0;
	while (1)
	{
		// starting point : head(dummy node)
		graph->list[vertex].cur = graph->list[vertex].head;
		while (list_next_node(&(graph->list[vertex]), &next_vertex))
		{
			if (visit_vertex(graph, next_vertex))
			{
				enter_queue(&q, next_vertex);
				result++;
			}
		}
		if (queue_is_empty(&q))
			break ;
		else
			vertex = delete_queue(&q);
	}

	return (result);
}

int			virus_infection(int vertex_num, int size)
{
	t_al_graph	graph;
	int			vertex1;
	int			vertex2;
	int 		result;
	int			std;
	int			i;

	graph_init(&graph, vertex_num);  // adjacent list graph reset

	std = 1;  // standard vertex
	i = -1;
	while (++i < size)
	{
		scanf("%d %d", &vertex1, &vertex2);
		getchar();
		add_edge(&graph, vertex1 - std, vertex2 - std);
	}
	
	// when computer 1 is infected with virus, 
	// the number of computers transmitted is returned
	result = bfs_graph(&graph, 1 - std);
	
	free_all(&graph);
	return (result);
}



int			main(void)
{
	int			vertex_num;
	int			size;
	
	scanf("%d", &vertex_num);
	getchar();
	scanf("%d", &size);
	getchar();
	
	printf("%d\n", virus_infection(vertex_num, size));
}

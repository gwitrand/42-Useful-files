
#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_print_list(t_list *elem)
{
	t_list *list;

	list = elem;
	//printf("<=I==[%s]:", (char *)list->data);
		while (list->next)
	{
		list = list->next;
		if(list->data != NULL)
			printf("[[%s]]:\n",(char *)list->data);
	}
}

t_list			*ft_create_elem(void *data)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->data = data;
		tmp->next = NULL;
	}
	return (tmp);
}


void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

int		ft_list_size(t_list *begin_list)
{
	int count;

	count = 0;
	if (begin_list)
	{
		while (begin_list->next)
		{
			count++;
			begin_list = begin_list->next;
		}
		count++;
	}
	return (count);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	if (*begin_list)
	{
		list = ft_create_elem(data);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_elem(data);
}

int		main(int argc, char **argv)
{
	t_list	*list;
	char	*start;

	start = "list 0";
	list = ft_create_elem(start);
	ft_list_push_back(&list, "list 1");
	ft_list_push_back(&list, "list 2");
	ft_list_push_back(&list, "list 3");
	ft_list_push_back(&list, "list 4");
	ft_list_push_back(&list, "list 5");
	ft_list_push_back(&list, "list 6");
	ft_list_push_front(&list, "list insert");
	ft_print_list(list);
	printf("%i\n", ft_list_size(list));
	return (0);
}

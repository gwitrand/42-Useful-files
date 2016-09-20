#include <stdio.h>
#define FAIL (printf("fail\n") || 1)
#define GOES (printf("works!\n") && 0)

#include "ft_list.h"
t_list		*ft_create_elem(void *data);

int		main(void)
{
	t_list	*elem;
	int		lol;

	lol = 42;
	elem = ft_create_elem(&lol);
	if (elem->next != (void*)0)
		return FAIL;
	if (elem->data != &lol)
		return FAIL;
	return GOES;
}
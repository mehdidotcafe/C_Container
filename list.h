#ifndef C_LIST_
# define C_LIST_
# include <stdlib.h>

typedef struct	s_list
{
  void		*elem;
  struct s_list	*next;
}		t_list;

// init the list
t_list	*new_list();
// push element at the end of the list and return the updated list
t_list	*list_push_back(t_list *list, void *elem);
// push element at the front of the list and return the updated list
t_list	*list_push_front(t_list *list, void *elem);
// pop last element and return it, update the list
t_list	*list_pop_back(t_list **list);
// pop first element and return it, update the list
t_list	*list_pop_front(t_list **list);
// iterate throught the list and apply the function on each node
void	list_for_each(t_list *list, void (*fx)(void *elem, void *data),
		      void *data);
/*
  Iterate trought the list and check if
  parameter function returned 1 (success comparison case)
  and return the element
 */
void	*list_get_node(t_list *list, int (*fx)(void *elem, void *data),
		       void *data);
// get n-th element
void	*list_nth(t_list *list, int idx);
// delete list node
t_list	*list_delete_node(t_list *list, void *elem);
// delete all list, this function will not free the element if it's malloced
t_list	*list_delete(t_list *list);
// get length of the list
int	list_size(t_list *list);
// get last element of the list
void	*list_get_last(t_list *list);
// check if list is empty, return 1 if yes, 0 otherwise
int	list_empty(t_list *);
// clear the list, this also delete list node but not element of the nodes
t_list	*list_clear(t_list *);

#endif /* C_LIST */

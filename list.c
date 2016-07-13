#include "list.h"

t_list	*new_list()
{
  return (0);
}

t_list 	*list_push_back(t_list *list, void *elem)
{
  t_list	*tmp;
  t_list	*node;

  if (!(node = malloc(sizeof(*node))))
    return (0);
  node->elem = elem;
  node->next = 0;
  if (!(tmp = list))
    return (node);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = node;
  return (list);
}

t_list	*list_push_front(t_list *list, void *elem)
{
  t_list	*node;

  if (!(node = malloc(sizeof(*node))))
    return (0);
  node->elem = elem;
  node->next = list;
  return (node);
}

t_list	*list_pop_front(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  *list = (*list)->next;
  return (tmp);
}

t_list	*list_pop_back(t_list **list)
{
  t_list	*tmp;
  t_list	*prev;

  tmp = *list;
  prev = 0;
  while (tmp->next)
    {
      prev = tmp;
      tmp = tmp->next;
    }
  if (prev)
    prev->next = 0;
  return (tmp);
}

void	list_for_each(t_list *list, void (*fx)(void *, void *), void *data)
{
  t_list	*tmp;
  t_list	*tmp_n;

  tmp = list;
  while (tmp)
    {
      tmp_n = tmp->next;
      fx(tmp->elem, data);
      tmp = tmp_n;
    }
}

void	*list_get_node(t_list *list, int (*fx)(void *, void *), void *data)
{
  t_list	*tmp;
  t_list	*tmp_n;

  tmp = list;
  while (tmp)
    {
      tmp_n = tmp->next;
      if (fx(tmp->elem, data) == 1)
	      return (tmp->elem);
      tmp = tmp_n;
    }
  return (0);
}

void		*list_nth(t_list *list, int idx)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (tmp)
    {
      if (idx == i)
	return (tmp->elem);
      ++i;
      tmp = tmp->next;
    }
  return (0);
}

int		list_size(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (tmp)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}

t_list	*list_delete(t_list *list)
{
  if (list)
    list_delete(list->next);
  free(list);
  return (0);
}

t_list		*list_delete_node(t_list *list, void *elem)
{
  t_list	*tmp;
  t_list	*tmp_n;

  tmp = list;
  if (tmp && tmp->elem == elem)
    {
      tmp_n = tmp->next;
      free(tmp);
      return (tmp_n);
    }
  while (tmp)
    {
      if (tmp->next && tmp->next->elem == elem)
	     {
         tmp_n = tmp->next->next;
         free(tmp->next);
         tmp->next = tmp_n;
       }
      if (tmp)
	     tmp = tmp->next;
    }
  return (list);
}

void		*list_get_last(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp->next)
    tmp = tmp->next;
  return (tmp->elem);
}

int		list_empty(t_list *list)
{
  return (!!list);
}

t_list		*list_clear(t_list *list)
{
  return (list_delete(list));
}

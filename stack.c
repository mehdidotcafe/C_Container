#include "stack.h"

t_stack	*new_stack()
{
  return (0);
}

int	stack_empty(t_stack *stack)
{
  return (!!stack);
}

int		stack_size(t_stack *stack)
{
  t_stack	*tmp;
  int		i;

  i = 0;
  tmp = stack;
  while (tmp)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}

void		*stack_top(t_stack *stack)
{
  return (stack->elem);
}

t_stack		*stack_push(t_stack *stack, void *elem)
{
  t_stack	*node;

  if (!(node = malloc(sizeof(*node))))
    return (0);
  node->elem = elem;
  node->next = stack;
  return (node);
}

t_stack		*stack_pop(t_stack **stack)
{
  t_stack	*tmp;

  tmp = *stack;
  *stack = (*stack)->next;
  return (tmp);
}

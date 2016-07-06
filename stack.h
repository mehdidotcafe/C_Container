#ifndef C_STACK_
# define C_STACK_
# include <stdlib.h>

typedef struct		s_stack
{
  void			*elem;
  struct s_stack	*next;
}			t_stack;

// init stack
t_stack	*new_stack();
// check if stack is empty
int	stack_empty(t_stack *stack);
// return stack length
int	stack_size(t_stack *stack);
// get first element in stack
void	*stack_top(t_stack *stack);
// push element on stack, return the updated stack
t_stack	*stack_push(t_stack *stack, void *elem);
// pop first element of stack, and return it
t_stack	*stack_pop(t_stack **stack);

#endif /* !C_STACK_ */

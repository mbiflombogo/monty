#include "monty.h"

/**
 * add_node - add a new node to a circular linked list
 * @stack: double pointer to the beginning of the circular linked list
 * @n: value to add to the new node
 *
 * Description: the function will add the node to the begining if in
 * stack mode and the end if in queue mode
 *
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.queue == STACK || var.stack_len == 0)
		*stack = new;
	return (new);
}
/**
 * m_fs_close - close file stream
 * @status: status passed to exit
 * @arg: pointer to file stream
 *
 * Return: void
 */
void m_fs_close(int status, void *arg)
{
	FILE *fs;

	(void)status;

	fs = (FILE *) arg;
	fclose(fs);
}
/**
 * m_pchar - print character from top of stack
 * @stack: double pointer to top of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (var.stack_len < 1)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}

#include <stdio.h>
#include <stdlib.h>

#define ALLOCATE 0
#define FETCHPOINTERS 1

// Define a structure to store allocation information
typedef struct Allocation
{
	void				*ptr;
	struct Allocation	*next;
}						t_Allocation;

// Function to free all tracked allocations
void	free_all(t_Allocation *g_allocations)
{
	t_Allocation	*current;
	t_Allocation	*next;

	current = g_allocations;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	g_allocations = NULL;
}

// Function to allocate memory and keep track of it
t_Allocation	*my_malloc(size_t size, int FUNCTION)
{
	static t_Allocation		*g_allocations = NULL;
	t_Allocation			*new_alloc;

	if (FUNCTION)
		return (g_allocations);
	new_alloc = (t_Allocation *)malloc(sizeof(t_Allocation));
	if (!new_alloc)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free_all(g_allocations);
		exit(EXIT_FAILURE);
	}
	new_alloc->ptr = malloc(size);
	if (!new_alloc->ptr)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free_all(g_allocations);
		exit(EXIT_FAILURE);
	}
	new_alloc->next = g_allocations;
	g_allocations = new_alloc;
	return (new_alloc);
}

// TEST------------------------------------------------
int	main(void)
{
	int		*arr;
	char	*str;
	int		i;

	i = 0;
	arr = (int *)my_malloc(10 * sizeof(int), ALLOCATE)->ptr;
	str = (char *)my_malloc(50 * sizeof(char), ALLOCATE)->ptr;
	while (i < 10)
	{
		arr[i] = i;
		i++;
	}
	snprintf(str, 50, "Hello, World!");
	printf("Array: ");
	i = 0;
	while (i < 10)
		printf("%d ", arr[i++]);
	printf("\nString: %s\n", str);
	free_all(my_malloc(0, FETCHPOINTERS));
	return (0);
}
//----------------------------------------------------

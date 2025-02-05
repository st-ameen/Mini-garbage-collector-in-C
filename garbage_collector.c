#include <stdio.h>
#include <stdlib.h>

// Define a structure to store allocation information
typedef struct Allocation
{
	void				*ptr;
	struct Allocation	*next;
}						t_Allocation;

static t_Allocation		*g_allocations = NULL;

// Function to allocate memory and keep track of it
void	*my_malloc(size_t size)
{
	void			*ptr;
	t_Allocation	*new_alloc;

	ptr = malloc(size);
	if (!ptr)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	new_alloc = (t_Allocation *)malloc(sizeof(t_Allocation));
	if (!new_alloc)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	new_alloc->ptr = ptr;
	new_alloc->next = g_allocations;
	g_allocations = new_alloc;
	return (ptr);
}

// Function to free all tracked allocations
void	free_all(void)
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

// TEST------------------------------------------------
int	main(void)
{
	int		*arr;
	char	*str;
	int		i;

	i = 0;
	arr = (int *)my_malloc(10 * sizeof(int));
	str = (char *)my_malloc(50 * sizeof(char));
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
	free_all();
	return (0);
}
//----------------------------------------------------

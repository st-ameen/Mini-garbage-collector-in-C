<h1 align="center">
	Basic Garbage Collector in C
</h1> 
<p align="center">
	This project helped you? Give it a 🌟!
</p>

## Description

This repository contains a basic implementation of a garbage collector in C. The garbage collector tracks memory allocations and frees them at the end of the program to prevent memory leaks.

## How to Use

### Functions

- `t_Allocation	*my_malloc(size_t size, int FUNCTION)`: Allocates memory and keeps track of the allocation when using the flag ALLOCATE, returns the head of the list of the allocated pointer when using the flag FETCHPOINTERS.
- `void	free_all(t_Allocation *g_allocations)`: Frees all tracked allocations, call using my_malloc with the FETCHPOINTERS flag.

### Example Usage

To see an example of how to use the garbage collector, please refer to the `garbage_collector.c` file in this repository.

### Steps to Run

1. **Clone the repository:**
    ```sh
    git clone https://github.com/st-ameen/Mini-garbage-collector-in-C.git
    cd Mini-garbage-collector-in-C
    ```

2. **Compile the code:**
    ```sh
    gcc -o garbage_collector garbage_collector.c
    ```

3. **Run the executable:**
    ```sh
    ./garbage_collector
    ```

### Notes

- Ensure that every allocation is properly tracked and freed to avoid memory leaks.
- This is a basic implementation and may not handle all edge cases or errors.
- In a real-world scenario, you may want to add more error handling and possibly thread-safety mechanisms if you are working in a multi-threaded environment.

## Contributing

Feel free to open issues or submit pull requests if you find any bugs or want to add new features.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

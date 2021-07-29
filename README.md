# 42-libft
## Task
This is one of the first projects at Hive. Task is to create my own C library. This means I have to code my own versions of libc functions such as strlen or atoi. In addition to that I am encouraged to add more functions which I feel useful.
## Constraints
* Code must be complied with -Wall, -Wextra and -Werror flags.
* Only the following functions are allowed: malloc, free, and write.
## Solution
I created mandatory and bonus functions. In addition to that I have been adding many useful functions.
I have also included here two additional projects, get_next_line and ft_printf, both are very useful in the following projects.

# get_next_line
## Task
I have to create function which reads from a file descriptor one line at a time. This function could then be used in a loop to read a file line by line.
## Constraints
* Code must be complied with -Wall, -Wextra and -Werror flags.
* Only the following functions are allowed: malloc, free, and read.
## Solution
I solved this by using linked lists. I read from the file descriptor and add the data to a linked list. Then I process the data so that each time the function is called, it returns one line of text, leaving the "next line" back at the linked list.

# ft_printf
## Task
Task is to re-create the printf function. Following conversions are mandatory: csp, diouxX with flags hh, h, l and ll, f with flags l and L. I also have to manage %%, flags #0-+ and space, field-width and precision.
## Constraints
* Code must be complied with -Wall, -Wextra and -Werror flags.
* Only the following functions are allowed: write, malloc, free, exit, and the functions of stdarg
## Solution
In addition to the mandatory conversions, I also handled eEgGaA, and b, which is not a original conversion but a custom one converting unsigned integer value to binary string.

# push_swap
This project is my implementation of push_swap, an optimised sorting algorithm using two stacks and a limited set of instructions.
Instructions allowed are the following:

| Instructions |  | 
| :---: | :--- | 
| sa | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
| sb | Swap the first 2 elements at the top of stack b.Do nothing if there is only one or no elements.
| ss | sa and sb at the same time.
| pa | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
| pb | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
| ra | Shift up all elements of stack a by 1. The first element becomes the last one.
| rb | Shift up all elements of stack b by 1. The first element becomes the last one.
| rr | ra and rb at the same time.
| rra | Shift down all elements of stack a by 1. The last element becomes the first one.
| rrb | Shift down all elements of stack b by 1. The last element becomes the first one.
| rrr | rra and rrb at the same time.

The algorithm first parses the argument that should be a list of integer. It then pushes everything on stack b and does a trivial sort of the 3 elements left on stack a. The algorithm then associate each elements of stack b (node) to an element of stack a (target_node), and calculate a price based ont the respective position of both. the cheapest pair of nodes are then passed to the top of their respective stacks and the top element of stack b is pushed back to stack a in the correct position. Once the stack b is empty, stack a is rotated until its smallest element is on the top.
More info: [subject.pdf](https://github.com/Axel-ex/push_swap/blob/main/subject.pdf)

## Usage 

## Test 

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

The algorithm first parses the argument that should be a list of integer formated as `"1 2 3 4 5"` or `1 2 3 4 5`. It then pushes everything on stack b and does a trivial sort of the 3 elements left on stack a. The algorithm then associate each elements of stack b (node) to an element of stack a (target_node), and calculate a price based ont the respective position of both. the cheapest pair of nodes are then passed to the top of their respective stacks and the top element of stack b is pushed back to stack a in the correct position. Once the stack b is empty, stack a is rotated until its smallest element is on the top.
More info: [subject.pdf](https://github.com/Axel-ex/push_swap/blob/main/subject.pdf)

## Usage 
`git clone` this project `cd` into it and `make`. the program is executed as so:

```shell
./push_swap <integer_list>
```
The program will display the instructions it executed in order to sort the integer_list you provided. Additionally, if you run `make bonus` you'll have access to the checker executable. the checker is executed as so:
```shell
./checker
```
The checker will wait for the user to enter valid commands. If a valid command is prompted, the checker will execute it and wait for the next instruction. the checker stops when the user hits `CTRL-D`. if the stack is sorted upon signal reception, it will display **OK** otherwise it will display **KO**. The checker can also be executed as so:
```shell
ARGS=<integer_list> && ./push_swap $ARGS | ./checker $ARGS
```
the output of push swap will be redirected to the checker and the checker will perform the moves on the stack and check if the stack is sorted.
## Test
```shell
nums=$(gshuf -i 1-2147483647 -n 500 | tr '\n' ' ') ; ./push_swap $nums | wc -l
```
This command will execute the program on a randomly generated integer list. To visualize the program working, I recommand the vizualiser of elijahkash:
```shell
pip3 install push_swap_gui
python3 -m push_swap_gui
```

## Norme

All 42 projects must be written following the **Norme**.

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
 	- Each line must be at most 80 columns wide, comments included
	- A function can take 4 named parameters maximum
	- No more than 5 variables in 1 function

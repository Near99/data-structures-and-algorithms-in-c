# Practical Data structures and Algorithms in C

## October-22-2022 Update

Well It's been a while since I started coding data structures in C, had a lot of fun and learned a lot from it.
C is just the best for basic data structures I encourage anyone who wants to get better at data structures to 
coding with C for a while to really feel the beauty of data structures and algorithms in your bones. However, C 
is such a low level language compared to most of the high level languages which brings us some inconvenience to 
practice algorithm problems. Some of the algorithm questions listed below are not done in C for example. I would 
suggest to stop coding in c from what I've done in this repo and switch to  c++ if you are really into c style 
programming, or any other modern languages you like such as Java, Python, JavaScript just to name a few. Best of luck!

## Array

### :heavy_check_mark: Vector implementation. 

- [x] `vector_create()`          - create a new vector.
- [x] `vector_destory()`         - destory a vector. 
- [x] `vector_extend_capacity()` - double the capacity automatically when needed.
- [x] `vector_shrink_capacity()` - shrink the capacity automatically when needed.
- [x] `vector_push()`            - add element to the end of the vector.
- [x] `vector_pop()`             - remove the last element from the vector and return that element.
- [x] `vector_at()`              - return the element at given index.
- [x] `vector_is_empty()`        - if the vector is empty.
- [x] `vector_find()`            - return the first index of the given element.
- [x] `vector_size()`            - size of the vector.
- [x] `vector_capacity()`        - current capacity.
- [x] `vector_insert()`          - insert new element at given index and shift trailing elements to the right.
- [x] `vector_delete()`          - delete the element at given index and shift trailing elements to the left.
- [x] `vector_remove()`          - remove all matched elements.

### Array algorithm practice questions:

- [x] Two Sum
- [x] Validate Subsequence.
- [x] Best Time to Buy and Sell Stock.
- [x] Move Element to End.
- [x] Spiral Traverse.
- [x] Longest Peak.
- [x] First Duplicate Value.

## List

### :heavy_check_mark: Singly linked list with tail implementation.

- [x] `list_create()`           - create a new linked list.
- [x] `list_insert_front()`     - insert a node at front of the list.
- [x] `list_insert_back()`      - insert a node at end of the list.
- [x] `list_insert_by_index()`  - insert a node at the given index.
- [x] `list_search_by_index()`  - search a node at the given index and return its value.
- [x] `list_pop_front()`        - remove the first node of the list.
- [x] `list_pop_back()`         - remove the last node of the list.
- [x] `list_traverse()`         - traverse the list and print the value.
- [x] `list_recursive()`        - traverse the linked list recursively servers as a helper function to `list_traverse()` api.
- [x] `list_destory()`          - destory the list and release the memory.
- [x] `list_remove()`           - remove the node by the given value.
- [x] `list_empty()`            - if list is empty.
- [x] `list_size()`             - size of the list.

### Linked-list algorithm practice questions: 

- [x] Reverse Linked List.
- [x] Remove Kth Node From End.
- [x] Remove Duplicates From Linked List.
- [x] Sum of Linked Lists.
- [x] Merge Linked List.
- [x] Detect Cycle in a Linked List.
- [x] Delete the Middle Node of a Linked List.

## Stack

### :heavy_check_mark: Stack implementation with linked list.

- [x] `stack_create()`          - create a new stack.
- [x] `stack_push()`            - add an element to the stack.
- [x] `stack_pop()`             - remove an element from the stack.
- [x] `stack_is_empty()`        - if stack is empty.

### Stack algorithm practice questions:

- [x] Balanced Brackets.
- [x] Next Greater Element.

## Queue

### :heavy_check_mark: Queue implementation with linked list.

- [x] `queue_create()`          - create a new queue.
- [x] `queue_enqueue()`         - add an element to the end of the queue.
- [x] `queue_dequeue()`         - remove an element at the front of the queue.
- [x] `queue_empty()`           - if queue is empty.

### :heavy_check_mark: Queue implementation with array.

- [x] `queue_create()`          - create a new queue.
- [x] `queue_enqueue()`         - add an element to the end of the queue.
- [x] `queue_dequeue()`         - remove an element at the front of the queue.
- [x] `queue_empty()`           - if queue is empty.
- [x] `queue_full()`            - if queue is full.
- [x] `queue_size()`            - size of the queue.

### Queue algorithm practice questions:

- [x] None for now. 

## Dictionary

### :heavy_check_mark: Dictionary implementation with hash map.

- [x] `hashmap_create()`        - create a new hash map.
- [x] `hashmap_insert()`        - insert an element to the dictionary.
- [x] `hashmap_search()`        - search an element by key.
- [x] `hashmap_delete()`        - delete an element by key.
- [x] `hashmap_exist()`         - if exist.
- [x] `_hasing()`               - generate hash index.

### Dictionary algorithm practice questions:

- [x] Not applicable as it is usually used with other data structures when solving algorithm problems.

## Trees

### :heavy_check_mark: Binary Search Tree implementation.

- [x] `bst_create()`            - create a new binary search tree.
- [x] `bst_insert()`            - insert an element to the BST.
- [x] `bst_print_ascending()`   - print BST nodes in ascending order.
- [x] `bst_print_descending()`  - print BST nodes in descending order.
- [x] `bst_get_min()`           - get minimum node in the BST.
- [x] `bst_get_max()`           - get the maximum node in the BST.
- [x] `bst_node_count()`        - count nodes in the BST.
- [x] `bst_traverse_inorder()`  - traverse inorder (left, current, right).
- [x] `bst_traverse_preorder()` - traverse preorder (current, left, right).
- [x] `bst_traverse_postorder()`- traverse postorder (left, right, current).
- [x] `bst_search()`            - if value is in the tree.
- [x] `bst_get_height()`        - get the height of the BST.
- [x] `bst_valid()`             - if is a valid BST.
- [ ] `bst_delete_node()`       - delete node from a BST.
- [ ] `bst_successor()`         - find the successor of the given node.

### BST algorithm practice questions:

- [x] Validate BST.
- [x] BST Traverse.
- [x] Invert Binary Tree.

## Priority Queue && Binary Heap

### :heavy_check_mark: Priority Queue implementation with heap.

- [x] `p_queue_create()`        - create a new priority queue.
- [x] `p_queue_insert()`        - insert an element to the queue.
- [x] `p_queue_fine_min()`      - find the minimum element in the queue.
- [x] `p_queue_extract_min()`   - delete the minimum element in the queue.
- [x] `p_queue_size()`          - size of the queue.
- [x] `p_queue_is_empty()`      - if the queue is empty.
- [x] `p_queue_is_full()`       - if the queue is full.
- [x] `p_queue_parent()`        - helper function, get the parent's index.
- [x] `p_queue_young_child()`   - helper function, get the child's index.
- [x] `p_queue_bubble_up()`     - helper funtionc, bubble the smallest element to the top.
- [x] `p_queue_bubble_down()`   - helper funtionc, bubble root down if it's not the smallest to its childs.

### Heap practice questions:

- [x] Heap Sort.

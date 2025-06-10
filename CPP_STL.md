# C++ STL Complete Reference Guide

## Table of Contents
1. [Sequence Containers](#sequence-containers)
2. [Associative Containers](#associative-containers)
3. [Unordered Containers](#unordered-containers)
4. [Container Adaptors](#container-adaptors)
5. [Algorithms](#algorithms)
6. [Iterators](#iterators)
7. [Function Objects](#function-objects)
8. [Utility Components](#utility-components)

---

## Sequence Containers

### std::vector
**Header:** `#include <vector>`

#### Member Functions:
- **Constructors:**
  - `vector()` - Default constructor
  - `vector(size_t n)` - Fill constructor
  - `vector(size_t n, const T& val)` - Fill constructor with value
  - `vector(InputIterator first, InputIterator last)` - Range constructor
  - `vector(const vector& x)` - Copy constructor
  - `vector(initializer_list<T> il)` - Initializer list constructor

- **Capacity:**
  - `size()` - Return size
  - `max_size()` - Return maximum size
  - `resize(size_t n)` - Change size
  - `capacity()` - Return size of allocated storage
  - `empty()` - Test whether container is empty
  - `reserve(size_t n)` - Request a change in capacity
  - `shrink_to_fit()` - Shrink to fit

- **Element Access:**
  - `operator[](size_t n)` - Access element
  - `at(size_t n)` - Access element with bounds checking
  - `front()` - Access first element
  - `back()` - Access last element
  - `data()` - Access data

- **Modifiers:**
  - `assign(InputIterator first, InputIterator last)` - Assign container content
  - `push_back(const T& val)` - Add element at the end
  - `pop_back()` - Delete last element
  - `insert(iterator position, const T& val)` - Insert elements
  - `erase(iterator position)` - Erase elements
  - `swap(vector& x)` - Swap content
  - `clear()` - Clear content
  - `emplace(iterator position, Args&&... args)` - Construct and insert element
  - `emplace_back(Args&&... args)` - Construct and insert element at the end

- **Iterators:**
  - `begin()` - Return iterator to beginning
  - `end()` - Return iterator to end
  - `rbegin()` - Return reverse iterator to reverse beginning
  - `rend()` - Return reverse iterator to reverse end
  - `cbegin()` - Return const_iterator to beginning
  - `cend()` - Return const_iterator to end
  - `crbegin()` - Return const_reverse_iterator to reverse beginning
  - `crend()` - Return const_reverse_iterator to reverse end

### std::deque
**Header:** `#include <deque>`

#### Member Functions:
- **Constructors:** Same as vector
- **Capacity:** `size()`, `max_size()`, `resize()`, `empty()`, `shrink_to_fit()`
- **Element Access:** `operator[]`, `at()`, `front()`, `back()`
- **Modifiers:**
  - `assign()` - Assign container content
  - `push_back()` - Add element at the end
  - `push_front()` - Insert element at beginning
  - `pop_back()` - Delete last element
  - `pop_front()` - Delete first element
  - `insert()` - Insert elements
  - `erase()` - Erase elements
  - `swap()` - Swap content
  - `clear()` - Clear content
  - `emplace()` - Construct and insert element
  - `emplace_front()` - Construct and insert element at beginning
  - `emplace_back()` - Construct and insert element at the end
- **Iterators:** Same as vector

### std::list
**Header:** `#include <list>`

#### Member Functions:
- **Constructors:** Same as vector
- **Capacity:** `size()`, `max_size()`, `empty()`
- **Element Access:** `front()`, `back()`
- **Modifiers:**
  - `assign()` - Assign container content
  - `push_front()` - Insert element at beginning
  - `pop_front()` - Delete first element
  - `push_back()` - Add element at the end
  - `pop_back()` - Delete last element
  - `insert()` - Insert elements
  - `erase()` - Erase elements
  - `swap()` - Swap content
  - `resize()` - Change size
  - `clear()` - Clear content
  - `emplace()` - Construct and insert element
  - `emplace_front()` - Construct and insert element at beginning
  - `emplace_back()` - Construct and insert element at the end

- **Operations:**
  - `splice()` - Transfer elements from list to list
  - `remove(const T& val)` - Remove elements with specific value
  - `remove_if(Predicate pred)` - Remove elements fulfilling condition
  - `unique()` - Remove duplicate values
  - `merge(list& x)` - Merge sorted lists
  - `sort()` - Sort elements in container
  - `reverse()` - Reverse the order of elements

- **Iterators:** Same as vector

### std::forward_list
**Header:** `#include <forward_list>`

#### Member Functions:
- **Constructors:** Same as vector
- **Capacity:** `empty()`, `max_size()`
- **Element Access:** `front()`
- **Modifiers:**
  - `assign()` - Assign container content
  - `push_front()` - Insert element at beginning
  - `pop_front()` - Delete first element
  - `insert_after()` - Insert elements after position
  - `erase_after()` - Erase elements after position
  - `swap()` - Swap content
  - `resize()` - Change size
  - `clear()` - Clear content
  - `emplace_front()` - Construct and insert element at beginning
  - `emplace_after()` - Construct and insert element after position

- **Operations:**
  - `splice_after()` - Transfer elements between forward_lists
  - `remove()` - Remove elements with specific value
  - `remove_if()` - Remove elements fulfilling condition
  - `unique()` - Remove duplicate values
  - `merge()` - Merge sorted forward_lists
  - `sort()` - Sort elements in container
  - `reverse()` - Reverse the order of elements

- **Iterators:** `begin()`, `end()`, `cbegin()`, `cend()`, `before_begin()`, `cbefore_begin()`

### std::array
**Header:** `#include <array>`

#### Member Functions:
- **Capacity:** `size()`, `max_size()`, `empty()`
- **Element Access:** `operator[]`, `at()`, `front()`, `back()`, `data()`
- **Modifiers:** `fill(const T& val)`, `swap(array& x)`
- **Iterators:** Same as vector

---

## Associative Containers

### std::set
**Header:** `#include <set>`

#### Member Functions:
- **Constructors:**
  - `set()` - Default constructor
  - `set(const Compare& comp)` - Constructor with comparison object
  - `set(InputIterator first, InputIterator last)` - Range constructor
  - `set(const set& x)` - Copy constructor
  - `set(initializer_list<T> il)` - Initializer list constructor

- **Capacity:** `empty()`, `size()`, `max_size()`

- **Modifiers:**
  - `insert(const T& val)` - Insert element
  - `erase(iterator position)` - Erase elements
  - `swap(set& x)` - Swap content
  - `clear()` - Clear content
  - `emplace(Args&&... args)` - Construct and insert element
  - `emplace_hint(iterator position, Args&&... args)` - Construct and insert element with hint

- **Observers:**
  - `key_comp()` - Return comparison object
  - `value_comp()` - Return comparison object

- **Operations:**
  - `find(const T& val)` - Get iterator to element
  - `count(const T& val)` - Count elements with specific value
  - `lower_bound(const T& val)` - Return iterator to lower bound
  - `upper_bound(const T& val)` - Return iterator to upper bound
  - `equal_range(const T& val)` - Get range of equal elements

- **Iterators:** Same as vector

### std::multiset
**Header:** `#include <set>`
#### Member Functions: Same as std::set

### std::map
**Header:** `#include <map>`

#### Member Functions:
- **Constructors:** Same as set
- **Capacity:** Same as set
- **Element Access:** `operator[](const Key& k)`, `at(const Key& k)`
- **Modifiers:**
  - `insert(const pair<Key,T>& val)` - Insert element
  - `erase(iterator position)` - Erase elements
  - `swap(map& x)` - Swap content
  - `clear()` - Clear content
  - `emplace(Args&&... args)` - Construct and insert element
  - `emplace_hint(iterator position, Args&&... args)` - Construct and insert element with hint

- **Observers:** `key_comp()`, `value_comp()`
- **Operations:** `find()`, `count()`, `lower_bound()`, `upper_bound()`, `equal_range()`
- **Iterators:** Same as vector

### std::multimap
**Header:** `#include <map>`
#### Member Functions: Same as std::map (except no `operator[]` and `at()`)

---

## Unordered Containers

### std::unordered_set
**Header:** `#include <unordered_set>`

#### Member Functions:
- **Constructors:** Similar to set with hash and equality parameters
- **Capacity:** `empty()`, `size()`, `max_size()`
- **Modifiers:** `insert()`, `erase()`, `swap()`, `clear()`, `emplace()`, `emplace_hint()`
- **Observers:** `hash_function()`, `key_eq()`
- **Operations:** `find()`, `count()`, `equal_range()`
- **Buckets:**
  - `bucket_count()` - Return number of buckets
  - `max_bucket_count()` - Return maximum number of buckets
  - `bucket_size(size_t n)` - Return bucket size
  - `bucket(const Key& k)` - Locate element's bucket
- **Hash policy:**
  - `load_factor()` - Return load factor
  - `max_load_factor()` - Get or set maximum load factor
  - `rehash(size_t n)` - Set number of buckets
  - `reserve(size_t n)` - Request a capacity change
- **Iterators:** Same as vector plus bucket iterators

### std::unordered_multiset
**Header:** `#include <unordered_set>`
#### Member Functions: Same as std::unordered_set

### std::unordered_map
**Header:** `#include <unordered_map>`

#### Member Functions:
- **Constructors:** Similar to unordered_set
- **Capacity:** Same as unordered_set
- **Element Access:** `operator[]`, `at()`
- **Modifiers:** Same as unordered_set
- **Observers:** Same as unordered_set
- **Operations:** Same as unordered_set
- **Buckets:** Same as unordered_set
- **Hash policy:** Same as unordered_set
- **Iterators:** Same as unordered_set

### std::unordered_multimap
**Header:** `#include <unordered_map>`
#### Member Functions: Same as std::unordered_map (except no `operator[]` and `at()`)

---

## Container Adaptors

### std::stack
**Header:** `#include <stack>`

#### Member Functions:
- **Constructors:**
  - `stack()` - Default constructor
  - `stack(const Container& ctnr)` - Constructor with underlying container
- **Capacity:** `empty()`, `size()`
- **Element Access:** `top()` - Access next element
- **Modifiers:**
  - `push(const T& val)` - Insert element
  - `pop()` - Remove top element
  - `emplace(Args&&... args)` - Construct and insert element
  - `swap(stack& x)` - Swap contents

### std::queue
**Header:** `#include <queue>`

#### Member Functions:
- **Constructors:** Same as stack
- **Capacity:** `empty()`, `size()`
- **Element Access:** `front()`, `back()`
- **Modifiers:**
  - `push(const T& val)` - Insert element
  - `pop()` - Remove next element
  - `emplace(Args&&... args)` - Construct and insert element
  - `swap(queue& x)` - Swap contents

### std::priority_queue
**Header:** `#include <queue>`

#### Member Functions:
- **Constructors:**
  - `priority_queue()` - Default constructor
  - `priority_queue(const Compare& comp)` - Constructor with comparison
  - `priority_queue(InputIterator first, InputIterator last)` - Range constructor
- **Capacity:** `empty()`, `size()`
- **Element Access:** `top()` - Access top element
- **Modifiers:**
  - `push(const T& val)` - Insert element
  - `pop()` - Remove top element
  - `emplace(Args&&... args)` - Construct and insert element
  - `swap(priority_queue& x)` - Swap contents

---

## Algorithms

### Non-modifying sequence operations
**Header:** `#include <algorithm>`

- `all_of()` - Test condition on all elements in range
- `any_of()` - Test if any element in range fulfills condition
- `none_of()` - Test if no elements fulfill condition
- `for_each()` - Apply function to range
- `find()` - Find value in range
- `find_if()` - Find element in range (condition)
- `find_if_not()` - Find element in range (negative condition)
- `find_end()` - Find last subsequence in range
- `find_first_of()` - Find element from set in range
- `adjacent_find()` - Find equal adjacent elements in range
- `count()` - Count appearances of value in range
- `count_if()` - Return number of elements in range satisfying condition
- `mismatch()` - Return first position where two ranges differ
- `equal()` - Test whether the elements in two ranges are equal
- `search()` - Search range for subsequence
- `search_n()` - Search range for elements

### Modifying sequence operations
- `copy()` - Copy range of elements
- `copy_n()` - Copy elements
- `copy_if()` - Copy certain elements of range
- `copy_backward()` - Copy range of elements backward
- `move()` - Move range of elements
- `move_backward()` - Move range of elements backward
- `swap()` - Exchange values of two objects
- `swap_ranges()` - Exchange values of two ranges
- `iter_swap()` - Exchange values of objects pointed to by two iterators
- `transform()` - Transform range
- `replace()` - Replace value in range
- `replace_if()` - Replace values in range (conditional)
- `replace_copy()` - Copy range replacing value
- `replace_copy_if()` - Copy range replacing value (conditional)
- `fill()` - Fill range with value
- `fill_n()` - Fill sequence with value
- `generate()` - Generate values for range with function
- `generate_n()` - Generate values for sequence with function
- `remove()` - Remove value from range
- `remove_if()` - Remove elements from range (conditional)
- `remove_copy()` - Copy range removing value
- `remove_copy_if()` - Copy range removing values (conditional)
- `unique()` - Remove consecutive duplicates in range
- `unique_copy()` - Copy range removing duplicates
- `reverse()` - Reverse range
- `reverse_copy()` - Copy range reversed
- `rotate()` - Rotate left the elements in range
- `rotate_copy()` - Copy range rotated left
- `random_shuffle()` - Randomly rearrange elements in range
- `shuffle()` - Randomly rearrange elements in range using generator

### Partitions
- `is_partitioned()` - Test whether range is partitioned
- `partition()` - Partition range in two
- `stable_partition()` - Partition range in two (stable)
- `partition_copy()` - Partition range into two
- `partition_point()` - Get partition point

### Sorting
- `sort()` - Sort elements in range
- `stable_sort()` - Sort elements preserving order of equivalents
- `partial_sort()` - Partially sort elements in range
- `partial_sort_copy()` - Copy and partially sort range
- `is_sorted()` - Check whether range is sorted
- `is_sorted_until()` - Find first unsorted element in range
- `nth_element()` - Sort element in range

### Binary search (operating on partitioned/sorted ranges)
- `lower_bound()` - Return iterator to lower bound
- `upper_bound()` - Return iterator to upper bound
- `equal_range()` - Get subrange of equal elements
- `binary_search()` - Test if value exists in sorted sequence

### Merge (operating on sorted ranges)
- `merge()` - Merge sorted ranges
- `inplace_merge()` - Merge consecutive sorted ranges
- `includes()` - Test whether sorted range includes another sorted range
- `set_union()` - Union of two sorted ranges
- `set_intersection()` - Intersection of two sorted ranges
- `set_difference()` - Difference of two sorted ranges
- `set_symmetric_difference()` - Symmetric difference of two sorted ranges

### Heap
- `push_heap()` - Push element to heap range
- `pop_heap()` - Pop element from heap range
- `make_heap()` - Make heap from range
- `sort_heap()` - Sort elements of heap
- `is_heap()` - Test if range is heap
- `is_heap_until()` - Find first element not in heap order

### Min/max
- `min()` - Return the smallest
- `max()` - Return the largest
- `minmax()` - Return smallest and largest elements
- `min_element()` - Return smallest element in range
- `max_element()` - Return largest element in range
- `minmax_element()` - Return smallest and largest elements in range

### Other
- `lexicographical_compare()` - Lexicographical less-than comparison
- `next_permutation()` - Transform range to next permutation
- `prev_permutation()` - Transform range to previous permutation

---

## Iterators

### Iterator Categories
**Header:** `#include <iterator>`

1. **Input Iterator** - Read only, forward moving
2. **Output Iterator** - Write only, forward moving
3. **Forward Iterator** - Read/write, forward moving
4. **Bidirectional Iterator** - Read/write, forward and backward moving
5. **Random Access Iterator** - Read/write, jump to any element

### Iterator Functions
- `advance(iterator& it, Distance n)` - Advance iterator
- `distance(InputIterator first, InputIterator last)` - Return distance between iterators
- `begin(Container& c)` - Iterator to beginning
- `end(Container& c)` - Iterator to end
- `prev(BidirectionalIterator it)` - Get iterator to previous element
- `next(ForwardIterator it)` - Get iterator to next element

### Iterator Adaptors
- `reverse_iterator` - Reverse iterator
- `back_insert_iterator` - Back insert iterator
- `front_insert_iterator` - Front insert iterator
- `insert_iterator` - Insert iterator
- `move_iterator` - Move iterator

### Iterator Generators
- `back_inserter()` - Back insert iterator
- `front_inserter()` - Front insert iterator
- `inserter()` - Insert iterator
- `make_move_iterator()` - Move iterator

---

## Function Objects

### Base Classes
**Header:** `#include <functional>`

- `unary_function` - Unary function object base class
- `binary_function` - Binary function object base class

### Operator Classes
#### Arithmetic operations
- `plus` - Addition function object
- `minus` - Subtraction function object
- `multiplies` - Multiplication function object
- `divides` - Division function object
- `modulus` - Modulus function object
- `negate` - Negate function object

#### Comparisons
- `equal_to` - Equal-to function object
- `not_equal_to` - Not-equal-to function object
- `greater` - Greater-than function object
- `less` - Less-than function object
- `greater_equal` - Greater-than-or-equal-to function object
- `less_equal` - Less-than-or-equal-to function object

#### Logical operations
- `logical_and` - Logical AND function object
- `logical_or` - Logical OR function object
- `logical_not` - Logical NOT function object

### Negators
- `not1()` - Return negation of unary predicate
- `not2()` - Return negation of binary predicate

### Binders
- `bind1st()` - Return function object with first parameter bound
- `bind2nd()` - Return function object with second parameter bound
- `bind()` - Bind function arguments

### Member Functions
- `mem_fn()` - Convert member function to function object
- `mem_fun_ref()` - Convert member function to function object
- `mem_fun()` - Convert member function to function object

### Wrappers
- `function` - Function wrapper
- `reference_wrapper` - Reference wrapper
- `ref()` - Construct reference_wrapper to object
- `cref()` - Construct reference_wrapper to const object

---

## Utility Components

### std::pair
**Header:** `#include <utility>`

#### Member Functions:
- **Constructors:**
  - `pair()` - Default constructor
  - `pair(const T1& a, const T2& b)` - Initialization constructor
  - `pair(const pair& pr)` - Copy constructor
- **Assignment:** `operator=`
- **Access:** `first`, `second` (public members)

#### Non-member Functions:
- `make_pair()` - Construct pair object
- `get<>()` - Get element (C++11)

### std::tuple (C++11)
**Header:** `#include <tuple>`

#### Functions:
- `make_tuple()` - Construct tuple
- `tie()` - Tie arguments to tuple elements
- `forward_as_tuple()` - Forward arguments as tuple
- `tuple_cat()` - Concatenate tuples
- `get<>()` - Get element
- `tuple_size` - Tuple size
- `tuple_element` - Tuple element type

### Smart Pointers (C++11)
**Header:** `#include <memory>`

#### std::unique_ptr
- `reset()` - Replace managed object
- `release()` - Release ownership
- `get()` - Get pointer
- `operator*()` - Dereference
- `operator->()` - Dereference
- `operator bool()` - Check if not null
- `make_unique()` - Create unique_ptr

#### std::shared_ptr
- `reset()` - Replace managed object  
- `get()` - Get pointer
- `use_count()` - Use count
- `unique()` - Check if unique
- `operator*()` - Dereference
- `operator->()` - Dereference
- `operator bool()` - Check if not null
- `make_shared()` - Create shared_ptr

#### std::weak_ptr
- `reset()` - Replace managed object
- `use_count()` - Use count
- `expired()` - Check if expired
- `lock()` - Lock and return shared_ptr

### Other Utilities
**Header:** `#include <utility>`

- `swap()` - Exchange values of two objects
- `move()` - Move semantics
- `forward()` - Perfect forwarding
- `declval()` - Obtain reference to type

### Type Traits (C++11)
**Header:** `#include <type_traits>`

Common type traits include:
- `is_same` - Check if types are same
- `is_integral` - Check if integral type
- `is_floating_point` - Check if floating point
- `is_pointer` - Check if pointer type
- `is_const` - Check if const-qualified
- `remove_const` - Remove const qualification
- `add_const` - Add const qualification
- `conditional` - Conditional type

---

This reference covers the major components of the C++ Standard Template Library. Each container and algorithm has specific use cases and performance characteristics that make them suitable for different scenarios in C++ programming.
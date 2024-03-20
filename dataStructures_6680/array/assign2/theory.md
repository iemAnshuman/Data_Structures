### Explain the term arrays as a linear data structure.
Arrays are linear data structures that store elements in contiguous memory locations. They allow random access to elements, which means any element can be accessed directly if the index is known. Arrays are characterized by their fixed size, which is decided at the time of array declaration and cannot be altered during runtime. Elements in an array are usually of the same data type.

### What are the sparse matrices? Give an example.
Sparse matrix is a matrix in which most of the elements are zero.
When a sparse matrix is represented with a 2-dimensional array, we waste a lot of space to represent that matrix. For example, consider a matrix of size 100 X 100 containing only 10 non-zero elements.

### How two-dimensional arrays are represented in memory? Also obtain the formula for calculating the address of any element stored in the array, in the case of column-major.
Arrays are stored in linear(contiguous) fashion.
Two-dimensional arrays are stored in memory either in row-major order (where the entire rows are stored one after another) or in column-major order (where the entire columns are stored one after another).
In row major order, first row is stored first then second row is stored and so on.
In column major order, first column is stored first then second column and so on.

### Write an algorithm to count the common elements of two one-dimensional arrays.
ALGORITHM:
Input: Two one-dimensional arrays, array1 and array2, each of size n1 and n2 respectively.
Output: Count of common elements between array1 and array2.
Steps:
1. Initialisee a variable Count to 0 
2. Loop through each element (element1) in array1:
     a. Inner loop through each element (element2) in array2:
          b. If element1 is equal to element2, increment commonCount by 1. 
3. Print or return the value of commonCount as the result.

### Write a short note on any two:
Static Memory Allocation: Memory is allocated at compile time. The size and location of memory are determined before the program starts running. 
Dynamic Memory Allocation: Memory is allocated at runtime, i.e., while the program is executing. The size and location of memory can be determined during program execution.

Arrays of pointers-
A pointer array is a homogeneous collection of indexed pointer variables that are references to a memory location. It is generally used in C Programming when we want to point at multiple memory locations of a similar data type in our C program.

### Explain the memory representation of two- dimensional arrays with the help of examples.
Two-dimensional arrays are like a grid or a table with rows and columns. Think of it as a spreadsheet where you store information in different cells arranged in rows and columns.

how we store and access these grids in memory can vary:
Row-major order: This means we store all elements of a row together, one row after the other. If you're using languages like C or C++, this is how they do it. For example, if you have a small grid with numbers from 1 to 6 arranged in 3 rows and 2 columns, it's stored as 1, 2, 3, 4, 5, 6 in memory, going row by row.
Column-major order: Here, we store all elements of a column together, one column after the other. Some languages like Fortran use this approach. Using the same grid example, it would be stored as 1, 3, 5, 2, 4, 6 in memory, going column by column.
```c
#include <stdio.h>

int main() {
    int grid[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("This spot has: %d\n", grid[0][2]); // It'll show 3, from the first row, third column
    return 0;
}
```

### Draw a linked list and vector representation of the following sparse matrix.
Linked List Representation:
We can use a linked list to represent non-zero elements along with their positions (row and column). Each node in the linked list contains the value, row index, column index, and a pointer to the next node.
Linked List:
Head -> (1, 2, 12) -> (2, 2, 11) -> (3, 1, 9)

Vector Representation:
We can use a vector to store a tuple of (row, column, value) for each non-zero element in the matrix.
Vector:
[(1, 2, 12), (2, 2, 11), (3, 1, 9)]


### Explain the application areas of the array with a suitable example.
Arrays are fundamental data structures that play a crucial role in various application areas. Here are some application areas of arrays along with suitable examples:
Numerical Computing:
Example: In scientific and engineering applications, arrays are used to store and process numerical data efficiently. For instance, in image processing, pixel values are often stored in arrays to represent images. 
Data Structures:
Example: Arrays are the foundation for other data structures, such as stacks, queues, and linked lists. For instance, a stack can be implemented using an array where elements are added or removed from one end (top of the stack).
Databases:
Example: Arrays are used to represent records and tables in databases. Each column of a table can be represented as an array, and each row corresponds to an entry in the database.
Dynamic Memory Allocation:
Example: Arrays are used in dynamic memory allocation. For instance, dynamic arrays (arrays whose size can be changed during runtime) are often implemented using pointers and memory allocation functions in languages like C and C++.
Sorting and Searching Algorithms:
Example: Arrays are central to sorting and searching algorithms. For example, the binary search algorithm operates on a sorted array, efficiently finding a specific element by repeatedly dividing the search space in half.
Text Processing:
Example: Arrays are used in text processing for string manipulation and searching. For example, an array of characters can represent a string, and algorithms can be applied to search for patterns or perform transformations.
Game Development:
Example: In game development, arrays are used to represent game boards, character attributes, and various game states. For instance, a 2D array can represent the layout of a game level, with each cell representing a specific location.
In programming specifically:-
Sorting algorithms like: Quick sort, Merge sort, bubble sort, etc
Searching algorithms like LS, BS, etc
Dynamic programming: fibonacci series
Graph algo like: BFS, DFS

### Write an algorithm for matrix operations such as the addition of two matrices, multiplication, subtraction, and transpose.
Algorithm: Addition
Input: Two matrices A and B of size m x n.
Output: Resultant matrix C = A + B.
Steps:
1. If the dimensions of matrices A and B are not compatible (m1 != m2 or n1 != n2), print an error message and exit.
2. Initialize a result matrix C of size m x n.
3. For each element C[i][j]:
     a. C[i][j] = A[i][j] + B[i][j].
4. Print or return the resultant matrix C.
Algorithm: Subtraction
Input: Two matrices A and B of size m x n.
Output: Resultant matrix C = A - B.
Steps:
1. If the dimensions of matrices A and B are not compatible (m1 != m2 or n1 != n2), print an error message and exit.
2. Initialize a result matrix C of size m x n.
3. For each element C[i][j]:
     a. C[i][j] = A[i][j] - B[i][j].
4. Print or return the resultant matrix C.

Algorithm: MatrixMultiplication
Input: Two matrices A and B of size m x p and p x n, respectively.
Output: Resultant matrix C = A * B of size m x n.
Steps:
1. If the number of columns in matrix A is not equal to the number of rows in matrix B (p1 != p2), print an error message and exit.
2. Initialize a result matrix C of size m x n.
3. For each element C[i][j]:
     a. Set C[i][j] to the sum of the products of corresponding elements of the ith row of A and the jth column of B.
4. Print or return the resultant matrix C.
Algorithm: MatrixTranspose
Input: Matrix A of size m x n.
Output: Transposed matrix A^T of size n x m.
Steps:
1. Initialize a result matrix A^T of size n x m.
2. For each element A^T[i][j]:
     a. Set A^T[i][j] to A[j][i].
3. Print or return the transposed matrix A^T.

## Determine the formula to find the address location of an element in three-dimensional arrays, suppose each element takes four bytes of space and elements are stored in row-major order.
Row-major order storage means that elements are stored in memory row by row. For a 3D array, this implies that elements are stored one full 2D array after another. Within each 2D array, rows are stored one after another, and within each row, elements are stored sequentially.

Let’s assume,
B be base address of the array
A: address of the element we want to find
W : the size of each element in bytes in array
Indices be i,j,k
x,y,z  are dimensions where x means the number of 2d arrays, y means the number of rows in 2d arrays and z means the number of columns in each row.

A = B + W*(total offset)
Total offset = offset till the beginning of 2d array + offset after the 2d array 											beginning
Total offset = i*y*z + (j*z + k)
Therefore,
		 A=B+W×((I×Y×Z)+(j×Z)+k)

### Write and explain the algorithm to find the 7th smallest element in an array.
Algorithm:-
	Input: An array A of n elements.
	Step 1: Sort the array A in ascending order.(e.g., QuickSort, MergeSort).
	Step 2: Check if the array has at least 7 elements. If n < 7, then it's not possible to find the 7th smallest element, so you should return an error or a message indicating the problem.
	Step 3: If the array has 7 or more elements, the 7th smallest element is now at the 6th index of the sorted array
	Step 4: Return the element at the 6th index of the sorted array.

<h3> Let A[1 : : : n] be an array of n distinct numbers. If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A. 
List the five inversions of the array < 2; 3; 8; 6; 1 >.What array with elements from the set {1, 2,..........., n} has the most inversions? How many does it have?Give an algorithm that determines the number of inversions in any permutation of n elements in O(n log n) time. (Hint: Modify a known sorting algorithm). </h3>

Five inversions are: (2,3), (3,4), (2,4), (0,4), (1,4)
Array {8,6,3,2,1} has max inversions
Number of inversions = 4+3+2+1 = 10
Algorithm:-
1. **procedure**:
    
    a. **Divide**: Split the array into two halves, say `Left` and `Right`, at the midpoint.
    
    b. **Conquer**: Recursively count the inversions in the `Left` half and the `Right` half. This step will recursively apply the Merge Sort to sort the array while counting inversions.
    
    c. **Combine**: Count the inversions where the elements in the pair `(i, j)` are split between the `Left` and `Right` halves. This step involves merging the two halves back together and, in the process, counting the cross-inversions. When an element from the right array is placed before one from the left array during merging, it means there are as many inversions as the remaining elements in the left array, since the left array elements are greater and come before the right array element being placed.


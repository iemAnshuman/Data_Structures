# Description
language: C
compiler: Visual Studio Code
<br>

# Contents
# No warnings
<p>
e002: int to char
In this case, a is an integer with the value 10. When passed to printf with the %c format specifier,
a is implicitly converted to an unsigned char, and the character with the ASCII value of 10 
(which is a newline character in ASCII) is printed. This behavior is defined and expected according 
to the C standard, which is why a compiler might not issue a warning for this specific case.

e010: cool things to do on float(related to inf and nan)

e009: divided by 0 for int
output: 0
in gcc compiler, this output is a manifestation of the undefined behavior as GCC adheres to the C standard, which states that integer division by zero is undefined. 
**Q. if it's undefined behavior, why i am not getting 0 every single time?**
The term "undefined behavior" means the C standard does not define what the outcome of certain operations should be, leaving it up to the compiler to decide how to handle such cases. 
</p>
<br>

# Syntax Errors
    - any mistake in syntax
<br>
<br>

# Compilation Errors
<p>Compilation error or compile error refers to a state when a compiler fails to compile a piece of computer program source code, either due to errors in the code, or, more unusually, due to errors in the compiler itself. </p>
<br>

![001](<Screenshot 2024-03-26 at 1.30.26 AM.png>)
<br>

![004](<Screenshot 2024-03-26 at 1.35.07 AM.png>)
<br>

![008](<Screenshot 2024-03-26 at 2.11.41 AM.png>)
<br>
<br>

# Linker Errors
<p>Linker errors occur when the linker is trying to put all the pieces of a program together to create an executable, and one or more pieces are missing.</p>
<br>

![005](<Screenshot 2024-03-26 at 1.42.29 AM.png>)
<br>

<br>
<br>

# Runtime Errors
<p>A runtime error in a program is an error that occurs while the program is running after being successfully compiled. </p>
<br>

# Segmentation Errors
<p>A segmentation fault is a specific kind of error caused by accessing memory that the program does not have the rights to access. 
e011
</p>
<br>
<br>

# Bus Errors
<p>An error that occurs when the processor detects a misaligned memory access.

</p>

# Logical Errors
<p>a logic error is a bug in a program that causes it to operate incorrectly, but not to terminate abnormally.</p>
<br>
<br>

# Warnings(potential errors)
![003](<Screenshot 2024-03-26 at 1.28.10 AM.png>)
<br>

    - unused variable

    - warning: non-void function does not return a value in all control paths [-Wreturn-type]
<br>

# Other important observations

1. diff btwn 2.0f and 2.0
2. using {} while declaring var inside switches
3. instead of using mid = (min+max)/2, use mid = min + (max - min)/2. This prevents overflow
4. when returning from a function, sometimes its not possible to return any int in that case 
change the function type to long or long long int and return long_max or something like that.

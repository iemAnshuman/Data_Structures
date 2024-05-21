# Asymptotic Notation
:DESCRIPTION: This is a part of 6.042 which is a pre-requisite of 6.006.

### What? 
Asymptotic notation is a shorthand, used to give a quick measure of the **behavior of a function f(n) as n grows large.**

### Little Oh
![Little Oh](<Screenshot 2024-03-23 at 6.13.36 PM-1.png>)

### Big Oh
![Big Oh](<Screenshot 2024-03-23 at 6.25.24 PM.png>)
![Big Oh](<Screenshot 2024-03-23 at 7.04.35 PM.png>)
<p>In simple terms, "Big Oh" notation is used to describe the upper limit of how fast a function can grow as its input size goes to infinity. If a function f(x) is said to be O(g(x)), it means that the growth rate of f(x) does not exceed the growth rate of g(x) up to a constant multiple, for sufficiently large values of x.</p>

<p>The "lim sup" in the definition refers to the "limit superior" as x approaches infinity. This ensures that even if f(x)/g(x) oscillates or has spikes as x grows, as long as it doesn't go off to infinity and has an upper boundary, we can say f(x) is O(g(x)).</p>

### Diff between Little Oh and Big Oh
If f(x)=O(g(x)), it means that for large values of x, the function f(x) does not grow faster than   g(x) multiplied by some constant.
while  If f(x) = o(g(x)), it means that as x approches to infinity, f(x) is strictly slower than g(x).

### Big-Omega
![Big Omega](<Screenshot 2024-03-23 at 6.58.45 PM.png>)
represents: the running time of the algo- rithm is a least

### Little-Omega
![Little Omega](<Screenshot 2024-03-23 at 7.18.19 PM.png>)

### Theta
![Theta](<Screenshot 2024-03-23 at 10.12.23 PM.png>)

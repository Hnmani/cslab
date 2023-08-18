<h1>CSLAB Assignments [CS6P001]</h1>
This Repo Contains the Solutions for CSLAB Assignments(CS6P001)[Computer Systems Lab] taught @ IITBBS.
<h2>Assignment 1</h2>
<ul>
  <li>
    Catalan numbers C(n), n &gt; 0, are defined recursively as follows.<br>
    C(0) = 1,<br>
    C(n) = C(0)C(n−1) + C(1)C(n−2) + C(2)C(n−3) + · · · + C(n−1)C(0) for n &gt; 1<br>
    Write a recursive function to return C(n).<br>
  </li>
  <li>
    In a circular linked list, the next pointer of the last node points back to the first node
    in the list. Write a function that, given a circular linked list and a positive integer k,
    replaces the key at each node by the maximum of the next k elements in the list. For
    example, if the input list is <strong>3,1,6,2,7,4,5,2,9,8,5,2,</strong> and k = 3, the list should be
    updated to <strong> 6,7,7,7,5,9,9,9,8,5,3,6</strong>. So that you know, no new linked list is to be created. The
    existing list must be modified.
  </li>
  <li>
    A file input.txt stores student records. The first line of the file stores the count n of
    students. This is followed by n lines, each storing a roll number (a string like
    23CS06033), the CGPA of the student (a real number like 8.76), and finally the name
    of the student (may contain spaces). The three fields in each line are separated by
    one or more spaces (or tabs). Read the student records, sort the records based on
    student names, and write the sorted records to a file output.txt in the format Name
    RollNo CGPA. You may use any sorting algorithm.
  </li>
  <li>
    You are given an n×n matrix M of integers.<br>
    (a) Sort each row of M in the ascending order.<br>
    (b) Sort each column of M in descending order.<br>
    (c) Write a function that, given an integer x, finds out whether x is an element of M.<br>
    Assume that you have applied the sorting phases of Parts (a) and (b). Your
    program should run in O(n) time.
  </li>
  <li>
    (a) Build a stack S of integers. Write functions to implement the initialize, top, push,
    and pop operations for S.<br>
    (b) Use the stack operations to evaluate a postfix expression involving integer
    operands and the operators +, -, *, /, and %.<br>
  </li>
</ul>

<h2>Assignment 2</h2>
<ul>
  <li>
    Given a directed graph with N nodes and E edges where the weight of each of the
edges is greater than one, also given a source S and a destination D. Write a program
to find the path with the minimum product of edges from S to D. If there is no path
from S to D then print -1. (10 Marks)<br>
Input: N = 3, E = 3, Edges = {{{1, 2}, 5}, {{1, 3}, 9}, {{2, 3}, 1}}, S = 1, and D = 3<br>
Output: 5<br>
The path with the smallest product of edges will be 1->2->3
with the product as 5*1 = 5.<br>
Input: N = 3, E = 3, Edges = {{{3, 2}, 5}, {{3, 3}, 9}, {{3, 3}, 1}}, S = 1, and D = 3<br>
Output: -1<br>
  </li>
  <li>
    Consider the task of multiplying two integer matrices A and B, each of size 500 × 500.
Each matrix can have at most 500 non-zero entries. Any row of A or B that contains at
least one non-zero element must have no less than 50 non-zero elements. (10 Marks)<br>
(a) Propose a space-efficient data structure for this task.<br>
(b) Based on your proposed data structure, design an efficient algorithm to multiply
A and B. The resulting matrix should be stored separately.<br>
(c) What is the maximum number of integer multiplications needed to complete this
task as per your implementation?<br>
  </li>
  <li>
    The houses in a village are connected by dirt roads. The panchayat of the village
wanted to plan the paving of proper roads to make travel easy for villagers. They had
two requirements:<br>
<ul>
<li>Enough roads must be paved so that it is possible for everyone to travel from
their house to anyone else's house only along paved roads, and </li>
<li>The paving should cost as little as possible. The houses are numbered from 0
to n-1, and the number of dirt roads is m, where each dirt road connects any
2 houses.</li>
</ul>
The input should be in the following format:<br>
➢ 1. n //no of houses<br>
➢ 2. m //no of dirt roads<br>
➢ 3. 2D array of size m x 3<br>

where every row of the 2D array describes a dirt road; in every row, the first 2
elements represent the house number that the road connects, and the 3rd element
represents the cost of building that road.
The output should be the expense required to build the roads that satisfy the above
requirements. (10 Marks)<br>
Input:<br>
5 6 <br>
1 2 6<br>
2 3 5<br>
3 4 4<br>
1 4 1<br>
1 3 2<br>
3 5 3<br>
Output:
11
  </li>
  <li>
    Let S = {x1, x2, . . .xn
} be a set of n integers. A pair (xi, xj ) (where i ≠ j) is said to be the
closest pair if |xi-xj | ≤ |xi’-xj’|, for all possible pairs (xi’, xj’), i′, j′ = 1, 2, . . . , n, i′ ≠ j′. (10Marks)<br>
(a) Describe a method for finding the closest pair among the set of integers in
S using O(n log2 n) comparisons.<br>
(b) Now suggest an appropriate data structure for storing the elements in S
such that if a new element is inserted into the set S or an already existing
element is deleted from the set S, the current closest pair can be reported in
O(log2 n) time.<br>
(c) Briefly explain the method of computing the current closest pair and the
necessary modification of the data structure after each update. Justify the
time complexity.<br>
  </li>
</ul>

<h2>Assignment 3</h2>
<ul>

<li>Given a binary tree, write a program to print all the nodes of the binary tree in
Pre-order, Post-order, and In-order using only one stack traversal.</li>
<li>Given the root of a binary tree, return the length of the diameter of the tree.
Notes:
The diameter of a binary tree is the length of the longest path between any two
nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges
between them.<br>
Example: If the graph is as follows, the diameter can be [4,2,1,3] or [5,2,1,3].<br>
Output: 3<br>
</li>
<li>There are n cities. Some of them are connected, while some are not. If city a is
connected directly with city b and city b is connected directly with city c, then city a
is connected indirectly with city c.<br>
A province is a group of directly or indirectly connected cities and no other cities
outside of the group.<br>
You are given an n x n matrix where the entry will be 1 if the two cities are
connected otherwise, 0.<br>
Return the total number of provinces.<br>

Input:<br>
1 1 0 1 0 0<br>
1 1 1 0 0 0<br>
0 1 1 1 0 0<br>
1 0 1 1 0 0<br>
0 0 0 0 1 1<br>
0 0 0 0 1 1<br>
Output: 2<br>
</li>
<li>There is an integer array sorted in ascending order (with distinct values).
The array can be rotated at a pivot index k (1 <= k < nums.length) such that the
resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
nums[k-1]] (0-indexed).<br>
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
[4,5,6,7,0,1,2].<br>
Given the array after the possible rotation and an integer target, return the index of
the target if it is in the resultant array or -1 if it is not.<br>
Propose an algorithm with O(log n) runtime complexity and write the program.<br>
Input: nums = [4,5,6,7,0,1,2], target = 0<br>
Output: 4<br>
</li>
</ul>

<h2>Assignment 4</h2>
<ul>
<li>Write a program to find the maximum number of edges that can be added to a tree
without violating the bipartite property.</li>
<li>You are given an m x n integer array grid. There is a robot initially located at the
top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner
(i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in
time.<br>
An obstacle and space are marked as 1 or 0 respectively in the grid. A path that the
robot takes cannot include any square that is an obstacle.<br>
Write a program to return the number of possible unique paths that the robot can
take to reach the bottom-right corner.</li>
<li>You have planned some train travelling one year in advance. The days of the year in
which you will travel are given as an integer array of days. Each day is an integer from
1 to 365.<br>
  
Train tickets are sold in three different ways:<br>
  
  <ul>
   <li> a 1-day pass is sold for costs[0] dollars,</li>
   <li> a 7-day pass is sold for costs[1] dollars, and</li>
   <li> a 30-day pass is sold for costs[2] dollars.</li>
  </ul>

The passes allow that many days of consecutive travel.<br>
For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5,
6, 7, and 8.<br>
Return the minimum number of dollars you need to travel every day in the given list
of days.<br>
Example<br>
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]<br>
Output: 17<br>

Explanation: For example, here is one way to buy passes that lets you travel on your
travel plan:<br>
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.<br>
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.<br>
In total, you spent $17 and covered all the days of your travel.<br>

<li>Given an array arr of positive integers. Write a program to find the maximum length
of a subsequence of the array which satisfies the following conditions:<br>
  <ol>
    <li>arr.length >= 3</li>
<li>There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
<ol>
 <li>arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 <li>arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
  </ol>
   </li>
</ol>
</ul>

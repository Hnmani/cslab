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

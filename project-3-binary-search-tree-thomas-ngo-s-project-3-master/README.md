CSUF CPSC 131, Fall 2016
Project 3
"Binary Search Tree" (using the data structures learned in CPSC 131)

Group members:

Thomas Ngo tngo0508@csu.fullerton.edu



## You need to answer the following question. 
Two binary search trees contains exactly the same number of entries of student information but in different orders.
Do they give the same performance in terms of key searching or firstname searching? if not, why? use the data you obtain from you code to 
explain your answer. 

Although two binary search trees contain exactly the same number of entries of student information but in different orders, they do not give the same performance in terms of key searching or firstname searching. Since the first binary tree is already rearranged or sorted in alphabetical order, the searching is depended on the firstname letter being searched. When the key (firstname) is searched, the compiler will traverse all the way down the binary in which has many long branches (left or right subtrees) due to alphabetical order. Meanwhile, the second binary is constructed based on randomness. Therefore, it will randomly change direction when going down the tree in order to search for the key. Besides, the two binary is not optimized by using restructured concept such as AVL tree. So, the performance will take longer time to get to the key. 

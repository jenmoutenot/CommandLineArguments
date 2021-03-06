# Wash
Jen Moutenot
CS 366

## Analysis
This program called 'wash' will be useful in manipulating and organizing Mr. Krab's files. Most importantly, in order to accomplish this, the use of I/O is necessary. I will create functions that corresspond to each of the 11 commands (c,d,r,u,t,a,l,m,x,n, and q). These functions will allow Mr. Krabs to play around with his files in the 11 different ways he may wish. First, Mr. Krabs will need to start the program by typing in the name of the program (wash) and the corresponding file(s) he wants to manipulate. Then, the program will take this input, and output the name of the first file in the list, asking for a command. Mr. Krabs will then need to type in one of the commands and the resulting action will occur. When Mr. Krabs is done manipulating the files, he can then just type in the command 'q' and the program quits. 

## Analysis Questions
1. Where do the files come from (a,b,c)?  
2. How does the command 'm' for mode change the current file's access mode?
3. How can we obtain the information on a file's last 100 bytes (or fewer if fewer exists) and displaying them using command 'l'?
4. Are the files stored in an array or do we make the files? 
5. What information is inside of the files that make up the last 100 bytes? 

## Test Plan

Partial of test plan that tests the command line arguments
```command  +   input  output         rationale
no arguments        nothing        verify program starts up and shuts down
wash a b c    q     nothing        verify program correctly quits after startup
wash a        n     nothing        verify program correctly quits at end of list
wash a b c    n q   nothing        verify program correctly quits after next
wash a b c    c q   contents of a  verify program get contents to screen
 (assuming that a exists)
wash a b c    c q   "a not found"  verify program print error message to screen
 (where a does not exists)
wash a b c    t q   nothing        verify file a is created and has length zero
 (where file a does not exist)
wash a b c    c q   nothing        verify file a now has zero length
 (where file a exists)```

[//]: # Jen's Fleshed Out Black-Box Test Plan for 'r'
```command  +   input  output                 rationale
no arguments	    nothing	       verify program starts up and shuts down
wash a b c   r	    enter new name     verify program correctly renames the current file
wash a b c   c r    contents of a
		    enter new name     verify program correctly gets contents to screen and asks to rename the file
wash a b c   d r    enter destination
		    enter new name     verify program correctly duplicates the current file, which creates a copy of the file, then asks to rename the current file
wash a b c   u r    enter new name     verify program deletes the current file then asks to rename the current file
wash a b c   t r    enter new name     verify program deletes contents of file then asks to rename the file
wash a b c   a r    append location    
		    enter new name     verify program appends the current file to another file, then asks to rename the current file
wash a b c   l r    last 100 bytes
                    enter new name     verify program displays last 100 bytes of the current file, then asks to rename the current file
wash a b c   m r    enter chmod mode	
		    enter new name     verify program changes the file's access mode, then asks to rename the current file
wash a b c   x r    enter new name     verify program changes the current file's access time to the current time, then asks to rename the file
wash a b c   n r    enter new name     verify program goes to the next file then asks to rename the current file
wash a b c   r q    enter new name     verify program asks to rename the current file then quits after shuts down`

# text_frame
### DESCRIPTION
C program to draw a frame around the words of all its parameters.

***

### SYNOPSIS
```
Compilation
$> gcc frame.c -o <executable_name>

Execution
$> ./<executable_name> [frame_char] [STR] [STR2]...
```
We will be using '*frame*' as an <executable_name> for the following examples.

***

### USAGE
At program execution, you will have to give a **[frame_char] character** and one or more **strings ([STR] [STR2]...)** as arguments.

The program will then print on console the words of all the input [STR] inside a frame composed of [frame_char]. The width of the frame depends on the longest word found :
```
$> ./frame "*" "I've" "been         framed :o"
**********
* I've   *
* been   *
* framed *
* :o     *
**********
$> _
```
Words are composed of a succession of non-whitespace characters outlined by whitespace characters.

This means that multiple successive spaces will be ignored by the program as shown on the example above.

The program will only use the first character of the **[frame_char]** argument if multiple are inputted :
```
$> ./frame "*or#?" Hello World! 
**********
* Hello  *
* World! *
**********
$> _
```
Enjoy !

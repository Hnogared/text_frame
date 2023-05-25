# text_frame
### DESCRIPTION
C program to draw a frame around the words of all its parameters.

### SYNOPSIS
```
Compilation
$> gcc frame.c -o <executable_name>

Execution
$> ./<executable_name> [frame_char] [STR] [STR2]...
```
We will be using '*frame*' as an <executable_name> for the following examples.

### USAGE
At program execution, you will have to give a **[frame_char] character** and one or more **strings ([STR] [STR2]...)** as arguments.<br />
The program will then print on console the words of all the input [STR] inside a frame composed of [frame_char] :
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

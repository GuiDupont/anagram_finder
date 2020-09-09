# get_next_line_42

Get_next_line function reads a new line from a fd at every new call. It can be particularly useful to parse a file and extract information line by line.

---

**Read buffer size**

The size of the buffer used for the read function is not predefined and can take any value >0 and < 100 000 000. It has to befined during compilation.

**Return value**

When it reaches the end of the file (EOF) and there is no line to display anymore, the function returns 0.
If there is an issue it returns -1. Otherwise, 1 is returned.

--- 

**How to test it?**

run the following command to compile it, you can put BUFFER_SIZE up to 100 000 000:

`gcc -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c main_test.c`

then execute the program with one argument which is the path to file to be displayed:

`./a.out text_files/la_marseillaise.txt`
 
 In order to test various situation, test files are stored in the text_files folder.

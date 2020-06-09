# readline-in-c

## Object
Program for read file one line
<br><br>

## constraint in c
1. read memoey with only contraint buffer (using option -D)
2. only use read() in unistd.h and malloc(), free() in stdlib.h
3. return code is below<br>

|code|description|
|int `1`|read sucess|
|int `0`|file end|
|int `-1`|error happend|
4. no memory leak
5. input is below<br>

|name|description|
|:---|:---|
|int`fd`| file descriptor got from `open()`|
|char **`line`|read line of file|
6. file is only compose of string, not binary, but if you want, you can apply binanry char
<br><br>


#### defualt form
```c
read_line (int fd, char **line) {
	~
	return (code)
}
```
<br><br><br><br>

flex homework.l
bison -d -v homework.y
gcc lex.yy.c homework.tab.c  
./a.out test.txt

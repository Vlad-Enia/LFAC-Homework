flex homework.l
bison -d homework.y
gcc lex.yy.c homework.tab.c  
./a.out test.txt

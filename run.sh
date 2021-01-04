flex homework.l
bison -d homework.y
gcc lex.yy.c homework.tab.c -ll
./a.out test.txt
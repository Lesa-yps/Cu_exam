app.exe: main.c
	gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -g3 -o $@ $<

run: app.exe
	./app.exe

test: app.exe test.txt test_ans.txt
	./app.exe < test.txt > test_out.txt
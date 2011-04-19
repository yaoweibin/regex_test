all : test_re2 test_pcre pure_c

test_re2 : re2.cc
	g++ -o test_re2 re2.cc -I/usr/local/include -L/usr/local/lib -lre2

test_pcre : pcre.c
	gcc -o test_pcre pcre.c -I/usr/local/include -L/usr/local/lib -lpcre

pure_c : pure_c.c
	gcc -o pure_c pure_c.c

clean: 
	rm -f test_re2 test_pcre pure_c
	rm -f *.o

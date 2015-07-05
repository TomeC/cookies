exe: clean expr.o
	g++ -o ../lib/main main.cc ../lib/expr.o
expr.o:
	g++ -c expr.cc -o ../lib/expr.o
clean:
	rm -rf ../lib/*.o ../lib/main
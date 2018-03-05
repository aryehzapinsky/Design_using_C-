CXX = /usr/local/opt/llvm/bin/clang++
LDLIBS = -L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib
CXXFLAGS = -I/usr/local/opt/llvm/include -std=c++17 -O2

sort:

.PHONY: clean
clean:
	rm ./sort

.PHONY: run
run: sort
	./sort

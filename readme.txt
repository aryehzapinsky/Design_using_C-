compile:

/usr/local/opt/llvm/bin/clang++ -L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib -I/usr/local/opt/llvm/include -std=c++17 vectorlist.cpp

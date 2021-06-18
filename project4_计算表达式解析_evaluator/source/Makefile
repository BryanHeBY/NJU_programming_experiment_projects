src = $(wildcard ./*.cpp)
obj = $(patsubst %.cpp, %.o, $(src))
target = main
CC = g++

main: $(obj)
	$(CC) $(obj) -o $(target) 

%.o: %.cpp
	$(CC)  -c $< -o $@ 

.PHONY: clean
clean:
	rm -rf $(obj) $(target)

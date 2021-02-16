cpp_obj = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

bin : $(cpp_obj)
	g++ -o bin $(cpp_obj)

.PHONY : clean run

clean : 
	@rm -rf bin $(cpp_obj)

run : bin
	@echo -------------------
	@./bin

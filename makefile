all:
	rm -f main
	g++ -std=c++11 -g *.cpp -o main
	./main

build:
	rm -f main
	g++ -std=c++11 -g *.cpp -o main

clean:
	rm -f main

run:
	./main

debug:
	gdb ./main

valgrind: build
	valgrind --leak-check=full --show-leak-kinds=all ./main


#  clang++ -std=c++11 -fprofile-instr-generate -fcoverage-mapping *.cpp -o TestingMain

# LLVM_PROFILE_FILE="TestingMain.profraw" ./TestingMain
# rm -f *.o *.gcno *.gcda TestingMain coverage.info

# g++ -std=c++11 -fprofile-arcs -ftest-coverage *.cpp -o TestingMain
# ./TestingMain
# lcov --capture --directory . --output-file coverage.info
# genhtml coverage.info --output-directory out
# xdg-open out/index.html

# lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch
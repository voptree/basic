all:
	gcc -o librandom.so random.cpp -fPIC -shared
	g++ -o main_test main_test.cpp  -L./ -lrandom  --std=c++11

clean:
	rm -rf ./*.o

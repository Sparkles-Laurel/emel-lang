CC=c++

build:
	if [ ! -d "build"]
	then
		mkdir build
	else
		rm -rf build/*
	fi
	$(CC) -o build/emelc cpp/*.cpp

clean:
	rm -rf build/*
	rm -f grammar y.tab.c y.tab.h lex.yy.c

test:
	./build/emelc test/test.emel


objects= ./src/main.c ./src/menu_list.c ./src/configure.c
huphoria: $(objects)
	clang -Wall $^ -lncurses -o build/bin/huphoria

install:
	sudo ln -s $(CURDIR)/build/bin/huphoria /usr/local/bin/huphoria

clean:
	rm -rf build/bin/huphoria 

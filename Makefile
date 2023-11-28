#objects= ./src/main.c ./src/menu_list.c ./src/configure.c
objects= ./src/main.c
huphoria: $(objects)
	clang -Wall $^ -lmenu -lncurses -o build/bin/huphoria

install:
	sudo ln -s $(CURDIR)/build/bin/huphoria /usr/local/bin/huphoria

clean:
	rm -rf build/bin/huphoria 

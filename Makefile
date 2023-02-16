huphoria: ./src/main.c ./src/menu_list.c
	clang -Wall $^ -o build/bin/huphoria

install:
	sudo ln -s ~/code/huphoria/build/bin/huphoria /usr/local/bin/huphoria

clean:
	rm -rf build/bin/huphoria 

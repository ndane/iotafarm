all:
	rm -rf build
	mkdir -v build
	gcc -std=c99 main.c seed_gen.c -o build/farm

clean:
	rm -rf build
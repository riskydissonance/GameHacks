all:
	cmake -G Ninja -S . -B build
	ninja  -v -C build

clean:
	rmdir /S /Q build

rebuild: clean all

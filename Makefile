all:
	@ cmake -G Ninja -S . -B build
	@ ninja  -v -C build
	@ echo Done

clean:
	@ rmdir /S /Q build

rebuild: clean all

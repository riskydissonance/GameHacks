all:
	cmake -G Ninja -S . -B build
	ninja -C build
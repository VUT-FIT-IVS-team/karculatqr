CC = g++

all: 
	if ! [ -d "build" ]; then mkdir build && (cd build ;cmake ..); fi
	(cd ./build/; make)
	
run: all
	./build/karculatqr
	

test: all
	build/MathLibraryTest

pack: all doc profile
	mkdir ./build/install
	mkdir ./build/repo

	cp -r ./doc/ ./build/

	cp ../resources/* ./build/install/
	cp ./build/karculatqr ./build/install/
	cp ./stddev ./build/install/
	
	(cd ./build/install; zip karculatqr.zip karculatqr install.sh uninstall.sh karculatqr.desktop)
	(cd ./build/install; zip stddev.zip stddev installstddev.sh uninstallstddev.sh)

	(cd build; git clone git@github.com:VUT-FIT-IVS-team/karculatqr.git repo)

	(cd build; zip -r xbrudn02_xblaha37_xotevr03_xpriby20.zip ./install/ ./doc/ ./repo/)
	
profile: mathlib.a stddev.o
	$(CC) $(CFLAGS) stddev.o -o stddev mathlib.a -L.

mathlib.a: MathLibrary.o MathLibraryExceptions.o
	ar -crs $@ $^
	
doc:
	doxygen

%.o : %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ -fPIC

clean: 
	rm -rf build/
	rm -rf doc/
	rm -f *.a
	rm -f stddev
	rm -f *.o
	


final: UtPodDriver.o UtPod.o Song.o
	g++ -std=c++0x -otest  UtPodDriver.o UtPod.o Song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -std=c++0x -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -std=c++0x -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -std=c++0x -c Song.cpp

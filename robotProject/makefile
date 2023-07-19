clientApp: robot.o clientApp.o
	c++ robot.o clientApp.o -o clientApp.exe

clientApp.o: clientApp.cpp robot.h
	c++ -c clientApp.cpp

robot.o: robot.cpp robot.h
	c++ -c robot.cpp
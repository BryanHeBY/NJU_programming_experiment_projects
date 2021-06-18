sql: main.o DObject.o DCol.o DExpr.o DFunc.o DTable.o
	g++ -o sql main.o DObject.o DCol.o DExpr.o DFunc.o DTable.o -g

main.o: main.cpp
	g++ -c main.cpp -o main.o

DObject.o: DObject.cpp
	g++ -c -o DObject.o DObject.cpp

DTable.o: DTable.cpp
	g++ -c -o DTable.o DTable.cpp

DCol.o: DCol.cpp 
	g++ -c -o DCol.o DCol.cpp

DExpr.o: DExpr.cpp DExpr.h
	g++ -c -o DExpr.o DExpr.cpp

DFunc.o: DFunc.cpp DFunc.h
	g++ -c -o DFunc.o DFunc.cpp

clean:
	rm *.o sql

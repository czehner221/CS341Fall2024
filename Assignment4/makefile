A4.exe: driver.o Node.o LinkedNode.o LinkedList.o DoubleLinkedList.o
	g++ driver.o Node.o LinkedNode.o LinkedList.o DoubleLinkedList.o -o A4.exe
	
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o
	
DoubleLinkedList.o: DoubleLinkedList.cpp
	g++ -c DoubleLinkedList.cpp -o DoubleLinkedList.o

clean:
	rm -rf *.o A4.exe
	
run:
	A4.exe
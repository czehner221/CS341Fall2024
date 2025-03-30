A5.exe: driver.o Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o
	g++ driver.o Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o -o A5.exe
	
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o
	
BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o

RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o

clean:
	rm -rf *.o A5.exe
	
run:
	A5.exe
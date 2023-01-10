This code includes a set of files that you should not modify
 (and you really don’t need to to understand them to get this to work properly).  
 These files are main.cpp, graphicsStuff.cpp, NavigationInterface.h, and a 
 variety of text files specifying road networks (you can create more road 
 networks if you want).

To complete this lab, you should add to the supplied code to create a class
 called Navigation that inherits from (and implements) the interface file
  NavigationInterface.h.  You should do this by creating a Navigation.cpp
   and and Navigation.h file (the class should inherit from NavigationInterface.h).

While you should not modify main.cpp, graphicsStuff.cpp, and NavigationInterface.cpp,
 a little information about them is helpful.  Indeed, the content about main.cpp 
 describes how you run the program (once you get it to compile).

------------

main.cpp:

This main.cpp file processes the inputs, instantiates a class that you will write,
 and calls the functions in your class.  Finally, it calls functions defined in
graphicsStuff.cpp to create the file Map.bmp, which displays the road network
 and the shortest path computed by your program.

The program takes as as input (from the command line) a road network, a start
 location in the network (specified by an integer), and an end location in the
 network (specified by an integer). Once you create a dummy class that implements
 NavigationInterface.h and compile the code along with main.cpp and
 graphicsStuff.cpp, you can run the program as follows:

./navigate [roadNetwork] [startNode] [endNode]

For example:

./navigate ../Maps/map1.txt 12 3

finds the shortest path from location 12 to location 3 in the road network
 defined in the file ../Maps/map1.txt.

------------

graphicsStuff.cpp:

This file creates the file Map.bmp displaying the shortest path your program
 computes.  Numbers written in the image specify the cost of each link.  The 
 green shading marks the path computed by your code.

Note: If you are getting hung up trying to figure out what this code does, 
 you are not understanding what you are doing (so ask for help).  Do not 
 worry about this code unless you are trying to understand something outside 
 of the lab.

------------

NavigateInterface.cpp:

An interface file describing the abstract class that you should implement. 
 This is the blueprint to your Navigation class.  The NavigationInterface.h
 file defines three functions that your Navigation class should implement.  
 Comments in the NavigationInterface.h file tell how these functions should
 operate.

------------

Map files (in the Maps folders):

The “Maps” folder contains some sample road networks to help you start to
 test your program.  These map files are in the following format:

Line 1 specifies the number of nodes in the network.  For example, in map1.txt,
 there are 15 nodes in the network.

Lines 2 through N+1 in these files specify the adjacency matrix defining
 Cost(I,j) (see the algorithm).  For example, Line 2 specifies the cost for
 getting from node 0 to all other nodes in the network.  A cost of -1 indicates
 that there is no direct path from node 0 to a node.  For example, in map1.txt,
 there is a cost of 20 to get to node 4 from node 0, but you cannot get directly 
 to any other node from node 0.  Lines 3 through N+1 specifies the costs for 
 getting from nodes 1 though N (where N is the number of nodes read in on Line 1) 
 to all other nodes in the network.

Lines N+2 through 2N+1 specify the coordinates of each node in the network.  
 The algorithm doesn’t actually need this information so you can ignore it.  
 But graphicsStuff.cpp uses the information to create a graphical representation 
 of the road network.
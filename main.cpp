#include<iostream>
#include"Vector.h"
#include <cmath>
#include<string>
#include<ctime>
#include <fstream>
#include <sstream>
#include"Graph.h"
#include "GraphAdjList.h"

using namespace std;
int main()
{

    srand(time(0));//time seeding for passing random integer data to vertices of graph
    cout<<"-----Welcome to our Graph shortest path program-----"<<endl;
    ifstream myfile("dataset.txt");

    string line;
    Graph<int> Airports;
    for (int i=0;i<50;i++)
    {
        Airports.addVertex(rand());
    }
    ifstream myfile2("USAirportsafterEdit.txt");
    if (myfile2.is_open())
    {
        while (getline(myfile2, line))
        {
            vector<string> token;
            stringstream check1(line);
            string intermediate;
            while (getline(check1, intermediate, ' '))
            {
                token.pushback(intermediate);
            }
            Airports.ConnectBetween(stoi(token[0])-1,stoi(token[1])-1,stoi(token[2]));
           /* from.pushback(stoi(token[0]));
            to.pushback(stoi(token[1]));
            weight.pushback(stoi(token[2]));*/
        }
        myfile2.close();
    }


    else
    {cout << "Unable to open file"<<endl;
    }
cout<<Airports<<endl;

//Airports.printShortestPathfrom(1,40);


    ////trying graphs and adjacency list


   return 0;
}
////randomizing connections of 50 vertices
/*for(int i=0;i<100;i++)
{

omar.ConnectBetween(rand()%50, rand() % 50, (rand()%200)+(100));
}*/
////joseph tests
/*  vector<EdgeAdjList> edges;
    EdgeAdjList edge(0,1,2);
    edges.pushback(edge);
    GraphAdjList graphAdjList (edges,edges.mysize());
    for (int i = 0; i < graphAdjList.numberOfVertices; i++)
    {
        // display adjacent vertices of vertex i
        graphAdjList.display_AdjList(graphAdjList.head[i], i);
    }*/
////vector tests
/* vector<int> omar;
   cout<<"size is"<<omar.mysize()<<endl;
      cout<<"capacity is"<<omar.mycapacity()<<endl;
   for(int i=0;i<10;i++)
   {
       omar.insert(10,i);
   }
   omar.pushback(200);
   omar.display();
      cout<<"size is"<<omar.mysize()<<endl;
      cout<<"capacity is"<<omar.mycapacity()<<endl;
    //  omar.resize(50);
    //  omar.display();
      cout<<"size is"<<omar.mysize()<<endl;
      cout<<"capacity is"<<omar.mycapacity()<<endl;

  cout<<omar[10]<<endl;*/
//// trying normal vectors and their operations
//vector<int> omar111;
//omar111.pushback(1);
//omar111.pushback(12);
//omar111.insert(4, 1);
//for (int i = 0; i < 10; i++)
//{
//	omar111.pushback(pow(i, 2));

//}
/*vector<char> omarc;
char z = 'a';
for (int i = 0; i < 21; i++)
{
    omarc.pushback(z);
    z = z + 1;
}*/
//omarc.display();
//omar111.insert(3, 2);
//cout << "size now is" << omar111.mysize() << endl;
//omar111.display();
//cout << endl;
//cout << "element 0 is" << omar111.get(8) << endl;
//omar111.erase(2);
//cout << "size after erasing is" << omar111.mysize() << endl;
//omar111.display();

////tobe used tomorrow
////file reading and parsing
/* ifstream myfile("dataset.txt");
 Graph<int> omar;
 for (int i = 0; i < 50; i++) {
     omar.addVertex(rand());
 }

 omar.display();
 int from,to,weight;
 while(myfile >> from >> to >>weight)
 {
   omar.ConnectBetween(from-1,to-1,weight);
 }
 omar.display();
 //omar.display();
//  omar.displayAdjacencyMatrix();
 omar.printShortestPathfrom(0, 21);
*/
////trying vector of vectors to be used in graphs
//	vector<int>o1, o2, o3;
//vector<int>* o4;
//vector<vector<int>> max;
//for (int i = 0; i < 4; i++)
//{
//	o1.pushback(rand());
//	o2.pushback(rand());
//	o3.pushback(rand());
//}
//
//
//
//cout << "display o1" << endl;
//o1.display();
//cout << endl;
//cout << "display o2" << endl;
//o2.display();
//cout << endl;
//cout << "display o3" << endl;
//o3.display();
//cout << endl;
//o3 = o1;
//cout << "display o3after copying o1" << endl;
//o3.display();
//cout << endl;
//max.pushback(o1);
//max.pushback(o2);
//max.pushback(o3);
//cout << "size" << o1.mysize() << endl;
//cout << "size" << max.get(0)->mysize() << endl;
//for (int i = 0; i < 3; i++)
//{
//	cout << endl;
//	max.get(i)->display();
//	cout << endl;
//}
////graph we have in picture
/*Graph<int> omar;
for (int i = 0; i < 5; i++) {
omar.addVertex(rand());
}
omar.ConnectBetween(0, 2, 3);
omar.ConnectBetween(1, 2, 1);
omar.ConnectBetween(2, 1, 4);
omar.ConnectBetween(1, 3, 2);
omar.ConnectBetween(2, 3, 8);
omar.ConnectBetween(3, 4, 7);
omar.ConnectBetween(4, 3, 9);
omar.ConnectBetween(2, 4, 2);
omar.display();
omar.displayAdjacencyMatrix();
cout << "vertices size" << omar.vertices.mysize() << endl;
// omar.removeVertex(2);
// cout<<"after removing vertex 2"<<endl;
omar.displayAdjacencyMatrix();
//omar.display();
cout<<"removing connection between 1 and 2"<<endl;
//  omar.removeEdgeInBetween(0,2);
omar.displayAdjacencyMatrix();
cout<<"printing shortestpath from 0 to 3"<<endl;
omar.displayAdjacencyMatrix();
omar.printShortestPathfrom(0,3);*/






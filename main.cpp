#include<iostream>
#include"Vector.h"
#include <cmath>
#include<string>
#include<ctime>
#include <fstream>
#include <sstream>
#include"Graph.h"

using namespace std;
int main()
{
bool cont=1;
int choice;
    srand(time(0));//time seeding for passing random integer data to vertices of graph
    cout<<endl;
    cout<<"-----Welcome to our Graph shortest path program-----"<<endl;
    cout<<endl;
    while(cont)
    {
        cout<<"enter 1 to use Airports Dataset,  2 to use graph example"
              "\n and you can operate on it1 otherwise will terminate"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:{
                cout<<endl;
                cout<<"********Graph of Airports after being filtered to only 50 airports with max weight of their distances*****"<<endl;
                cout<<"visit this link to check whole dataset :http://opsahl.co.uk/tnet/datasets/USairport500.txt"<<endl;
                cout<<endl;
                string line;
                Graph<int> Airports;
                for (int i = 0; i < 50; i++) {
                    Airports.addVertex(rand());
                }
                ifstream myfile2("USAirportsafterEdit.txt");
                if (myfile2.is_open()) {
                    while (getline(myfile2, line)) {
                        vector<string> token;
                        stringstream check1(line);
                        string intermediate;
                        while (getline(check1, intermediate, ' ')) {
                            token.pushback(intermediate);
                        }
                        Airports.ConnectBetween(stoi(token[0]) - 1, stoi(token[1]) - 1, stoi(token[2]));
                        /* from.pushback(stoi(token[0]));
                         to.pushback(stoi(token[1]));
                         weight.pushback(stoi(token[2]));*/
                    }
                    myfile2.close();
                } else {
                    cout << "Unable to open file" << endl;
                }
                int choice1;
                cout << "1 to print 2 to show adjacency matrix 3 to show shortest path between two nodes from 0 to 49"
                     << endl;
                cin >> choice1;
                switch (choice1) {
                    case 1:
                        cout << Airports << endl;
                        break;
                    case 2:
                        Airports.displayAdjacencyMatrix();
                        break;
                    case 3:
                        int from1, to1;
                        cout << "enter from then to";
                        cin >> from1;
                        cin >> to1;
                        cout << endl;
                        Airports.printShortestPathfrom(from1, to1);
                        break;
                    default:
                        break;

                }
                break;
        }

            case 2:
            {
                cout<<endl;
                cout<<"*****Graph as in picture is inserted and you can operate on it*****"<<endl;
                cout<<endl;
                Graph<int> omar;
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
                bool operate=true;
                int choice3;
                while(operate) {
                    cout << " what do you want  to do 1 to print 2 to show adjacency matrix 3 to connect between\n"
                            " 4 to disconnect 5 to print shortest path 6 to add vertex 7 to remove vertex else terminates " << endl;
                    cin>>choice3;
                    switch (choice3) {
                        case 1:
                            omar.display();
                            break;
                        case 2:
                            omar.displayAdjacencyMatrix();
                            break;
                        case 3:
                            int from2,to2,weight2;
                            cout<<"enter from and to then weight" <<endl;
                            cin>>from2;cin>>to2;cin>>weight2;
                            cout<<endl;
                            omar.ConnectBetween(from2,to2,weight2);
                            break;
                        case 4:
                            int from,to;
                            cout<<"enter from and to for disconnection"  <<endl;
                            cin>>from;cin>>to;
                            cout<<endl;
                            omar.removeEdgeInBetween(from,to);
                            break;
                        case 5:
                            int from3,to3;
                            cout<<"enter from and to for shortest path"  <<endl;
                            cin>>from3;cin>>to3;
                            omar.printShortestPathfrom(from3,to3);
                        case 6:
                            omar.addVertex(rand());
                            break;
                        case 7:
                            cout<<"enter the number of vertex to be removed such that it is not bigger than "<<omar.size()-1<<endl;
                            int removable;
                            cin>> removable;
                            omar.removeVertex(removable);
                            break;
                        default:
                            operate=0;
                            break;


                    }
                }
                break;


            }
            default:
                cont=0;
                break;
        }
    }
    cout<<endl;
    cout<<"-----thanks for your attention----"<<endl;
cout<<endl;
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






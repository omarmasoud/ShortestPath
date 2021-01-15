#pragma once
#include"Vector.h"
#include <limits.h>
#include<string>
template<class T>
class Vertex
{
public:
    // vector<int> adj;
    // Vertex<T>& operator=(const Vertex<T>RHS);
    int num;
    //int previousVisitor;//might be used in shortest path algorithm
    T data;
    Vertex(int num, T data);
    Vertex();
    Vertex<T>& operator=(const Vertex<T>& RHS);
};
class Edge
{
public:
    int ter1, ter2, weight;
    Edge();
    Edge(int from, int to);
    Edge(int from, int to, int weight);
    Edge& operator=(const Edge RHS);
};
template<class T>
class Graph
{

private:
    int numVertices;
    //vector<Vertex<T>> vertices;
    vector<Edge> edges;
    int LeastDistanceindex(int distances[], bool visited[]);

public:

    vector<Vertex<T>> vertices;
    Graph();
    //Graph(int size);
    ~Graph();
    Graph<T>& operator = (Graph<T>& RHS);
    void addVertex(T data);
    void ConnectBetween(int from, int to, int weight);
    void removeVertex(int num);
    void removeEdgeInBetween(int from, int to);
    void printShortestPathfrom(int from, int to);
    void display();
    void displayAdjacencyMatrix();
    int size();

    vector<vector<int>>  AdjacencyMatrix;

};
#include<new>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class T>
Vertex<T>::Vertex(int num, T data) :num(num), data(data)
{
}
template<class T>
Vertex<T>::Vertex() {}

Edge::Edge(int from, int to) : ter1(from), ter2(to)
{}

Edge::Edge(int from, int to, int weight) : ter1(from), ter2(to), weight(weight)
{}
Edge::Edge()
{
}
template<class T>
Graph<T>::Graph() :numVertices(0) {}

template<class T>
void Graph<T>::addVertex(T data)
{
    //debugging
   // cout << "added vertex number " << numVertices << endl;
    Vertex<T> ver(numVertices++, data);
    vertices.pushback(ver);
    vector<int> adj;
    AdjacencyMatrix.pushback(adj);
    for (int i = 0; i < numVertices; i++)
    {
        AdjacencyMatrix.get(i)->pushback(0);
    }
    for (int i = 0; i < numVertices-1; i++)
    {
        AdjacencyMatrix.get(numVertices - 1)->pushback(0);
    }

}
template<class T>
void Graph<T>::ConnectBetween(int from, int to, int weight)
{
    if ((from <= numVertices - 1 && from >= 0) && (to <= numVertices - 1 && to >= 0) && (from != to))
    {
    for(int i=0 ;i<edges.mysize();i++)
    {
        //checks if there already exists a connection
        //if it is longer we delete it and if shorter we keep it
        if((edges[i].ter1==from)&&(edges[i].ter2==to)&&edges[i].weight<weight)
        {
            cout<<from<<" and "<<to<<" are linked already with weight "<<*AdjacencyMatrix.get(from)->get(to)<<endl;
            cout<<"can't insert a link with weight "<<weight<<endl;
            //already found and you got to exit
            return;
        }
        else if((edges[i].ter1==from)&&(edges[i].ter2==to)&&edges[i].weight>weight)
        {
            edges.erase(i);
            break;
        }
    }

        Edge edge(from, to, weight);
        edges.pushback(edge);
        *AdjacencyMatrix.get(from)->get(to) = weight;
    }
    else
    {
        cout<<"can't insert a link between "<<from<<" and "<<to<< "with weight "<<weight<<endl;
    }
}
template<class T>
void Graph<T>::removeVertex(int num)//need modifications
{
    if (num < vertices.mysize())
    {
        cout << "cleaning edges" << endl;
        for (int j = 0; j < edges.mysize(); j++)
        {

            if ((edges.get(j)->ter1 == num) || (edges.get(j)->ter2 == num))
            {
                edges.erase(j);//remove edges connected with this vertex
            }
        }
        // debugging
        //cout << "cleaning vertices" << endl;
        vertices.erase(num);
        for (int k = num; k < vertices.mysize(); k++)
        {
            //debugging
            //cout << "shifting numbers " << endl;
            vertices.get(k)->num = vertices.get(k)->num - 1;
        }

        AdjacencyMatrix.erase(num);
        for (int i = 0; i < AdjacencyMatrix.mysize(); i++)
        {
            AdjacencyMatrix.get(i)->erase(num);
        }
        //   ConnectionList.erase(num);
        numVertices--;
    }
    else
    {
        cout << " no vertex of number " << num << " was found to be erased" << endl;
    }
}
template<class T>
void Graph<T>::display()
{
    for (int i = 0; i < AdjacencyMatrix.mysize(); i++)
    {
        cout << " vertex number " << i << " connected with : ";
        for (int j = 0; j < AdjacencyMatrix[i].mysize(); j++)
        {
            if (AdjacencyMatrix[i][j] != 0)
            {
                cout << "vertex " << j << " by distance " << AdjacencyMatrix[i][j] << " , ";
            }
        }
        cout << endl;
    }
}
template<class T>
void Graph<T>::displayAdjacencyMatrix()
{
    cout << "adjacency list is" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        AdjacencyMatrix[i].display();
        cout << endl;
    }

}

template<class T>
Vertex<T>& Vertex<T>:: operator=(const Vertex<T>& RHS) {
    this->data = RHS.data;
    this->num = RHS.num;
    //  this->adj = RHS.adj;
    return *this;
}

Edge& Edge:: operator=(const Edge RHS) {
    this->ter1 = RHS.ter1;
    this->ter2 = RHS.ter2;
    this->weight = RHS.weight;
    return *this;
}
template<class T>
void Graph<T>::printShortestPathfrom(int from, int to)
{
    //Dijkstra algorithm
    bool* visited = new bool[numVertices];
    int* distances = new int[numVertices];
    int* previousvertex = new int[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
        distances[i] = INT_MAX;
    }
    distances[from] = 0;
    //visited[leastindex] = 1;
    for (int i = 0; i < numVertices - 1; i++)
    {
        int leastindex = LeastDistanceindex(distances, visited);
        //   cout<<"least index is "<<LeastDistanceindex(distances, visited)<<endl;
        visited[leastindex] = true;
        for (int j = 0; j < numVertices; j++)
        {
            if ((AdjacencyMatrix[leastindex][j] != 0) && distances[leastindex] != INT_MAX /*to avoid overflow*/
                && !visited[j] && (AdjacencyMatrix[leastindex][j] + distances[leastindex] < distances[j]))
            {
                distances[j] = *AdjacencyMatrix.get(leastindex)->get(j) + distances[leastindex];
                previousvertex[j] = leastindex;
                // cout << "meh" << *AdjacencyMatrix.get(leastindex)->get(j) << endl;
            }
            // cout<<distances[j]<<endl;
        }
    }
    for (int i = 0; i < numVertices; i++)
    {
        cout << "distance of " << i << " from source " << from << " is " << ((distances[i] != INT_MAX) ? to_string(distances[i]) : "no path found") << endl;
    }
    int CurrentlyStandingAtNode = to;
    if (distances[to] != INT_MAX)
    {
        cout << "shortest path from " << from << " to " << to<<" of weight " <<distances[to]<< " is: " << endl;
        while (CurrentlyStandingAtNode != from)
        {
            cout << CurrentlyStandingAtNode << " <- ";
            CurrentlyStandingAtNode = previousvertex[CurrentlyStandingAtNode];
        }
        cout << from << endl;
    }
    else
    {
        cout << "sadly no path for your destination" << endl;
    }
    delete[]visited;
    delete[]distances;
    delete[]previousvertex;
}

template<class T>
int Graph<T>::LeastDistanceindex(int distances[], bool visited[])
{
    int leastindex;
    int leastdistance = INT_MAX;
    for (int i = 0; i < numVertices; i++)
    {
        if (distances[i] <= leastdistance && visited[i] == false)
        {

            leastdistance = distances[i];
            leastindex = i;
        }
    }
    //debugging
    //cout << "least " << leastindex << endl;
    return leastindex;
}
template<class T>
void Graph<T>::removeEdgeInBetween(int from, int to)
{
    for(int i=0;i<edges.mysize();i++)
    {
        if ((edges[i].ter1==from)&&(edges[i].ter2==to))
        {
         edges.erase(i);
         *AdjacencyMatrix.get(from)->get(to)=0;//set weight by zero
        }
    }
}
template<class T>
int Graph<T>:: size()
{
    return numVertices;
}
template<class T>
 Graph<T>:: ~Graph()
 {
     ////nothing needs to be put in here really since the only dynamically
   //// allocated memories are vectors and their destructors are called by default

 }
//overloading = operator
template<class T>
Graph<T>& Graph<T>:: operator = (Graph<T>& RHS)
{
    this->numVertices=RHS.numVertices;
    this->vertices=RHS.vertices;
    this->edges=RHS.edges;
    this->AdjacencyMatrix=RHS.AdjacencyMatrix;
    return *this;
}
 //overloading << operator
template<class T>
ostream& operator<<(ostream& out ,Graph<T>& tobePrinted)
{
    tobePrinted.display();
    return out;

}

////this commented code was just a trial for another constructor and using some inconvinient methods

//template<class T>
//Graph<T>::Graph(int size) : numVertices(0), size(size)
//{
//	cout << "constructing graph" << endl;
//	//Debugging
//	/*  if (size > AdjacencyMatrix.mycapacity())
//	  {
//		  AdjacencyMatrix.Recapacity(size);
//		 AdjacencyMatrix.resize(size);
//	  }*/
//	  /*AdjacencyMatrix=vector<vector<int>>(size);
//	  cout<<"adj list capacity is"<<AdjacencyMatrix.mycapacity()<<"size: "<<AdjacencyMatrix.mysize();
//		  cout<<"constructing internals graph"<<endl;
//	  for(int i=0;i<size;i++)
//	  {
//		  *AdjacencyMatrix.get(i)=vector<int>(size);
//
//	  }*/
//	  /*cout<<"adj list capacity is"<<AdjacencyMatrix.get(0)->mycapacity()<<"size: "<<AdjacencyMatrix.get(0)->mysize();
//	  cout<<"done constructing"<<endl;
//	 // AdjacencyMatrix.get(0)->NewVector(size);
//
//  cout<<"capacity"<<AdjacencyMatrix.mycapacity()<<endl;
//	  cout<<"size"<<AdjacencyMatrix.get(1)->mysize()<<endl;
//		   cout<<"constructing lists1"<<endl;*/
//		   //AdjacencyMatrix.get(0)->pushback(404);
//		   //cout<<*AdjacencyMatrix.get(0)->get(0)<<"size is"<< endl;
//
//	for (int i = 0; i < size; i++)
//	{
//		vector<int> adj;
//		AdjacencyMatrix.pushback(adj);
//		cout << "constructing adj lists " << i << endl;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++) {
//			AdjacencyMatrix.get(i)->pushback(0);
//			cout << "constructing adj lists " << i << " " << j << endl;
//		}
//	}
//
//	cout << *AdjacencyMatrix.get(1)->get(0) << "lalal is" << endl;
//	cout << "constructing lists2" << endl;
//}
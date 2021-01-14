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
    Vertex<T>* next;
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
    Graph(int size);
    void addVertex(T data);
    void ConnectBetween(int from, int to, int weight);
    void removeVertex(int num);
    //void removeEdgeInBetween(int from, int to);
    void printShortestPathfrom(int from, int to);
    void display();
    void displayAdjacencylist();
    //void MakeAdjList();
    int size;
    //vector<vector<int>>  ConnectionList;
    vector<vector<int>>  AdjacencyList;

};
#include<new>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class T>
Vertex<T>::Vertex(int num, T data) :num(num), data(data)
{
    // vector<int> adj();
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
Graph<T>::Graph(int size) :numVertices(0), size(size)
{
    cout << "constructing graph" << endl;
    //Debugging
    /*  if (size > AdjacencyList.mycapacity())
      {
          AdjacencyList.Recapacity(size);
         AdjacencyList.resize(size);
      }*/
    /*AdjacencyList=vector<vector<int>>(size);
    cout<<"adj list capacity is"<<AdjacencyList.mycapacity()<<"size: "<<AdjacencyList.mysize();
        cout<<"constructing internals graph"<<endl;
    for(int i=0;i<size;i++)
    {
        *AdjacencyList.get(i)=vector<int>(size);

    }*/
    /*cout<<"adj list capacity is"<<AdjacencyList.get(0)->mycapacity()<<"size: "<<AdjacencyList.get(0)->mysize();
    cout<<"done constructing"<<endl;
   // AdjacencyList.get(0)->NewVector(size);

cout<<"capacity"<<AdjacencyList.mycapacity()<<endl;
    cout<<"size"<<AdjacencyList.get(1)->mysize()<<endl;
         cout<<"constructing lists1"<<endl;*/
    //AdjacencyList.get(0)->pushback(404);
    //cout<<*AdjacencyList.get(0)->get(0)<<"size is"<< endl;

    for (int i = 0; i < size; i++)
    {
        vector<int> adj;
        AdjacencyList.pushback(adj);
        cout << "constructing adj lists " << i << endl;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            AdjacencyList.get(i)->pushback(0);
            cout << "constructing adj lists " << i << " " << j << endl;
        }
    }

    cout << *AdjacencyList.get(1)->get(0) << "lalal is" << endl;
    cout << "constructing lists2" << endl;
}
template<class T>
void Graph<T>::addVertex(T data)
{
    cout << "added vertex number " << numVertices << endl;
    Vertex<T> ver(numVertices++, data);
    vertices.pushback(ver);

    if (AdjacencyList.mycapacity() < numVertices)
    {
        int oldcap = AdjacencyList.mycapacity();
        AdjacencyList.Recapacity(AdjacencyList.mycapacity() + 10);

        // vector<int>newadj,newcon;

        //      ConnectionList.resize(numVertices);

        for (int i = oldcap; i < numVertices; i++)
        {
            for (int j = oldcap; numVertices; j++)
            {
                AdjacencyList.get(i)->pushback(0);
            }
        }


    }
//    AdjacencyList.resize(numVertices);

    // ConnectionList.get()
    //vector<int> adjindex;
    //ConnectionList.pushback(adjindex);
    /*if (vertices.mysize() > 10) {
        ConnectionList.resize(vertices.mysize());
    }*/
}
template<class T>
void Graph<T>::ConnectBetween(int from, int to, int weight)
{
    /*if ((from > 0 && from < numVertices) && (to > 0 && to < numVertices))
    {*/

    Edge edge(from, to, weight);
     edges.pushback(edge);
    //  ConnectionList.get(from)->pushback(to);
    *AdjacencyList.get(from)->get(to) = weight;

    //}
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
        cout << "cleaning vertices" << endl;
        vertices.erase(num);
        for (int k = num; k < vertices.mysize(); k++)
        {
            cout << "shifting numbers " << endl;
            vertices.get(k)->num = vertices.get(k)->num - 1;
        }

        AdjacencyList.erase(num);
        for (int i = 0; i < AdjacencyList.mysize(); i++)
        {
            AdjacencyList.get(i)->erase(num);
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
   for(int i=0;i<AdjacencyList.mysize();i++)
   {
       cout<<" vertex number "<<i<<" connected with : ";
       for(int j=0;j<AdjacencyList[i].mysize();j++)
       {
           if(AdjacencyList[i][j]!=0)
           {
               cout<<"vertex " <<j<<" by distance "<< AdjacencyList[i][j]<<" , ";
           }
       }
       cout<<endl;
   }
}
template<class T>
void Graph<T>::displayAdjacencylist()
{
    cout << "adjacency list is" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        AdjacencyList[i].display();
        cout << endl;
    }

}

template<class T>
Vertex<T>& Vertex<T>:: operator=(const Vertex<T>& RHS) {
    this->data = RHS.data;
    this->next = RHS.next;
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
            if ((AdjacencyList[leastindex][j] != 0) && distances[leastindex]!=INT_MAX /*to avoid overflow*/
            && !visited[j] && (AdjacencyList[leastindex][j] + distances[leastindex] < distances[j]))
            {
                distances[j] = *AdjacencyList.get(leastindex)->get(j) + distances[leastindex];
                previousvertex[j]=leastindex;
               // cout << "meh" << *AdjacencyList.get(leastindex)->get(j) << endl;
            }
            // cout<<distances[j]<<endl;
        }
    }
    for (int i = 0; i < numVertices; i++)
    {
        cout << "distance of " << i << "from source "<<from<< " is " << ((distances[i] != INT_MAX) ? to_string(distances[i]) : "no path found") << endl;
    }
    int CurrentlyStandingAtNode=to;
    if(distances[to]!=INT_MAX)
        {
        cout<<"path is:"<<endl;
        while (CurrentlyStandingAtNode!=from)
        {
         cout<<CurrentlyStandingAtNode<<" <- ";
            CurrentlyStandingAtNode=previousvertex[CurrentlyStandingAtNode];
        }
        cout<<from<<endl;
        }
    else
        {
        cout<<"sadly no path for your destination"<<endl;
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

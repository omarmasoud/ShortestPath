#pragma once
#include"Vector.h"
#include <limits.h>
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
    [[noreturn]] void printShortestPathfrom(int from, int to);
    void display();
    void displayAdjacencylist();
    void MakeAdjList();
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
    //cout<<"constructing graph"<<endl;
    if (size > AdjacencyList.mycapacity())
    {
        AdjacencyList.Recapacity(size);
        AdjacencyList.resize(size);
    }


    //     cout<<"constructing lists1"<<endl;



    for (int i = 0; i < size; i++)
    {
        //   cout<<"constructing lists"<<endl;
        for (int j = 0; j < size; j++) {
            AdjacencyList.get(i)->pushback(0);
        }
    }
}
template<class T>
void Graph<T>::addVertex(T data)
{
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
    AdjacencyList.resize(numVertices);

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
    //MakeAdjList();
    cout << "vertex num:		connected to" << endl;
    for (int i = 0; i < numVertices; i++)
    {

        cout << "vertex " << i << " connected with";
        //    ConnectionList.get(i)->display();
        cout << endl;
    }
}
template<class T>
void Graph<T>::displayAdjacencylist()
{
    cout << "adjacency list is" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        AdjacencyList.get(i)->display();
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
{//Dijkstra algorithm

    if (!(from >= 0 && from < numVertices) && !(to >= 0 && to < numVertices))
    {
        cerr << "insert in boundary vertices" << endl;
        exit(1);
    }
    bool* visited = new bool[numVertices];
    int* distances = new int[numVertices];
    //int previousnode[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i];
        distances[i] = INT_MAX;
    }
    cout << "awel habda be salam" << endl;
    for (int i = 0; i < AdjacencyList.get(from)->mysize(); ++i)
    {
        if (*AdjacencyList.get(from)->get(i) != 0)
        {
            distances[i] = *AdjacencyList.get(from)->get(i);
        }
    }
    cout << "tany habda be salam" << endl;
    visited[from] = 1;
    distances[from]=0;



    int leastindex = this->LeastDistanceindex(distances, visited);
    visited[leastindex] = 1;
    for (int i = 0; i<numVertices - 1; i++)
    {



        for (int i = 0; i < numVertices; i++)
        {
            if (*AdjacencyList.get(leastindex)->get(i) + distances[leastindex] < distances[i] && !visited[i])
            {
                distances[i] = *AdjacencyList.get(leastindex)->get(i) + distances[leastindex];
            }

        }
    }
    for (int i = 0; i < numVertices; i++)
    {
        cout << "dist of " << i << " is " << distances[i] << endl;
    }
    delete[]visited;
    delete[]distances;





}
template<class T>
int Graph<T>::LeastDistanceindex(int distances[], bool visited[])
{
    int leastindex , leastdistance;
    leastdistance = INT_MAX;
    for (int i = 0; i < this->numVertices; i++)
    {
        if (distances[i] < leastdistance && visited[i] == 0)
        {
            leastdistance = distances[i];
            leastindex = i;
        }
    }
    return leastindex;
}

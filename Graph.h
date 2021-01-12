#pragma once
#include"Vector.h"
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

public:

    vector<Vertex<T>> vertices;
    Graph(int size);
    void addVertex(T data);
    void ConnectBetween(int from, int to,int weight);
    void removeVertex(int num);
    //void removeEdgeInBetween(int from, int to);
    void printShortestPathfrom(int from,int to);
    void display();
    void displayAdjacencylist();
    void MakeAdjList();
    int size;
    vector<vector<int>>  ConnectionList;
    vector<vector<int>>  AdjacencyList;

};
#include<new>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class T>
Vertex<T>::Vertex(int num,T data):num(num),data(data)
{
   // vector<int> adj();
}
template<class T>
Vertex<T>::Vertex(){}

Edge::Edge(int from, int to) : ter1(from),ter2(to)
{}

Edge::Edge(int from, int to,int weight) : ter1(from),ter2(to),weight(weight)
{}
Edge::Edge()
{
}

template<class T>
Graph<T>::Graph(int size):numVertices(0),size(size)
{
    //cout<<"constructing graph"<<endl;
    for(int i=0;i<size;i++)
    {
        vector<int> newadj(size);
   //     cout<<"constructing lists1"<<endl;

        AdjacencyList.pushback(newadj);

    }
    for(int i=0;i<size;i++)
    {
    //   cout<<"constructing lists"<<endl;
        for(int j=0;j<size;j++) {
           AdjacencyList.get(i)->pushback(0);
       }
    }
}
template<class T>
void Graph<T>::addVertex(T data)
{
    Vertex<T> ver(numVertices++, data);
    vertices.pushback(ver);

    if(AdjacencyList.mycapacity()<numVertices)
    {
        int oldcap=AdjacencyList.mycapacity();
        AdjacencyList.resize(AdjacencyList.mycapacity()+10);
         for(int i=0;i<numVertices-AdjacencyList.mysize();i++)
         {
              vector<int>newadj,newcon;
             AdjacencyList.pushback(newadj);
             ConnectionList.pushback(newcon);
          }
        for(int i=oldcap;i<numVertices;i++)
            {
                for(int j=oldcap;numVertices;j++)
                    {
                    AdjacencyList.get(i)->pushback(0);
                  }
             }


    }

   // ConnectionList.get()
    //vector<int> adjindex;
    //ConnectionList.pushback(adjindex);
    /*if (vertices.mysize() > 10) {
        ConnectionList.resize(vertices.mysize());
    }*/
}
template<class T>
void Graph<T>::ConnectBetween(int from , int to,int weight)
{
    /*if ((from > 0 && from < numVertices) && (to > 0 && to < numVertices))
    {*/

    Edge edge(from, to,weight);
    edges.pushback(edge);
    ConnectionList.get(from)->pushback(to);
   *AdjacencyList.get(from)->get(to)=weight;

    //}
}
template<class T>
void Graph<T>:: removeVertex(int num)//need modifications
{
    if(num<vertices.mysize())
    {

            for (int j = 0; j < edges.mysize(); j++)
            {
                if ((edges.get(j)->ter1 == num) || (edges.get(j)->ter2== num)) {
                    edges.erase(j);//remove edges connected with this vertex
                }
            }
            for(int k=num+1;k<vertices.mysize();k++)
            {
                vertices.get(k)->num=vertices.get(k)->num-1;
            }
            vertices.erase(num);
        AdjacencyList.erase(num);
            for(int i=0;i<AdjacencyList.mysize();i++)
            {
                AdjacencyList.get(i)->erase(num);
            }



         //   ConnectionList.erase(num);
            numVertices--;


    }
    cout << " no vertex of number " << num <<" was found to be erased"<< endl;
}
template<class T>
void Graph<T>::display()
{
    //MakeAdjList();
    cout << "vertex num:		connected to" << endl;
    for (int i = 0; i < numVertices; i++)
    {

        cout << "vertex " << i << " connected with";
        ConnectionList.get(i)->display();
        cout << endl;
    }
}
template<class T>
void Graph<T>::displayAdjacencylist()
{   cout << "adjacency list is" << endl;
    for (int i = 0; i <numVertices; i++)
    {
        AdjacencyList.get(i)->display();
        cout << endl;
    }

}

template<class T>
Vertex<T>& Vertex<T>:: operator=(const Vertex<T>& RHS){
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
/*template<class T>
void Graph<T>:: printShortestPathfrom(int from,int to)
{
    vector<int>distances(vertices.mysize());
    vector<bool>visited(vertices.mysize());
    for(int i=0;i<vertices.mysize();i++)
    {
        visited.insert(0,i);//all unvisited
       distances.insert(-1,i);//no value of distances so needs to be calculated to get least
    }


    distances.set(0,from);
    for (int i = 0; i < ConnectionList.mysize() ; i++)
    {

        for (int j = 0; j < edges.mysize(); j++)
        { int* target=ConnectionList.get(i)->get(j);
            if ((edges.get(i)->ter1==from&&edges.get(*target)->ter2==to)
            ||(edges.get(*target)->ter1==to&&edges.get(i)->ter2==from))
            {
                distances.set(edges.get(j)->weight,*target);
            }

            visited.set(true,i);
        }

    }



}*/

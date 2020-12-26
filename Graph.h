#pragma once
#include"Vector.h"
template<class T>
class Vertex
{
public:
    vector<int> adj;
    // Vertex<T>& operator=(const Vertex<T>RHS);
    int num;
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
    Graph();
    void addVertex(T data);
    void ConnectBetween(int from, int to);
    void removeVertex(int num);
    void removeEdgeInBetween(int from, int to);
    void display();
    void MakeAdjList();
    vector<vector<int>>  adjList;

};
#include<new>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class T>
Vertex<T>::Vertex(int num,T data):num(num),data(data)
{
    vector<int> adj();
}
template<class T>
Vertex<T>::Vertex(){}

Edge::Edge(int from, int to) : ter1(from),ter2(to)
{

}
Edge::Edge(){}
Edge::Edge(int from, int to,int weight){
    Edge(from, to);
    this->weight = (rand() % 50) + 1;//random weight might be adjusted later
}
template<class T>
Graph<T>::Graph():numVertices(0)
{
}
template<class T>
void Graph<T>::addVertex(T data)
{
    Vertex<T> ver(numVertices++, data);
    vertices.pushback(ver);
    adjList.pushback(ver.adj);
    //vector<int> adjindex;
    //adjList.pushback(adjindex);
    /*if (vertices.mysize() > 10) {
        adjList.resize(vertices.mysize());
    }*/
}
template<class T>
void Graph<T>::ConnectBetween(int from , int to)
{
    /*if ((from > 0 && from < numVertices) && (to > 0 && to < numVertices))
    {*/
    Edge edge(from, to);
    edges.pushback(edge);
    adjList.get(from)->pushback(to);
    adjList.get(to)->pushback(from);

    //}
}
template<class T>
void Graph<T>:: removeVertex(int num)//need modifications
{
    for(int i=0;i<vertices.mysize();i++)
    {
        if(vertices.get(i)==num)
        {
            vertices.erase(i);
            numVertices--;
            for (int i = 0; i < edges.mysize(); i++)
            {
                if ((edges.get(i)->ter1 == num) || (edges.get(i)->ter2== num)) {
                    edges.erase(i);//remove edges connected with this vertex
                }
            }
            break;
        }
    }
    cout << " no vertex of number " << num << endl;
}
template<class T>
void Graph<T>::display()
{
    //MakeAdjList();
    cout << "vertex num:		connected to" << endl;
    for (int i = 0; i < adjList.mysize(); i++)
    {
        cout << "vertex " << i << " connected with";
        adjList.get(i)->display();
        cout << endl;
    }
}
//template<class T>
//void Graph<T> ::MakeAdjList()
//{
//	for (int i = 0; i < edges.mysize(); i++)
//	{
//
//		Edge myedge = edges.get(i);
//		adjList.get(myedge.ter1).pushback(myedge.ter2);
//		adjList.get(myedge.ter2).pushback(myedge.ter1);
//	}
//
//}
template<class T>
Vertex<T>& Vertex<T>:: operator=(const Vertex<T>& RHS){
    this->data = RHS.data;
    this->next = RHS.next;
    this->num = RHS.num;
    this->adj = RHS.adj;
    return *this;
}

Edge& Edge:: operator=(const Edge RHS) {
    this->ter1 = RHS.ter1;
    this->ter2 = RHS.ter2;
    this->weight = RHS.weight;
    return *this;
}

// Created by Joseph Daoud on 15/01/2021.
//
#pragma once
#include "Vector.h"
class EdgeAdjList
{
public:
    int startPoint, endPoint, weight;
    EdgeAdjList();
    EdgeAdjList(int from, int to, int weight);
};

class VertexAdjList{
public:
    int value;
    int cost;
    VertexAdjList * next;
    VertexAdjList(int num, int data, VertexAdjList * head);
    VertexAdjList();
};

class GraphAdjList{
public:
    int numberOfVertices;
    VertexAdjList **head;
    GraphAdjList( vector<EdgeAdjList> &edge, int numOfVer);
    ~GraphAdjList();
    void  display_AdjList(VertexAdjList* ptr, int i);
};
#include<new>
EdgeAdjList::EdgeAdjList(int from, int to, int weight) {
    this->startPoint=from;
    this->endPoint=to;
    this->weight=weight;
}
VertexAdjList::VertexAdjList(int num, int data, VertexAdjList *head) {
    this->value=num;
    this->cost=data;
    this->next=head;
}
GraphAdjList::GraphAdjList( vector<EdgeAdjList> &edge, int numOfVer) {
    this->head= new VertexAdjList*[numOfVer];
    this->numberOfVertices=numOfVer;
    for (int i = 0; i < numOfVer; ++i) {
        this->head[i]= nullptr;
    }
    for (int i = 0; i < edge.mysize() ; ++i) {
        head[edge[i].startPoint]= new VertexAdjList(edge[i].endPoint,
                                                    edge[i].weight,
                                                    head[edge[i].startPoint]);
    }
}
EdgeAdjList::EdgeAdjList()
{
}
GraphAdjList::~GraphAdjList() {
    for (int i = 0; i < numberOfVertices; i++)
        delete[] head[i];
    delete[] head;
}
void GraphAdjList:: display_AdjList(VertexAdjList* ptr, int i)
{
    while (ptr != nullptr) {
        std::cout << "(" << i << ", " << ptr->value
                  << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
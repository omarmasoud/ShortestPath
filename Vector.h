#pragma once
#include"cassert"
template<class T>
class vector {
public:
    vector<T>& operator =(const vector < T >& RHS);

    T& operator [](int pos);
    void set(T element, int pos);
    ~vector();
    vector(int capaicty);
    int mysize();
    int mycapacity();
    vector();
    void insert(const T& element, int pos);
    void pushback(const T& element);
    void Recapacity(int size);
    T* get(int pos);
    void erase(int pos);
    void display();
private:
    void allocateMoreMemory();
    int capacity;
    T* myArray;
    int size;
};
# include<new>
using namespace std;
template<class T>
vector<T>::vector() :capacity(10), size(0)
{
    this->myArray = new(nothrow) T[capacity];
}
template<class T>
void vector<T>::insert(const T& element, int pos)
{
    if (pos >= 0) {
        if (pos == size && capacity > size)
        {
            myArray[pos] = element;
            size++;
        }
        else if (pos == size && capacity == size)
        {
            allocateMoreMemory();
            myArray[pos] = element;
            size++;
        }
        else if ((pos < size) && (capacity > size)) {
            for (int i = size; i > pos; i--) {
                myArray[i] = myArray[i - 1];
            }
            myArray[pos] = element;
            size++;
        }
        else if (capacity == size) {
            allocateMoreMemory();
            for (int i = size; i > pos; i--) {
                myArray[i] = myArray[i - 1];
            }
            myArray[pos] = element;
            size++;
        }
        else if (pos > capacity) {
            cerr << "can't insert in such location " << endl;
        }

    }
    else {
        cerr << "out of boundary insertion" << endl;
        exit(2);
    }
}
template<class T>
vector<T>::vector(int capaicty) :capacity(capaicty), size(0)
{
    myArray = new(nothrow) T[capaicty];
    if (myArray = NULL)
    {
        cerr << "array not allocated" << endl;
    }
    else
    {
        cout << "array allocated with capacity " << capaicty << endl;
    }
}
template<class T>
void vector<T>::set(T element, int pos)
{
    if (pos >= 0)myArray[pos] = element;
}

template<class T>
void vector<T>::pushback(const T& element)
{
    this->insert(element, this->mysize());
    /* if(size==capacity)
     {
         allocateMoreMemory();
     }
     myArray[size] = element;
     size++;*/
}


//template<class T>
//void vector<T>::pushfront(T element)
//{
//}
template<class T>
void vector<T>::allocateMoreMemory()
{
    T* replacer = new (nothrow)T[capacity + 10];//allocate extra 10 places for expecting any nearby insertings
    if (replacer != NULL)
    {
        capacity = capacity + 10;
        for (int i = 0; i < size; i++)
        {
            replacer[i] = myArray[i];
        }
        delete[] myArray;
        myArray = replacer;
    }
    else {
        //cerr << "couldnt allocate more memory" << endl;
    }
}
template<class T>
void vector<T>::display() {
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << ",";

    }
}
template<class T>
T* vector<T>::get(int pos)
{
    if (pos >= 0 && pos < size) {
        return &myArray[pos];
    }

}
template<class T>
void vector<T>::erase(int pos)
{
    if (pos >= 0 && pos < size)
    {
        for (int i = pos; i < size - 1; i++)
        {
            myArray[i] = myArray[i + 1];

        }
        size--;
    }
    else {
        cerr << "pos in appropriate for deletion" << endl;
        exit(1);
    }
}
template<class T>
int vector<T> ::mysize() {
    return size;
}
/*
template<class T>
void vector<T>::resize(int size) {
	this->size = size;
}
*/

template<class T>
void vector<T>::Recapacity(int newsize)
{

    if (newsize == mycapacity()) return;
    else if (size < 0)
    {
        cerr << "no size less than 0" << endl;
        return;
    }
    else
    {
        if (newsize < capacity)
        {
            size = newsize;
        }
        else {
            size = size;
        }
        T* arr = new (nothrow)T[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = myArray[i];
        }
        delete[] myArray;
        capacity = newsize;

        myArray = arr;
    }

}
template<class T>
vector<T>& vector<T>:: operator =(const vector < T >& RHS)
{
    if (RHS.size != this->size) {
        delete[] this->myArray;
        this->myArray = new(nothrow) T[RHS.size];
    }
    for (int i = 0; i < RHS.size; i++)
    {
        this->myArray[i] = RHS.myArray[i];
    }
    this->capacity = RHS.capacity;
    this->size = RHS.size;
    return *this;
}
//this function is commented due to compiler error deleting when called on visual studio
template<class T>
vector<T> :: ~vector()
{
    delete[]myArray;
    //cout<<"vector destructor"<<endl;
}
template<class T>
int vector<T>::mycapacity()
{
    return this->capacity;
}
template<class T>
T& vector<T>:: operator [](int pos)
{
    return *this->get(pos);
}
/*
template<class T>
vector<T>::vector(T defaultvalue)
		{
			for (int i = 0; i <capacity ; ++i) {
				myArray[i]=defaultvalue;
			}
		}*/

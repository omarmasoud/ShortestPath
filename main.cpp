#include<iostream>
#include"Vector.h"
#include <cmath>
#include<cstring>
#include<ctime>
#include"Graph.h"

using namespace std;
int main()
{// trying normal vectors and their operations
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

    //return 0;

    //trying vectors of vectors
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

    //trying graphs and adjacency list
    Graph<int> omar;
    for (int i = 0; i < 4; i++) {
        omar.addVertex(rand());
    }
    omar.ConnectBetween(0, 2);
    omar.ConnectBetween(0, 1);
    omar.ConnectBetween(0, 3);
    omar.ConnectBetween(1, 2);
    omar.ConnectBetween(2, 3);
    //int num = omar.vertices.get(3).num;
    //cout << num;
    omar.display();
    cout << "size of adj list 1 is " << omar.adjList.get(0)->mysize() << endl;
    cout << "size is" << omar.adjList.mysize() << endl;


    return 0;
}


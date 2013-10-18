#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

typedef struct nodeTree* NodeTree;
struct nodeTree{
  void* value;
  NodeTree left;
  NodeTree right;
};




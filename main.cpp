#include "kdtree.h"

int main(){
    
    std::vector<int> x;
    std::vector<int> y;
    std::vector<int> n;
    std::vector<int> nearest_neighbor;
    n.push_back(0);
    n.push_back(0);
    x.push_back(3);
    x.push_back(3);
    y.push_back(5);
    y.push_back(6);
    int k = 2;
    KDTree xy(k);
    xy.insert(x);
    xy.insert(y);
    nearest_neighbor = xy.NNS(n);

    std::cout<< nearest_neighbor[0] << nearest_neighbor[1] << std::endl;
    
    return 0;
}
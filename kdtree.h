#pragma once
#include <iostream>
#include <vector>

struct KDNode {

    std::vector<int> pt;
    KDNode* left;
    KDNode* right;
    KDNode(std::vector<int> x);
};

class KDTree {
    
private:
    KDNode* root;
    int dim;
public:
    KDTree(int k);
    KDTree(int k,std::vector<int> x);
    void insert(std::vector<int> x);
    KDNode* insert(std::vector<int> x, KDNode *t, int cd);
    void NNS(std::vector<int> n, KDNode *p, std::vector<int> &ref_point,float &ref_distance, int cd);
    std::vector<int> NNS(std::vector<int> n);
};


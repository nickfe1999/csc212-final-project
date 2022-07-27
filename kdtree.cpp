#include <iostream>
#include <vector>
#include <cmath>
#include "kdtree.h"

KDNode::KDNode(std::vector<int> x) {
    for(int i = 0; i < x.size();i++){
        pt[i] = x[i];
    }
    
    left = nullptr;
    right = nullptr;
}

KDTree::KDTree(int k, std::vector<int> x) {
    dim = k;
    root = new KDNode(x);
}

KDNode* KDTree::insert(std::vector<int> x, KDNode* t, int cd) {
        
    if (t == nullptr) {
        t = new KDNode(x);
    }
    
    else if (x == t->pt) {
        std::cout<< "error! duplicate" << std::endl;
    }
    
    else if (x[cd] < t->pt[cd]) {
        t->left = insert(x, t->left, (cd+1) % dim);
    }
    
    else{
        t->right = insert(x, t->right, (cd+1) % dim);
    }
    
    return t;
}

KDNode* KDTree::NNS(std::vector<int> q, KDNode* n, std::vector<int> p,float w){
    int search_first;

    if(n->left== nullptr && n->right == nullptr) {
        float sum = 0;
        for(int i = 0; i < dim; i++) {
            sum += pow(n->pt[i]-q[i],2);
        }
        float w_prime = std::sqrt(sum);                            
        if(w_prime < w) {
            w = w_prime;
            for(int i = 0; i < n->pt.size(); i++) {
                p[i] = n->pt[i];
            }
            
        }
       
    }
    else {
        if(q[n->cutDim] <= dim){
            search_first = 0;
        }
        else {
            search_first = 1;
        }
        if(search_first == 0){
            if(q[n->cutDim] - w <= dim) {
                NNS(q,n->left,p,w);
            }
            if(q[n->cutDim] + w > dim) {
                NNS(q,n->right,p,w);
            }
        }
        else { //search_first == right or 1
            if(q[n->cutDim] + w > dim) {
                NNS(q,n->right,p,w);
            }
            if(q[n->cutDim] - w <= dim) {
                NNS(q,n->left,p,w);
            }
        }
    }


    for(int i = 0; i < n->pt.size();i++){
        std::cout<<n->pt[i]; 
    }
    
}
    
    


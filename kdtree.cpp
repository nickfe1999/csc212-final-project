#include <iostream>
#include <vector>
#include <cmath>
#include "kdtree.h"

KDNode::KDNode(std::vector<int> x) {
    for(int i = 0; i < x.size();i++){
        pt.push_back(x[i]);
    }
    
    left = nullptr;
    right = nullptr;
}

KDTree::KDTree(int k) {
    dim = k;
    root = nullptr;

}



KDTree::KDTree(int k, std::vector<int> x) {
    dim = k;
    root = new KDNode(x);

}

void KDTree::insert(std::vector<int> x){
    if (root == nullptr) {
        root = new KDNode(x);
    }

    else{
        root = insert(x,root,0);
    }
}


KDNode* KDTree::insert(std::vector<int> x, KDNode* t, int cd) {
        
    if (t == nullptr) {
        return new KDNode(x);
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

void KDTree::NNS(std::vector<int> q, KDNode* n, std::vector<int> &p, float &w, int cd){
    
    
    if(n == nullptr){
        return;
    }
    int search_first;
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
       
        if(q[cd] <= n->pt[cd]){
            
            search_first = 0;
        }
        else {
            search_first = 1;
        }
        if(search_first == 0){
            NNS(q,n->left,p,w,cd+1);

            if(q[cd] + w >  n->pt[cd]) {
                NNS(q,n->right,p,w,cd+1);
            }
        }
        else { //search_first == right or 1

            NNS(q,n->right,p,w,cd+1);

            if(q[cd] - w <=  n->pt[cd]) {
                NNS(q,n->left,p,w, cd+1);
            }
        }
}

std::vector<int> KDTree::NNS(std::vector<int> n) {
    float dist = 99999;
    std::vector<int> temp(this->dim);

    
    
    NNS(n, root, temp, dist, 0);
    
    return temp;

}
    


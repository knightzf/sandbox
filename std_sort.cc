#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
// sort list
// quick sort

template<class ForwardIt, class UnaryPredicate>
ForwardIt mypartition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if_not(first, last, p);
    if (first == last) {
        return first;
    }
    for(auto i = std::next(first); i != last; ++i) {
        if (p(*i)) {
            std::iter_swap(i, first);
            ++first;
        }
    }
    return first;
}

template<class ForwardIt, class T>
void mysort(ForwardIt first, ForwardIt last) {
    if(first == last) {
        return;
    }
    T pivot = *first;
    auto mid = mypartition(first, last, [pivot] (T v) {return v < pivot;});
    
    mysort<ForwardIt, T>(first, mid);
    if(mid == first) ++mid;        
    mysort<ForwardIt, T>(mid, last); 
}       

int main() {
    //std::vector<int> a{3, 5, 1, 2, 6, 7, 4};
    std::vector<int> a{3, 2, 1};
    mysort<std::vector<int>::iterator, int>(a.begin(), a.end());
    for(auto i : a) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
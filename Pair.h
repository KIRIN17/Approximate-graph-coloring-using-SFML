#pragma once
#include <tuple>

template<typename M,typename N>
class Pair {
public:

    M first;
    N second;


    Pair():first(M()),second(N()){}
    Pair(M first_, N second_) : first(first_), second(second_) {}
};

bool operator > (const Pair<int,int>& lhs,const Pair<int,int>& rhs){
    return std::make_tuple(lhs.first,lhs.second) > std::make_tuple(rhs.first,rhs.second);
}

bool operator != (const Pair<int,int>& lhs,const Pair<int,int>& rhs){
    return std::make_tuple(lhs.first,lhs.second) != std::make_tuple(rhs.first,rhs.second);
}

template<typename M,typename N>
std::ostream& operator << (std::ostream& ostream,const Pair<M,N>& pair){
    return ostream << "[ " << pair.first << ", " << pair.second << " ]";
}
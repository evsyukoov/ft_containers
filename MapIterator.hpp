

#ifndef CONTAINERS_MAPITERATOR_HPP
#define CONTAINERS_MAPITERATOR_HPP

#include "Tree.hpp"

namespace ft {
    template < class Key, class T, class Compare >

    class MapIterator {
    protected:
       s_tree<Key, T> *ptr;
       Tree<Key, T, Compare> tree;

    public:

        MapIterator(Tree<Key, T, Compare> tree)
        {
            this->tree = tree;
        }

        void setPtr(s_tree<Key, T> *ptr) {
            this->ptr = ptr;
        }



        //Coplien's form
        MapIterator() {
            ptr = 0;
        }

        virtual ~MapIterator() {}

        MapIterator(const MapIterator<Key, T, Compare> &copy) {
            this->ptr = copy.ptr;
        }

        MapIterator &operator=(const MapIterator<Key, T, Compare> &copy) {
            this->ptr = copy.ptr;
            return (*this);
        }

        //operators equal

        bool operator==(const MapIterator &rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const MapIterator &rhs) const {
            return rhs.ptr != ptr;
        }

        //pointers

        std::pair<Key, T> &operator*() {
            return (*(ptr->pair));
        }

        std::pair<Key, T> *operator->() {
            return (ptr->pair);
        }

        s_tree<Key, T> *getPtr() const {
            return ptr;
        }

        MapIterator &operator++() {
            ptr = tree.inc(ptr);
            return (*this);
        }

        MapIterator operator++(int) {
            MapIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        MapIterator &operator--() {
            ptr = tree.dec(ptr);
            return (*this);
        }

        MapIterator operator--(int) {
            MapIterator tmp(*this);
            this->operator--();
            return (tmp);
        }
    };

    template < class Key, class T, class Compare >
    class ReverseMapIterator
    {
    protected:
        s_tree<Key, T> *ptr;
        Tree<Key, T, Compare> tree;

    public:

        ReverseMapIterator(Tree<Key, T, Compare> tree)
        {
            this->tree = tree;
        }

        void setPtr(s_tree<Key, T> *ptr) {
            this->ptr = ptr;
        }

        //Coplien's form
        ReverseMapIterator() {
            ptr = 0;
        }

        virtual ~ReverseMapIterator() {}

        ReverseMapIterator(const ReverseMapIterator<Key, T, Compare> &copy) {
            this->ptr = copy.ptr;
        }

        ReverseMapIterator &operator=(const ReverseMapIterator<Key, T, Compare> &copy) {
            this->ptr = copy.ptr;
            return (*this);
        }

        //operators equal

        bool operator==(const ReverseMapIterator &rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const ReverseMapIterator &rhs) const {
            return rhs.ptr != ptr;
        }

        //pointers

        std::pair<Key, T> &operator*() {
            return (*(ptr->pair));
        }

        std::pair<Key, T> *operator->() {
            return (ptr->pair);
        }

        Tree<Key, T, Compare> *getPtr() const {
            return ptr;
        }

        ReverseMapIterator &operator++() {
            ptr = tree.dec(ptr);
            return (*this);
        }

        ReverseMapIterator operator++(int) {
            ReverseMapIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        ReverseMapIterator &operator--() {
            ptr = tree.inc(ptr);
            return (*this);
        }

        ReverseMapIterator operator--(int) {
            ReverseMapIterator tmp(*this);
            this->operator--();
            return (tmp);
        }
    };

    template < class Key, class T, class Compare >
    class ConstReverseMapIterator : public MapIterator<Key, T, Compare>
    {
        ConstReverseMapIterator(s_tree<Key, T> *ptr) : ReverseMapIterator<Key, T, Compare>(ptr) {}

        ConstReverseMapIterator() : ReverseMapIterator<Key, T, Compare>() {}

        ConstReverseMapIterator(const ConstReverseMapIterator<Key, T, Compare> &copy) : ReverseMapIterator<Key, T, Compare>(copy) {}

        ConstReverseMapIterator(ReverseMapIterator<Key, T, Compare> iterator) {}

        const T &operator*() {
            return *(this->ptr->pair);
        }
    };

    template < class Key, class T, class Compare >
    class ConstMapIterator : public MapIterator<Key, T, Compare>
    {
        ConstMapIterator(s_tree<Key, T> *ptr) : ReverseMapIterator<Key, T, Compare>(ptr) {}

        ConstMapIterator() : ReverseMapIterator<Key, T, Compare>() {}

        ConstMapIterator(const ConstMapIterator<Key, T, Compare> &copy) : ReverseMapIterator<Key, T, Compare>(copy) {}

        ConstMapIterator(ReverseMapIterator<Key, T, Compare> iterator) {}

        const T &operator*() {
            return *(this->ptr->pair);
        }
    };
    
}
#endif //CONTAINERS_MAPITERATOR_HPP

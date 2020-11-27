#include <iostream>
#include <list>
#include "ListIterator.hpp"
#include "list.hpp"
#include <algorithm>

template <typename T>
void    printList(T &container)
{
    typename T::iterator it1 = container.begin();
    typename T::iterator it2 = container.end();
    while (it1 != it2)
    {
        std::cout << *it1 << std::endl;
        it1++;
    }
}

bool condition(int curr, int prev)
{
    if (prev > curr)
        return true;
    return false;
}

bool comp(int first, int second)
{
    if (first < second)
        return true;
    return false;
}

struct Predicate
{
    bool operator()(int curr, int prev)
    {
        if (prev + 1 == curr)
            return true;
        return false;
    }
};

int main() {
    {
        std::cout << "Default constructor: " << std::endl;
        ft::list<int> my;
        printList(my);
        std::cout << "Constructor fill: " << std::endl;
        ft::list<int> my2((size_t) 3, 4);
        printList(my2);
        my2.push_back(100);
        my2.push_front(1);
        my2.push_front(3);
        std::cout << "Constructor range: " << std::endl;
        ft::list<int> my3(my2.begin(), my2.end());
        printList(my3);
        std::cout << "Constructor copy: " << std::endl;
        ft::list<int> *my4 = new ft::list<int>(my3);
        printList(*my4);
        delete my4;
    }
    {
//    std::list<int> lst;
//    lst.push_back(2);
//    lst.push_back(100);
//    lst.push_back(101);
//    std::list<int>::iterator it2 = lst.end();
//    std::list<int>::iterator it1 = lst.begin();
//    ft::ListIterator<int> a;
//    ++a;
//    std::cout << lst.max_size() << std::endl;
//    ft::list<int> lst2;
//    lst2.push_back(2);
//    lst2.push_back(3);
//    lst2.push_back(4);
//    ft::list<int>::iterator bit = lst2.begin();
//    ft::list<int>::iterator bend = lst2.end();
//    lst2.assign(it1, it2);
//    std::cout << "Beg: " << *bit << std::endl;
//    std::cout << "end: " << *bend << std::endl;
//    lst2.push_front(777);
//    //lst2.push_front(1);
//    lst2.push_back(45);
//    printList(lst2);
//    ft::list<int>::iterator bit2 = lst2.begin();
//    ft::list<int>::iterator bend2 = lst2.end();
//    lst2.pop_front();
//    lst2.pop_front();
//    lst2.pop_back();
//    ft::list<int>::iterator bit3 = lst2.begin();
//    bit3--;
//    bit3--;
//    ft::list<int>::iterator bend3 = lst2.end();
//    bend3--;
//    std::cout << "beg: " << *bit3 << std::endl;
//    std::cout << "end: " << *bend3 << std::endl;
//    std::cout << "new list" << std::endl;
//    printList(lst2);
//    while (bit != bend) {
//        std::cout << *bit << std::endl;
//        bit++;
//    }
//    std::cout << lst2.max_size() << std::endl;
        {
        ft::list<int> lst;
        lst.push_back(1);
        lst.push_back(5);
        lst.push_back(10);
        ft::list<int>::iterator iter = lst.begin();
        iter++;
        iter++;
        iter++;
        lst.insert(iter, (size_t )3 , 6);
        ft::list<int>::iterator iter2 = lst.begin();
        ft::list<int>::iterator beg = lst.begin();
        ft::list<int>::iterator end = lst.end();
        while (beg != end)
        {
            std::cout << "pa: " << *beg << std::endl;
            beg++;
        }
        lst.insert(lst.begin(), 101);
        ++beg;
        std::cout << "Iters: " << std::endl;
        std::cout << *beg << std::endl;
        std::cout << *end << std::endl;
        std::cout << "List: " << std::endl;
        printList(lst);
        }
        {
//        ft::list<int> lst;
//        lst.push_back(1);
//        lst.push_back(5);
//        std::list<int> libLst;
//        libLst.push_back(100);
//        libLst.push_back(101);
//        libLst.push_back(102);
//        ft::list<int>::iterator pos = lst.begin();
//        pos++;
//        lst.insert(pos, libLst.begin(), libLst.end());
//        std::cout << "My: " << std::endl;
//        printList(lst);
//        std::list<int> lstLib;
//        lstLib.push_back(1);
//        lstLib.push_back(5);
//        std::list<int>::iterator libLstStart = libLst.begin();
//        std::list<int>::iterator libLstEnd = libLst.end();
//        lstLib.insert(++lstLib.begin(), libLstStart, libLstEnd);
//        std::cout << "Lib: " << std::endl;
//        printList(lstLib);
        }
        {
        std::cout << "Erase test: " << std::endl;
        ft::list<int> lstMy;
        lstMy.push_back(1);
        lstMy.push_back(2);
        lstMy.push_back(100);
        ft::list<int>::iterator i = lstMy.begin();
        lstMy.erase(i);
        lstMy.push_back(3);
        lstMy.push_back(4);
        printList(lstMy);
        std::cout << "Erase test range" << std::endl;
        ft::list<int>::iterator i1 = lstMy.begin();
        i1++;
        ft::list<int>::iterator i2 = lstMy.end();
        i2--;
        lstMy.erase(i1, i2);
        printList(lstMy);
        lstMy.push_back(32);
        lstMy.push_back(33);
        lstMy.resize(7, 77);
        std::cout << "push..." << std::endl;
            std::cout << "head: " << lstMy.front() << std::endl;
            std::cout << "tail: " << lstMy.back() << std::endl;
        printList(lstMy);
        }
        {
//        std::cout << "Erase test" << std::endl;
//        std::list<int> a1;
//        a1.push_back(1);
//        a1.push_back(2);
//        a1.push_back(3);
//        std::list<int>::iterator position = a1.begin();
//        position++;
//        position++;
//        position++;
//        position++;
//        std::list<int> a2;
//        a2.push_back(11);
//        a2.push_back(12);
//        a2.push_back(13);
//        std::list<int>::iterator i = a2.begin();
//        i++;
//        i++;
            //i++;
            //i++;
//        a1.splice(a1.begin(), a2, i);
//        std::cout << "a1: " << std::endl;
//        printList(a1);
//        std::cout << "a2: " << std::endl;
//        printList(a2);
//        std::cout << "a2.size() " << a2.size() << std::endl;
            ft::list<int> my1;
            my1.push_back(1);
            my1.push_back(2);
            my1.push_back(3);
            ft::list<int> my2;
            my2.push_back(10);
            my2.push_back(11);
            my2.push_back(12);
            my2.push_back(100);
            ft::list<int>::iterator pos1 = my1.begin();
            // pos1++;
            // pos1++;
            // pos1++;
            // pos1++;
//        my1.splice(pos1, my2, my2.begin());
//        std::cout << "my1: " << std::endl;
//        printList(my1);
//        std::cout << "my2: " << std::endl;
//        std::cout << "my2.size()" << my2.size() << std::endl;
//        printList(my2);
//        ft::list<int>::iterator pos2 = my1.begin();
//        //pos2--;
//        my1.splice(pos2, my2, ++my2.begin());
//        std::cout << "my1: " << std::endl;
//        printList(my1);
//        std::cout << "my2: " << std::endl;
//        std::cout << "my2.size()" << my2.size() << std::endl;
//        printList(my2);
//        std::cout << "my2 tail: " << my2.back() << std::endl;
//        std::cout << "my2 head: " << my2.front() << std::endl;
//        ft::list<int>::iterator beg1 = my2.begin();
//        beg1++;
//        ft::list<int>::iterator end2 = my2.end();
//        --end2;
//        pos1--;
//        my1.splice(pos1, my2);
//        std::cout << "my1: " << std::endl;
//        printList(my1);
//        std::cout << "my2: " << std::endl;
//        std::cout << "my2.size()" << my2.size() << std::endl;
//        printList(my2);
//        std::cout << "my2 tail: " << my2.back() << std::endl;
//        std::cout << "my2 head: " << my2.front() << std::endl;
//        std::cout << "my1 tail: " << my1.back() << std::endl;
//        std::cout << "my1 head: " << my1.front() << std::endl;
        }
        {
            std::cout << "Remove test" << std::endl;
            ft::list<int> my2;
            my2.push_back(10);
            my2.push_back(10);
            my2.push_back(10);
            my2.push_back(10);
            my2.push_back(10);
            my2.remove(10);
            my2.push_back(20);
            std::cout << "my2: " << std::endl;
            printList(my2);
            std::cout << "my2 head: " << my2.front() << std::endl;
            std::cout << "my2 tail: " << my2.back() << std::endl;
        }
        {
//        std::cout << "Unique test" << std::endl;
//        ft::list<int> myUniq;
//        myUniq.push_back(3);
//        myUniq.push_back(4);
//        myUniq.push_back(5);
//        myUniq.push_back(6);
//        myUniq.push_back(7);
//        myUniq.push_back(2);
//        myUniq.push_back(3);
//        myUniq.push_back(3);
//        std::list<int> libUniq;
//        Predicate pr;
//        myUniq.unique(pr);
//        printList(myUniq);
        }
        {
//        std::cout << "Merge test" << std::endl;
//        ft::list<int> my1;
//        my1.push_back(5);
//        my1.push_back(9);
//        my1.push_back(12);
//        my1.push_back(13);
//        ft::list<int> my2;
//        my2.push_back(0);
//        my2.push_back(4);
//        my2.push_back(8);
//        my2.push_back(10);
//        my2.push_back(13);
//        my2.push_back(14);
//        my2.push_back(14);
//        my2.push_back(15);
//        my1.merge(my2, comp);
//        std::cout << "my1: " << std::endl;
//        printList(my1);
//        std::cout << "my1 head: " << my1.front() << std::endl;
//        std::cout << "my1 tail: " << my1.back() << std::endl;
//        std::cout << "my2: " << std::endl;
//        printList(my2);
//        std::cout << "my2 head: " << my2.front() << std::endl;
//        std::cout << "my2 tail: " << my2.back() << std::endl;
        }
        {
            std::cout << "Sort test" << std::endl;
            ft::list<int> mySort;
            mySort.push_back(4);
            mySort.push_back(0);
            mySort.push_back(5);
            mySort.push_back(10);
            mySort.push_back(7);
            mySort.push_back(11);
            mySort.push_back(8);
            mySort.sort();
            std::cout << "head of sorted: " << mySort.front() << std::endl;
            std::cout << "tail of sorted: " << mySort.back() << std::endl;
            //mySort.swapNodes(mySort.begin().getPtr(),(++mySort.begin()).getPtr());
//        printList(mySort);
        }
        {
            std::cout << "Reverse test" << std::endl;
            ft::list<int> myRev;
            myRev.push_back(4);
            myRev.push_back(0);
            myRev.push_back(5);
            myRev.push_back(10);
            myRev.push_back(7);
            myRev.push_back(11);
            myRev.push_back(8);
            myRev.reverse();
            printList(myRev);
            std::cout << "head of reversed: " << myRev.front() << std::endl;
            std::cout << "tail of reversed: " << myRev.back() << std::endl;
            std::cout << "iterators after reverse test" << std::endl;
            ft::list<int>::iterator beg = myRev.begin();
            ft::list<int>::iterator end = myRev.end();
            beg--;
            beg--;
            end++;
            std::cout << "beg: " << *beg << std::endl;
            std::cout << "end: " << *end << std::endl;
        }
        {
            std::cout << "Operators test" << std::endl;

            ft::list<int> a;
            a.push_back(10);
            a.push_back(20);
            a.push_back(30);
            ft::list<int> b;
            b.push_back(10);
            b.push_back(20);
            b.push_back(30);
            ft::list<int> c;
            c.push_back(30);
            c.push_back(20);
            c.push_back(10);
            if (a == b) std::cout << "a and b are equal\n";
            if (b != c) std::cout << "b and c are not equal\n";
            if (b < c) std::cout << "b is less than c\n";
            if (c > b) std::cout << "c is greater than b\n";
            if (a <= b) std::cout << "a is less than or equal to b\n";
            if (a >= b) std::cout << "a is greater than or equal to b\n";

        }
    }
}

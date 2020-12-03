//
// Created by 1 on 27.11.2020.
//

#include <map>
#include <iostream>
#include "map.hpp"

template <typename T>
void    printMap(T &container)
{
    typename T::iterator i = container.begin();
    typename T::iterator ie = container.end();
    while (i != ie)
    {
        std::cout << i->first << ":" << i->second << " ";
        i++;
    }
    std::cout << std::endl;
}


void    bounds_test()
{
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    //mymap['b']=40;
    //mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    printMap(mymap);
    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('e');   // itup points to e (not d!)
    std::cout << "low: " << itlow->first << ":" << itlow->second << std::endl;
    std::cout << "low: " << itup->first << ":" << itup->second << std::endl;
    mymap.erase(itlow,itup);        // erases [itlow,itup)

//    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//        std::cout << it->first << " => " << it->second << '\n';
}

void    equal_range()
{
    std::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void    count_test()
{
    std::map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
        else
            std::cout << " is not an element of mymap.\n";
    }
}

void    find_test()
{
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    std::cout << "val = "
    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout  << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
    
}

int main()
{
    find_test();
    count_test();
    bounds_test();
    equal_range();
//    std::map<int, int> libMap;
//    libMap.insert(std::pair<int, int>(100, 1));
//    libMap.insert(std::pair<int, int>(1, 1));
//    libMap.insert(std::pair<int, int>(101, 1));libMap.insert(std::pair<int, int>(12, 1));
//    std::cout << "ret: " << libMap.erase(0) << std::endl;
//    libMap.clear();
//    printMap(libMap);
//    std::less<int> comp;
//    std::cout << comp(2, 3) << std::endl;
//    std::map<char, int> lib;
//    std::pair<std::map<char,int>::iterator, bool> p2 = lib.insert(std::pair<char, int>('f',10));
//    std::cout << p2.first->first << ":" << p2.first->second << ",bool: " << p2.second << std::endl;
//    p2 = lib.insert(std::pair<char, int>('b',2));
//    std::cout << p2.first->first << ":" << p2.first->second << ",bool: " << p2.second << std::endl;
//    lib.insert(std::pair<char, int>('c',3));
//    p2 = lib.insert(std::pair<char, int>('b',100));
//    std::cout << p2.first->first << ":" << p2.first->second << ",bool: " << p2.second << std::endl;
//    lib.insert(std::pair<char, int>('z',3));
//    std::cout << "lib[b]: " << lib['b'] << std::endl;
//    std::cout << "size: " << lib.size() << std::endl;
//   lib.insert(--lib.end(), std::pair<char, int>('r', 2));
//    std::map<char, int>::iterator i = lib.insert(--lib.end(), std::pair<char, int>('r', 100));
//    std::cout << i->first << ":" << i->second << std::endl;
    //printMap(lib);
//        ft::map<int, int> map;
//    std::pair<ft::map<int,int>::iterator, bool> p1 = map.insert(std::pair<int, int>(10,9));
//    std::cout << "p1: " << p1.first->first << ":" << p1.first->second << ",bool: " << p1.second << std::endl;
//    p1 = map.insert(std::pair<int, int>(9, 2));
//    std::cout << "p1: " << p1.first->first << ":" << p1.first->second << ",bool: " << p1.second << std::endl;
//    map.insert(std::pair<int, int>(11, 1));
//    p1 = map.insert(std::pair<int, int>(9, 1));
//    std::cout << "p1: " << p1.first->first << ":" << p1.first->second << ",bool: " << p1.second << std::endl;
//    map.insert(std::pair<int, int>(5, 2));
//    map.insert(std::pair<int, int>(12, 1));
//    map.insert(std::pair<int, int>(6, 2));
//    map.tree->print(map.tree->getRoot());
//    ft::map<int, int>::reverse_iterator it = map.rbegin();
//    ft::map<int, int>::reverse_iterator ite = map.rend();
//    while (it != ite)
//    {
//        std::cout << it->first << std::endl;
//        it++;
//    }
//    std::cout << "size my: " << map.tree->getSize() << std::endl;
//
//    map[100] = 10000;
//    std::cout << "finded val: " <<  map[100] << std::endl;
//    map.tree->print(map.tree->getRoot());
//    std::cout << "size my: " << map.tree->getSize() << std::endl;
//    std::cout << "finded val: " <<  map[4] << std::endl;
//    map.tree->print(map.tree->getRoot());
//    std::cout << "finded val: " <<  map[2] << std::endl;
//    map.tree->print(map.tree->getRoot());
//
//    ft::map<int, int>::iterator it1 = map.begin();
//    ft::map<int, int>::iterator ite1 = map.end();
//    while (it1 != ite1)
//    {
//        std::cout << it1->first << std::endl;
//        it1++;
//    }
//std::map<int, int> m;
//std::cout << (m.begin())->first << std::endl;
//    ft::map<int, int> map;
//    std::cout << "my:" << std::endl;
    //map.insert(std::pair<int, int>(30, 10));
//    map.insert(std::pair<int, int>(25, 1));
//   map.insert(map.begin(), std::pair<int, int>(32, 11));
//    ft::map<int, int>::iterator i2 = map.insert(map.begin(), std::pair<int, int>(32, 100));
    //std::cout << i2->first << ":" << i2->second << std::endl;
//    ft::map<int, int> map2;
//    map2.insert(std::pair<int, int>(30, 1));
//    map2.insert(std::pair<int, int>(15, 1));
//    map2.insert(std::pair<int, int>(40,2));
//    map2.insert(std::pair<int, int>(10,2));
//    map2.insert(std::pair<int, int>(20,2));
//    map2.insert(std::pair<int, int>(35,2));
//    map2.insert(std::pair<int, int>(50,2));
//    map2.insert(std::pair<int, int>(7,2));
//    map2.insert(std::pair<int, int>(13,2));
//    map2.insert(std::pair<int, int>(17,2));
//    map2.insert(std::pair<int, int>(7,2));
//    map2.insert(std::pair<int, int>(32,2));
//    map2.insert(std::pair<int, int>(38,2));
//    map2.insert(std::pair<int, int>(46,2));
//    map2.insert(std::pair<int, int>(55,2));
//    map2.insert(std::pair<int, int>(14,2));
//    map2.insert(std::pair<int, int>(33,2));
//    map2.insert(std::pair<int, int>(58,2));
//    map2.insert(std::pair<int, int>(60,2));
//    map2.insert(std::pair<int, int>(57,2));
//    map2.insert(std::pair<int, int>(4,2));
//    map2.insert(std::pair<int, int>(3,2));
//    map2.insert(std::pair<int, int>(3,2));
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(++map2.begin(), --map2.end());
//
//    printMap(map2);
//        std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.insert(std::pair<int, int>(14,2));
//    map2.insert(std::pair<int, int>(33,2));
//    map2.insert(std::pair<int, int>(58,2));
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(3);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(60);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(58);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//    map2.erase(14);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(33);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.insert(std::pair<int, int>(100,2));
//    map2.insert(std::pair<int, int>(4,2));
//    map2.insert(std::pair<int, int>(56,2));
//    map2.insert(std::pair<int, int>(80,2));
//    map2.insert(std::pair<int, int>(11,2));
//    map2.insert(std::pair<int, int>(134,2));
//
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(100);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(134);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//    map2.clear();
//    printMap(map2);
//    map2.insert(std::pair<int, int>(30, 1));
//    map2.insert(std::pair<int, int>(15, 1));
//    map2.insert(std::pair<int, int>(40,2));
//    map2.insert(std::pair<int, int>(30, 1));
//    map2.insert(std::pair<int, int>(15, 1));
//    map2.insert(std::pair<int, int>(40,2));
//    map2.insert(std::pair<int, int>(60,2));
//    map2.insert(std::pair<int, int>(62, 1));
//    map2.insert(std::pair<int, int>(71, 1));
//    map2.insert(std::pair<int, int>(3,2));
//    printMap(map2);
//    map2.erase(++map2.begin(), --map2.end());
//    printMap(map2);


//
//    map2.erase(58);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(46);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(15);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    map2.erase(32);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//    ft::map<int, int>::iterator i3 = map2.begin();
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//    i3++;
//    i3++;
//    std::cout << "ERASE......" << i3->first << std::endl;
//    map2.erase(i3);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i4 = map2.begin();
//    i4++;
//    i4++;
//    map2.erase(i4);
//    std::cout << "ERASE......" << i4->first << std::endl;
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//    ft::map<int, int>::iterator i5 = map2.begin();
//    i5++;
//    i5++;
//    i5++;
//    i5++;
//    std::cout << "ERASE......" << i5->first << std::endl;
//    map2.erase(i5);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i6 = map2.end();
//    i6--;
//    i6--;
//    i6--;
//    i6--;
//    i6--;
//    std::cout << "ERASE......" << i6->first << std::endl;
//    map2.erase(i6);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i7 = map2.end();
//    i7--;
//    i7--;
//    i7--;
//    i7--;
//    std::cout << "ERASE......" << i7->first << std::endl;
//    map2.erase(i7);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i8 = map2.begin();
//    i8++;i8++;i8++;i8++;i8++;i8++;
//    std::cout << "ERASE......" << i8->first << std::endl;
//    map2.erase(i8);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i9 = map2.end();
//    i9--;
// ;
//    std::cout << "ERASE......" << i9->first << std::endl;
//    map2.erase(i9);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i10 = map2.end();
//    i10--;
//    i10--;
//    i10--;
//    std::cout << "ERASE......" << i10->first << std::endl;
//    map2.erase(i10);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i11 = map2.begin();
//    i11++;
//    i11++;
//    std::cout << "ERASE......" << i11->first << std::endl;
//    map2.erase(i11);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i12 = map2.begin();
//    i12++;
//    i12++;
//    std::cout << "ERASE......" << i12->first << std::endl;
//    map2.erase(i12);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i13 = map2.begin();
//    i13++;
//    i13++;
//    std::cout << "ERASE......" << i13->first << std::endl;
//    map2.erase(i13);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i14 = map2.begin();
//    i14++;
//    std::cout << "ERASE......" << i14->first << std::endl;
//    map2.erase(i14);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i15 = map2.end();
//    i15--;
//    i15--;
//    std::cout << "ERASE......" << i15->first << std::endl;
//    map2.erase(i15);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i16 = map2.begin();
//   i16++;
//    std::cout << "ERASE......" << i16->first << std::endl;
//    map2.erase(i16);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i17 = map2.begin();
//    i17++;
//    std::cout << "ERASE......" << i17->first << std::endl;
//    map2.erase(i17);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i18 = map2.begin();
//    std::cout << "ERASE......" << i18->first << std::endl;
//    map2.erase(i18);
//    std::cout << "-------------------TREE-------------------------\n";
//    map2.tree->print(map2.tree->getRoot());
//    std::cout << "-------------------ITERS-------------------------\n";
//    printMap(map2);
//
//    ft::map<int, int>::iterator i19 = map2.begin();
//    std::cout << "ERASE......" << i19->first << std::endl;




}


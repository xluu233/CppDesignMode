//
// Created by xlu on 2023/9/11.
//
#pragma once
#include "vector"
#include "MyIterator.h"

//迭代器容器抽象类
template<typename Item>
class Aggregate{

    //声明友元类是为了解决MyIterator无法访问原始容器
    friend class MyIterator<Item,Aggregate>;

public:
    Aggregate(){};

    virtual ~Aggregate()
    {
        data.clear();
        data.shrink_to_fit();
        std::cout << "Deleted Aggregate!!" << std::endl;
    };

    void push(Item item)
    {
        data.push_back(item);
    };

    MyIterator<Item,Aggregate>* createIterator()
    {
//        if (!it)
//        {
//            it = new MyIterator<Item,Aggregate>(this);
//        }
        return new MyIterator<Item,Aggregate>(this);
    };

    Item& operator[](int index)
    {
        return data[index];
    };

    int size()
    {
        return data.size();
    };

private:
    std::vector<Item> data;
//    MyIterator<Item,Aggregate> *it;
};

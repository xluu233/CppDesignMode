//
// Created by xlu on 2023/9/11.
//

#ifndef CPPDESIGNMODE_MYITERATOR_H
#define CPPDESIGNMODE_MYITERATOR_H

#include <vector>
#include <iterator>

//迭代器
template<typename Item,typename Container>
class MyIterator
{
public:
    //关键字 typename 来显示的说明它是一个类型而非 成员变量。否则编译会报错
    typedef typename std::vector<Item>::iterator iter_type;

    explicit MyIterator(Container* c_data) : m_c_data(c_data)
    {
        it = m_c_data->data.begin();
    };

    virtual ~MyIterator()
    {
        std::cout << "MyIterator deleted!!" << std::endl;
    };

    void first()
    {
        it = m_c_data->data.begin();
    }

    void next()
    {
        it++;
    }

    void end()
    {
        it = m_c_data->data.end();
    }


    iter_type curItem()
    {
        return it;
    }

    bool isDone()
    {
        return it == m_c_data->data.end();
    }

private:
    Container* m_c_data;
    iter_type it;
};

#endif //CPPDESIGNMODE_MYITERATOR_H

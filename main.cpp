#define BOOST_TEST_MODUILE test_module
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "MyList.h"

using namespace std;

BOOST_AUTO_TEST_CASE(TestListPush)
{
    List _list;
    _list.push_front(4);
    BOOST_CHECK_EQUAL(4,_list.front());
    _list.push_back(8);
    BOOST_CHECK_EQUAL(8,_list.back());
}

BOOST_AUTO_TEST_CASE(TestListPop)
{
    List _list;
    _list.push_front(5);
    _list.push_back(10);
    _list.push_back(15);
    BOOST_CHECK_EQUAL(5,_list.front());
    _list.pop_front();
    BOOST_CHECK_EQUAL(10,_list.front());
    _list.pop_front();
    BOOST_CHECK_EQUAL(15,_list.front());
    _list.pop_front();
    _list.push_front(10);
    _list.push_front(5);
    _list.push_back(15);
    BOOST_CHECK_EQUAL(15,_list.back());
    _list.pop_back();
    BOOST_CHECK_EQUAL(10,_list.back());
    _list.pop_back();
    BOOST_CHECK_EQUAL(5,_list.back());
    _list.pop_back();
}

BOOST_AUTO_TEST_CASE(TestListOperator)
{
    List _list1,_list2;
    _list1.push_front(5);
    _list1.push_back(10);
    _list1.push_back(15);
    _list2=_list1;
    BOOST_CHECK_EQUAL(5,_list2.front());
    _list2.pop_front();
    BOOST_CHECK_EQUAL(10,_list2.front());
    _list2.pop_front();
    BOOST_CHECK_EQUAL(15,_list2.front());
    _list2.pop_front();
}

BOOST_AUTO_TEST_CASE(TestListBegEnd)
{
    List _list;
    _list.push_front(5);
    _list.push_back(10);
    _list.push_back(15);
    int i=0;
    for (List::iterator _b=_list.begin(), _e=_list.ending();i<1;i++)
    {
        BOOST_CHECK_EQUAL(5,_list.print(_b));
        _e.operator --();
        BOOST_CHECK_EQUAL(15,_list.print(_e));
    }
}

BOOST_AUTO_TEST_CASE(TestListInsert)
{
    List _list;
    _list.push_front(5);
    _list.push_back(10);
    _list.push_back(20);
    int i=0;
    for (List::iterator _b=_list.begin(), _e=_list.ending();i<2 && _b!=_e;i++,_b.operator ++())
    {
        if (i + 1 == 2)
            _list.insert(_b,15);
    }
    // List: 5 -> 10 -> 15 -> 20
    i=0;
    for (List::iterator _b=_list.begin(), _e=_list.ending();_b!=_e;_b.operator ++())
    {
        BOOST_CHECK_EQUAL(i+5,_list.print(_b));
        i+=5;
    }
}

BOOST_AUTO_TEST_CASE(TestListErase)
{
    List _list;
    _list.push_front(5);
    _list.push_back(10);
    _list.push_back(15);
    int i=0;
    for (List::iterator _b=_list.begin(), _e=_list.ending();i<2 && _b!=_e;i++,_b.operator ++())
    {
        if (i + 1 == 2)
            _list.erase(_b);
    }
    // List: 5 -> 15
    i=-5;
    for (List::iterator _b=_list.begin(), _e=_list.ending();_b!=_e;_b.operator ++())
    {
        BOOST_CHECK_EQUAL(i+10,_list.print(_b));
        i+=10;
    }
}

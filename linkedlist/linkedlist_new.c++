#include <iostream>
#include <linkedlist.h>

using namespace std;

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

my_list::my_list()
{
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node *p;
    p = new node;
    *p = t;

    head->link = p;

    if (tail == NULL)
    {
        tail->link = p;
    }
}

void my_list::add_to_tail(node t)
{
    node *p;
    p = new node;
    *p = t;

    // tail에 추가하는 모든 요소는 마지막 element이기때문에 p->link가 null이어야한다.
    p->link = NULL;

    if (head != NULL)
    {
        //tail의 link가 가르키는곳 == 삽입 전 마지막 노드
        // 삽입전 마지막 노드에 p를 삽입
        tail->link = p;
    }
    else
    {
        // 틀림
        // 설명 : head == null 일 경우에는 head 의 link가 p를 가리키게 해야함.
        // head/tail은 공간 설정이 안되어 있음.
        // head-> link = p가 아니라 head = p를 하는 이유는
        // 첫번째 element 자체가 공간을 할당하고 p라는 값을 삽입하는 것이다.
        head = p;
    }
    tail = p;
}

node my_list::delete_from_head()
{
    node *tmp;
    tmp = new node;

    // find current node and delete;

    *tmp = head->link;

    delete head->link;
    // connect previous node to next node;

    head = head->link;

    return tmp;
}

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

    p->link = head; //p의 link에 head 삽입
    head = p;

    if (tail == NULL)
        tail = p;
}

void my_list::add_to_tail(node t)
{
    node *p;
    p = new node;
    *p = t;

    p->link = NULL;
    if (tail != NULL)
    {
        tail->link = p;
    }
    else
    {
        head = p;
    }
    tail = p;
}

node my_list::delete_from_head()
{
    node temp;
    node *t;

    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL)
        tail = NULL;
    return temp;
}

int my_list::remove_a_node(string t_name)
{
    node *target, *prev;

    prev = NULL;
    target = head;

    while ((target != NULL) && (target->name != t_name))
    {
        prev = target;
        target = target->link;
    }
    if (target == NULL)
        return 0;

    if (prev)
        prev->link = target->link;
    else
        head = target->link;
    if (head == NULL)
        tail = NULL;
    if (target == tail)
        tail = prev;

    delete target;

    return 1;
}

// node my_list::remove_a_node_t(string t_name)
// {
//     node *t;
//     node temp;
//     node *target *prev;

//     prev = NULL;
//     target = head;

//     prev = t->link;
//     if(t->link == head){

//     }

//     for (t = head; t != NULL; t = t->link)
//     {
//         if (t->name == t_name)
//         {

//             // 삭제할 노드를 저장;
//             temp = prev.link;

//             // 노드 빼기 3번 해결
//             prev.link = t->link;
//             delete t;
//             return temp;
//         }
//         else
//             return 0;

//         // 1번 전 노드 찾기 완료
//         if(t->link == head){
//             head = t->link;
//         }
//         if(t->link == tail){
//             tail = t->link;
//         }
//         prev = t->link;
//     }
//     return temp;
// }

int my_list::num_nodes()
{
    node *t;
    int count = 0;
    for (t = head; t != NULL; t = t->link)
    {
        count++;
    }
    return count;
}

bool my_list::list_empty()
{
    if (head == NULL)
    {
        return 1;
    }
    else
        return 0;
}

double my_list::score_sum()
{
    node *t;
    double sum = 0;
    for (t = head; t != NULL; t = t->link)
    {
        sum += t->score;
    }
    return sum;
}

double my_list::get_score(string t_name)
{
    node *t;
    for (t = head; t != NULL; t = t->link)
    {
        if (t->name == t_name)
        {
            return t->score;
        }
    }
}

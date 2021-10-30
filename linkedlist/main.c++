#include <iostream>
// #include <linkedlist.h>

using namespace std;
class node
{
private:
    string name;
    double score;

public:
    node *link;
    void set_data(string s, double n);
    string getName();
    int getNum();
};

class my_list
{
private:
    node *head, *tail;

public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    int remove_a_node(string t_name);
    double score_sum();
    double get_score(string t_name);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
    // std::cout << "\n"
    //           << name << "  " << score;
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
}

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
            // return t->score;
            return t->score;
        }
    }
    return 0;
}

int main()
{
    my_list a;
    node tmp;

    tmp.set_data("Kim ", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);                                      // head 위치로 2개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 1단계 점검

    tmp.set_data("park", 91.3);
    a.add_to_tail(tmp);                                      // tail 위치로 1개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; //2단계 점검

    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n"; // 3단계 점검

    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);

    tmp.set_data("ryu", 94.3);
    a.add_to_head(tmp); // 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";
    cout << "Park's score : " << a.get_score("park") << "\n"; // 4단계 점검

    if (a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n"; // 5단계 점검

    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 최종 점검

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class node
{
private:
    string name;
    int num1, num2;

public:
    node *link;
    void setNode(string name, int num1, int num2);
    string getName();
    int getNum1();
    int getNum2();
};

class linked_queue
{
private:
    node *front;
    node *rear;

public:
    linked_queue();
    void printQueue();
    void insert_into_rear(node t);
    node delete_from_front();
    bool isEmpty();
};

void node::setNode(string name_s, int num1_s, int num2_s)
{
    name = name_s;
    num1 = num1_s;
    num2 = num2_s;
    std::cout << "name : " << name << " num1 : " << num1 << " num2 : " << num2 << "\n";
}

string node::getName()
{
    return name;
}
int node::getNum1()
{
    return num1;
}
int node::getNum2()
{
    return num2;
}

linked_queue::linked_queue()
{
    front = NULL;
    rear = NULL;
}

void linked_queue::insert_into_rear(node t)
{

    node *p;
    node *prev;

    p = new node;
    *p = t;

    if (front == NULL)
    {

        front = p;
        rear = p;
        std::cout << "all null, insert\n";
    }
    else
    {

        prev = rear;
        rear = p;
        prev->link = p;
        p->link = NULL;
        std::cout << "insert done : " << t.getName() << "\n";
    }
}

node linked_queue::delete_from_front()
{
    node temp;
    node *p;

    p = front;
    temp = *front;

    if (!isEmpty())
    {
        front = front->link;
        delete p;
        return temp;
        std::cout << "deleted\n";
    }
    else
    {
        std::cout << "not deleted\n";
    }
}
bool linked_queue::isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void linked_queue::printQueue()
{
    node *t;
    // t = new node;
    int count = 0;
    for (t = front; t != NULL; t = t->link)

    {

        std::cout << "h---" << (*t).getName() << count << "\n";
        count++;
    }
}

int main()
{

    linked_queue a;
    node tmp;
    std::cout << "Insertion\n";
    tmp.setNode("C++ Programming", 534, 35000);
    // std::cout << tmp.printElement();

    a.insert_into_rear(tmp);
    // a.printStatus();

    // a.printElement();
    std::cout << "2";
    tmp.setNode("Data Structure", 621, 42000);

    a.insert_into_rear(tmp);

    tmp.setNode("JAVA Programming", 485, 38000);

    a.insert_into_rear(tmp);

    tmp.setNode("Logic Design", 532, 44000);

    a.insert_into_rear(tmp);
    // a.printStatus();

    a.printQueue();

    std::cout << "\ndeletion\n";
    while (!a.isEmpty())
    {

        tmp = a.delete_from_front();

        cout << tmp.getName() << " : " << tmp.getNum1() << " : " << tmp.getNum2() << "\n";
    }
    std::cout << "after deletion\n";
    a.printQueue();

    return 0;
}
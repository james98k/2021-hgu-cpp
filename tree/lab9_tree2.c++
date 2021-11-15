#include <iostream>

using namespace std;

class node
{
private:
public:
    string name;
    double score;

    node *left, *right;
    node();
    node(string name, double score);
    void setNode(string name, double score);
};

class my_tree
{
private:
public:
    int node_count;
    node *root;
    my_tree();
    int insert_root(node t);
    void insert_left(string name, node t);
    void insert_left_node(my_tree *p, ; string name, node t);
    void insert_right(string name, node t);
    void insert_right_node(my_tree *p, string name, node t);
};

my_tree::my_tree()
{
    node_count = 0;
    root = NULL:
}

int my_tree::insert_root(node t)
{
    if (root != NULL)
        return 0;

    node *p;
    p = new node;
    (*p) = t;

    return 1;
}

void node::node()
{
    this.name = "";
    this->score = 0;
}
void node::setNode(string name, double score)
{
    this->name = name;
    this->score = score;
}

int main()
{
    my_tree thetree;
    node tmp;

    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);

    std::cout << "Score Sum : " << thetree.score_sum() << "\n";
    std::cout << "Score Average : " << thetree.score_average() << "\n";
    std::cout << "\n Inorder Traversal Result \n";
    thetree.print_data_inorder();
    std::cout << "\n Preorder Traversal Result \n";
    thetree.print_data_preorder();
    std::cout << "\n Postorder Traversal Result \n";
    thetree.print_data_postorder();

    return 0;
}
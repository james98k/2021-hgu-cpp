#include <iostream>
#include <string>
using namespace std;

class node
{
private:
public:
    string lastName;
    double score;

    node *left, *right;
    node();
    node(string s, double n);
    void set_data(string s, double n);
};

class my_tree
{
private:
public:
    int node_count;
    node *root;
    my_tree();
    int insert_root(node t);
    int insert_left(string insertParentValue, node t);
    int insert_left(node *root, string insertParentValue, node t);
    int insert_right(string insertParentValue, node t);
    int insert_right(node *root, string insertParentValue, node t);
    double score_sum();
    double score_average();
    double sum_allnodes(node *p);
    void print_data_inorder();
    void print_data_preorder();
    void print_data_postorder();
    void inorder_print(node *p);
    void preorder_print(node *p);
    void postorder_print(node *p);
};

my_tree::my_tree()
{
    node_count = 0;
    root = NULL;
}
int my_tree::insert_root(node t)
{

    if (root != NULL)
    {
        return 0;
    }

    node *p;
    p = new node;
    (*p) = t;

    p->left = NULL;
    p->right = NULL;
    root = p;

    node_count++;
    return 1;
}

int my_tree::insert_left(string insertParentValue, node t)
{

    int result;
    result = insert_left(root, insertParentValue, t);

    if (result == 1)
    {
        node_count++;
    }
    return result;
}

int my_tree::insert_left(node *p, string insertParentValue, node t)
{
    std::cout << "insert left, parentName : " << p->lastName << " childlastName : " << t.lastName << "\n";
    if (p == NULL) //if root if NULL
        return 0;

    if (p->lastName == insertParentValue) //if name value 4== inputName;
    {

        if (p->left != NULL) //root's left is full
        {
            return -1;
        }

        node *temp; //if root's left is not full;
        temp = new node;
        (*temp) = t;

        temp->left = NULL; //new node's left and right setting;
        temp->right = NULL;

        p->left = temp; //root's left = temp;
        return 1;
    }
    else
    {
        std::cout << "insert left , root full, inserting to other leaf\n";
        int result = insert_left(p->left, insertParentValue, t); //root->left's value insert;
        if (result != 0)
        {
            return result;
        }
        return insert_left(p->right, insertParentValue, t);
    }
}
int my_tree::insert_right(string insertParentValue, node t)
{

    int result;
    result = insert_right(root, insertParentValue, t);

    if (result == 1)
    {
        node_count++;
    }
    return result;
}

int my_tree::insert_right(node *p, string insertParentValue, node t)
{
    std::cout << "insert right, parentName : " << p->lastName << " childlastName : " << t.lastName << "\n";
    if (p == NULL)
    {
        return 0;
    }
    if (p->lastName == insertParentValue)
    {

        if (p->right != NULL)
        {
            return -1;
        }
        node *temp;
        temp = new node;
        (*temp) = t;

        temp->left = NULL;
        temp->right = NULL;

        p->right = temp;
        return 1;
    }
    else
    {
        std::cout << "insert right, root full, inserting to other leaf\n";
        int result = insert_right(p->right, insertParentValue, t);
        if (result != 0)
        {
            return result;
        }
        return insert_right(p->left, insertParentValue, t);
    }
}

double my_tree::score_sum()
{
    return sum_allnodes(root);
}

double my_tree::sum_allnodes(node *p)
{
    if (p == NULL)
    {
        return 0;
    }

    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

double my_tree::score_average()
{
    return this->score_sum() / node_count;
}

void my_tree ::print_data_inorder()
{
    inorder_print(root);
}

void my_tree::inorder_print(node *p)
{
    if (p == NULL)
        return;
    inorder_print(p->left);
    std::cout << p->lastName << " : " << p->score << "\n";
    inorder_print(p->right);
}

void my_tree::print_data_preorder()
{
    preorder_print(root);
}
void my_tree::preorder_print(node *p)
{
    if (p == NULL)
    {
        return;
    }
    std::cout << p->lastName << " : " << p->score << "\n";
    preorder_print(p->left);
    preorder_print(p->right);
}

void my_tree::print_data_postorder()
{
    postorder_print(root);
}

void my_tree::postorder_print(node *p)
{
    if (p == NULL)
        return;

    preorder_print(p->left);
    preorder_print(p->right);
    std::cout << p->lastName << " : " << p->score << "\n";
}

node::node()
{
    lastName = "";
    double score = 0.0;
}
node::node(string s, double n)
{
    lastName = s;
    score = n;
}
void node::set_data(string s, double n)
{
    lastName = s;
    score = n;
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
    // thetree.insert_right("Lee", tmp);
    tmp.set_data("Sun", 9.9);
    thetree.insert_left("Park", tmp);
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
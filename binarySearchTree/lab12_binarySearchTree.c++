#include <iostream>
using namespace std;

class bst_node
{
public:
    string name;
    string s_id;
    double score;
    bst_node *left, *right;
    bst_node();
    bst_node(string s1, string s2, double n);
    void set_data(string s1, string s2, double n);
};
class s_record
{
    string name;
    string s_id;
    double score;
};

class bst_tree
{
    bst_node *root;
    int csize;

public:
    bst_tree();
    void insert_node(bst_node t);
    void show_inorder();
    void show_inorder_print(bst_node *p);
    // bool empty();
    // int size();
    bst_node search(string s);
};
bst_node::bst_node()
{
    this->s_id = "";
    this->name = "";
    this->score = 0;
}
bst_node::bst_node(string s1, string s2, double n)
{
    this->s_id = "";
    this->name = "";
    this->score = 0;
}

void bst_node::set_data(string s1, string s2, double n)
{
    this->s_id = s1;
    this->name = s2;
    this->score = n;
    std::cout << "name : " << s1 << " score : " << s2 << " score : " << n << "\n";
}

bst_tree::bst_tree()
{
    root = NULL;
    csize = 0;
}

bst_node bst_tree::search(string tid)
{
    bst_node *p;
    p = root;
    if (root == NULL)
    {
        bst_node tmp;
        tmp.set_data("000000", "None", -1);
        std::cout << "The Key " << tid << " does not exist.\n";
        return tmp;
    }
    while (1)
    {
        if (p->s_id == tid)
            return (*p);
        if (p->s_id < tid)
        {
            if (p->right == NULL)
            {
                //해당 노드 없음처리
            }
            else
            {
                p = p->right;
            }
        }
        else
        {
            if (p->left == NULL)
            {
                // 해당 노드 없음 처리
            }
            else
            {
                p = p->left;
            }
        }
    }
}

void bst_tree::insert_node(bst_node t)
{
    bst_node *p;
    bst_node *tmp;

    tmp = new bst_node;
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;

    if (root == NULL)
    {
        root = tmp;
        std::cout << "root null, tmp to root\n";
        return;
    }
    p = root;
    while (1)
    {
        if (p->s_id == t.s_id)
        {
            std::cout << "insetion failed : the Key " << t.s_id << " already exists" << endl;
            return;
        }
        if (p->s_id < t.s_id)
        {
            if (p->right == NULL)
            {
                p->right = tmp;
                std::cout << "insert to right value when null :" << p->name << "\n";
                return;
            }
            else
            {
                std::cout << "insert to right with value\n";
                p = p->right;
            }
        }
        else
        {
            if (p->left == NULL)
            {
                p->left = tmp;
                std::cout << "insert to left value when null : " << p->name << "\n";
                return;
            }
            else
            {
                std::cout << "insert to left with value\n";
                p = p->left;
            }
        }
    }
}

void bst_tree::show_inorder()
{
    bst_node *tmp;
    tmp = root;

    show_inorder_print(tmp);
}
void bst_tree::show_inorder_print(bst_node *p)
{
    if (p == NULL)
        return;
    show_inorder_print(p->left);
    // std::cout >> p->name >> p->s_id;
    std::cout << p->name << p->s_id << "\n";
    show_inorder_print(p->right);
}

int main()
{
    bst_node temp;
    bst_tree t1;

    // temp.set_data("21900013", "Kim", 6.5);
    // t1.insert_node(temp);
    // temp.set_data("21900136", "Lee", 8.8);
    // t1.insert_node(temp);
    // temp.set_data("21900333", "Park", 9.2);
    // t1.insert_node(temp);
    // temp.set_data("21800442", "Choi", 7.1);
    // t1.insert_node(temp);
    // temp.set_data("21900375", "Ryu", 5.4);
    // t1.insert_node(temp);
    // temp.set_data("21700248", "Cho", 6.3);
    // t1.insert_node(temp);

    while (1)
    {
        int type;
        std::cout << "enter number from 0-3\n0 : insert value\n 1 : search value\n 2 : print inorder\n 3 : exit()\n ";
        std::cin >> type;
        switch (type)
        {
        case 0:
        {
            string phoneNumber, birthday;
            double value;
            std::cout << "insert phoneNumber, birthday, number\n";
            std::cin >> phoneNumber >> birthday >> value;

            temp.set_data(phoneNumber, birthday, value);
            t1.insert_node(temp);
            break;
        }

        case 1:
        {
            string s_key = "21800442";
            temp = t1.search(s_key);
            cout << "\n -- " << s_key << "'s record ---" << endl;
            cout << " Student ID   : " << temp.s_id << endl;
            cout << " Student Name : " << temp.name << endl;
            cout << " Score: " << temp.score << endl;
            break;
        }

        case 2:
        {
            cout << "\n\n Node List : inorder sequence \n";
            t1.show_inorder();
            break;
        }

        case 3:
        {
            exit(0);
        }

        default:
            break;
        }
        return 0;
    }
}

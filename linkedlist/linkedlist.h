class node
{
private:
public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
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
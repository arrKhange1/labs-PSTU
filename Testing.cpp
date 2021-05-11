#include <iostream>
using namespace std;

int n;


// binary search tree
class tree_elem
{
public:
    int data;
    tree_elem* left;
    tree_elem* right;
    tree_elem(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
    tree_elem()
    {

    }
};

class binary_tree
{
public:
    tree_elem* m_root;
private:
    int m_size;
public:
    void print_tree(tree_elem*);
    binary_tree() {};
    binary_tree(int);
    void insert(int);
};

binary_tree::binary_tree(int key)
{
    m_root = new tree_elem(key);
    m_size = 1;
}

void binary_tree::print_tree(tree_elem* curr)
{
    if (curr)
    {
        print_tree(curr->left);
        cout << curr->data << " ";
        print_tree(curr->right);
    }
}



void binary_tree::insert(int key)
{
    tree_elem* curr = m_root;
    while (curr && curr->data != key)
    {
        if (curr->data > key && curr->left == NULL)
        {
            curr->left = new tree_elem(key);
            ++m_size;
            return;
        }
        if (curr->data < key && curr->right == NULL)
        {
            curr->right = new tree_elem(key);
            ++m_size;
            return;
        }
        if (curr->data > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

tree_elem* Tree(int n, tree_elem* p)
{
    tree_elem* r;
    int nl, nr;
    if (n == 0) { p = NULL; return p; }
    nl = n / 2;
    nr = n - nl - 1;
    r = new tree_elem;
    cin >> r->data;
    r->left = Tree(nl, r->left);
    r->right = Tree(nr, r->right);
    p = r;
    return p;
}

float sred_arifm = 0;
void PrintTree(tree_elem* p, int level)
{
    if (p)
    {
        PrintTree(p->left, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << p->data << endl;
        sred_arifm += (p->data / (float)n);
        PrintTree(p->right, level + 1);
    }
}




int main()
{
    tree_elem* p = 0;
    cout << "Enter quantity of elements: ";
    cin >> n;
    p = Tree(n, p);
    PrintTree(p, n);
    cout << "\nSred_Arifm: " << sred_arifm << endl;

    int in, n1;  cin >> in >> n1;
    binary_tree tree(in);
    for (int i = 0; i < n1; ++i)
    {
        cin >> in;
        tree.insert(in);
    }
    tree.print_tree(tree.m_root);

    return 0;
}
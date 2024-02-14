#include <iostream>
#include <cstdlib>
using namespace std;

struct nod
{
    int info;
    struct nod *l;
    struct nod *r;
} *r;

class BST
{
public:
    void search(int data);
    void insert(nod *tree, nod *newnode);
    void del(int data);
    void casea(nod *par, nod *loc);
    void caseb(nod *par, nod *loc);
    void casec(nod *par, nod *loc);
    void show(nod *ptr, int level);

    BST()
    {
        r = NULL;
    }

private:
    void find(int data, nod **par, nod **loc);
    int locate(nod *root, int data, int depth);
};

void BST::find(int data, nod **par, nod **loc)
{
    nod *ptr, *ptrsave;
    if (r == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (data == r->info)
    {
        *loc = r;
        *par = NULL;
        return;
    }
    if (data < r->info)
        ptr = r->l;
    else
        ptr = r->r;
    ptrsave = r;
    while (ptr != NULL)
    {
        if (data == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (data < ptr->info)
            ptr = ptr->l;
        else
            ptr = ptr->r;
    }
    *loc = NULL;
    *par = ptrsave;
}

void BST::search(int data)
{
    int depth = locate(r, data, 1);
    if (depth == -1)
    {
        cout << "Data not found in the tree" << endl;
    }
}

int BST::locate(nod *root, int data, int depth)
{
    if (root == NULL)
        return -1; // Element not found
    if (data == root->info)
    {
        cout << "\nData found at depth: " << depth << endl;
        return depth;
    }
    else if (data < root->info)
        return locate(root->l, data, depth + 1);
    else
        return locate(root->r, data, depth + 1);
}

void BST::insert(nod *tree, nod *newnode)
{
    if (r == NULL)
    {
        r = new nod;
        r->info = newnode->info;
        r->l = NULL;
        r->r = NULL;
        cout << "Root Node is Added" << endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout << "Element already in the tree" << endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->l != NULL)
            insert(tree->l, newnode);
        else
        {
            tree->l = newnode;
            tree->l->l = NULL;
            tree->l->r = NULL;
            cout << "Node Added To Left" << endl;
            return;
        }
    }
    else
    {
        if (tree->r != NULL)
            insert(tree->r, newnode);
        else
        {
            tree->r = newnode;
            tree->r->l = NULL;
            tree->r->r = NULL;
            cout << "Node Added To Right" << endl;
            return;
        }
    }
}

void BST::del(int data)
{
    nod *par = NULL, *loc = r;
    if (r == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }
    int depth = locate(r, data, 1);
    if (depth == -1)
    {
        cout << "Item not present in tree" << endl;
        return;
    }
    find(data, &par, &loc);
    if (loc->l == NULL && loc->r == NULL)
    {
        casea(par, loc);
        cout << "Item deleted" << endl;
    }
    if (loc->l != NULL && loc->r == NULL)
    {
        caseb(par, loc);
        cout << "Item deleted" << endl;
    }
    if (loc->l == NULL && loc->r != NULL)
    {
        caseb(par, loc);
        cout << "Item deleted" << endl;
    }
    if (loc->l != NULL && loc->r != NULL)
    {
        casec(par, loc);
        cout << "Item deleted" << endl;
    }
    free(loc);
}

void BST::casea(nod *par, nod *loc)
{
    if (par == NULL)
    {
        r = NULL;
    }
    else
    {
        if (loc == par->l)
            par->l = NULL;
        else
            par->r = NULL;
    }
}

void BST::caseb(nod *par, nod *loc)
{
    nod *child;
    if (loc->l != NULL)
        child = loc->l;
    else
        child = loc->r;
    if (par == NULL)
        r = child;
    else
    {
        if (loc == par->l)
            par->l = child;
        else
            par->r = child;
    }
}

void BST::casec(nod *par, nod *loc)
{
    nod *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->r;
    while (ptr->l != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->l;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->l == NULL && suc->r == NULL)
        casea(parsuc, suc);
    else
        caseb(parsuc, suc);
    if (par == NULL)
        r = suc;
    else
    {
        if (loc == par->l)
            par->l = suc;
        else
            par->r = suc;
    }
    suc->l = loc->l;
    suc->r = loc->r;
}

void BST::show(nod *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        show(ptr->r, level + 1);
        cout << endl;
        if (ptr == r)
            cout << "Root->: ";
        else
        {
            for (i = 0; i < level; i++)
                cout << " ";
        }
        cout << ptr->info;
        show(ptr->l, level + 1);
    }
}

int main()
{
    int c, item;
    BST bst;
    nod *t;
    while (1)
    {
        cout << "1.Insert Element " << endl;
        cout << "2.Delete Element " << endl;
        cout << "3.Search/Locate Element" << endl;
        cout << "4.Display the tree" << endl;
        cout << "5.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            t = new nod;
            cout << "Enter the number to be inserted: ";
            cin >> t->info;
            bst.insert(r, t);
            break;
        case 2:
            if (r == NULL)
            {
                cout << "Tree is empty, nothing to delete" << endl;
                continue;
            }
            cout << "Enter the number to be deleted: ";
            cin >> item;
            bst.del(item);
            break;
        case 3:
            cout << "Search/Locate:" << endl;
            cin >> item;
            bst.search(item);
            break;
        case 4:
            cout << "Display BST:" << endl;
            bst.show(r, 1);
            cout << endl;
            break;
        case 5:
            exit(1);
        default:
            cout << "Wrong choice!" << endl;
        }
    }
    return 0;
}

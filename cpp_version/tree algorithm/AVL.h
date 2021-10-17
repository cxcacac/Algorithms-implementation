/**
 * LL, LR, RL, RR
*/
template<class Type>
class AVLTree{
private:
    struct AVLNode{
        Type data;
        AVLNode *left;
        AVLNode *right;
        // use height to record current balance status;
        int height;
        AVLNode(const Type &element, AVLNode *l, AVLNode *r, int h = 0) : data(element), left(l), right(r), height(h){};
    };
    AVLNode *root;
    void insert(const Type &x, AVLNode *&t);
    void remove(const Type &x, AVLNode *&t);
    void makeEmpty(AVLNode *&t);
    // inline function, no need add comma.
    int height(AVLNode *t) const { return t == NULL ? -1 : t->height; }
    void LL(AVLNode *&t);
    void LR(AVLNode *&t);
    void RL(AVLNode *&t);
    void RR(AVLNode *&t);
    int max(int a, b) { return a > b ? a : b; }
public:
    AVLTree(AVLNode *t = NULL) : root(t){};
    ~AVLTree(){makeEmpty(root)};
    bool find(const Type &x) const;
    void insert(const Type &x) { insert(x, root); }
    void remove(const Type &x) { remove(x, root); }
};

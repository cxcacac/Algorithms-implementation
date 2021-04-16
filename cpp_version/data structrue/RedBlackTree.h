template<class Type>
class RedBlackTree{
private:
    struct RedBlackNode{
        Type data;
        RedBlackNode *left;
        RedBlackNode *right;
        int color; // Red = 0, Black=1;
        RedBlackNode(const Type &element, RedBlackNode *l, RedBlackNode *r, int c = 0) : data(element), left(l), right(r), color(c){}
    };
    RedBlackNode *root;
    // pointer reference...
    void makeEmpty(RedBlackNode *&t);
    void LL(RedBlackNode *&t);
    void LR(RedBlackNode *&t);
    void RL(RedBlackNode *&t);
    void RR(RedBlackNode *&t);
    void Relink(RedBlackNode *oldp, RedBlackNode *newp, linkStack<RedBlackNode *> &path);
    void insertRebalance(RedBlackNode *newp, linkStack<RedBlackNode *> &path);
    void removeRebalance(RedBlackNode *newp, linkStack<RedBlackNode *> &path);
public:
    RedBlackTree(RedBlackNode *r=nullptr) : root(r){}
    ~RedBlackTree(){makeEmpty(root)};
    bool find(const Type &x) const;
    void insert(const Type &x);
    void remove(const Type &x);
};

template<class Type>
class BinarySearchTree{
private:
    struct BinaryNode{
        Type data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const Type &d, BinaryNode *l, BinaryNode *r) : data(d), left(l), right(r){};
    };
public:
    BinarySearchTree(BinaryNode *r = NULL) : root(r){};
    ~BinarySearchTree();
    bool find(const Type &x) const;
    void insert(const Type &x);
    void remove(const Type &x);

private:
    BinaryNode *root;
    // *& means take pointer parameter as reference
    void insert(const Type &x, BinaryNode *&t);
    void remove(const Type &x, BinaryNode *&t);
    bool find(cosnt Type &x, BinaryNode *&t) const;
    void makeEmpty(BinaryNode *&t);
};

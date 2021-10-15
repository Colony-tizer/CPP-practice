#ifndef BTREENODE_H_
#define BTREENODE_H_
template <class T>
class BTreeNode {
    public:
        BTreeNode() : value(), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}
        BTreeNode(const T& val) : value(val), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}
        BTreeNode(const BTreeNode& obj) : value(obj.value), parent(obj.parent), leftChild(obj.leftChild), rightChild(obj.rightChild) {}
        BTreeNode(BTreeNode* obj) : value(obj->value), parent(obj->parent), leftChild(obj->leftChild), rightChild(obj->rightChild) {}

        bool operator==(const BTreeNode& obj) {
            return obj.parent == parent && obj.leftChild == leftChild && obj.rightChild == rightChild && obj.value == value;
        }
        bool operator!=(const BTreeNode& obj) {
                    return !(this == obj);
        }
        const T& getValue() const { return value; }
        BTreeNode* getParent() { return parent; }
        BTreeNode* getLeftChild() { return leftChild; }
        BTreeNode* getRightChild() { return rightChild; }
        void setValue(const T& val) { value = val; }
        void setParent(BTreeNode* node) { 
            if (!parent) parent = new BTreeNode(node);
            else parent = node;
        }
        void setLeftChild(BTreeNode* node) { leftChild = node; node->parent = this; }
        void setRightChild(BTreeNode* node) { rightChild = node; node->parent = this; }

        void removeChilds(BTreeNode* node) { delete leftChild; delete rightChild; leftChild = rightChild = nullptr; }
    private:
        T value;
        BTreeNode* parent;
        BTreeNode* leftChild;
        BTreeNode* rightChild;
};
#endif
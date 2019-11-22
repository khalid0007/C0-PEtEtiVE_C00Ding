// BST header of just copy

// Header guard!!
#ifndef __NORMAL_BST__H_

#define __NORMAL_BST__H_

template<class _Type> class Node{
public:
    _Type data;
    Node<_Type>* lnode;
    Node<_Type>* rnode;

    Node(_Type val) : data(val), lnode(NULL), rnode(NULL) {}
}; 


template<class _Type> class iterator_BST;

template<class _Type> class BST{
// Attributes
private:
    Node<_Type>* root;
    int size;

// Methods
private:
    void insertNode(_Type value, Node<_Type>* node){
        if(value < node->data){
            if(node->lnode) insertNode(value, node->lnode);

            else {
                size++;
                node->lnode = new Node<_Type>(value);
            }
        }

        else if(value > node->data){
            if(node->rnode) insertNode(value, node->rnode);

            else {
                size++;
                node->rnode = new Node<_Type>(value);
            }
        }

        else return;
    }

    Node<_Type>* getMin(Node<_Type>* node)
    {
        while(node->lnode) node = node->lnode;

        return node;
    }

    Node<_Type>* getMax(Node<_Type>* node)
    {
        while(node->rnode) node = node->rnode;

        return node;
    }


    void TraverseInOrder(Node<_Type>* node){
        if(node->lnode) TraverseInOrder(node->lnode);

        cout << node->data << " ";

        if(node->rnode) TraverseInOrder(node->rnode);
    }


    // Returns parent node containing value
    Node<_Type>* find(_Type value, Node<_Type>* node){
        // If the value does not exist
        if(!node) return node;

        // if current node-value is greater
        else if(node->data > value) {

            // If left child contains data
            if((node->lnode)->data == value) return node;

            find(value, node->lnode);
        }

        // If current node-value is smaller
        else {
            // If Right child contains data
            if((node->rnode)->data == value) return node;
            
            find(value, node->rnode);
        }
    }

    void deleteUtil(Node<_Type>* prev, Node<_Type>* cur, bool relation) // true if connected through left edge
    {
        if(!(cur->lnode) && !(cur->rnode))
        {
            if(relation) prev->lnode = NULL;
            else prev->rnode = NULL;

            delete cur;
        }

        else if(!(cur->lnode) && cur->rnode)
        {
            if(relation) prev->lnode = cur->rnode;
            else prev->rnode = cur->rnode;

            delete cur;
        }

        else if(cur->lnode && !(cur->rnode))
        {
            if(relation) prev->lnode = cur->lnode;
            else prev->rnode = cur->lnode;

            delete cur;
        }

        else
        {
            Node<_Type>* prevNode = cur, *curNode = cur->lnode;
            
            // Find predecessor
            while(curNode->rnode){
                prevNode = curNode;
                curNode = curNode->rnode;
            }

            // swap current node value with predecessor
            swap(curNode->data, cur->data);

            // delte the predecessor
            deleteUtil(prevNode, curNode, true);
        }
    }

public:
    BST() : root(NULL), size(0) {}

    iterator_BST<_Type> begin();
    iterator_BST<_Type> end();

    void insert(_Type value)
    {
        // If tree is empty
        if(!root) {
            size++;
            root = new Node<_Type>(value);
        }

        else insertNode(value, root);
    }

    int len() {return size;}

    _Type MIN(){
        if(root) return getMin(root)->data;
        else {
            cout << "Binary search tree is empty!!\n";
            exit(1);
        }
    }

    _Type MAX(){
        if(root) return getMax(root)->data;
        else {
            cout << "Binary search tree is empty!!\n";
            exit(1);
        }
    }

    void traverse(){
        if(size == 0) {
            cout << "BST is empty!!\n";
            return;
        }

        else {
            TraverseInOrder(root);
            cout << endl;
        }
    }

    bool exist(_Type value) {
        if(root) find(value, root) != NULL;
        else return false;
    }

    void remove(_Type value){
        if(!root) {
            exit(1);
        }

        if(!root->lnode && !root->rnode){
            delete root;
            root = NULL;
            size--;
            return;
        }

        Node<_Type>* prev = find(value, root), *cur;
        bool relation;

        if(prev == NULL) return;

        if(value < prev->data) {
            relation = true; // true: for left node
            cur = prev->lnode;
        }

        else {
            relation = false; // false: for right node
            cur = prev->rnode;
        }

        deleteUtil(prev, cur, relation);
        size--;
    }

    friend class iterator_BST<_Type>;
};


template<class _Type> class iterator_BST { 
private: 
    // Stack to store the nodes 
    // of BST 
    stack<Node<_Type>*> q;
  
public:
    iterator_BST() {}
    // Constructor for the class 
    iterator_BST(Node<_Type>* root) 
    { 
        // Initializing stack 
        Node<_Type>* curr = root; 
        while (curr != NULL) 
            q.push(curr), curr = curr->lnode; 
    }

    iterator_BST(BST<_Type>& a){
        Node<_Type>* curr = a.root; 
        while (curr != NULL) 
            q.push(curr), curr = curr->lnode; 
    }

    // Function to return 
    // current element iterator 
    // is pointing to 
    const _Type* curr() 
    {
        if(q.size() == 0) return NULL;
        else return &(q.top())->data;
    }
  
    // Function to iterate to next 
    // element of BST 
    void next() 
    { 
        Node<_Type>* curr = q.top()->rnode;
        q.pop(); 
        while (curr != NULL) 
            q.push(curr), curr = curr->lnode;
    }
  
    // Function to check if 
    // stack is empty 
    bool isEnd() 
    { 
        return !(q.size());
    }

    bool operator!=(iterator_BST<_Type>& a){
        return (curr() != a.curr());
    }

};

template<class _Type> const _Type& operator*(iterator_BST<_Type>& a){
    return *(a.curr());
}

template<class _Type> void operator++(iterator_BST<_Type>& a){
    a.next();
}

template<class _Type> iterator_BST<_Type> BST<_Type>::begin(){
    iterator_BST<_Type> a(BST<_Type>::root);

    return a;
}

template<class _Type> iterator_BST<_Type> BST<_Type>::end(){
    iterator_BST<_Type> a;

    return a;
}

#endif


int main(){

    BST<int> a;

    int x;

    for(int i = 0; i < 5; i++) {
        cin >> x;
        a.insert(x);
    }

    // This will work fine
    for(auto i : a) cout << i << endl;

    cout << endl;

    return 0;
}

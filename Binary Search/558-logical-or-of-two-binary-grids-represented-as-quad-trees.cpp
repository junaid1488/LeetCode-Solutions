class Solution {
public:
    Node* intersect(Node* a, Node* b) {

        if(a->isLeaf)
            return a->val ? new Node(true, true) : b;

        if(b->isLeaf)
            return b->val ? new Node(true, true) : a;

        Node* tl = intersect(a->topLeft, b->topLeft);
        Node* tr = intersect(a->topRight, b->topRight);
        Node* bl = intersect(a->bottomLeft, b->bottomLeft);
        Node* br = intersect(a->bottomRight, b->bottomRight);

        if(tl->isLeaf && tr->isLeaf &&
           bl->isLeaf && br->isLeaf &&
           tl->val == tr->val &&
           tr->val == bl->val &&
           bl->val == br->val)
            return new Node(tl->val, true);

        Node* root = new Node(false, false);

        root->topLeft = tl;
        root->topRight = tr;
        root->bottomLeft = bl;
        root->bottomRight = br;

        return root;
    }
};

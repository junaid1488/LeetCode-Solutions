/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    // Returns tail of flattened list
    Node* flattenDFS(Node* head) {

        Node* curr = head;
        Node* last = head;

        while (curr) {

            Node* nextNode = curr->next;

            // If child exists
            if (curr->child) {

                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                // Connect current node with child
                curr->next = childHead;
                childHead->prev = curr;

                // Connect child's tail with next node
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                curr->child = nullptr;
                last = childTail;
            }
            else {
                last = curr;
            }

            curr = nextNode;
        }

        return last;
    }

    Node* flatten(Node* head) {

        if (!head)
            return nullptr;

        flattenDFS(head);

        return head;
    }
};

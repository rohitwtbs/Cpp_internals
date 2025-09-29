class Node{
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr
    }
};


class linked_list{
private:
    Node* head;
public:
    linked_list (int val) {
        head = new Node(val):

    }

    void append(int val) {
        Node* newNode = new Node(val);
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }


};
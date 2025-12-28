int getNthFromLast(Node* head, int n)
{
    if (head == NULL) return -1;

    int len = 0;
    Node* temp = head;

    // length nikalna
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    // invalid case
    if (n > len) return -1;

    int pos = len - n;
    Node* curr = head;

    while (pos > 0) {
        curr = curr->next;
        pos--;
    }

    return curr->data;
}

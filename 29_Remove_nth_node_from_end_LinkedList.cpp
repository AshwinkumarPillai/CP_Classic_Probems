// Remove the kth node from the end of the list;

void RemoveNode(Node *head, int k)
{
    Node *first = head, second = head;
    for (int i = 0; i < k; i++)
    {
        first = first->next;
    }

    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    if (first == head)
    {
        head = first->next;
        return;
    }
    first->val = first->next->val;
    first->next = first->next->next;
}
void tail_recursive_preorder_rec(stack worklist) {
  if (!worklist.isEmpty()) {
    node n = worklist.pop()
    dosomething (n);
    foreach child_node in n.getChildren() {
        worklist.push(child_node);
    }
  }
  tail_recursive_preorder_rec(worklist)
}

void tail_recursive_preorder (node n) {
  stack worklist = stack().push(n);
  tail_recursive_preorder_rec(worklist);
}


template<typename T>
void List<T>::reverse() {
    if (_head == nullptr)
        return;

    // Initialize the tail to head
    _tail = _head;

    // call the recursive function
    reverseUtil(_head, NULL, &_head);
}

// Private Utility method for reverse
template<typename T>
void List<T>::reverseUtil(Node *iCurr, Node *iPrev, Node **iHead) {
    //If last node mark it head
    if (iCurr->_link == nullptr) {
        *iHead = iCurr;

        /* Update next to prev node */
        iCurr->_link = iPrev;
        return;
    }

    //Save next node for recursive call
    Node *aNext = iCurr->_link;

    // update next with previous (swapping)
    iCurr->_link = iPrev;

    // do this, recursively
    reverseUtil(aNext, iCurr, iHead);
}

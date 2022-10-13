void segregateEvenOdd(Node **head_ref)
{
    Node *end = *head_ref;
    Node *prev = NULL;
    Node *curr = *head_ref;
 
    // /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;
 
    Node *new_end = end;
 
    /* Consider all odd nodes before the first
     even node and move then after end */
    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 
    // 10->8->17->17->15
    /* Do following steps only if
    there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to
        point to first even node */
        *head_ref = curr;
 
        /* now current points to
        the first even node */
        while (curr != end)
        {
            if ( (curr->data) % 2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between
                prev and current */
                prev->next = curr->next;
 
                /* Make next of curr as NULL */
                curr->next = NULL;
 
                /* Move curr to end */
                new_end->next = curr;
 
                /* make curr as new end of list */
                new_end = curr;
 
                /* Update current pointer to
                next of the moved node */
                curr = prev->next;
            }
        }
    }
 
    /* We must have prev set before executing
    lines following this statement */
    else prev = curr;
 
    /* If there are more than 1 odd nodes
    and end of original list is odd then
    move this node to end to maintain
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}

void segregateEvenOdd(Node *head_ref)
{
    // Starting node of list having
    // even values.
    Node *evenStart = NULL;
     
    // Ending node of even values list.
    Node *evenEnd = NULL;
     
    // Starting node of odd values list.
    Node *oddStart = NULL;
     
    // Ending node of odd values list.
    Node *oddEnd = NULL;
     
    // Node to traverse the list.
    Node *currNode = *head_ref;
     
    while(currNode != NULL){
        int val = currNode -> data;
         
        // If current value is even, add
        // it to even values list.
        if(val % 2 == 0) {
            if(evenStart == NULL){
                evenStart = currNode;
                evenEnd = evenStart;
            }
             
            else{
                evenEnd -> next = currNode;
                evenEnd = evenEnd -> next;
            }
        }
         
        // If current value is odd, add
        // it to odd values list.
        else{
            if(oddStart == NULL){
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else{
                oddEnd -> next = currNode;
                oddEnd = oddEnd -> next;
            }
        }
                     
        // Move head pointer one step in
        // forward direction
        currNode = currNode -> next;   
    }
     
    // If either odd list or even list is empty,
    // no change is required as all elements
    // are either even or odd.
    if(oddStart == NULL || evenStart == NULL){
        return;
    }
     
    // Add odd list after even list.    
    evenEnd -> next = oddStart;
    oddEnd -> next = NULL;
     
    // Modify head pointer to
    // starting of even list.
    *head_ref = evenStart;
}
 
 void kreverse(node *head,int k)
 {
    if(head==NULL||k==1)
    return head;
    node *dummy=new node;
    dumm->next=head;
    node *curr=dummy,*nex=dummy,*pre=dummy;
    int count=0;
    while(curr->next!=NULL)
    {
        curr=curr->next;
        count++;
    }
    while(curr->next!=NULL)
    {
        curr=curr->next;
        nex=curr->next;
        for(int i=0;i<k;i++)
        {
            curr->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            next=curr->next;
        }
        pre=curr;
        count-=k;
    }
    return(dummy->next);
 }

 void reversellrecursive(node *head)
 {
     
 }
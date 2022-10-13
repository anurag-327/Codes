DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data)
 {
   DoublyLinkedListNode* p=new DoublyLinkedListNode(data);
   DoublyLinkedListNode *p1=llist;
   DoublyLinkedListNode *p2=llist->next;
   if(llist==NULL)
   {
       return NULL;
   }
   else if(data<=p1->data)
   {
       p1->prev=p;
       p->next=p1;
       llist=p;
       return llist;
   }
   else
   {
   while(p2!=NULL)
   {
       if(p1->data<=data&&data<=p2->data)
       {
       p1->next=p;
       p->prev=p1;
       p->next=p2;
       p2->prev=p;
       return llist;
       }
       if(p1->data<=data&&data>=p2->data&&p2->next==NULL)
       {
       p2->next=p;
       p->prev=p2;
       p->next=NULL;
       return llist;
       }
       p1=p1->next;
       p2=p2->next;
   }  
   }
   return NULL ; 
}
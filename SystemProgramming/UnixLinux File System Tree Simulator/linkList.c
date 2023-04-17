int insert(NODE** list, NODE* p) // insert p to end of *list
{
	NODE* q = *list;
	if (q == 0) // if list is empty:
		*list = p; // insert p as first element
	else { // otherwise, insert p to end of list
		while (q->next) // step to LAST element
			q = q->next;
		q->next = p; // let LAST element point to p
	}
	p->next = 0; // p is the new last element.
}
// LINKED LIST BASIC FUNCTIONS 
// THE FUNCTIONS WHICH CANNOT BE PERFORMED, DUE TO INVALID PARAMETERS, RETURN FALSE

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int info;
	node* next;

	node(int info)
	{
		this -> info = info;
		this -> next = NULL;
	}
};

class linked_list
{
	node* head;
	int size; 

	public:
		linked_list()
		{
			head = NULL;
			size = 0;
		}

		int get_size()
		{
			return size;
		}

		bool empty_l()
		{
			return head == NULL;
		}

		bool atend_l(node* n)
		{
			if(n == NULL)
				return false;
			else
				return n -> next == NULL;
		}

		int get_front()
		{
			if(empty_l())
				return INT_MIN;

			else
				return head ->info;
		}

		void insert_front(int target)
		{
			node *p = new node(target);
			p -> next = head;
			head = p;
			size++;
		}

		void insert_after_util(node* target, node* prev)
		{
			target -> next = prev -> next;
			prev -> next = target;
			size++;
		}

		bool insert_after(int target, int prev)
		{
			node* n = head;

			while(n != NULL)
			{
				if(n -> info == prev)
				{
					node* p = new node(target);
					insert_after_util(p, n);
					return true;
				}
				n = n -> next;
			}
			return false;
		}

		bool delete_front()
		{
			if(empty_l())
				return false;

			node* p = head;
			head = head -> next;
			delete p;
			size--;
			return true;
		}

		void delete_after_util(node* prev)
		{
			node* p = prev -> next;
			prev -> next = p -> next;
			delete p;
			size--;
		}

		bool delete_after(int prev)
		{
			if(empty_l())
				return false;

			node* n = head;

			while(!atend_l(n))
			{
				if(n -> info == prev)
				{
					delete_after_util(n);
					return true;
				}
				n = n -> next;
			}
			return false;
		}

		void display_list()
		{
			node* n = head;

			while(n != NULL)
			{
				cout << n -> info << " ";
				n = n -> next;
			}
			cout << endl;
		}

		void display_reversed_util(node* p)
		{
			if(p == NULL)
				return;

			display_reversed_util(p -> next);
			cout << p -> info << " ";
		}

		void display_reversed()
		{
			display_reversed_util(head);
			cout << endl;
		}

		bool insert_at(int index, int target)
		{
			if(index > size)
				return false;

			if(index == 0)
			{
				insert_front(target);
				return true;
			}

			node* n = head;
			int k = 1;
			while(k != index)
			{
				k++;
				n = n -> next;
			}

			node* p = new node(target);
			insert_after_util(p, n);
			return true;


		}

		bool delete_at(int index)
		{
			if(index >= size)
				return false;

			if(index == 0)
			{
				delete_front();
				return true;
			}

			node* n = head;
			int k = 1;
			while(k != index)
			{
				k++;
				n = n -> next;
			}

			delete_after_util(n);
			return true;
		}

		bool insert_before(int target, int next)
		{
			node* n = head;

			while(n != NULL)
			{
				if(n -> info == next)
				{
					node* p = new node(target);
					insert_after_util(p, n);
					//Swapping the values of nodes pointed by p and n
					swap(n, p);
					return true;
				}
				n = n -> next;
			}
			return false;
		}

		void clear_list()
		{
			while(!empty_l())
				delete_front();
		}

		void reverse_list()
		{
			node* prev = NULL, *curr = head, *next = NULL;

			while(curr != NULL)
			{
				next = curr -> next;
				curr -> next = prev;
				prev = curr;
				curr = next;
			}

			head = prev;
		}

		void swap(node* a, node* b)
		{
			int temp = a -> info;
			a -> info = b -> info;
			b -> info = temp;
		}

		void sort()
		{
			if(head == NULL)
				return;

			int swapped;
			node* p = NULL; 
			node* lptr = NULL;

			do
			{
				swapped = 0;
				p = head;
				while(p -> next != lptr)
				{
					if((p -> info) > ((p -> next) -> info))
					{
						swap(p, p -> next);
						swapped = 1;
					}
					p = p -> next;
				}
				lptr = p;
			}
			while(swapped);
		}
};
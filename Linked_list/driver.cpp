#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;

int main()
{
	linked_list ll;
	char ch = 'y';
	int choice, target, prev, index, next;
	while(ch == 'y' || ch == 'Y') 
	{
		cout << "Enter choice:" << endl;
		cout << "1. Insert front" << endl;
		cout << "2. Delete front" << endl;
		cout << "3. Insert after" << endl;
		cout << "4. Delete after" << endl;
		cout << "5. Display list" << endl;
		cout << "6. Display list reversed" << endl;
		cout << "7. Insert nth element" << endl;
		cout << "8. Delete nth element" << endl;
		cout << "9. Insert before" << endl;
		cout << "10. Clear list" << endl;
		cout << "11. Reverse list" << endl;
		cout << "12. Sort list" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1: cout << "Enter element to be inserted:" << endl;
					cin >> target;
					ll.insert_front(target);
					break;

			case 2: ll.delete_front();
					break;

			case 3: cout << "Enter element to be inserted and previous element:" << endl;
					cin >> target >> prev;
					ll.insert_after(target, prev);
					break;

			case 4: cout << "Enter previous element:" << endl;
					cin >> prev;
					ll.delete_after(prev);
					break;

			case 5: ll.display_list();
					break;

			case 6: ll.display_reversed();
					break;

			case 7: cout << "Enter element to be inserted and index:" << endl;
					cin >> target >> index;
					ll.insert_at(index, target);
					break;

			case 8: cout << "Enter index of element to be deleted:" << endl;
					cin >> index;
					ll.delete_at(index);
					break;

			case 9: cout << "Enter element to be inserted and next element:" << endl;
					cin >> target >> next;
					ll.insert_before(target, next);
					break;

			case 10: ll.clear_list();
					break;

			case 11: ll.reverse_list();
					break;

			case 12: ll.sort();
					break;
					
			default: exit(0);

		}

		cout << "Enter more?(y/n)";
		cin >> ch;
	}
	
	
}


#include <iostream>
#include <string>
using namespace std;
#include "node.h"
class list {

private:
	node *head, *tail;
	int counter;
public:
	list()
	{
		head = NULL;
		tail = NULL;
		counter = 0;
	}
	//============================== functions ==============================================
	node *create_node(int stuvalue,string namevalue , string familyvalue , float scorevalue) {
		counter += 1;
		node *temp = new node;
		temp->stunum = stuvalue;
		temp->name = namevalue;
		temp->family = familyvalue;
		temp->score = scorevalue;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	//=================================================
	void insert_start(int stuvalue ,string namevalue, string familyvalue, float scorevalue)
	{
		if (counter == 0) {
			node *temp = new node;
			temp->stunum = stuvalue;
			temp->name = namevalue;
			temp->family = familyvalue;
			temp->score = scorevalue;
			temp->next = head;
			head = temp;
			counter += 1;
		}
		else {
			node *c = new node;
			c = head;
			while (c->next != NULL)
			{
				if (c->stunum == stuvalue) {

					cout << "EROR--you can't use this id \nAdd your new id: ";
					cin >> stuvalue;
				}
				c = c->next;

			}
			if (c->stunum == stuvalue)
			{
				cout << "EROR--you can't use this id \nAdd your new id: ";
				cin >> stuvalue;
			}
			node *temp = new node;
			temp->stunum = stuvalue;
			temp->name = namevalue;
			temp->family = familyvalue;
			temp->score = scorevalue;
			temp->next = head;
			head = temp;
			counter += 1;
		}
		
		
	}
	//============================
	void insert_default(int stuvalue ,string namevalue, string familyvalue, float scorevalue, int where)
	{
		
		node *pre = new node;
		node *now = new node;
		node *temp = new node;
		now = head;
		node *c = new node;
		c = head;
		while (c->next !=NULL)
		{
			if (c->stunum == stuvalue) {
				
				cout << "EROR--you can't use this id \nAdd your new id: ";
				cin >> stuvalue;
			}
		c = c->next;

		}
		if (c->stunum==stuvalue)
		{
			cout << "EROR--you can't use this id \nAdd your new id: ";
			cin >> stuvalue;
		}
		for (int i = 1; i<where; i++)
		{
			pre = now;
			now = now->next;
		}
			temp->stunum = stuvalue;
			temp->name = namevalue;
			temp->family = familyvalue;
			temp->score = scorevalue;
			pre->next = temp;
			temp->next = now;
			counter += 1;
		
	}
	//================================================

	void view_list() {
		node *temp = new node;
		temp = head;
		cout << "stu Id \t Firstname \tLastname \t Score\n";
		cout << "===================================================================\n";
		while (temp!=NULL)
		{
			cout <<temp->stunum<<" \t "<<temp->name <<"\t        "<<temp->family<<" \t         "<<temp->score<< "\n";
		    temp = temp->next;
			
		}
	
		//cout << temp->stunum << " \t " << temp->name << "\t  " << temp->family << " \t " << temp->score << "\n";
		cout << "====================================================================\n";

	}

	//================================================
	void view_list_by_number(int n) {
		node *temp = new node;
		temp = head;
		
		while (temp->stunum != n) {
			temp = temp->next;
		}
		if (temp->stunum != n) {
			cout << "we don't have any student with this id\n";
		}
		else {
			cout << "his/her name is :" << temp->name << " " << temp->family << " score :" << temp->score << "\n";
		}

	}
	//================================================
	void edit(int where, string n,string f,float score ) {
		node *temp = new node;
		temp = head;
		while (temp->stunum != where) {
			temp = temp->next;
		}
		cout << "his/her last name is :" << temp->name << " " << temp->family<<" "<< "score :" << temp->score;
			temp->name = n;
			temp->family = f;
			temp->score = score;
			cout << "\nYESS we do it !\n";

		}
		

	
	//=================================================
	void delete_last()
	{
		
		node *current = new node;
		current = head;
		if (current == NULL) {
			cout << "it's empty.\n";

		}
		if (current->next == NULL) {
			delete current;
			current = NULL;
			cout << "now,it's deleted\n";
		}
		else {
			while (current->next->next != NULL)
			{
				current = current->next;
			}
			tail = current;
			tail->next = NULL;
			delete current->next;
			cout << "now, it's deleted .\n";
		}
		counter -= 1;
	}
	//==================================================
	void delete_default_by_number(int num)
	{
		node *current = new node;
		node *previous = new node;
		current = head;
		for (int i = 0; i < counter; i++) {
			if (current->stunum != num) {
				previous = current;
				current = current->next;
			}
			else {
				if (i == 0) {
					node *temp = new node;
					temp = head;
					head = head->next;
					delete temp;
					cout << "done .\n";
				
				}
				else {
					previous->next = current->next;
					delete current;
					cout << "Now, it's deleted.\n";
				}
				
			}
			
		}//end 

			
		counter -= 1;
		
	};
	

}; //end class
   //===========================================================================================================
   //===========================================================================================================

int main() {
	list obj;
	int f = 1;
	int u = 0;
	while (f != 0) {

		if (u == 0) {
			string name1;
			string family1;
			float score1;
			int id1;
			cout << "WELCOME TO YOUR PROGRAM :)\n";
			cout << "ADD NEW STUDENT :\n";
			cout << "name? :";
			cin >> name1;
			cout << "last name ? :";
			cin >> family1;
			cout << "score :";
			cin >> score1;
			cout << "and student id? :";
			cin >> id1;
			obj.insert_start(id1,name1, family1, score1);
		}


		cout << "number.1 ADD STUDENT \nnumber.2 SHOW STUDENTS \nnumber.3 DELETE A STUDENT \nnumber.4 EDIT A STUDENT \nnumber.5 EXIT? seriously? \nenput your number :";
		int a;
		cin >> a;
			switch (a) {
			case 1: //ezafe kardane gere
			{
				cout << "number.1 Add student at the first\nnumber.2 Add student in your location :\n";
				int a1;
				cin >> a1;

				if (a1 == 1) {
					string dataname11, datafamily11;
					float score11;
					int id11;
					cout << "enter NAME ? :\n";
					cin >> dataname11;
					cout << "enter FAMILY:\n";
					cin >> datafamily11;
					cout << "enter SCORE :\n";
					cin >> score11;
					cout << "enter STU ID :";
					cin >> id11;
					obj.insert_start(id11 ,dataname11 , datafamily11,score11);

				}
				//==========================
				else {
					int num12 , id12;
					string dataname12, datafamily12;
					float score12;
					cout << "Enter student location by number :\n";
					cin >> num12;
					cout << "what's the student NAME ? :\n";
					cin >> dataname12;
					cout << "enter FAMILY :\n";
					cin >> datafamily12;
					cout << "what's the SCORE:\n";
					cin >> score12;
					cout << "and student ID is :";
					cin >> id12;
					obj.insert_default(id12 ,dataname12, datafamily12, score12, num12);


				}


				break;
			}// end ADD node =====================================================
			case 2: // SHOW LIST
			{
				cout << "number.1 Show all of the student \nnumber.2 Show student by ID : \n";
				int a2;
				cin >> a2;

				if (a2 == 1) {

					obj.view_list();
				}
				else if (a2 == 2) {

					cout << "Enput student id:";
					int num22;
					cin >> num22;
					obj.view_list_by_number(num22);

				}

			}//===========end show list
			case 3://DELETE===================
			{
				cout << "\nnumber.1 DELETE student by ID \nnumber.2 DELETE from the end \nnumber.3 EXIT\n";
				int a3;
				cin >> a3;

				switch (a3) { 
				case 1:
					//delete special node

						cout << "what's the student id :\n";
						int a311;
						cin >> a311;
						obj.delete_default_by_number(a311);
					f = 0;
					break;
					//end case 1 in case3
				case 2://delete from end
					obj.delete_last();
					break;

				case 3:

					f = 0;
					break;
				}//end inside switch
				break;
			}// end switch case 3 
			//end delete================================
			case 4://edit data
			{
				int searchdata;
				string newname, newfamily;
				float newscore;
				cout << "Which student do you want? enter student id :";
				cin >> searchdata;
				if (searchdata == 0) {
					f = 0;
					break;
				}
				cout << "Enter stu new NAME :";
				cin >> newname;

				cout << "Enter stu new FAMILY :";
				cin >> newfamily;

				cout << "Enter stu new SCORE :";
				cin >> newscore;

				obj.edit(searchdata, newname, newfamily, newscore);
				f = 0;
				break;
			}//end edit  case 4
			case 5:
			{
				f = 0;
				break;
			}
			default:
				cout << "Oh sorry it was not true ... ";
				break;

			}// end all switch 

			cout << "continue ? if YES num.1 if NO num.0 :\n";
			cin >> f;
			u = 2;
		
		}//end while
		cout << "OH underestand ! good luck .";
	
		cin.get();
		cin.get();
	    return 0;

}// end main



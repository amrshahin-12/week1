#include<iostream>
#include"Resource.h"
#include"LinkedQueue.h"
#include"Treatment.h"
#include"EU_WaitList.h"

using namespace std;


int main()
{
	// Resource 
	/*LinkedQueue<Resource*> E_Available_Resources;
	LinkedQueue<Resource*> U_Available_Resources;
	LinkedQueue<Resource*> X_Available_Resources;
	int e,u,x;

	cin >> e >> u>>x;
	for (int i = 0;i < e;i++)
	{
		Resource* Eptr = new Resource("EDevice", i+1, 1);
		E_Available_Resources.enqueue(Eptr);
	}
	for (int i = 0;i < u;i++)
	{
		Resource* Uptr = new Resource("UDevice", i + 1, 1);
		U_Available_Resources.enqueue(Uptr);
	}
	for (int i = 0;i < x;i++)
	{
		int y;
		cin >> y;
		Resource* Xptr = new Resource("GymRoom", i + 1, y);
		X_Available_Resources.enqueue(Xptr);
	}


	cout << "Available EDevices: ";
	E_Available_Resources.print();
	
	cout << "Available UDevices: ";
	U_Available_Resources.print();
	
	cout << "Available Rooms: ";
	X_Available_Resources.print();*/
	

	// Treatment
	/*
	LinkedQueue<Treatment*> s;
	int size;
	char type;
	int time;
	cin >> size;
	for (int i = 0;i < size;i++)
	{
		cin >> type >> time;
		
		Treatment* ptr = nullptr;
		if (type == 'U')
		{
			ptr= new U_Treatment(time);
		}
		else if (type == 'E')
		{
			ptr = new E_Treatment(time);
		}
		else if (type == 'X')
		{
			ptr = new X_Treatment(time);
		}
		s.enqueue(ptr);
	}
	s.print();
	*/
	// Patient 

	//////////////////////////////////////////////////////////////
	//testing insertsorted
	
	EU_WaitList waitList;
	LinkedQueue<Treatment*> treatments;

	Patient* p1 = new Patient('N', 5, 2, treatments);  // PT = 5
	Patient* p2 = new Patient('R', 10, 3, treatments); // PT = 10
	Patient* p3 = new Patient('N', 15, 1, treatments); // PT =15

	waitList.enqueue(p1);
	waitList.enqueue(p2); 
	waitList.enqueue(p3); 

	Patient* tempPatient;
//	LinkedQueue<Patient*> tempQueue;

	// a new patient
	Patient* p4 = new Patient('N', 9, 4, treatments);  // PT 11 + penalty 2 = 13
	waitList.insertSorted(p4, 2);

	// print updated waitlist
	cout << "test1\n";
	cout << "\n after inserting patient sortKey = 13" << endl;
	while (!waitList.isEmpty()) {
		waitList.dequeue(tempPatient);  
		cout << "Patient with PT: " << tempPatient->PT << endl;
	//	tempQueue.enqueue(tempPatient); 
	}

	//case: empty list
	Patient* p5 = new Patient('N', 9, 4, treatments);  // PT + penalty  = 13
	waitList.insertSorted(p4, 2);
	// print updated waitlist
	cout << "\ncase: empty list";
	cout << "\n after inserting patient sortKey = 13" << endl;
	while (!waitList.isEmpty()) {
		waitList.dequeue(tempPatient);
		cout << "Patient with PT: " << tempPatient->PT << endl;
//		tempQueue.enqueue(tempPatient); 
	}

	//case:it should be the last
	Patient* p10 = new Patient('N', 5, 2, treatments);  // PT = 5
	Patient* p11 = new Patient('R', 10, 3, treatments); // PT = 10
	Patient* p12 = new Patient('N', 15, 1, treatments); // PT = 15

	waitList.enqueue(p10);
	waitList.enqueue(p11);
	waitList.enqueue(p12);

	Patient* p13 = new Patient('N', 15, 1, treatments);  //sortKey = 16
	waitList.insertSorted(p13, 2);

	// print updated waitlist
	cout << "\ncase:it should be the last";
	cout << "\n after inserting patient sortKey = 16" << endl;
	while (!waitList.isEmpty()) {
		waitList.dequeue(tempPatient);
		cout << "Patient with PT: " << tempPatient->PT << endl;
//		tempQueue.enqueue(tempPatient); 
	}
	
///////////////////////////////////////////////////////////////
//  some treatments
U_Treatment* u1 = new U_Treatment(10);
U_Treatment* u2 = new U_Treatment(15);

LinkedQueue<Treatment*> t1, t2;
t1.enqueue(u1);
t2.enqueue(u2);

Patient* p14 = new Patient('N', 5, 1, t1);
Patient* p15 = new Patient('N', 10, 3, t2);

EU_WaitList waitList2;
waitList2.enqueue(p14);
waitList2.enqueue(p15);

// calculate treatment latency
cout << "test1: \nU-Treatment : " << waitList2.calcTreatmentLatency() << endl;
//////////////test2////////////////////////
//  some treatments
E_Treatment* e1 = new E_Treatment(10);
E_Treatment* e2 = new E_Treatment(1);

LinkedQueue<Treatment*> t3, t4;
t3.enqueue(e1);
t4.enqueue(e2);

Patient* p16 = new Patient('N', 5, 1, t3);
Patient* p17 = new Patient('N', 10, 3, t4);

EU_WaitList waitList3;
waitList3.enqueue(p16);
waitList3.enqueue(p17);

// calculate treatment latency
cout << "test2: \nE-Treatment : " << waitList3.calcTreatmentLatency() << endl;

	return 0;
}
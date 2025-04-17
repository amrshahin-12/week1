#pragma once
#include "Patient.h"
class EU_WaitList : public LinkedQueue <Patient*>
{


public:



    //doest check => assuming if we call the func with object U for ex, then it's its turn
    int calcTreatmentLatency() {
        int totalLatency = 0;

        Node<Patient*>* current = frontPtr;

        // traverse
        while (current) {  
            Patient* patient = current->getItem();

            // peek at the first treatment 
            Treatment* firstTreatment;
            if (patient->Required_Treatments.peek(firstTreatment)) {
                totalLatency += firstTreatment->duration;
            }

            current = current->getNext(); // le el next node
        }

        return totalLatency;
    } 
    /////////////////////////////////////////////
//checks if the top treatment is U or E
/* int calcTreatmentLatency(int flag) {
     //the flag: 1 => U , 0 => E
     int totalLatency = 0;

     Node<Patient*>* current = frontPtr; // from the front of the queue

     while (current) {  // traverse until the end of the list
         Patient* patient = current->getItem();

         // peek at the first treatment
         Treatment* firstTreatment;
         if ((patient->Required_Treatments.peek(firstTreatment)&& flag == 1 && dynamic_cast<U_Treatment*>(firstTreatment)) || (flag == 0 && dynamic_cast<E_Treatment*>(firstTreatment)))
         {
             totalLatency += firstTreatment->duration;
         }

         current = current->getNext(); // to the next node
     }

     return totalLatency;
 }*/
 /////////////////////////////////////////////
 // 
    ///////////////////////////////////////////////////////////////////////////////////
 /*   int calcTreatmentLatency(int flag) {
        //flag 1 => U, 0 => E
        int totalLatency = 0;

        Node<Patient*>* current = frontPtr; 

        while (current) {
            Patient* patient = current->getItem();

            // traverse all treatments of the current patient
            LinkedQueue<Treatment*> tempQueue;
            Treatment* treatment;

            while (!patient->Required_Treatments.isEmpty()) {
                patient->Required_Treatments.dequeue(treatment);  

                if ((flag == 1 && dynamic_cast<U_Treatment*>(treatment)) ||
                    (flag == 0 && dynamic_cast<E_Treatment*>(treatment))) {
                    totalLatency += treatment->duration;
                }
                tempQueue.enqueue(treatment); // put in a temp queue to restore later
            }

            // restore treatments to the patient's queue
            while (!tempQueue.isEmpty()) {
                tempQueue.dequeue(treatment);
                patient->Required_Treatments.enqueue(treatment);
            }
            current = current->getNext(); // to the next patient
        }

        return totalLatency;
    }*/


    bool insertSorted(Patient* p, int penalty) {
        int sortKey = p->PT + penalty;
        Node<Patient*>* newNode = new Node<Patient*>(p);

        //the list is empty => we just enqueue
        if (isEmpty()) {
            enqueue(p);
            return true;
        }

        LinkedQueue<Patient*> tempQueue;
        Patient* tempPatient;
        bool inserted = false;

        //we will dequeue the elements in a temp queue, and add the new patient in their correct position

        while (!isEmpty()) {
            peek(tempPatient);
            if (!inserted && tempPatient->PT >= sortKey) {
                tempQueue.enqueue(p); // Insert new patient before larger one
                inserted = true;
            }
            dequeue(tempPatient);
            tempQueue.enqueue(tempPatient);
        }

        //if not inserted yet that means
        //  all the list should be before the new p, we add it lastly
        if (!inserted) {
            tempQueue.enqueue(p);
        }

        // restore elements from tempQueue into the main queue
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(tempPatient);
            enqueue(tempPatient);
        }

        return true;
    }











};


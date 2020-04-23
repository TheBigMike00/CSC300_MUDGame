#include "LinkedListOfStudents.hpp"

LinkedListOfStudents::LinkedListOfStudents()
{
    this->head = 0;
    this->count = 0;
}

void LinkedListOfStudents::addFront(Student* s)
{
    StudentNode* sn = new StudentNode(s);
    if(!this->head)
    {
        this->head = sn;
    }
    else
    {
        sn->setNextNode(this->head);
        this->head = sn;
    }
    this->count++;
}

Student* LinkedListOfStudents::getAtIndex(int index)
{
    //if they give us a bad index, return null
    if(index > this->count-1 || index < 0)
    {
        return 0;
    }
    else
    {
        StudentNode* currNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();
    }
}

Student* LinkedListOfStudents::removeAtIndex(int index)
{
    //is the list empty or is index out of range?
    if(!this->head || index < 0 || index > this->count - 1)
    {
        return 0;
    }
    else
    {
        Student* studentToReturn = 0;

        if(index == 0)
        {
            //remove from front
            studentToReturn = this->head->getPayload();
            this->head = this->head->getNextNode();
            this->count--;
        }
        else if(index == this->count - 1)
        {
            //remove from the end
            StudentNode* currNode = this->head;
            //positions currNode to the guy before the last guy
            for(int i = 0; i < this->count-2; i++)
            {
                currNode = currNode->getNextNode();
            }
            studentToReturn = currNode->getNextNode()->getPayload();
            StudentNode* nodeToDelete = currNode->getNextNode();
            currNode->setNextNode(0);
            delete nodeToDelete;
            this->count--;
        }
        else
        {
            //remove from the middle
            StudentNode* firstPoint = this->head->getNextNode();
            StudentNode* beforePoint = this->head;

            for(int i = index-1; i>0; i--)
            {
                firstPoint = firstPoint->getNextNode();
                beforePoint = beforePoint->getNextNode();
            }
            studentToReturn = firstPoint->getPayload();
            beforePoint->setNextNode((firstPoint->getNextNode()));
            firstPoint->setNextNode(0);
            this->count--;
        }
        return studentToReturn;
    }
    
}

int LinkedListOfStudents::indexOf(Student* s)
{
    int index = 0;
    StudentNode* traverse = this->head;
    for(int i = 0; i < this->count-1; i++)
    {
        if(traverse->getPayload() == s)
        {
            return index;
        }
        else
        {
            traverse = traverse->getNextNode();
            index++;   
        }
    }
    return -1;
}
#include "NumberList.h"

// Constructor
CourseList::CourseList() 
{
    head = nullptr; 
}

// Destructor
CourseList::~CourseList()
{
    deleteAllNodes(); 
}

void CourseList::addCourse(int course, int Hours, char grade)
{
    CourseNode* newNode = new CourseNode;
    newNode->course = course;
    newNode->Hours = Hours;
    newNode->grade = grade;
    newNode->next = nullptr;

    if (!head || head->course > course) 
    {
        // Creating/adding head
        newNode->next = head;
        head = newNode;
    }
    else 
    { 
        CourseNode* current = head;
        CourseNode* previous = nullptr;
        while (current != nullptr && current->course < course) {
            previous = current;
            current = current->next;
        }
        previous->next = newNode;
        newNode->next = current;
    }
}

// Delete a specific course by courseCode
void CourseList::deleteCourse(int course)
{
    if (!head) 
    {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    CourseNode* nodePtr = head;
    CourseNode* prevPtr = nullptr;

    if (head->course == course) 
    { 
        head = head->next;
        delete nodePtr;
    }
    else {
        while (nodePtr != nullptr && nodePtr->course != course)
        {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (!nodePtr)
        { 
            cout << "Course not found.\n";
            return;
            // If code course isn't found
        }

        prevPtr->next = nodePtr->next; 
        delete nodePtr;
    }
}

// Delete all nodes
void CourseList::deleteAllNodes() 
{
    CourseNode* nodePtr = head;
    while (nodePtr != nullptr) 
    {
        CourseNode* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
    }
    head = nullptr;
}

// Display all of the courses before deletion
void CourseList::displayList() const // Since the values are submitted, no other nodes will change so keep it const.
{
    if (!head)
    {
        cout << "The list is empty.\n";
        return;
    }

    CourseNode* nodePtr = head;
    cout << "Course List:\n";
    while (nodePtr != nullptr) 
    {
        cout << "Course Code: " << nodePtr->course
            << ", Credit Hours: " << nodePtr->Hours
            << ", Grade: " << nodePtr->grade << endl;
        nodePtr = nodePtr->next;
    }
}

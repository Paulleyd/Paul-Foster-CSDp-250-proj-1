#ifndef NumberList_h
#define NumberList_h

#include <iostream>
#include <string>
using namespace std;

class CourseList 
{
private:
    struct CourseNode
    {
        int course;
        int Hours;
        char grade;
        CourseNode* next;
    };

    CourseNode* head;

public:
    CourseList();  
    ~CourseList(); 

    void addCourse(int course, int Hours, char grade);
    void deleteCourse(int courseCode);
    void deleteAllNodes();
    void displayList() const;
};

#endif



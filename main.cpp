#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;



/*
Create a Student Grade project
-make a student grade class
-put all students in a vector 
- fin average grade of students
*/


//1. makes student grade class
class Student_grade{
private:
    friend std::ostream &operator<<(std::ostream &os, const Student_grade &obj);
protected:
    std::string name;
    double grade;
public:
    Student_grade(std::string name_val, double grade_val)
        :name(name_val), grade(grade_val) {

        }
    ~Student_grade() {}

    std::string get_name() const {return name;}
    double get_grade() const {return grade;}

};


std::ostream &operator<<(std::ostream &os, const Student_grade &obj){
    os << "Name: " << obj.get_name() << "\t\tGrade:" << obj.get_grade() <<std::endl;
    return os;
}





//make a display_menu
void display_menu()  {
    std::cout<<"\t\t\t__________________________________________________________________________"<<std::endl;
    std::cout<<"\t\t\t|________________________________________________________________________|"<<std::endl;
    std::cout<<"\t\t\t|                                                                        |"<<std::endl;
    std::cout<<"\t\t\t|                        Student Grade Records                           |"<<std::endl;
    std::cout<<"\t\t\t|________________________________________________________________________|"<<std::endl;
    std::cout<<"\t\t\t|                                                                        |"<<std::endl;
    std::cout<<"\t\t\t|   1) Enter a Student Grade                                             |"<<std::endl;
    std::cout<<"\t\t\t|                                                                        |"<<std::endl;
    std::cout<<"\t\t\t|   2) Display Student Grades                                            |"<<std::endl;
    std::cout<<"\t\t\t|                                                                        |"<<std::endl;
    std::cout<<"\t\t\t|   3) Display Honor roll                                                |"<<std::endl;
    std::cout<<"\t\t\t|                                                                        |"<<std::endl;
    std::cout<<"\t\t\t|   4) Exit Program                                                      |"<<std::endl;
    std::cout<<"\t\t\t|________________________________________________________________________|\n\n"<<std::endl;
}




//make a function that creates a Student grade obj
Student_grade create_Student_grade() {
    std::string name;
    double grade;

    std::cout<<"Enter a full name: ";
    std::getline(std::cin, name);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout<<"Enter a Grade: ";
    std::cin>> grade;

    //clear the input buffer

    //create object
    Student_grade temp_student_grade(name, grade);
    return temp_student_grade;

}



//create a function that displays student grade
void display_student_grades(const std::vector<Student_grade>& student_grade_vector){

    for(const auto& student: student_grade_vector){
        std::cout<< student <<std::endl;
    }
}


//display honoe roll
void display_honor_roll(std::vector<Student_grade>& student_grade_vector){
    std::cout<<"Honor Roll Students: "<<std::endl;
    for (const auto&student:student_grade_vector){
        if (student.get_grade() >= 90.0) {
            std::cout <<student <<std::endl;
        }
    }
}


//make a function to exit the program
void exit_program(){
    std::cout<<"Exiting program..."<<std::endl;
    exit(0);
}

int main() {
    bool is_running {true};
    //make a vector for student grade object
    std::vector<Student_grade> student_vector;
    //std::vector<Student_grade> honor_roll_vector;

    do{
    

        display_menu();
        int selection;
        std::cout<<"\n\t\t\t Enter a selection: ";
        std::cin>> selection;

        switch (selection) {
            case 1:
                std::cout<<"Enter a student grade"<<std::endl;
                student_vector.push_back(create_Student_grade());

                break;

            case 2:
                std::cout<<"Display Student grades"<<std::endl;
                display_student_grades(student_vector);
                break;

            case 3:
                std::cout<<"Display Honor roll"<<std::endl;
                break;

            case 4:
                std::cout<<"Exit"<<std::endl;
                exit_program();
                break;

            default:
                std::cout<<"Invalid selection..."<<std::endl;                                
        }

    }while(is_running);

    return 0;
}
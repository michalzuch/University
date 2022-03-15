#include <iostream>

using namespace std;

class CanDoResearch {
public:
    CanDoResearch() { cout << "I can do research." << endl; }
    void futureCDR() { cout << "My dream is to be a scientist." << endl; }
};

class CanTeach {
public:
    CanTeach() { cout << "I can teach." << endl; }
    void futureCT() { cout << "My dream is to be a professor." << endl; }
};

class TPerson {
protected:
    string name;
public:
    TPerson() { cout << "Hi!" << name << endl; }
    void whatName(string nameInput) {
        name = nameInput;
        cout << "I am " << name << endl;
    }
};

class CanBeStudent {
public:
    CanBeStudent() { cout << "I can be a student." << endl; }
    void futureCBS() { cout << "My dream is to change the world." << endl; }
};

class TResearchAssistant: public virtual TPerson, public CanDoResearch {
public:
    TResearchAssistant() { cout << "I am a research assistant." << endl; }
    void whatAssistantDoes() { cout << "Someday I will be doing research myself." << endl; }
};

class TTeacher: public virtual TPerson, public CanTeach {
protected:
    string name;
    string field;
public:
    TTeacher() { cout << "I am a teacher." << endl; }
    void whatTeacherDoes(string fieldInput) {
        field = fieldInput;
        cout << "I teach " << field << endl;
    }
};

class TStudent: public virtual TPerson, public CanBeStudent {
protected:
    string exam;
public:
    TStudent() { cout << "I'm a student." << endl; }
    void whatStudentDoes(string examInput) {
        exam = examInput;
        cout << "I should learn because soon there is " << exam << " exam." << endl;
    }
};

class TPhDStudent: public TStudent {
protected:
    string field;
public:
    TPhDStudent() { cout << "I am a PhD student." << endl; }
    void whatPhDDoes(string fieldInput) {
        field = fieldInput;
        cout << "I am developing myself in the " << field << endl;
    }
};

class TPhDStudentResearcher: public TResearchAssistant, public TPhDStudent {
protected:
    string science;
public:
    TPhDStudentResearcher() { cout << "I am PhD Student Researcher." << endl; }
    void whatPhDResearcherDoes(string scienceInput) {
        science = scienceInput;
        cout << "I do research on " << science << endl;
    }
};

class TPhDStudentTeacher: public CanTeach, public TPhDStudent {
protected:
    int group;
public:
    TPhDStudentTeacher() { cout << "I am a PhD student teacher." << endl; }
    void whatPhDDoesTeacher(int groupInput) {
        group = groupInput;
        cout << "I run classes in a group " << group << endl;
    }
};

int main() {
    
    cout << "--STUDENT---------------" << endl;
    TStudent student;
    student.whatName("Michael");
    student.futureCBS();
    student.whatStudentDoes("C++");
    cout << endl;

    cout << "--PhD STUDENT------------" << endl;
    TPhDStudent PhD;
    PhD.whatName("Nick");
    PhD.futureCBS();
    PhD.whatStudentDoes("Physics");
    PhD.whatPhDDoes("Biology");
    cout << endl;
    
    cout << "--PhD STUDENT TEACHER-----" << endl;
    TPhDStudentTeacher PhDTeacher;
    PhDTeacher.whatName("Mary");
    PhDTeacher.futureCBS();
    PhDTeacher.futureCT();
    PhDTeacher.whatStudentDoes("Logic");
    PhDTeacher.whatPhDDoes("Numeral Methods");
    PhDTeacher.whatPhDDoesTeacher(1);
    cout << endl;
    
    cout << "--TEACHER------------" << endl;
    TTeacher teacher;
    teacher.whatName("Nathan");
    teacher.futureCT();
    teacher.whatTeacherDoes("Math");
    cout << endl;
    
    cout << "--RESEARCH ASSISTANT--" << endl;
    TResearchAssistant assistant;
    assistant.whatName("Ann");
    assistant.futureCDR();
    assistant.whatAssistantDoes();
    cout << endl;
    
    cout << "--PHD STUDENT REASEARCHER-------" << endl;
    TPhDStudentResearcher PhDResearcher;
    PhDResearcher.whatName("Sofia");
    PhDResearcher.futureCBS();
    PhDResearcher.futureCDR();
    PhDResearcher.whatStudentDoes("Psychology");
    PhDResearcher.whatPhDDoes("Ecomonics");
    PhDResearcher.whatAssistantDoes();
    PhDResearcher.whatPhDResearcherDoes("artificial intelligence");
    cout << endl;
    
    return 0;
}

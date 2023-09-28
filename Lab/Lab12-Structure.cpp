/*
    จงเขียนฟังก์ชันการตัดเกรดในแต่ละรายวิชาของนักเรียนจำนวน 3 คน โดยนักเรียนแต่ละคนจะมีข้อมูลดังต่อไปนี้
    ชื่อ, นักศักศึกษา, คะแนนในวิชาที่ 1, คะแนนในวิชาที่ 2, คะแนนในวิชาที่ 3, คะแนนในวิชาที่ 4, คะแนนในวิชาที่ 5
    แสดงได้ดังโครงสร้างข้อมูลต่อไปนี้

    struct Student {
        char Name[20] ;
        char ID[5] ;
        float ScoreSub1 ;
        float ScoreSub2 ;
        float ScoreSub3 ;
        float ScoreSub4 ;
        float ScoreSub5 ;
    } typedef S ;

    Test Case:
        Enter the details of 3 students :
        Student 1:
        Name: 
            John Doe
        ID: 
            101
        Scores in Subject 1: 
            77
        Scores in Subject 2: 
            64
        Scores in Subject 3: 
            66
        Scores in Subject 4: 
            54
        Scores in Subject 5: 
            56

        Student 2:
        Name: 
            Jane Smith
        ID: 
            102
        Scores in Subject 1: 
            43
        Scores in Subject 2: 
            70
        Scores in Subject 3: 
            76
        Scores in Subject 4: 
            77
        Scores in Subject 5: 
            80

        Student 3:
        Name: 
            Mark Johnson
        ID: 
            103
        Scores in Subject 1: 
            77
        Scores in Subject 2: 
            74
        Scores in Subject 3: 
            76
        Scores in Subject 4: 
            81
        Scores in Subject 5: 
            69

    Output:
    Student Details:
    Student 1:
    Name: John Doe
    ID: 101
    Scores: 77 64 66 54 56
    Grades: B+  C C+ D  D+
    Average Scores: 63.4

    Student 2:
    Name: Jane Smith
    ID: 102
    Scores: 43 70 76 77 80
    Grades:  F  B B+ B+  A
    Average Scores: 69.2

    Student 3:
    Name: Mark Johnson
    ID: 103
    Scores: 77 74 76 81 69
    Grades: B+  B B+  A C+
    Average Scores: 75.4
*/

#include <stdio.h>

struct Student {
    char Name[30];
    char ID[14];
    float ScoreSub1;
    float ScoreSub2;
    float ScoreSub3;
    float ScoreSub4;
    float ScoreSub5;
} typedef S;

// ฟังก์ชันเพื่อคำนวณเกรด
char calculateGrade(float score) {
    if (score >= 85) return 'A+';
    else if (score >= 80) return 'A';
    else if (score >= 75) return 'B+';
    else if (score >= 70) return 'B';
    else if (score >= 65) return 'C+';
    else if (score >= 60) return 'C';
    else if (score >= 55) return 'D+';
    else if (score >= 50) return 'D';
    else return 'F';
}

int main() {
    S students[3];

    printf("Enter the details of 3 students:\n");

    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].Name);

        printf("ID: ");
        scanf("%s", students[i].ID);

        printf("Scores in Subject 1: ");
        scanf("%f", &students[i].ScoreSub1);

        printf("Scores in Subject 2: ");
        scanf("%f", &students[i].ScoreSub2);

        printf("Scores in Subject 3: ");
        scanf("%f", &students[i].ScoreSub3);

        printf("Scores in Subject 4: ");
        scanf("%f", &students[i].ScoreSub4);

        printf("Scores in Subject 5: ");
        scanf("%f", &students[i].ScoreSub5);
    }

    printf("\nStudent Details:\n");

    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].Name);
        printf("ID: %s\n", students[i].ID);
        printf("Scores: %.0f %.0f %.0f %.0f %.0f\n",
               students[i].ScoreSub1, students[i].ScoreSub2,
               students[i].ScoreSub3, students[i].ScoreSub4,
               students[i].ScoreSub5);

        printf("Grades: %c %c %c %c %c\n",
               calculateGrade(students[i].ScoreSub1),
               calculateGrade(students[i].ScoreSub2),
               calculateGrade(students[i].ScoreSub3),
               calculateGrade(students[i].ScoreSub4),
               calculateGrade(students[i].ScoreSub5));

        float averageScore = (students[i].ScoreSub1 + students[i].ScoreSub2 +
                              students[i].ScoreSub3 + students[i].ScoreSub4 +
                              students[i].ScoreSub5) / 5.0;
        printf("Average Scores: %.1f\n\n", averageScore);
    }

    return 0;
}//end main function
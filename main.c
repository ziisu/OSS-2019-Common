#include "header.h"

int main(int argc, char** argv)
{
    // convert student id from string to integer
    int student_id = atoi(argv[1]);

    char student_name[100];
    int student_section;

    // open student info file
    FILE* fp;
    fp = fopen("student_info.txt", "r");

    // read student info until it finds the student_id
   
    // imepment you code here
    //fscanf(fp, "%s %s %s\n", buffer1, buffer2,buffer3);
    // hint: you can use fscanf(fp, "%s %s %s\n", buffer1, buffer2, buffer3)
    // hint: use atoi(str) function to convert string to integer
    //student_id = atoi(buffer1);
    // printf("There is no student with the student ID: %d", student_id);

     char buffer1[30];
     char buffer2[30];
     char buffer3[30];
     int temp;
     while(100)
     {
         temp = fscanf(fp, "%s %s %s\n", buffer1, buffer2, buffer3);
         if(student_id == atoi(buffer1))
         {
            //student_id = atoi(buffer1);
           // strcpy(student_name, buffer2);
            //student_section = atoi(buffer3);
           // break;

         }else
         {
            printf("There is no student with the student ID: %d", student_id);
            break;
         }
         
     if(temp<=0) break;
     }

    fclose(fp);

    // Print the (Mission 1) result
    printf("Student ID: %d, Name: %s, Section Number: %d\n", 
            student_id, student_name, student_section);

    
    // open section score
    if (student_section == 1)
    {
        fp = fopen("data//scores_section1.dat", "r");
    }
    else
    {
        fp = fopen("data//scores_section2.dat", "r");
    }
    
    // read scores and copy values to int array
    const int num_sec_students = 50;
    int sec_scores[num_sec_students];
    
    // implemnt you code here
    // hint: use fread() function to read binary file
    
    fclose(fp);

    // calculate mean and variance
    double sec_mean;
    double sec_var;
    // impement you code here

    // Print the (Mission 2) result
    printf("The average score and s.d of Section %d ", student_section);
    printf("are %.2f and %.2f, respectively.\n", sec_mean, sqrt(sec_var));

    // get student's score
    int student_score;
    // implement you code here
    // note that the student info and scores 
    // are sorted according to increasing order of student id

    // sort scores
    sortArray(sec_scores, num_sec_students);

    // find student's rank in the section
    int student_rank = findRank(student_score, sec_scores, num_sec_students);

    // Print the (Mission 3) result
    printf("The student's score is %d and the rank is %d in Section %d.\n",
        student_score, student_rank, student_section);

    return 0;
}

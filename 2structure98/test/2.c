#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int num;
    double score1, score2, quiz;
} Student;

void printStudents(Student* students, int n);
int searchStudent(Student* students, int n, char* searchName);

int main() {
    Student* students;
    int n;
    char fname[50];

    FILE* file = fopen("f2.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }

    fscanf(file,"%d", &n);
    students = (Student*)malloc(n * sizeof(Student));
	if (students == NULL) {
		return -1;
	}
    for (int i = 0; i < n; i++) {
		fscanf(file, "%s %lf %lf %lf", students[i].name, &students[i].score1, &students[i].score2, &students[i].quiz);
		students[i].num = i + 1;
	}
    printStudents(students, n);
    printf("\n");
    scanf("%s", fname);
    
    int s = searchStudent(students, n, fname);
    if(s != -1) {
        printf("%d %s %.1lf %.1lf %.1lf %.1lf\n", students[s].num, students[s].name, students[s].score1, students[s].score2, students[s].quiz, students[s].score1 + students[s].score2 + students[s].quiz);
    }
    else {
        return -1;
    }
    fclose(file);
    free(students);
	return 0;
}

void printStudents(Student* students, int n) {
    for(int i=0; i<n; i++) {
        printf("%d %s %.1lf %.1lf %.1lf %.1lf\n", students[i].num, students[i].name, students[i].score1, students[i].score2, students[i].quiz, students[i].score1 + students[i].score2 + students[i].quiz);
    }
}

int searchStudent(Student* students, int n, char* searchName) {
    for(int i=0; i<n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
			return i;
		}
    }
    return -1;
}
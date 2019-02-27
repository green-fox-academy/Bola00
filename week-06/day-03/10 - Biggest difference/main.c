#include <stdio.h>
#include <stdlib.h>

// You will write a program that keeps track of exam results.
// First, your program should ask the user how many classes took the exam. Let's say this number is N.
// Then you need to ask how many students took the exam in the first class. Let's say this number is M.
// You need to ask for the name of the class, the the exam results in percentage M times and store them.
// The number of students might be different for each class.
// You need to repeat this N times.
// Make sure you have a separate function that reads the data and returns it.

// Once you have the data write functions for the following questions:
// Which class has the biggest difference between the worst and best exam and how much is the difference?
// Which class has the best exam?
// What is the average of all the exams?

typedef struct
{
  int students;
  float *students_results;
  char class_name[20];
} class_t;

void biggest_difference(class_t classes[], int number_of_classes);

void best_class(class_t classes[], int number_of_classes);

float average (class_t classes[], int number_of_classes);

int main()
{
    int classcounter;
    printf("Number of classes:");
    scanf("%d", &classcounter);

    class_t classes[classcounter];

    for (int i = 0; i < classcounter; ++i) {
        printf("Name of the class:");
        scanf("%s", classes[i].class_name);
        printf("Number of students:");
        scanf("%i", &classes[i].students);
        printf("number of studs: %i\n", classes[i].students);
        classes[i].students_results = (float *) malloc(classes[i].students * sizeof(float));
        for (int j = 0; j < classes[i].students; j++) {
            printf("result of the %dth student:", j + 1);
            scanf("%f", &classes[i].students_results[j]);
        }

    }

    biggest_difference(classes, classcounter);
    best_class(classes, classcounter);
    printf("The average percentage is %.2f.", average(classes, classcounter));

    for (int k = 0; k < classcounter; ++k) {
        free(classes[k].students_results);
    }

    return 0;
}

void biggest_difference(class_t classes[], int number_of_classes)
{
    int class_index = 0;
    float difference = 0;

    for (int i = 0; i < number_of_classes; i++) {
        float current_smallest = 100;
        float current_biggest = 0;
        for (int j = 0; j < classes[i].students; j++) {

            if (classes[i].students_results[j] < current_smallest) {
                current_smallest = classes[i].students_results[j];
            }
            if (classes[i].students_results[j] > current_biggest) {
                current_biggest = classes[i].students_results[j];
            }
        }
        if (difference < (current_biggest - current_smallest)) {
            difference = current_biggest - current_smallest;
            class_index = i;
        }
    }
    printf("In the %s class is the biggest the difference with %.2f percentage.\n", classes[class_index].class_name,
           difference);
}

void best_class(class_t classes[], int number_of_classes)
{
    int class_index = 0;
    float best_average = 0;
    for (int i = 0; i < number_of_classes; i++) {
        float current_sum = 0;
        for (int j = 0; j < classes[i].students; j++) {
            current_sum += classes[i].students_results[j];
        }
        float current_avegage = current_sum / classes[i].students;
        if (best_average < current_avegage) {
            best_average = current_avegage;
            class_index = i;
        }
    }
    printf("The %s class was the best.\n", classes[class_index].class_name);
}

float average (class_t classes[], int number_of_classes)
{
    int students_counter = 0;
    float sum = 0;
    for (int i = 0; i < number_of_classes; i++) {
        for (int j = 0; j < classes[i].students; j++) {
            sum += classes[i].students_results[j];
            students_counter++;
        }
    }
    return sum / students_counter;
}
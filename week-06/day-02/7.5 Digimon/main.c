#include <stdio.h>
#include <string.h>

enum digivolution
{
  BABY,
  IN_TRAINING,
  ROCKYE,
  CHAMPION,
  ULTIMATE,
  MEGA
};

typedef struct
{
  char name[127];
  int age;
  int health;
  char tamer[255];
  enum digivolution level;
} digimon_t;

int get_minimum_health_index(digimon_t digimons[], int array_lenght)
{
    int index_of_smallest_health = 0;

    for (int i = 1; i < array_lenght; ++i) {
        if (digimons[i].health < digimons[index_of_smallest_health].health)
            index_of_smallest_health = i;
    }

    return index_of_smallest_health;
}

int get_same_digivolution_level_count(digimon_t digimons[], int array_lenght, enum digivolution checklevel)
{
    int counter = 0;

    for (int i = 0; i < array_lenght; ++i) {
        if (digimons[i].level == checklevel)
            counter++;
    }
    return
        counter;
}

int get_same_tamer_count(digimon_t digimons[], int array_lenght, char tamer_name[])
{
    int counter = 0;

    for (int i = 0; i < array_lenght; ++i) {
        if (strcmp (digimons[i].tamer, tamer_name) == 0)
            counter++;
    }
    return
        counter;
}

int get_average_health_of_the_same_tamer(digimon_t digimons[], int array_lenght, char tamer_name[])
{
    int counter = 0;
    int health = 0;

    for (int i = 0; i < array_lenght; ++i) {
        if (strcmp (digimons[i].tamer, tamer_name) == 0) {
            counter++;
            health += digimons[i].health;
        }
    }
    if (counter == 0)
        return 0;

    return health / counter;

}
int main()
{
    digimon_t digimon1;
    digimon_t digimon2;
    digimon_t digimon3;

    digimon1.health = 80;
    digimon2.health = 23;
    digimon3.health = 99;

    strcpy(digimon1.tamer, "Ash");
    strcpy(digimon2.tamer, "Yugi");
    strcpy(digimon3.tamer, "Yugi");

    strcpy(digimon1.name, "Megaman");
    strcpy(digimon2.name, "Optimus Prime");
    strcpy(digimon3.name, "Super Mario");

    digimon1.level = ROCKYE;
    digimon2.level = ROCKYE;
    digimon3.level = ULTIMATE;

    digimon_t digimons[] = {digimon1, digimon2, digimon3};
    int lenght = sizeof(digimons) / sizeof(*digimons);

    printf("%s is least healthy digimon. \n", digimons[get_minimum_health_index(digimons, lenght)].name);
    printf("%i pokemon is on ROCKYE level.\n", get_same_digivolution_level_count(digimons, lenght, ROCKYE));
    printf("Yugi has %i bakugan.\n", get_same_tamer_count(digimons, lenght, "Yugi"));
    printf("Yugi's pikachus have %i average health.", get_average_health_of_the_same_tamer(digimons, lenght, "Yugi"));
    return 0;
}
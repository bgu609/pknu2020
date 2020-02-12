/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.12
  writer - BGW.
*/

#include <stdio.h>
#include <stdlib.h>
#include "parson.h"



void json_read();
void json_write(void);



/*--------------------------*/



// 메인함수
int main(void) 
{
    json_read();
    json_write();

	system("pause");
	return EXIT_SUCCESS;
}



/*--------------------------*/



void json_read(void)
{
    JSON_Value* rootValue;
    JSON_Object* rootObject;

    rootValue = json_parse_file("package.json");
    rootObject = json_value_get_object(rootValue);

    printf("name : %s\n", json_object_get_string(rootObject, "name"));
    printf("version : %s\n", json_object_get_string(rootObject, "version"));
    printf("repo : %s\n", json_object_get_string(rootObject, "repo"));
    printf("description : %s\n", json_object_get_string(rootObject, "description"));

    printf("keywords: [ ");
    JSON_Array* keywords = json_object_get_array(rootObject, "keywords");
    for (int i = 0; i < (int) json_array_get_count(keywords); i++)
    {
        printf(" %s ", json_array_get_string(keywords, i));
    }
    printf(" ]\n");

    printf("license : %s\n", json_object_get_string(rootObject, "license"));

    printf("src:\n");
    JSON_Array* src = json_object_get_array(rootObject, "src");
    for (int i = 0; i < (int) json_array_get_count(src); i++)
    {
        printf("  %s\n", json_array_get_string(src, i));
    }

    printf("temp : %.1lf\n", json_object_get_number(rootObject, "temp"));

    /*
    printf("Title : %s\n",json_object_get_string(rootObject,"Title"));

    printf("Year : %d\n", (int)json_object_get_number(rootObject,"Year"));
    printf("Runtime : %d min\n", (int)json_object_get_number(rootObject, "Runtime"));

    printf("Genre : %s\n", json_object_get_string(rootObject, "Genre"));
    printf("Director : %s\n", json_object_get_string(rootObject, "Director"));

    printf("Actors:\n");

    JSON_Array* array = json_object_get_array(rootObject, "Actors");
    for (int i = 0; i < json_array_get_count(array); i++)
    {
        printf("  %s\n", json_array_get_string(array, i));
    }
    */

    json_value_free(rootValue);
}

void json_write(void)
{

}
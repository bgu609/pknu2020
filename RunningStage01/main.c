/*
  filename - main.cpp
  version - 1.0
  description - Text File Reader
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - GW B.


  ���� �����õ� ��ȹ :
  * ���� txt���� ��� �迭 �ʱ�ȭ �� ������� �˻� ����
  * main�Լ��� for�� �Լ�ȭ
  * ���ŵ� txt �б� �Ұ� �ڸ�Ʈ �۵� (�ϴ� �ذ�)
  * ��� C6262: �Լ��� <constant > ����Ʈ�� ������ ��� �մϴ�./analyze: stacksize <constant 2 >�� �ʰ� �մϴ�. �Ϻ� �����͸� ������ �̵� �ϴ� ���� �����ϴ�.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <windows.h>



struct CompareArray { char name[512]; }; // �ߺ� �˻� ����ü
struct _finddata_t FileData; // _finddata_t ����ü FileData ����

char BasePath[512] = { "D:\\documents\\" }; // �⺻ ��� ����

struct CompareArray Array[512] = { 0 }; // name �����

int FileCheck(char* TargetPath);
int txtCheck(char* BaseTxtPath);
void txt_Read(char* TargetPath, char* TargetName);

/*----------------------------- �����Լ�-----------------------------------------------------------*/

int main(void)
{
    char BaseTxtPath[517];
    char TargetPath[512]; // Ÿ�� ��� ����
    char TargetName[512]; // Ÿ�� �̸�

    int FCResult; // ���� �ĺ� ����
    int txtResult; // txt ���� �ĺ� ����
    int Nexttxt = 1; // txt �ĺ���, ���� txt �˻� ���� ���� �ʱ�ȭ


    int ChangeResult; // �񱳰˻� ���

    strcpy(TargetPath, BasePath); // ���� ��θ� BasePath�� ����

    strcpy(BaseTxtPath, BasePath); // BasePath ��� txt ���� �ĺ���
    strcat(BaseTxtPath, "*.txt");

    struct CompareArray GetArray[512] = { 0 }; // name ���ſ� ����ü �迭


    while (1)
    {
        FCResult = FileCheck(TargetPath); // ���� �ĺ�
        if (FCResult == 1)
        {
            txtResult = txtCheck(BaseTxtPath); // txt ���� �ĺ� ( ���⼭ ù��° txt ���� ������ FileData�� ���� )

            if (txtResult != -1) // txt ���� �ĺ��� ����
            {
                for (int i = 0; i < 512; i++)
                {
                    strcpy(GetArray[i].name, FileData.name); // FileData�κ��� name ����

                    ChangeResult = strcmp(GetArray[i].name, Array[i].name); // ���ŵ� name ��

                    if (ChangeResult != 0)
                    {
                        printf("������� ������. ");
                        printf("( %s ---> %s )\n\n", Array[i].name, GetArray[i].name);
                        strcpy(TargetName, GetArray[i].name);

                        txt_Read(TargetPath, TargetName); // txt ���ϳ��� ǥ��

                        strcpy(TargetPath, BasePath); // ���� ã��� �����̸��� �߰��� �������� ���� ����
                    }

                    if (ChangeResult == 0)
                    {
                        printf("%s : ������� �������� ����.\n\n", Array[i].name);
                    }

                    Nexttxt = _findnext(txtResult, &FileData);

                    if ((Nexttxt == -1)) // �� �̻� ������ txt ������ ���ٸ�
                    {
                        if (strlen(Array[i + 1].name) != 0)
                        {
                            printf("������� ������. ");
                            printf("( %s ---> %s )\n\n", Array[i + 1].name, GetArray[i + 1].name);
                            strcpy(TargetName, Array[i + 1].name);

                            txt_Read(TargetPath, TargetName); // txt ���ϳ��� ǥ��

                            strcpy(TargetPath, BasePath); // ���� ã��� �����̸��� �߰��� �������� ���� ����
                        }
                        i = 512; // ī��Ʈ�� ���� ����
                    }
                }

                _findclose(txtResult);

                memcpy(Array, GetArray, sizeof(GetArray)); // ���ŵ� txt ����� ����
            }
        }
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*\n\n");

        Sleep(2000);
        main();
    }

    system("pause");
    return EXIT_SUCCESS;
}


/*-------------------------------------------------------------------------------------------------*/


int FileCheck(char* TargetPath) // ���� �ĺ� �Լ�
{
    int FCResult = 1; // ���� �ĺ� ����

    int FileSearch = _access(TargetPath, 0); // ��� ������ ���� ����, mode 0' (�����̸� 0, �����̸� -1)
    if (FileSearch == -1) // ���(����) ������
    {
        printf("��ΰ� �ĺ����� ����.\n");
        FCResult = -1;
    }

    return FCResult; // ���� �ĺ� ��� ��ȯ
}

int txtCheck(char* BaseTxtPath) // txt ���� �ĺ� �Լ�
{
    long TxtSearch;

    TxtSearch = _findfirst(BaseTxtPath, &FileData); // Ÿ�� ���� ������ txt���� ã��, ���� ������ FileData�� ��ȯ
    //-----------------------------------------
    if (TxtSearch == -1) // ���� txt���� ������
    {
        printf("txt ������ �ĺ����� ����.\n");
    }
    //-----------------------------------------

    return TxtSearch; // ���� �ĺ� ��� ��ȯ
    _findclose(TxtSearch);
}


void txt_Read(char* TargetPath, char* TargetName) // txt read,��� �Լ�
{
    //strcpy(TargetName, FileData.name); // �̸� ����
    strcat(TargetPath, TargetName); // ���� ��ο� �̸� ����
    printf("���ϸ� : %s\n", TargetName); // �˻��� ���� �̸� ���
    printf("���� ��� : %s\n", TargetPath); // �˻��� ���� ��� ���

    //---------------------------------
    char ReadTxtUnit;
    FILE* fp = fopen(TargetPath, "rt"); // ������ ����� Ư�� ������ �о����

    if (fp == NULL) // �б� ���н� ����
    {
        printf("\ntxt ���� �б� ����!\n\n");
        return;
    }
    else
    {
        printf("���� :\n"); // ������ ���� ��� ����
    }

    while (1)
    {
        ReadTxtUnit = fgetc(fp); // ���� �����ͷ� ���� ȹ�� (ȣ���� ������ ���������� �۵�)
        putchar(ReadTxtUnit); // int Ÿ���� char Ÿ������ ��ȯ �� ���

        if (ReadTxtUnit == EOF) // ���� ��� ��½� ����
        {
            printf("\n\n\n");
            break;
        }
    }

    fclose(fp);
}
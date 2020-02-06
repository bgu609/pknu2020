/*
  filename - main.cpp
  version - 1.0
  description - Text File Reader
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - GW B.


  다음 수정시도 계획 :
  * 최초 txt파일 목록 배열 초기화 후 변경사항 검사 시작
  * main함수의 for항 함수화
  * 제거된 txt 읽기 불가 코멘트 작동 (일단 해결)
  * 경고 C6262: 함수는 <constant > 바이트의 스택을 사용 합니다./analyze: stacksize <constant 2 >를 초과 합니다. 일부 데이터를 힙으로 이동 하는 것이 좋습니다.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <windows.h>



struct CompareArray { char name[512]; }; // 중복 검사 구조체
struct _finddata_t FileData; // _finddata_t 구조체 FileData 생성

char BasePath[512] = { "D:\\documents\\" }; // 기본 경로 지정

struct CompareArray Array[512] = { 0 }; // name 저장용

int FileCheck(char* TargetPath);
int txtCheck(char* BaseTxtPath);
void txt_Read(char* TargetPath, char* TargetName);

/*----------------------------- 메인함수-----------------------------------------------------------*/

int main(void)
{
    char BaseTxtPath[517];
    char TargetPath[512]; // 타겟 경로 변수
    char TargetName[512]; // 타겟 이름

    int FCResult; // 파일 식별 여부
    int txtResult; // txt 파일 식별 여부
    int Nexttxt = 1; // txt 식별시, 다음 txt 검사 진행 여부 초기화


    int ChangeResult; // 비교검사 결과

    strcpy(TargetPath, BasePath); // 최초 경로를 BasePath로 지정

    strcpy(BaseTxtPath, BasePath); // BasePath 기반 txt 파일 식별용
    strcat(BaseTxtPath, "*.txt");

    struct CompareArray GetArray[512] = { 0 }; // name 갱신용 구조체 배열


    while (1)
    {
        FCResult = FileCheck(TargetPath); // 파일 식별
        if (FCResult == 1)
        {
            txtResult = txtCheck(BaseTxtPath); // txt 파일 식별 ( 여기서 첫번째 txt 파일 정보가 FileData로 저장 )

            if (txtResult != -1) // txt 파일 식별시 실행
            {
                for (int i = 0; i < 512; i++)
                {
                    strcpy(GetArray[i].name, FileData.name); // FileData로부터 name 갱신

                    ChangeResult = strcmp(GetArray[i].name, Array[i].name); // 갱신된 name 비교

                    if (ChangeResult != 0)
                    {
                        printf("변경사항 감지됨. ");
                        printf("( %s ---> %s )\n\n", Array[i].name, GetArray[i].name);
                        strcpy(TargetName, GetArray[i].name);

                        txt_Read(TargetPath, TargetName); // txt 파일내용 표시

                        strcpy(TargetPath, BasePath); // 다음 찾기시 파일이름이 추가로 더해지는 문제 방지
                    }

                    if (ChangeResult == 0)
                    {
                        printf("%s : 변경사항 감지되지 않음.\n\n", Array[i].name);
                    }

                    Nexttxt = _findnext(txtResult, &FileData);

                    if ((Nexttxt == -1)) // 더 이상 갱신할 txt 파일이 없다면
                    {
                        if (strlen(Array[i + 1].name) != 0)
                        {
                            printf("변경사항 감지됨. ");
                            printf("( %s ---> %s )\n\n", Array[i + 1].name, GetArray[i + 1].name);
                            strcpy(TargetName, Array[i + 1].name);

                            txt_Read(TargetPath, TargetName); // txt 파일내용 표시

                            strcpy(TargetPath, BasePath); // 다음 찾기시 파일이름이 추가로 더해지는 문제 방지
                        }
                        i = 512; // 카운트로 강제 종료
                    }
                }

                _findclose(txtResult);

                memcpy(Array, GetArray, sizeof(GetArray)); // 갱신된 txt 목록을 저장
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


int FileCheck(char* TargetPath) // 파일 식별 함수
{
    int FCResult = 1; // 파일 식별 여부

    int FileSearch = _access(TargetPath, 0); // 경로 접근후 존재 조사, mode 0' (정상이면 0, 에러이면 -1)
    if (FileSearch == -1) // 경로(폴더) 없을시
    {
        printf("경로가 식별되지 않음.\n");
        FCResult = -1;
    }

    return FCResult; // 파일 식별 결과 반환
}

int txtCheck(char* BaseTxtPath) // txt 파일 식별 함수
{
    long TxtSearch;

    TxtSearch = _findfirst(BaseTxtPath, &FileData); // 타겟 폴더 내에서 txt파일 찾기, 파일 정보는 FileData로 반환
    //-----------------------------------------
    if (TxtSearch == -1) // 읽을 txt파일 없을시
    {
        printf("txt 파일이 식별되지 않음.\n");
    }
    //-----------------------------------------

    return TxtSearch; // 파일 식별 결과 반환
    _findclose(TxtSearch);
}


void txt_Read(char* TargetPath, char* TargetName) // txt read,출력 함수
{
    //strcpy(TargetName, FileData.name); // 이름 저장
    strcat(TargetPath, TargetName); // 폴더 경로에 이름 결합
    printf("파일명 : %s\n", TargetName); // 검색한 파일 이름 출력
    printf("파일 경로 : %s\n", TargetPath); // 검색한 파일 경로 출력

    //---------------------------------
    char ReadTxtUnit;
    FILE* fp = fopen(TargetPath, "rt"); // 지정된 경로의 특정 파일을 읽어오기

    if (fp == NULL) // 읽기 실패시 종료
    {
        printf("\ntxt 파일 읽기 실패!\n\n");
        return;
    }
    else
    {
        printf("내용 :\n"); // 성공시 내용 출력 시작
    }

    while (1)
    {
        ReadTxtUnit = fgetc(fp); // 파일 포인터로 문자 획득 (호출할 때마다 순차적으로 작동)
        putchar(ReadTxtUnit); // int 타입을 char 타입으로 변환 후 출력

        if (ReadTxtUnit == EOF) // 내용 모두 출력시 종료
        {
            printf("\n\n\n");
            break;
        }
    }

    fclose(fp);
}
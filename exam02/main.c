/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.14
  writer - BGW.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Card {
    int card_num;
    char kor_name[40];
    char phone[15];
    char e_mail[40];
} Card;

int input_business_card(Card* List, int save_num);
void show_cards(Card* List);
void search_business_card(Card* List);
void edit_business_card(Card* List, int edit_num);
int delete_card(Card* List, int delete_num);

// 메인함수
int main(void)
{
    Card Card_List[50];
    Card* save_point;
    Card* show_point;

    int menu = 0;
    int save_num = 0;
    int search = 0;

    printf("================================= 메뉴 ==================================\n");
    printf("== (1) 입력 / (2) 수정 / (3) 삭제 / (4) 전체출력 / (5) 검색 / (6) 종료 ==\n");

    while (menu != 6)
    {
        save_point = &Card_List[save_num];

        printf("\n명령 입력 : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("\n== (1) 입력 ==\n");
            save_num = input_business_card(save_point, save_num);

            for (int i = 0; i < (save_num-1); i++)
            {
                printf("%s : %s\n", Card_List[i].kor_name, Card_List[save_num-1].kor_name); // debuging
                if ((Card_List[i].kor_name == Card_List[save_num-1].kor_name) && (Card_List[i].phone == Card_List[save_num-1].phone))
                {
                    printf("이미 존재하는 명함입니다!\n");
                    save_num = delete_card(&Card_List[save_num], save_num);
                    break; 
                }
            }

            break;

        case 2:
            printf("\n== (2) 수정 ==\n");
            printf("명함 번호 입력 : ");
            scanf("%d", &search);
            show_point = &Card_List[search - 1];

            if (search > save_num)
            {
                printf("저장되지 않은 명함입니다!\n");
                break;
            }
            edit_business_card(show_point, search - 1);

            break;

        case 3:
            printf("\n== (3) 삭제 ==\n");

            for (int i = 0; i < save_num; i++)
            {
                show_point = &Card_List[i];
                show_cards(show_point);
            }
            
            printf("삭제할 명함 번호 입력 : ");
            scanf("%d", &search);
            show_point = &Card_List[search - 1];

            if (search > save_num)
            {
                printf("저장되지 않은 명함입니다!\n");
                break;
            }
            save_num = delete_card(&Card_List[save_num], save_num);

            break;

        case 4:
            printf("\n== (4) 전체출력 ==\n");

            for (int i = 0; i < save_num; i++)
            {
                show_point = &Card_List[i];
                show_cards(show_point);
            }

            break;

        case 5:
            printf("\n== (5) 검색 ==\n");
            printf("명함 번호 입력 : ");
            scanf("%d", &search);
            show_point = &Card_List[search - 1];

            if (search > save_num)
            {
                printf("저장되지 않은 명함입니다!\n");
                break;
            }
            search_business_card(show_point);

            break;

        case 6:
            printf("\n== (6) 종료 ==\n");
            break;

        default:
            printf("지원하지 않는 명령입니다.\n");
        }
    }

    system("pause");
    return EXIT_SUCCESS;
}

int input_business_card(Card* List, int save_num)
{
    List->card_num = save_num + 1;
    printf("한글 이름을 입력하세요 : ");
    scanf_s("%s", List->kor_name, sizeof(char) * 40);
    printf("휴대전화 번호를 입력하세요 : ");
    scanf_s("%s", List->phone, sizeof(char) * 15);
    printf("이메일을 입력하세요 : ");
    scanf_s("%s", List->e_mail, sizeof(char) * 40);

    save_num += 1;

    return save_num;
}

void show_cards(Card* List)
{
    printf("[%d] 이름 : %s, 전화번호 : %s, 이메일 : %s\n", List->card_num, List->kor_name, List->phone, List->e_mail);
}

void search_business_card(Card* List)
{
    show_cards(List);

    printf("\n================================= 메뉴 ==================================\n");
    printf("== (1) 입력 / (2) 수정 / (3) 삭제 / (4) 전체출력 / (5) 검색 / (6) 종료 ==\n");
}

void edit_business_card(Card* List, int edit_num)
{
    input_business_card(List, edit_num);
}

int delete_card(Card* List, int delete_num)
{
    List->card_num = NULL;
    //strcpy(List->kor_name, '\0');
    //strcpy(List->phone, '\0');
    //strcpy(List->e_mail, '\0');
    delete_num = delete_num - 1;

    return delete_num;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{

    //Variales
    char answer[3], option[15], text[100], decodedText[100], AlbertiStyleText[100];
    int numberOption, i, j, k, l, m, letter = 97;


    printf("Bienvenido al Cifrado de Alberti\n\n");
    do
    {
        printf("Elija una opcion:\n1.-Codificar\n2.-Decodificar\n3.-Salir\n");
        do
        {
            fflush(stdin);
            gets(option);
            if(strcmp("1",option) != 0 && strcmp("2",option) != 0 && strcmp("3",option) != 0)
                printf("Error %s nos es una respuesta valida, elija entre las opciones 1, 2 y 3\n\a",option);
        }while((strcmp("1",option) != 0 && strcmp("2",option) != 0 && strcmp("3",option) != 0));

        //Casting values
        if(strcmp("1",option) == 0)
        {
           numberOption = 1;
        }
        if(strcmp("2",option) == 0)
        {
           numberOption = 2;
        }
        if(strcmp("3",option) == 0)
        {
           numberOption = 3;
        }


        //Alphabet for general use ORGANIZED
        /*
        int alphabet[30];
        int numberIndex = 1;

        for(i = 0; i < 30; i++)
        {
            if(i < 26)
            {
                alphabet[i] = letter;
                letter++;
            }
            else
            {
                alphabet[i] = numberIndex;
                numberIndex++;
            }
        }
        */

        //Outter "Original"" alphabet (like really, the original one)
        int originalAlpha[24] = {65, 66, 67, 68, 69, 70, 71, 73, 76, 77, 78, 79, 80, 81, 82, 83, 84, 86,88, 90, 49, 50, 51, 52};
        

        //printf("\n");

        //Inner "tangled" alphabet
        int weirdAlpha[24] = {97, 99, 101, 103, 107, 108, 110, 112, 114, 116, 118, 122, 38, 120, 121, 115, 111, 109, 113, 105, 104, 102, 100, 98};
        

        //Print alphabet array for testing purpouses
        /*
        for(i = 0; i < 30; i++)
        {
            if(i < 26)
            {
                printf("%c ",alphabet[i]);
            }
            else
            {
                printf("%d ",alphabet[i]);            
            }
        }
        */


        //Different options
        switch(numberOption)
        {
            case 1:

            //Clear all the rubish from albertText
            for(i = 0; i < 100; i++)
            {
                text[i] = NULL;
            }

            system("clear");
            printf("\nCodificar\n\nIngresa el texto en mayusculas:\n\n");
            fflush(stdin);
            gets(text);

            //In case the user it's an asshole we turn the lower case into upper case
            int turnIt = 0;
            for(i = 0; i < 100; i++)
            {
                if(text[i] >= 97 && text[i] <=122)
                {
                    text[i] = (text[i] - 32);
                    turnIt = 1;
                }
            }
            if(turnIt == 1)
            {
                printf("\n¬¬ Te dije MAYUSCULAS, pero bueno lo haré por ti, al cliente lo que pida\n");
            }

            //First we need to change the text from traditional to Alberti style (withiout the resticted letters)
            int albertText[100];
            int change = 0, indexAlberti = 0;

            //Clear all the rubish from albertText
            for(i = 0; i < 100; i++)
            {
                albertText[i] = NULL;
            }

            for(i = 0;  i < 100; i++)
            {
                change = 0;
                //If the value it's a H'
                if(text[i] == 72)
                {
                    albertText[indexAlberti] = 70;
                    albertText[indexAlberti+1] = 70;
                    change = 1;
                    indexAlberti++;
                }
                //If the value it's a J'
                if(text[i] == 74)
                {
                    albertText[indexAlberti] = 73;
                    albertText[indexAlberti+1] = 73;
                    change = 1;
                    indexAlberti++;
                }
                //If the value it's a K'
                if(text[i] == 75)
                {
                    albertText[indexAlberti] = 81;
                    albertText[indexAlberti+1] = 81;
                    change = 1;
                    indexAlberti++;
                }
                //If the value it's a U'
                if(text[i] == 85)
                {
                    albertText[indexAlberti] = 86;
                    albertText[indexAlberti+1] = 86;
                    change = 1;
                    indexAlberti++;
                }
                //If the value it's a W'
                if(text[i] == 87)
                {
                    albertText[indexAlberti] = 88;
                    albertText[indexAlberti+1] = 88;
                    change = 1;
                    indexAlberti++;
                }
                //If the value it's a Y'
                if(text[i] == 89)
                {
                    albertText[indexAlberti] = 90;
                    albertText[indexAlberti+1] = 90;
                    change = 1;
                    indexAlberti++;
                }
                //If neither
                if(change == 0)
                {
                    if(text[i] != 32)
                    {
                        albertText[indexAlberti] = text[i];
                    }
                }
                indexAlberti++;
            }

            //Print AlbertiText
            printf("\nTexto original en estilo Alberti\n\n");
            for(i = 0; i < 100; i++)
            {
                printf("%c",albertText[i]);
            }

            //Pivot for original aphabet
            srand(time(NULL));
            int randOriginal = rand() % (23 + 1 - 0) + 0;
            //printf("\nOriginal:%d\n",(randOriginal+1));

            //Pivot for inner circle
            int randAlbert = rand() % (23 + 1 - 0) + 0;
            //printf("\nAlberti:%d\n",(randAlbert+1));
            
            //Eliminate if you want full random, else, leave this to sing always k
            randAlbert = 4;

            //Save values to decode
            int orig = randOriginal, alb = randAlbert;

            printf("\n\nLos pivotes son los siguientes:\nCirculo externo: %c\nCirculo interno: %c\n\n",originalAlpha[randOriginal], weirdAlpha[randAlbert]);

            //Array arraged with the pivots
            int encodeAlberti[24];
            int position = 0;
            for(i = 0; i < 24; i++)
            {
                if((randOriginal-randAlbert) < 0)
                {
                    position = (randAlbert+(24+(randOriginal-randAlbert)));
                    if(position >= 24)
                    {
                        position = position - 24;
                    }
                    encodeAlberti[position] = weirdAlpha[randAlbert];
                }
                else
                {
                    encodeAlberti[randOriginal] = weirdAlpha[randAlbert]; 
                }
                randAlbert++;
                randOriginal++;
                if(randAlbert >= 24)
                {
                    randAlbert = 0;
                }
                if(randOriginal >= 24)
                {
                    randOriginal = 0;
                }
            }

            //Encode text
            printf("El texto codificado es:\n\n%c",originalAlpha[orig]);
            for(i = 0; i < 100; i++)
            {
                for(j = 0;  j < 24; j++)
                {
                    if(albertText[i] == originalAlpha[j])
                    {
                        printf("%c",encodeAlberti[j]);
                        break;
                    }
                }
            }
            
            printf("\n\nSe utilizó la siguiente combinacion de la rueda:\n\n");

            //Print static (outter) alphabet
            for(i = 0; i < 24; i++) //(sizeof (originalAlpha) /sizeof (originalAlpha[0]))
            {
                printf("%c ",originalAlpha[i]);
            }
            printf("\n\n");

            //Print movil (inner) alphabet
            for(i = 0; i < 24; i++) //(sizeof (originalAlpha) /sizeof (originalAlpha[0]))
            {
                printf("%c ",encodeAlberti[i]);
            }

            break;

            case 2:

            //int decodedText[100];

            //Clear all the rubish from albertText
            for(i = 0; i < 100; i++)
            {
                text[i] = NULL;
                decodedText[i] = NULL;
                AlbertiStyleText[i] = NULL;
            }

            //system("clear");
            printf("Decodificar\n\nIngresa el texto:\n\n");
            fflush(stdin);
            gets(text);

            printf("\nEl texto decodificado en estilo Alberti es:\n\n");

            //Start decoding
            int decodeAlberti[24];
            int positionPointer = 0;
            //int outterCircle = , innerCircle = 4;
            int foundIt = 0, pivotK = 4;
            for(i = 0; i < 100; i++)
            {
                if(text[i] >= 65 && text[i] <= 90 || text[i] >= 49 && text[i] <= 52)
                {
                    //We found a pivot, we need to rearrage the array, but first we find the position in the letter in the original aphabet array
                    for(j = 0; j < 24; j++)
                    {
                        if(text[i] == originalAlpha[j])
                        {
                            foundIt = j;
                            break;
                        }
                    }
                    
                    //Now we move the circle
                    for(k = 0; k < 24; k++)
                    {
                        if((foundIt- pivotK) < 0)
                        {
                            positionPointer = (pivotK+(24+(foundIt-pivotK)));
                            if(positionPointer >= 24)
                            {
                                positionPointer = positionPointer - 24;
                            }
                            decodeAlberti[positionPointer] = weirdAlpha[pivotK];
                        }
                        else
                        {
                            decodeAlberti[foundIt] = weirdAlpha[pivotK]; 
                        }
                        pivotK++;
                        foundIt++;
                        if(pivotK >= 24)
                        {
                            pivotK = 0;
                        }
                        if(foundIt >= 24)
                        {
                            foundIt = 0;
                        }
                    }

                }
                else
                {
                    for(l = 0; l < 24; l++)
                    {
                        //printf("La letra %c es igual a %c?\n",text[i],decodeAlberti[l]);
                        if(text[i] == decodeAlberti[l])
                        {
                            printf("%c",originalAlpha[l]);
                            break;
                        }
                    }
                if(text[i] != NULL)
                {
                    AlbertiStyleText[i] = originalAlpha[l];
                }
                }
            }

            //This is kind of extra but oh well, we transform Alberti's connotation to normal (the the letters H, J, K, U, W and Y exist)
            int regularText[100];
            int changeIt = 0, indexNormal = 0;

            //Clear all the rubish from albertText
            for(i = 0; i < 100; i++)
            {
                regularText[i] = NULL;
            }

            for(i = 0;  i < 100; i++)
            {
                changeIt = 0;
                //If the value it's a H'
                if(AlbertiStyleText[i] == 70 && AlbertiStyleText[i+1] == 70)
                {
                    regularText[indexNormal] = 72;
                    changeIt = 1;
                    indexNormal++;
                    i++;
                }
                //If the value it's a J'
                if(AlbertiStyleText[i] == 73 && AlbertiStyleText[i+1] == 73)
                {
                    regularText[indexNormal] = 74;
                    changeIt = 1;
                    indexNormal++;
                    i++;
                }
                //If the value it's a K'
                if(AlbertiStyleText[i] == 81 && AlbertiStyleText[i+1] == 81)
                {
                    regularText[indexNormal] = 75;
                    changeIt = 1;
                    indexNormal++;
                    i++;
                }
                //If the value it's a U'
                if(AlbertiStyleText[i] == 86 && AlbertiStyleText[i+1] == 86)
                {
                    regularText[indexNormal] = 85;
                    changeIt = 1;
                    indexNormal++;
                    i++;
                }
                //If the value it's a W'
                if(AlbertiStyleText[i] == 88 && AlbertiStyleText[i+1] == 88)
                {
                    regularText[indexNormal] = 87;
                    changeIt = 1;
                    indexNormal++;
                    i++;
                }
                //If the value it's a Y'
                if(AlbertiStyleText[i] == 90 && AlbertiStyleText[i+1] == 90)
                {
                    regularText[indexNormal] = 89;
                    changeIt = 1;
                    indexNormal++;
                    i++;
                }
                //If neither
                if(changeIt == 0)
                {
                    if(AlbertiStyleText[i] != NULL)
                    {
                        regularText[indexNormal] = AlbertiStyleText[i];
                    }
                }
                        indexNormal++;
            }

             //Print AlbertiText
            printf("\n\nTexto original puro\n\n");
            for(i = 0; i < 100; i++)
            {
                printf("%c",regularText[i]);
            }




            printf("\n\nSe utilizó la siguiente combinacion de la rueda:\n\n");

                    //Print static (outter) alphabet
                    for(m = 0; m < 24; m++) //(sizeof (originalAlpha) /sizeof (originalAlpha[0]))
                    {
                        printf("%c ",originalAlpha[m]);
                    }
                    printf("\n\n");

                    //Print movil (inner) alphabet
                    for(m = 0; m < 24; m++) //(sizeof (originalAlpha) /sizeof (originalAlpha[0]))
                    {
                        printf("%c ",decodeAlberti[m]);
                    }

            printf("\n");



            break;

            case 3:

            //system("clear");
            printf("Saliendo...\n\n");
            getchar();

            break;
        }

        //Start over
        if(strcmp("3",option) != 0)// && numberOption != 3)
        {
            printf("\n\nQuieres codificar/decodificar algo mas? \nSi = 1 \nNo = 2\n");
            do
            {
                fflush(stdin);
                gets(answer);
                if(strcmp("1",answer) != 0 && strcmp("2",answer) != 0)
                    printf("Error %s nos es una respuesta valida, conteste Si = 1 o No = 2\n\a",answer);
            }while(strcmp("1",answer) != 0 && strcmp("2",answer));
            system("clear");
        }
        if(strcmp("2",answer) == 0)
        {
            printf("Saliendo...\n\n");
            getchar();
        }

    }while(strcmp("1",answer) == 0 && numberOption != 3);
}
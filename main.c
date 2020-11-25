#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Zvierata{
    char meno[50];
    char druh[30];
    int vyska;
    double vaha;
    long datum;
    long datumKrmenia;
    char menoOsetrovatela[50];
    struct Zvierata *next;
};
typedef struct Zvierata zvierata_t;


zvierata_t *aloccStruct(){
    zvierata_t *temp=malloc(sizeof(zvierata_t));
    temp->next=NULL;
    return temp;
}
void n(FILE **zvierataText, zvierata_t *head, int *pocetZaznamov){

    *pocetZaznamov=0;
    char line[50];
    zvierata_t tmp;
    *zvierataText=fopen("Zvierata.txt","r");
    if (*zvierataText==NULL){
        printf("Zaznamy neboli nacitane \n");
        return;
    }

    char *strod;

    fgets(line,50,*zvierataText);
    fgets(line,50,*zvierataText);
    strcpy(head->meno,line);
    fgets(line,50,*zvierataText);
    strcpy(head->druh,line);
    fgets(line,50,*zvierataText);
    head->vyska=atoi(line);
    fgets(line,50,*zvierataText);
    head->vaha=strtod(line,&strod);
    fgets(line,50,*zvierataText);
    head->datum=atol(line);
    fgets(line,50,*zvierataText);
    head->datumKrmenia=atol(line);
    fgets(line,50,*zvierataText);
    strcpy(head->menoOsetrovatela,line);
    (*pocetZaznamov)++;

    if(fgets(line,50,*zvierataText)==NULL) return;

    zvierata_t *temporary1=malloc(sizeof(zvierata_t));
    zvierata_t *temporary2=malloc(sizeof(zvierata_t));
    bool go2=true,go1=false;
    head->next=temporary1;
    do {
        go1=!go1;
        go2=!go2;

        if (go1){
            fgets(line,50,*zvierataText);
            strcpy(temporary1->meno,line);
            fgets(line,50,*zvierataText);
            strcpy(temporary1->druh,line);
            fgets(line,50,*zvierataText);
            temporary1->vyska=atoi(line);
            fgets(line,50,*zvierataText);
            temporary1->vaha=strtod(line,&strod);
            fgets(line,50,*zvierataText);
            temporary1->datum=atol(line);
            fgets(line,50,*zvierataText);
            temporary1->datumKrmenia=atol(line);
            fgets(line,50,*zvierataText);
            strcpy(temporary1->menoOsetrovatela,line);

            temporary1->next=temporary2;
            temporary1=aloccStruct();
        }
        if (go2){
            fgets(line,50,*zvierataText);
            strcpy(temporary2->meno,line);
            fgets(line,50,*zvierataText);
            strcpy(temporary2->druh,line);
            fgets(line,50,*zvierataText);
            temporary2->vyska=atoi(line);
            fgets(line,50,*zvierataText);
            temporary2->vaha=strtod(line,&strod);
            fgets(line,50,*zvierataText);
            temporary2->datum=atol(line);
            fgets(line,50,*zvierataText);
            temporary2->datumKrmenia=atol(line);
            fgets(line,50,*zvierataText);
            strcpy(temporary2->menoOsetrovatela,line);

            temporary2->next=temporary1;
            temporary2=aloccStruct();
        }
        (*pocetZaznamov)++;
    }while (fgets(line,50,*zvierataText)!=NULL);
}


int main() {
    FILE *zvierataText = NULL;
    zvierata_t head;
    int pocetZaznamov;
    bool jeAlokovane=false;
    while (true){
        char vstup;
        printf("\nNacitajte prikaz\n");
        scanf("%c",&vstup);
        if (vstup=='n'){
            n(&zvierataText,&head,&pocetZaznamov);
            zvierata_t temp;
            temp=head;
            for (int i = 0; i < pocetZaznamov; ++i) {
                printf("%s",temp.meno);
                printf("%s",temp.druh);
                printf("%d \n",temp.vyska);
                printf("%g \n",temp.vaha);
                printf("%ld \n",temp.datum);
                printf("%ld \n",temp.datumKrmenia);
                printf("%s",temp.menoOsetrovatela);
                temp=*temp.next;
            }
        }
        if (vstup=='o'){
        }
        if (vstup=='n'){
        }
        if (vstup=='s'){
        }
        if (vstup=='h'){
        }
        if (vstup=='p'){
        }
        if (vstup=='z'){
        }
        if (vstup=='k'){
            break;
        }
    }
    return 0;
}

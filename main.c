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

//    zvierata_t *temp;
//    if (head->vyska!=NULL){
//        for (int i = 0; i < *pocetZaznamov; ++i) {
//            temp=head->next;
//            free(head);
//            head=temp;
//        }
//    }
    *pocetZaznamov=0;
    char line[50];
    *zvierataText=fopen("Zvierata.txt","r");
    if (*zvierataText==NULL){
        printf("Zaznamy neboli nacitane \n");
        return;
    }

    char *strod;

    fgets(line,50,*zvierataText);
    fgets(line,50,*zvierataText);
    line[strlen(line)-1]='\0';
    strcpy(head->meno,line);
    fgets(line,50,*zvierataText);
    line[strlen(line)-1]='\0';
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
    line[strlen(line)-1]='\0';
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
            line[strlen(line)-1]='\0';
            strcpy(temporary1->meno,line);
            fgets(line,50,*zvierataText);
            line[strlen(line)-1]='\0';
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
            line[strlen(line)-1]='\0';
            strcpy(temporary1->menoOsetrovatela,line);

            temporary1->next=temporary2;
            temporary1=aloccStruct();
        }
        if (go2){
            fgets(line,50,*zvierataText);
            line[strlen(line)-1]='\0';
            strcpy(temporary2->meno,line);
            fgets(line,50,*zvierataText);
            line[strlen(line)-1]='\0';
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
            line[strlen(line)-1]='\0';
            strcpy(temporary2->menoOsetrovatela,line);

            temporary2->next=temporary1;
            temporary2=aloccStruct();
        }
        (*pocetZaznamov)++;
    }while (fgets(line,50,*zvierataText)!=NULL);
}

void v(zvierata_t *head, int *pocetZaznamov){
    if (head->vyska==NULL){
        printf("Zaznamy neboli nacitane \n");
        return;
    }
    zvierata_t *temp;
    temp=head;
    for (int i = 0; i < *pocetZaznamov; ++i) {
        printf("Meno: %s\n",temp->meno);
        printf("Druh: %s\n",temp->druh);
        printf("Vyska: %d \n",temp->vyska);
        printf("Vaha: %g \n",temp->vaha);
        printf("Datum narodenia: %ld \n",temp->datum);
        printf("Datum Krmenia: %ld \n",temp->datumKrmenia);
        printf("Meno osetrovatela: %s\n",temp->menoOsetrovatela);
        printf("\n");
        temp=temp->next;
    }
}

void p(zvierata_t *head, int *pocetZaznamov){
    if (head->vyska==NULL){
        printf("Zaznamy neboli nacitane \n");
        return;
    }

    int pozicia;
    zvierata_t *temporary=malloc(sizeof(zvierata_t));
    printf("Nacitajte poziciu, cislo od 1 do %d", *pocetZaznamov);
    scanf("%d", &pozicia);
    printf("Nacitajte polozky\n");
    scanf("%s", temporary->meno);
    scanf("%s",temporary->druh);
    scanf("%d",&temporary->vyska);
    scanf("%lf",&temporary->vaha);
    scanf("%ld",&temporary->datum);
    scanf("%ld",&temporary->datumKrmenia);
    scanf("%s",temporary->menoOsetrovatela);

    zvierata_t *temp=malloc(sizeof(zvierata_t));
    if (pozicia<1 || pozicia>*pocetZaznamov){
        temp=head->next;
        for (int i = 2; i < *pocetZaznamov; ++i) {
            temp=temp->next;
        }
        temp->next=temporary;
        (*pocetZaznamov)++;
        return;
    }
    else {
        if (pozicia==1){
            temporary->next=head;
            head=temporary;
            (*pocetZaznamov)++;
            return;
        }
        if (pozicia==2){
            temporary->next=head->next;
            head->next=temporary;
            (*pocetZaznamov)++;
            return;
        }
        if (pozicia==3){
            temp=head->next;
            temporary->next=temp->next;
            temp->next=temporary;
            (*pocetZaznamov)++;
            return;
        }

        temp=head->next;
        for (int i = 3; i < pozicia; ++i) {
            temp=temp->next;
        }
        temporary->next=temp->next;
        temp->next=temporary;
        (*pocetZaznamov)++;
    }
}

void z(zvierata_t *head, int *pocetZaznamov){
    if (head->vyska==NULL){
        printf("Zaznamy neboli nacitane \n");
        return;
    }

    char meno[50];
    printf("Nacitajte meno zvierata\n");
    scanf("%s",meno);

    if (strcmp(head->meno,meno)==0){
        printf("Zviera s menom %s bolo vymazane \n", head->meno);
        head=head->next;
        (*pocetZaznamov)--;
        return;
    }
    zvierata_t *temp=malloc(sizeof(zvierata_t));
    temp=head->next;
    if (strcmp(temp->meno,meno)==0){
        printf("Zviera s menom %s bolo vymazane \n", temp->meno);
        head->next=temp->next;
        (*pocetZaznamov)--;
        return;
    }
    zvierata_t *tempPredosli=malloc(sizeof(zvierata_t));
    tempPredosli=head->next;
    for (int i = 2; i < (*pocetZaznamov); ++i) {
        temp=tempPredosli->next;
        if (strcmp(temp->meno,meno)==0){
            printf("Zviera s menom %s bolo vymazane \n", temp->meno);
            tempPredosli->next=temp->next;
            (*pocetZaznamov)--;
            return;
        }
        tempPredosli=temp;
    }

    printf("Nenaslo sa zadane zviera");
}


int main() {
    FILE *zvierataText = NULL;
    zvierata_t *head=malloc(sizeof(zvierata_t));
    int pocetZaznamov;
    bool jeAlokovane=false;
    while (true){
        char vstup;
        printf("\nNacitajte prikaz\n");
        scanf("%c",&vstup);
        if (vstup=='n'){
            n(&zvierataText,head,&pocetZaznamov);
        }
        if (vstup=='v'){
            v(head,&pocetZaznamov);
        }
        if (vstup=='p'){
            p(head,&pocetZaznamov);
        }
        if (vstup=='z'){
            z(head,&pocetZaznamov);
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

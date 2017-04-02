#include <stdio.h>
#include <stdlib.h>
int niveau;

void menu(){
printf("###############################################################################\n");
printf("######################                   ######################################\n");
printf("###################### Jeu du MASTERMIND ######################################\n");
printf("######################                   ######################################\n");
printf("###############################################################################\n");
}

 int MenuNiveau(){
     int a;

    printf("\n\t\t1-Niveau Debutant");
    printf("\n\t\t2-Niveau Expert\n\n");
   do{ printf("Veuiller choisir un niveau : \t");

    scanf("%d",&niveau);
    getchar();
    a=(int)niveau;

        }while((niveau<1||niveau>2)|| a==0);
    return niveau;
 }

 int verification(int * tab , int i,int a){
 int j;
 if(i!=0)
 {
     for(j=0;j<i;j++)
        {
        if(tab[j]==a) return 0;
        }
 }
 return 1;
 }


void Joueur1(int *tab){
    int choixNiveau,i=0;
printf("\n \t\t\t Bonjour Joueur1 \n\nVeuiller Choisir un niveau :\n");
choixNiveau=MenuNiveau();
    if(choixNiveau==1)
    {
        while(i<5)
        {
           printf("\nA[%d]=\t",i+1);
           tab[i]=getch();
           tab[i]=tab[i]-48;
            while(!verification(tab,i,tab[i])){
            printf("A[%d]=\t",i+1);
            tab[i]=getch();
            tab[i]=tab[i]-48;

            }
            i++;
        }
    }
    else
        {
            printf("\n");
        for(i=0;i<5;i++)
            {
            printf("A[%d]=\t",i+1);
           tab[i]=getch();
           tab[i]=tab[i]-48;
           printf("\n");
            }
        }

}
 int verficationref(int*indice , int i, int r){

int j;
if(r!=0){
for(j=0;j<r;j++){
    if(i==indice[j]) return 1;
}
}
return 0;
 }
int comparaison(int *tabJoueur1,int*tabJoueur2)
{
 int i,nbcorrect=0,j,nbrinco=0,r=0,indice[5];
 for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++){
                if(tabJoueur1[i]==tabJoueur2[j]&&i==j){
                    nbcorrect++;
                    indice[r]=i;r++;
                }

    }
    }

 for(i=0;i<5;i++)
    {
        if(!verficationref(indice,i,r)){
            for(j=0;j<5;j++){
                if(!verficationref(indice,j,r)){
                    if(tabJoueur1[i]==tabJoueur2[j]) nbrinco++;
                }
            }
        }
    }
printf("\t\t##########################################");
 printf("\n\t\t## Nombres de chiffres bien places : %d\t##" , nbcorrect);
 printf("\n\t\t## Nombres de chiffres mal places  : %d\t##\n" , nbrinco);
 printf("\t\t##########################################\n\n");

 if(nbcorrect==5){return 1;} else{ return 0;}
}

int Joueur2(int * tabJoueur1 ){
    int tabJoueur2[5],nbressaie=0,i,a;
printf("\n \t\t\t Bonjour Joueur 2  \n");
if(niveau==1) printf("\n Le niveau Choisi est - Niveau Debutant - Vous ne pouvez pas repeter un chiffre \n");
if(niveau==2) printf("\n Le niveau Choisi est - Niveau Expert - Vous pouvez repeter un chiffre \n");
while(nbressaie<20)
    {
        int choix=0;

        printf("\n \t\t\t Essaie %d    \n\n",nbressaie+1);

    if(nbressaie>=9&&nbressaie<17){
        printf("\n\n\t\t###############################################\n");

        printf("\t\tVoulez Vous utilisez l option JOCKER 1-oui 0-non :");
        scanf("%d",&choix);
        nbressaie=nbressaie+3;
        printf("\t\t###############################################\n\n");
    }
   if(choix==1){
        int position,r;

    printf("\nEntrer la position du chiffre a afficher : \t");
    scanf("%d",&position);
    printf("\nCe chiffre est : %d\n\n",tabJoueur1[position-1]);

    for(r=0;r<5;r++)
        {
          do{
            printf("A[%d]=\t",r+1);
            scanf("%d",&tabJoueur2[r]);
            getchar();
            a=(int)tabJoueur2[r];
            }while(a==0);

        }if(comparaison(tabJoueur1,tabJoueur2)) { printf("Bravo Vous avez Gagner !");return -1;}
        nbressaie++;

    if(nbressaie==19) { printf("\n\nGAME OVER !\n\n"); return -2;}
   }
   if(choix==0){

    for(i=0;i<5;i++)
        {
         do{
            printf("A[%d]=\t",i+1);
            scanf("%d",&tabJoueur2[i]);
            getchar();
            a=(int)tabJoueur2[i];
            }while(a==0);
        }
        if(comparaison(tabJoueur1,tabJoueur2)) { printf("Vous Avez Gagner !");break;}
        nbressaie++;
    }
    }
return nbressaie;
}
int main()
{
    menu();
    int i,tableau1[5];
    Joueur1(tableau1);
    printf("\n\n");
   if(Joueur2(tableau1) >19) printf("GAME OVER !\n\n");
    return 0;
}

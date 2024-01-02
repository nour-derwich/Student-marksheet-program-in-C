 //C program for student marksheet

#include "stdio.h"
#include "unistd.h"

int i, j, option, error, check = 0;
char nom[50], Classe[20], repetition;
int numero_matricule, sj[15], n, notes[10], total;
float per;
const char *cours[8] = {
    "Programmation C", "Virtualisation et Cloud", "Math�matiques", "Algorithmique", "Bases de donn�es",
    "Physique", "Histoire", "Business"
};

// Fonction pour afficher le titre
void titre(){
    printf("\n================================================");
    printf("\n\ Programme de feuille de notes des �tudiants en Tek up");
    printf("\n================================================");
}


// Fonction pour repr�senter le pourcentage avec des di�ses (#)
void pourcentage(float per){
    int i;
    printf("\n\n");
    for (i = 0; i < per; i++){
        if ((i % 2) == 0){
            printf("#");
            usleep(19000);
        }
    }
}

// Fonction pour les d�tails de l'�tudiant
void DetailsEtudiant(){
    system("cls");
    titre();
    printf("\n\n----------- Entrez les d�tails de l'�tudiant -----------");
    printf("\n\nNom de l'�tudiant    : ");
    scanf("%s", &nom);
    printf("\n Num�ro matricule de l'�tudiant : ");
    scanf("%d", &numero_matricule);
    printf("\n Classe de l'�tudiant   : ");
    scanf("%s", &Classe);
}


void DetailsMatiere(){

    do{
        error = 0;
        system("cls");
        titre();
        printf("\n\n----------- Entrer les d�tails des cours -----------");
        printf("\n Entrez le nombre de cours : ");
        scanf("%d", &n);
        printf("\n---------------------------------------------");
        printf("\n\n Cours : ");
        printf("\n");

        for(i = 0; i < 8; i++){
            printf("%d. %s ", i, cours[i]);
            if(i == 4 || i == 7){
                printf("\n");
            }
        }
        printf("\n---------------------------------------------\n");
        for(i = 0; i < n; i++) {
        printf("\n Choisissez les cours : ");
            scanf("%d", &sj[i]);
        }

        for(i = 0; i < n; i++){ // Cette boucle for est utilis�e pour g�rer les erreurs
            if(sj[i] >= 8){
                printf("\n ERREUR : Le %d�me cours n'existe pas\n", sj[i]);
                error = 1;
                break;
            }

            for(j = i + 1; j < n; j++){
                if(sj[i] == sj[j]){
                    printf("\n ERREUR : Vous avez choisi le m�me cours plusieurs fois\n");
                    error = 1;
                }
            }
        }

        printf("\n");
        system("pause");

        if(error == 0){
            break;
        }
        system("cls");
    }while(error == 1);
}

// Fonction pour saisir les notes
void SaisieNotes(){
    system("cls");

    //Taking an input of subject notes from an user
     titre();
     printf("\n\n----------- Enter notes Details -----------");
     printf("\n\nEnter the notes : ");
     for(i=0;i<n;i++){
         int s=sj[i];
         printf("\n%d. %s : ",i+1, cours[s]);
         scanf("%d",&notes[i]);
     }

     printf("\n Calculating........");
     sleep(2);
}

// Fonction pour calculer les totaux et le pourcentage
void Calcul(){
    for(i=0;i<n;i++){
        total= total+notes[i];
    }


   int Maxnotes= n*100;
     per = (total*100)/Maxnotes;
}
// Fonction pour afficher les r�sultats

void Affichage(){
     system("cls");


     titre();
     printf("\n\n-------------------- R�sultats  ---------------------");
    printf("\n\n �tudiant nom    : %s",nom);
    printf("\n �tudiant numero_matricule   : %d",numero_matricule);
    printf("\n �tudiant Classe     : %s",Classe);

    printf("\n=================================================");
    printf("\n Classe\t\t\tnotes");
    printf("\n=================================================\n");
    for(i=0;i<n;i++){
        int s=sj[i];
        printf("\n%d",cours[s],notes[i]);

    }
    printf("\n--------------------------------------------------");
    printf("\n %d",total);
     for (int i = 0; i < n; i++)
    {
        if(notes[i]<35)
           check=1;
     }
    if(check==1){
    	printf("\n FAIL");
        check=0;
	}
	else{
		printf("\n  PASS");
        check=0;
	}

    pourcentage(per);
    printf("  %0.0f%%",per);

    //Statements
    if(per>=85){
    	printf("\n\n F�licitations %s, vous avez obtenu %0.0f%%", nom, per);
	}
	else if(per>=60 && per<85){
    	printf("\n\n Tr�s bien %s, vous avez obtenu %0.0f%%", nom, per);
	}
	else if(per>=35 && per<60){
    	printf("\n\n Pas mal %s, vous avez obtenu %0.0f%%", nom, per);
	}
    else if(per<35){
    	printf("\n\n Pas de probl�me %s, essayez de nouveau la prochaine fois.", nom);
        printf("\n Votre score est de %0.0f%%", per);
	}

    printf("\n\n Voulez-vous continuer?(Y/N) : ");
    scanf("%s",&repetition);
    total=0;
}


int main(){

    while(1){

	    system("cls");
         system("Color F0");
         error=0;

         // menu
	    titre();
	    printf("\n    1. Cr�er une feuille de notes\n");
	    printf("\n    2. Quitter\n");
        printf("\nChoisissez votre option : ");
	    scanf("%d",&option);
	    switch(option){
	    	case 1:
               //Calling an Addmark() function
	    	   //Addmark();
               do{
                  DetailsEtudiant();
                    DetailsMatiere();
                    SaisieNotes();
                    Calcul();
                    Affichage();
                  // percentage(per);
               }while (repetition =='y'||repetition =='Y');

	    	   break;

	        case 2:
	        	system("cls");
                printf("\n\n Merci d'avoir utilis� ce appplicaction");
                exit(0);

	    	default:
                //Error statement
                printf("\n\n\     ERREUR : Vous essayez de choisir une option inexistante!\n");
                printf("\n");
                system("pause");
                system("cls");
		}
    }

return 0;

 }


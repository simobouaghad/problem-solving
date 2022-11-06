#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>


  // FONCTION COLOR TEXT

      void textcolor(unsigned short color){
          HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
           SetConsoleTextAttribute(hcon,color);
        }

    // ************** PROJET DE REPERTOIRE TELEPHONIQUE **************** //

       // **************** CREER LE REPERTOIRE TELEPHONIQUE *******************//

            // --------------- LES STRUCTURES PRINCIPALE -------------------------//


         // LA STRUCTURE PRINCIPALE DES ABONNES

          typedef struct ElementAbonne{
              int num_telephone;
               char nom_Abonne[20];
                char Adresse[20];
                 struct ElementAbonne *precedent;
                 struct ElementAbonne *suivant;
          }Abonne;

          // LA STRUCTURE PRINCIPALE DES ZONES TELEPHONIQUE

          typedef struct Zone{
              int code_zone;
               char nom_zone[20];
                int nbr_Abonnes;
                 Abonne *Debut_Abonne;
                 Abonne *Fin_Abonne;
                  struct Zone *suivant;
          }Repertoire_telephone;

             // LA VARIABLE PRINCIPALE DE REPERTOIRA

            Repertoire_telephone *Liste_Zone;
             int nbrZ;
              int Entrer;


    // ----------------------- CREER UNE LISTE DES ABONNE ------------------------ //

          // CREER UN SEUL ABONNE

          Abonne *CreerAbonne(){
              Abonne *New;
               New=(Abonne *)malloc(sizeof(Abonne));
               textcolor(8);
               printf("\n\t\t\t.... Numero de telephone  : ");
                scanf("%d",&New->num_telephone);
                 printf("\n\t\t\t.... Nom d'abonne         : ");
                  scanf("%s",New->nom_Abonne);
                   printf("\n\t\t\t.... L'adresse            : ");
                    scanf("%s",New->Adresse);
                    New->precedent=NULL;
                    New->suivant=NULL;
              return New;
          }


          // FONCTION DE RECHERCHER LA FIN D'UNE LISE DES ABONNES

          Abonne *Recherche_Fin(Abonne *Liste_Ab){
              Abonne *tmp=Liste_Ab;
               while(tmp->suivant!=NULL){
                   tmp=tmp->suivant;
               }
            return Liste_Ab;
          }

          // FONCTION QUI RETOURNER LA TAILLE

          int Taille_Abonne(Abonne *Liste_Ab){
          	Abonne *tmp=Liste_Ab;
          	 int taille=1;
          	  while(tmp->suivant!=NULL){
          	  	tmp=tmp->suivant;
          	  	 taille++;
				}
			  if(tmp==NULL){
			  	return 0;
			  }
			  else{
			  	return taille;
			  }
		  }

          // FONCTION D'INSERER UN ELEMENT A LA FIN D'UNE LISTE DES ABONNES

          Abonne *InsererFin_Ab(Abonne *Liste_Ab){
              Abonne *Ele_Fin=Liste_Ab;
               Abonne *New;
                Ele_Fin=Recherche_Fin(Liste_Ab);
                New=CreerAbonne();
                 New->precedent=Ele_Fin;
                  Ele_Fin->suivant=New;
              return Liste_Ab;
          }

          // FONCTION QUI PERMET DE CREER UNE LISTE DES ABONNES

          Abonne *CreerListe_Ab(int nbr_Ab){
              int i;
               Abonne *Liste_Ab;
               for(i=1;i<=nbr_Ab;i++){
                    textcolor(6);
                  printf("\n\t\t\t.......... Abonne %d ..........\n ",i);
                   if(i==1){
                       Liste_Ab=CreerAbonne();
                   }
                   else{
                       Liste_Ab=InsererFin_Ab(Liste_Ab);
                   }
               }
            return Liste_Ab;
          }

    // ------------------- CREER UNE LISTE DES ZONES -------------------- //

       // CREER UNE ZONE UNIQUE

       Repertoire_telephone *CreerZone(){
           int i,nbr_Ab;
           Abonne *Liste_Ab;
            Repertoire_telephone *New;
             New=(Repertoire_telephone *)malloc(sizeof(Repertoire_telephone));
              textcolor(8);
              printf("\n\t\t---- Code de la zone     : ");
               scanf("%d",&New->code_zone);
                 printf("\n\t\t---- Nom de la zone      : ");
                 scanf("%s",New->nom_zone);
                  printf("\n\t\t---- Nombre des Abonnes  : ");
                   scanf("%d",&New->nbr_Abonnes);
                   nbr_Ab=New->nbr_Abonnes;
                    Liste_Ab=CreerListe_Ab(nbr_Ab);
                New->Debut_Abonne=Liste_Ab;
                New->Fin_Abonne=Recherche_Fin(Liste_Ab);
                 New->suivant=NULL;
            return New;
       }

       // FONCTION RECHERCHE LA FIN D'UNE LISTE DE ZONES

       Repertoire_telephone *Recherche_FinZ(Repertoire_telephone *Liste_Zone){
           Repertoire_telephone *Fin=Liste_Zone;
            while(Fin->suivant!=NULL){
                Fin=Fin->suivant;
            }
          return Fin;
       }

       // FONCTION D'INSERER UNE ZONE A LA FIN

       Repertoire_telephone *InsereFin_Zone(Repertoire_telephone *Liste_Zone){
           Repertoire_telephone *Ele_Fin;
            Repertoire_telephone *New;
             Ele_Fin=Recherche_FinZ(Liste_Zone);
              New=CreerZone();
               Ele_Fin->suivant=New;
          return Liste_Zone;
       }

       // FONCTION DE CREER UNE LISTE DE ZONES

       Repertoire_telephone *CreerListe_Zone(int nbr_Zones){
            int i;
             for(i=1;i<=nbr_Zones;i++){
                      textcolor(9);
                 printf("\n\t\t---------- Zone %d ----------\n",i);
                  if(i==1){
                      Liste_Zone=CreerZone();
                  }
                  else{
                      Liste_Zone=InsereFin_Zone(Liste_Zone);
                  }
             }
          return Liste_Zone;
       }


    // ********************** GERER LE REPERTOIRE TELEPHONIQUE *************************** //

      // FONCTION QUI RETOURNER NOMBRE DE ZONES D'UN REPERTOIRE

      int Repertoire_taille(Liste_Zone){
      	Repertoire_telephone *tmp=Liste_Zone;
      	 int taille=1;
       	while(tmp->suivant!=NULL){
       		tmp=tmp->suivant;
       		 taille++;
		   }
		  if(tmp==NULL){
		  	return 0;
		  }
		  else{
		  	return taille;
		  }
	  }

      // FONCTION QUI PERMI D'AJOUTER UNE ZONE DANS LE REPERTOIRE

      int Ajouter_Zone(){
      	 Liste_Zone=InsereFin_Zone(Liste_Zone);
      	  int New_taille=Repertoire_taille(Liste_Zone);
      	   if(New_taille>nbrZ){
      	   	return 1;
			 }
			 else{
			 	return -1;
			 }
	  }

	  // FONCTION QUI RECHERCHE UNE ZONE

	  Repertoire_telephone *Zone_Recherchee(int Code_Zone){
	  	Repertoire_telephone *tmp=Liste_Zone;
	  	 int cmp=0;
	  	 while(tmp->suivant!=NULL){
	  	 	if(tmp->code_zone==Code_Zone){
	  	 	   cmp++;
	  	 		return tmp;
			   }
			 tmp=tmp->suivant;
		   }
        if(tmp->suivant==NULL && tmp->code_zone==Code_Zone){
            cmp++;
            return tmp;
        }
        if(cmp==0){
            return NULL;
        }
	  }

	  // FONCTION QUI PERMI D'AJOUTER UN ABONNE DANS UNE ZONE

	  int Ajouter_Abonne(int Code_Zone){
	  	Repertoire_telephone *zone;
	  	 Abonne *Liste_Ab;
	  	 zone=Zone_Recherchee(Code_Zone);
	  	 if(zone!=NULL){
	  	 	Liste_Ab=zone->Debut_Abonne;
	  	 	 Liste_Ab=InsererFin_Ab(Liste_Ab);
                (zone->nbr_Abonnes)++;
	  	 	 	  return 1;
		   }
		   else{
		 	printf("Cette zone n'existe pas dans le repertoire");
		 }
	  }

	  // VERIFIER SI UNE PERSONNE EST ENREGISTRER DANS LE REPERTOIRE

	  int Enregestrer(int CodezonE,char *nom){
	  	Repertoire_telephone *Zone;
		  Zone=Zone_Recherchee(CodezonE);
		   if(Zone==NULL){
		   	return -1;
		   }
		   else{
		   	Abonne *ListeA=Zone->Debut_Abonne;
		   	 int nbr=Zone->nbr_Abonnes;
		   	  int cmp=0;
		   	  while(ListeA->suivant!=NULL){
		   	  	if(strcmp(ListeA->nom_Abonne,nom)==0){
		   	  	   cmp++;
		   	  		return (ListeA->num_telephone);
					 }
					ListeA=ListeA->suivant;
				 }
				 if(ListeA->suivant==NULL && strcmp(ListeA->nom_Abonne,nom)==0){
                    cmp++;
                    return (ListeA->num_telephone);
				 }
                if(cmp==0){
                    return -2;
                }
		   }
	  }

	  // FONCTION DE SUPPRIMER UN ABONNE AU DEBUT

	  Abonne *SuppAb_Debut(Abonne *ListeAb,Abonne *Abonne_Supp){
	  	ListeAb=ListeAb->suivant;
	  	 ListeAb->precedent=NULL;
	  	  free(Abonne_Supp);
	  	return ListeAb;
	  }


	  // FONCTION DE SUPPRIMER UN ABONNE A LA FIN

	  Abonne *SuppAb_Fin(Abonne *ListeAb,Abonne *Abonne_Supp){
	    Abonne_Supp->precedent->suivant=NULL;
	     free(Abonne_Supp);
	  	return ListeAb;
	  }


	  // FONCTION DE SUPPRIMER UN ABONNE AILLEUR DE LA LISTE

	  Abonne *SuppAb_Ailleur(Abonne *ListeAb,Abonne *Abonne_Supp){
	  	Abonne_Supp->suivant=Abonne_Supp->precedent->precedent;
	  	 Abonne_Supp->precedent->suivant=Abonne_Supp->suivant;
	  	return ListeAb;
	  }



	  // FONCTION DE RECHERCHER UN ABONNE SELON NUMERO DE TELEPHONE

	  Abonne *Recherche_AbonneNT(Abonne *Liste_Ab,int numero_tele){
	  	Abonne *tmp=Liste_Ab;
	  	 int cmp=0;
	  	 while(tmp->suivant!=NULL){
	  	   if(tmp->num_telephone==numero_tele){
	  	   	   return tmp;
	  	   	    cmp++;
			 }
	  	 	tmp=tmp->suivant;
		   }
		   if(tmp->suivant==NULL && tmp->num_telephone==numero_tele){
             cmp++;
              return tmp;
		   }
		if(cmp==0){
			return NULL;
		}
	  }

	  // FONCTION ENLEVER UN ABONNE

	   int Enlever_Abonne(int codeZone,int numero_tele){
	   	 Repertoire_telephone *Zone=Liste_Zone;
	   	  Abonne *Liste_Ab;
	   	   Abonne *Abonne_Supp;
	  	    Zone=Zone_Recherchee(codeZone);
	  	     Liste_Ab=Zone->Debut_Abonne;
	  	      Abonne_Supp=Recherche_AbonneNT(Liste_Ab,numero_tele);
	  	       if(Abonne_Supp==NULL){
                  return 0;
                  exit(0);
	  	       }
	  	       else if(Abonne_Supp->precedent==NULL && Abonne_Supp->suivant!=NULL){
	  	    	  Liste_Ab=SuppAb_Debut(Liste_Ab,Abonne_Supp);
	  	    	   Zone->nbr_Abonnes--;
			    }
			    else if(Abonne_Supp->precedent==NULL && Abonne_Supp->suivant==NULL){
                  free(Liste_Ab);
                   Liste_Ab==NULL;
                    Zone->nbr_Abonnes--;
			    }
			    else if(Abonne_Supp->suivant==NULL){
			    	Liste_Ab=SuppAb_Fin(Liste_Ab,Abonne_Supp);
			    	 Zone->nbr_Abonnes--;
			   }
			    else{
			  	  Liste_Ab=SuppAb_Ailleur(Liste_Ab,Abonne_Supp);
			  	   Zone->nbr_Abonnes--;
			    }
			    int taille;
			     taille=Taille_Abonne(Liste_Ab);
			      if(taille<=Zone->nbr_Abonnes){
			   	    return 1;
			     }
			      else{
                   return -1;
			     }
            }

	   // FONCTION SUPPRIMER AU DEBUT D'UNE LISTE DE ZONES

	   Repertoire_telephone *SuppZ_Debut(){

	   }


	   // FONCTION SUPPRIMER A LA FIN D'UNE LISTE DE ZONES

	   Repertoire_telephone *SuppZ_Fin(){

	   }


	   // FONCTION SUPPRIMER A AILLEUR D'UNE LISTE DE ZONES

	    Repertoire_telephone *SuppZ_Ailleur(){

	   }

	   // FONCTION RECHERCHER LA ZONE AVANT




	   // FONCTION ENLEVER UNE ZONE

	   int Enlever_zone(int codeZone){

	   }











int main(){

      F1:
      textcolor(10);
    printf("\n\n\t\t\t\t\t\t *************** Repertoire Telephonique ***************\n\n");
    F2:
    textcolor(3);
     printf("\n\t\t..........................\t\t..........................\t\t...........................\n");
      printf("\t\t. 1/ Creer le repertoire .\t\t. 2/ Gerer le repertoire .\t\t. 3/ Arreter le programme .\n");
       printf("\t\t..........................\t\t..........................\t\t...........................\n");
        printf("\n\t\t.... Entrer : ");
         scanf("%d",&Entrer);
          system("cls");


            // CREER LE REPERTOIRE TELEPHONIQUE

        if(Entrer==1){
        	textcolor(3);
              printf("\n\n\t\t\t\t\t=================================================\n");
               printf("\t\t\t\t\t= \tCreer le Repertoire Telephonique \t=\n");
                printf("\t\t\t\t\t=================================================\n");
                 textcolor(8);
                 printf("\n\n\t\t**** Nombre de zones  : ");
                  scanf("%d",&nbrZ);
                   Repertoire_telephone *f=CreerListe_Zone(nbrZ);
                    system("cls");
                     textcolor(8);
                      printf("\n\n\t\tvous avez terminee la Creation de repertoire\n");
                       goto F2;
                       system("cls");
		}

		    // GERER LE REPERTOIRE TELEPHONIQUE

        if(Entrer==2){
          	m:
			 textcolor(3);
              printf("\n\n\t\t\t\t\t=================================================\n");
               printf("\t\t\t\t\t= \tGerer le Repertoire Telephonique \t=\n");
                printf("\t\t\t\t\t=================================================\n");
                if(Liste_Zone==NULL){
                   textcolor(8);
                    printf("\n\t\t\t il n'exist pas de repertoire\n\n\t\t\t");
                     system("pause");
                      system("cls");
                       goto F1;

                }
                else{
                 textcolor(2);
                  N:
          	      printf("\n\t\t\t-----------------------\t\t------------------------\t---------------------------------------\n");
          	       printf("\t\t\t. 1/ Ajouter une zone .\t\t. 2/ Ajouter un Abonne .\t. 3/ Afficher les zones de repertoire .\n");
          	        printf("\t\t\t-----------------------\t\t------------------------\t---------------------------------------\t\n");
             	printf("\n\t\t\t------------------------------------------------------------------\t-------------------------------------\n");
          	     printf("\t\t\t. 4/ Verifier si une personne est Enregistree dans le repertoire .\t. 5/ Afficher les abonner d'une zone .\n");
          	      printf("\t\t\t------------------------------------------------------------------\t--------------------------------------\n");
          	       printf("\n\t\t\t-------------------------\t-----------------------\t\t--------------------------------------\n");
          	        printf("\t\t\t. 6/  Enlever un Abonne .\t. 7/ Enlever une zone .\t\t. 8/ Terminer de gerer le repertoire .\n");
          	         printf("\t\t\t-------------------------\t-----------------------\t\t--------------------------------------\n");
                      printf("\n\t\t\t.... Entrer : ");
          	           scanf("%d",&Entrer);
          	           system("cls");

            if(Entrer==1){
                    textcolor(3);
                printf("\n\n\t\t\t\t\t=================================================\n");
                 printf("\t\t\t\t\t= \tGerer le Repertoire Telephonique \t=\n");
                  printf("\t\t\t\t\t=================================================\n");
                    textcolor(2);
          	   	     printf("\n\t\t\t ------- Ajouter une zone ---------\n");
          	   	     int a=Ajouter_Zone();
          	   	      printf("\n\t\t\t Resultat : %d",a);
          	   	       if(a==1){
                        nbrZ++;
          	   	       }
          	   	       printf("\n");
          	   	        printf("\n\t\t\tvous avez terminer d'ajouter une zone\n\n\t\t\t");
          	   	         system("pause");
          	   	 	      system("cls");
          	   	           goto m;
          	   	            goto N;
				   }

			else if(Entrer==2){
                textcolor(3);
                 printf("\n\n\t\t\t\t\t=================================================\n");
                  printf("\t\t\t\t\t= \tGerer le Repertoire Telephonique \t=\n");
                   printf("\t\t\t\t\t=================================================\n");
                    textcolor(2);
				     printf("\n\t\t\t ------ Ajouter un Abonne -------\n");
				 	  textcolor(8);
				       printf("\n\t\t\tCode de la zone  : ");
				        scanf("%d",&Entrer);
				         int a=Ajouter_Abonne(Entrer);
				 	      printf("\n\t\t\tResultat         : %d",a);

				 	  	   printf("\n");
          	   	            printf("\n\t\t\tvous avez terminer d'ajouter un Abonne\n\n\t\t\t");
          	   	             system("pause");
          	   	 	          system("cls");
          	   	 	           goto m;
          	   	 	            goto N;
				       }

            else if(Entrer==3){
                    int i;
                     Repertoire_telephone *tmp=Liste_Zone;
                    textcolor(3);
                 printf("\n\n\t\t\t\t\t=================================================\n");
                  printf("\t\t\t\t\t= \tGerer le Repertoire Telephonique \t=\n");
                   printf("\t\t\t\t\t=================================================\n");
                    textcolor(2);
				     printf("\n\t\t\t ------ Afficher les zone du repertoire -------\n");
                     for(i=1;i<=nbrZ;i++){
                        textcolor(3);
                       printf("\n\n\t\t\t// .... Zone %d ..................... //\n",i);
                        textcolor(8);
                        printf("\n\t\t\t--> Code : %d",tmp->code_zone);
                         printf("\n\n\t\t\t--> Nom : %s",tmp->nom_zone);
                          printf("\n\n\t\t\t--> Nombre d'abonne : %d",tmp->nbr_Abonnes);
                           tmp=tmp->suivant;
                     }



				      printf("\n");
				       textcolor(8);
          	   	           printf("\n\t\t\tvous avez terminer l'affichage des zones de pepertoire\n\n\t\t\t");
          	   	            system("pause");
          	   	 	         system("cls");
                              goto m;
                               goto N;

                }

			else if(Entrer==4){
				int codezonE;
				 char nom[20];
				  textcolor(3);
				   textcolor(3);
                    printf("\n\n\t\t\t\t\t=================================================\n");
                     printf("\t\t\t\t\t= \tGerer le Repertoire Telephonique \t=\n");
                      printf("\t\t\t\t\t=================================================\n");
                       textcolor(2);
				 	    printf("\n\t\t\t ------- Verifier si une personne est enregistree dans la repertoire ------\n");
				 	     textcolor(8);
				 	      printf("\n\t\t\t.... Code de zone  : ");
				 	       scanf("%d",&codezonE);
				 	        printf("\n\t\t\t....Nom d'abonne   : ");
				 	         scanf("%s",nom);
				 	          int a=Enregestrer(codezonE,nom);
				 	            if(a==-1){
				 	            	textcolor(3);
				 	                printf("\n\t\t\t ---- Resultat :\n\n");
				 	                 textcolor(8);
				 	    	         printf("\n\t\t\t--> Cette zone n'existe pas");
						        }
				 	            else if(a==-2){
				 	            	textcolor(3);
				 	                printf("\n\t\t\t ---- Resultat :\n\n");
				 	                 textcolor(8);
				 	    	         printf("\n\t\t\t--> Cet Abonne n'existe pas dans Cette zone");
						        }
				 	            else{
				 	            	textcolor(3);
				 	                 printf("\n\t\t\t ---- Resultat :\n\n");
				 	                  textcolor(8);
				 	                   printf("\t\t\t--> Cet Abonne est exist dans le repertoire\n\n");
				 	    	            printf("\t\t\t--> Numero de telephone :%d%d",0,a);
						            }
						        printf("\n");
						         textcolor(8);
          	   	                  printf("\n\t\t\tvous avez terminer la verification\n\n\t\t\t");
          	   	                   system("pause");
          	   	 	                system("cls");
          	   	 	                 goto m;
          	   	 	                  goto N;
				    }

                else if(Entrer==5){


                }

				else if(Entrer==6){
				 	int code_Z,num_tele;
				 	 textcolor(3);
                      printf("\n\n\t\t\t\t\t=================================================\n");
                       printf("\t\t\t\t\t= \tGerer le Repertoire Telephonique \t=\n");
                        printf("\t\t\t\t\t=================================================\n");
				 	     textcolor(2);
				 	      printf("\n\t\t\t ------- Enlever un Abonne -------\n");
				 	       textcolor(8);
				 	 printf("\n\t\t\t.... Code de zone        : ");
				 	  scanf("%d",&code_Z);
				 	   printf("\n\t\t\t.... Numero de telephone : ");
				 	    scanf("%d",&num_tele);
				 	    int a=Enlever_Abonne(code_Z,num_tele);
				 	     printf("\n\t\t\t.... Resultat : ");
				 	      if(a==0){
                            printf("\n\t\t\tCet Abonne n'exist pas\n");
				 	      }
				 	      else{
                            printf("\n\t\t\t %d",a);
				 	      }

				 	      printf("\n");
          	   	           printf("\n\t\t\tvous avez terminer d'enlever un Abonne\n\n\t\t\t");
          	   	            system("pause");
          	   	 	         system("cls");
                              goto m;
                               goto N;
				 }

				 else if(Entrer==7){
					 int code_zone;
					textcolor(2);
                printf("\n\n\t\t\t\t\t=================================================\n");
                 printf("\t\t\t\t\t= \tGerer le Repertoire Telephonique \t=\n");
                  printf("\t\t\t\t\t=================================================\n");
					 textcolor(3);
					  printf("\n\t\t\t ------- Enlever une Zone -------\n");
					   textcolor(8);
					    printf("\n\t\t\t.... Code de zone : ");
				 	     scanf("%d",&code_zone);

				}

				else if(Entrer==8){
					system("cls");
					 textcolor(8);
					  printf("\n\t\t vous avez terminer de gerer le repertoire\n");
					   goto F2;
				}

            }
		  }

		  // ARRETER LE PROGRAMME

		  else if(Entrer==3){
		  	textcolor(8);
		  	printf("\n\n\t\t Vous avez Arreter le programme\n\n\t\tMerci pour l'utilisation\n\n");
		  }



    return 0;
}

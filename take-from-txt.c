#include "take-from-txt.h"

char *takeLineFromTxt(int indexLineToExtract, int argument) {
    char *ligne = (char *) malloc(70 * sizeof(char));
    int i = 0;

    FILE *dictionnaire = fopen("../Dictionnaire/dictionnaire_non_accentue.txt","r");//demander a jad comment on fait des path pas absolue



    if (dictionnaire == NULL) {
        printf("Error fichier introuvable");
        return " ";
    }
    while (i < indexLineToExtract - 1) {
        ligne[0] = (char) fgetc(dictionnaire);
        // printf("%s", ligne);
        if (*ligne == '\n') {
            i++;
        }
    }

    if (argument == 1) {
        fscanf(dictionnaire, "%s", ligne);
        // printf("\n%s", ligne);
    }
    if (argument == 2) {
        int a = 0;
        while (fgetc(dictionnaire) != '\t') {
            fscanf(dictionnaire, "%s", ligne);
            //printf("%s \n", &ligne);
        }
        fscanf(dictionnaire, "%[^\t]", ligne);
        // printf("\n%s", ligne);
    }
    if (argument == 3) {
        while (fgetc(dictionnaire) != '\t') {
            fscanf(dictionnaire, "%s", ligne);
            //printf("%s \n", &ligne);
        }
        while (fgetc(dictionnaire) != '\t') {
            fscanf(dictionnaire, "%s", ligne);
            //printf("%s \n", &ligne);
        }
        fscanf(dictionnaire, "%s", ligne);
        // printf("\n%s", ligne);
    }


    int returnCode = fclose(dictionnaire);
    if (returnCode == EOF) {
        fprintf(stderr, "Erreur durant la fermeture du fichier");
        exit(-1);
    }
    return ligne;
}

char *extractAgreeFormeFromLine(int extractInformationFromLine) {
    char *ligne = takeLineFromTxt(extractInformationFromLine, 1);
    return ligne;
}

char *extractBaseFormeFromLine(int extractInformationFromLine) {
    char *ligne = takeLineFromTxt(extractInformationFromLine, 2);
    return ligne;
}

char *extractInformationFromLine(int extractInformationFromLine) {
    char *ligne = takeLineFromTxt(extractInformationFromLine, 3);
    return ligne;
}

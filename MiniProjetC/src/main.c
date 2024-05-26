#include "calculeradresse.h"
#include "decoderip.h"
#include "extraireleschamps.h"
#include "verifierleformat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programme principal
int main() {
    char ip_adresse[19];

    // Demander à l'utilisateur d'entrer une adresse IP
    printf("Veuillez entrer une adresse IP (ex: xxx.xxx.xxx.xxx/xx) : ");
    scanf("%18s", ip_adresse);

    // Vérifier si l'adresse IP est au format valide
    if (ip_format_valide(ip_adresse)) {
        printf("L'adresse IP que vous avez entrée est valide.\n");

        // Extraire les octets et le masque de l'adresse IP
        char adresse_reseau[19];
        int octet1, octet2, octet3, octet4, masque;
        extraire_champs_ip(ip_adresse, &octet1, &octet2, &octet3, &octet4, &masque);

        // Afficher les octets et le masque extraits
        printf("Voici les champs extraits de l'adresse IP :\n");
        printf("Octet 1 : %d\n", octet1);
        printf("Octet 2 : %d\n", octet2);
        printf("Octet 3 : %d\n", octet3);
        printf("Octet 4 : %d\n", octet4);
        printf("Masque : %d\n", masque);

        // Décoder et attribuer le type, la classe et le nombre d'hôtes de l'adresse IP
        TypeAdresseIP type_ip = decoder_type_adresse_ip(ip_adresse);
        ClasseAdresseIP classe_ip = decoder_classe_adresse_ip(ip_adresse);
        int nombre_hotes = calculer_nombre_hotes(ip_adresse);

        // Afficher le type d'adresse IP
        afficher_type_adresse_ip(type_ip);

        // Afficher la classe de l'adresse IP et l'adresse réseau si applicable
        // Ignorer les types réseau et inconnu
        if (type_ip != TYPE_RESEAU && type_ip != TYPE_INCONNU) {
            afficher_classe_adresse_ip(classe_ip);
            calculeradressereseau(ip_adresse, adresse_reseau);
            printf("L'adresse réseau correspondante est : %s\n", adresse_reseau);

            // Afficher le nombre d'hôtes disponibles si applicable
            // Ignorer les types broadcast et multicast
            if (type_ip != TYPE_BROADCAST && type_ip != TYPE_MULTICAST){
                printf("Le nombre d'hôtes disponibles est : %u\n", nombre_hotes);
            }
        }

    // Si l'adresse IP est invalide, afficher un message d'erreur
    } else {
        printf("L'adresse IP que vous avez entrée est invalide.\n");
    }
}

#include "calculeradresse.h"
#include "decoderip.h"
#include "extraireleschamps.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Détermine l'adresse réseau à partir de l'adresse IP
void calculeradressereseau(const char *ip_adresse, char *adresse_reseau) {

  // Stocke les octets et le masque dans des variables
  int octet1, octet2, octet3, octet4, masque;
  extraire_champs_ip(ip_adresse, &octet1, &octet2, &octet3, &octet4, &masque);

  // Initialisation des octets de l'adresse réseau à 0
  unsigned int octet_adr_res[4] = {0};
  // Calcul du masque binaire en fonction du masque de sous-réseau
  unsigned int masque_binaire = 0xFFFFFFFF << (32 - masque);

  // Applique le masque sur chaque octet pour obtenir l'adresse réseau
  octet_adr_res[0] = octet1 & (masque_binaire >> 24);
  octet_adr_res[1] = octet2 & (masque_binaire >> 16);
  octet_adr_res[2] = octet3 & (masque_binaire >> 8);
  octet_adr_res[3] = octet4 & masque_binaire;

  // Ajuste l'adresse réseau si le masque est inférieur à 32
  if (masque < 32) {
    unsigned int ajustement = 1 << (32 - masque);
    octet_adr_res[3] = (octet_adr_res[3] / ajustement) * ajustement;
  }

  // Formate l'adresse réseau en chaîne de caractères
  sprintf(adresse_reseau, "%d.%d.%d.%d", octet_adr_res[0], octet_adr_res[1],
          octet_adr_res[2], octet_adr_res[3]);
}

// Calcule le nombre d'hôtes disponibles dans le réseau
int calculer_nombre_hotes(const char *ip_adresse) {
  
  // Stocke les octets et le masque dans des variables
  int octet1, octet2, octet3, octet4, masque;
  extraire_champs_ip(ip_adresse, &octet1, &octet2, &octet3, &octet4, &masque);

  // Vérifie si l'adresse est de type localhost
  // Retourne 1 pour localhost, sinon calcule le nombre d'hôtes possibles
  if ((decoder_classe_adresse_ip(ip_adresse)) == TYPE_LOCALHOST) {
    return 1;
  } else {
    return (pow(2, (32 - masque)) - 2);
  }
}

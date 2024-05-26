#include "decoderip.h"
#include "extraireleschamps.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Indique le type de l'adresse IP
void afficher_type_adresse_ip(TypeAdresseIP type) {

  // Un switch case qui affiche en fonction du type de réseau
  switch (type) {
  case TYPE_PUBLIQUE:
    printf("Type de l'adresse IP : Publique\n");
    break;
  case TYPE_PRIVEE:
    printf("Type de l'adresse IP : Privée\n");
    break;
  case TYPE_LOCALHOST:
    printf("Type de l'adresse IP : Localhost\n");
    break;
  case TYPE_BROADCAST:
    printf("Type de l'adresse IP : Broadcast\n");
    break;
  case TYPE_MULTICAST:
    printf("Type de l'adresse IP : Multicast\n");
    break;
  case TYPE_RESEAU:
    printf("Type de l'adresse IP : Réseau\n");
    break;
  case TYPE_INCONNU:
    printf("Type de l'adresse IP : Inconnue\n");
    break;
  }
}

// Indique la classe de l'adresse IP
void afficher_classe_adresse_ip(ClasseAdresseIP classe) {

  // Un switch case qui affiche en fonction de la classe de réseau
  switch (classe) {
  case CLASSE_A:
    printf("Classe de l'adresse IP : A\n");
    break;
  case CLASSE_B:
    printf("Classe de l'adresse IP : B\n");
    break;
  case CLASSE_C:
    printf("Classe de l'adresse IP : C\n");
    break;
  case CLASSE_D:
    printf("Classe de l'adresse IP : D\n");
    break;
  case CLASSE_E:
    printf("Classe de l'adresse IP : E\n");
    break;
  case CLASSE_INCONNUE:
    printf("Classe de l'adresse IP : Inconnue\n");
    break;
  }
}

// Détecte le type de l'adresse IP
// Retourne un type d'adresse IP
TypeAdresseIP decoder_type_adresse_ip(const char *ip_adresse) {
  int octet1, octet2, octet3, octet4, masque;
  extraire_champs_ip(ip_adresse, &octet1, &octet2, &octet3, &octet4, &masque);

  // Vérification si l'adresse est de type inconnu
  if (strncmp(ip_adresse, "0.0.0.0", 7) == 0) {
    return TYPE_INCONNU;
  }

  // Vérification si l'adresse est de type broadcast
  if (masque == 32) {
    return TYPE_BROADCAST;
  }
  if (masque >= 24) {
    if ((octet4 & ((1 << (8 - (masque % 8))) - 1)) ==
        ((1 << (8 - (masque % 8))) - 1)) {
      return TYPE_BROADCAST;
    }
  } else if (masque >= 16) {
    if (octet3 == 255 && (octet4 & ((1 << (8 - (masque % 8))) - 1)) ==
                             ((1 << (8 - (masque % 8))) - 1)) {
      return TYPE_BROADCAST;
    }
  } else if (masque >= 8) {
    if (octet2 == 255 && octet3 == 255 &&
        (octet4 & ((1 << (8 - (masque % 8))) - 1)) ==
            ((1 << (8 - (masque % 8))) - 1)) {
      return TYPE_BROADCAST;
    }
  } else {
    if (octet1 == 255 && octet2 == 255 && octet3 == 255 &&
        (octet4 & ((1 << (8 - (masque % 8))) - 1)) ==
            ((1 << (8 - (masque % 8))) - 1)) {
      return TYPE_BROADCAST;
    }
  }

  // Vérification si l'adresse est de type réseau
  if (octet4 == 0) {
    return TYPE_RESEAU;
  }

  // Vérification si l'adresse est de type privé
  // L'adresse IP est dans la plage 172.16.+ - 172.31.+
  // Et 10.+ Et 192.169.+
  if (strncmp(ip_adresse, "10.", 3) == 0 ||
      (strncmp(ip_adresse, "172.", 4) == 0 && (octet2 >= 16 && octet2 <= 31)) ||
      strncmp(ip_adresse, "192.168.", 8) == 0) {
    return TYPE_PRIVEE;
  }

  // Vérification si l'adresse est de type multicast
  if (strncmp(ip_adresse, "224.", 4) == 0 ||
      strncmp(ip_adresse, "239.", 4) == 0) {
    return TYPE_MULTICAST;
  }

  // Vérification si l'adresse est de type localhost
  if (strncmp(ip_adresse, "127.", 4) == 0) {
    return TYPE_LOCALHOST;
  }

  // Si aucune des conditions précédentes n'est remplie,
  // l'adresse IP est publique
  return TYPE_PUBLIQUE;
}

// Détecte la classe de l'adresse IP
// Retourne une classe d'adresse IP
ClasseAdresseIP decoder_classe_adresse_ip(const char *ip_adresse) {
  // Assigne le premier octet à une variable
  unsigned int premier_octet = 0;
  sscanf(ip_adresse, "%u", &premier_octet);

  // Vérification si l'adresse est de classe A
  if (premier_octet >= 1 && premier_octet <= 126) {
    return CLASSE_A;

    // Vérification si l'adresse est de classe B
  } else if (premier_octet >= 128 && premier_octet <= 191) {
    return CLASSE_B;

    // Vérification si l'adresse est de classe C
  } else if (premier_octet >= 192 && premier_octet <= 223) {
    return CLASSE_C;

    // Vérification si l'adresse est de classe D
  } else if (premier_octet >= 224 && premier_octet <= 239) {
    return CLASSE_D;

    // Vérification si l'adresse est de classe E
  } else if (premier_octet >= 240 && premier_octet <= 255) {
    return CLASSE_E;

    // Si aucune des conditions précédentes n'est remplie,
    // l'adresse IP est de classe inconnue
  } else {
    return CLASSE_INCONNUE;
  }
}


#ifndef DECODERIP_H
#define DECODERIP_H

// Enumération des types possibles d'adresses IP
typedef enum {
  TYPE_PUBLIQUE,
  TYPE_PRIVEE,
  TYPE_LOCALHOST,
  TYPE_BROADCAST,
  TYPE_MULTICAST,
  TYPE_RESEAU,
  TYPE_INCONNU
} TypeAdresseIP;

// Enumération des classes possibles d'adresses IP
typedef enum {
  CLASSE_A,
  CLASSE_B,
  CLASSE_C,
  CLASSE_D,
  CLASSE_E,
  CLASSE_INCONNUE
} ClasseAdresseIP;

// Indique le type de l'adresse IP
void afficher_type_adresse_ip(TypeAdresseIP type);

// Indique la classe de l'adresse IP
void afficher_classe_adresse_ip(ClasseAdresseIP classe);

// Détecte le type de l'adresse IP
// Retourne un type d'adresse IP
TypeAdresseIP decoder_type_adresse_ip(const char *ip_adresse);

// Détecte la classe de l'adresse IP
// Retourne une classe d'adresse IP
ClasseAdresseIP decoder_classe_adresse_ip(const char *ip_adresse);

#endif

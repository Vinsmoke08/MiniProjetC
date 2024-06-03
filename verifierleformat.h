#ifndef VERIFIERFORMAT_H
#define VERIFIERFORMAT_H

// Fonction pour vérifier si le format de l'adresse IP est valide
// Vérifie que les octets sont compris entre 0 et 255 et que le masque est entre 0 et 32
int ip_format_valide(const char *ip_adresse);

#endif

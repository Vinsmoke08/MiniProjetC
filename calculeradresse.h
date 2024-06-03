#ifndef CALCULERADRESSE_H
#define CALCULERADRESSE_H

// Détermine l'adresse réseau à partir de l'adresse IP
void calculeradressereseau(const char *ip_adresse, char *adresse_reseau);

// Calcule le nombre d'hôtes disponibles dans le réseau
int calculer_nombre_hotes(const char *ip_adresse);

#endif

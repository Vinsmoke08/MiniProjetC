#ifndef EXTRAIRELESCHAMPS_H
#define EXTRAIRELESCHAMPS_H

// Décompose l'adresse IP et extrait les octets et le masque de sous-réseau
void extraire_champs_ip(const char *ip_adresse, int *octet1, int *octet2,
                        int *octet3, int *octet4, int *masque);

#endif

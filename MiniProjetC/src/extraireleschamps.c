#include "extraireleschamps.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Décompose l'adresse IP et extrait les octets et le masque de sous-réseau
void extraire_champs_ip(const char *ip_adresse, int *octet1, int *octet2,
                        int *octet3, int *octet4, int *masque) {
  sscanf(ip_adresse, "%d.%d.%d.%d/%d", octet1, octet2, octet3, octet4, masque);
}

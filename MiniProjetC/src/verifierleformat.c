#include "verifierleformat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour vérifier si le format de l'adresse IP est valide
// Vérifie que les octets sont compris entre 0 et 255 et que le masque est entre 0 et 32
int ip_format_valide(const char *ip_adresse) {
    int octet1, octet2, octet3, octet4, subnet;

    // Scanner et extraire les octets et le masque de l'adresse IP
    int numScanned = sscanf(ip_adresse, "%d.%d.%d.%d/%d", &octet1, &octet2, &octet3, &octet4, &subnet);

    // Vérifier si les 5 valeurs ont été correctement scannées
    if (numScanned == 5) {
        // Vérifier que chaque octet est dans la plage valide (0-255)
        if (octet1 >= 0 && octet1 <= 255 && octet2 >= 0 && octet2 <= 255 &&
            octet3 >= 0 && octet3 <= 255 && octet4 >= 0 && octet4 <= 255) {
            // Vérifier que le masque est dans la plage valide (0-32)
            if (subnet >= 0 && subnet <= 32) {
                return 1;  // Format valide
            } else {
                return 0;  // Masque invalide
            }
        } else {
            return 0;  // Un des octets est invalide
        }
    } else {
        return 0;  // Format d'adresse IP incorrect
    }
}

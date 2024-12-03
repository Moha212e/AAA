#include "Requete.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h> // Pour `time_t`

void HandleTCPClient(int clntSocket) {
    struct Requete clientRequest;    // Requête reçue du client
    struct Requete serverResponse;  // Réponse à envoyer au client

    // Lire la requête envoyée par le client
    if (read(clntSocket, &clientRequest, sizeof(clientRequest)) <= 0) {
        perror("read() failed");
        close(clntSocket);
        return;
    }

    // Afficher la requête reçue pour le débogage
    printf("Requête reçue :\n");
    AfficheRequete(stdout, clientRequest);

    // Initialiser la réponse
    memset(&serverResponse, 0, sizeof(serverResponse));
    serverResponse.Type = OK;  // Par défaut, la réponse est positive
    serverResponse.Numero = clientRequest.Numero;
    serverResponse.Date = time(NULL); // Date actuelle

    // Traiter la requête selon le type
    switch (clientRequest.Type) {
        case Question:
            snprintf(serverResponse.Constructeur, sizeof(serverResponse.Constructeur), "Toyota");
            snprintf(serverResponse.Modele, sizeof(serverResponse.Modele), "Corolla");
            serverResponse.Prix = 15000;
            break;

        case Achat:
            if (clientRequest.Quantite > 0) {
                snprintf(serverResponse.NomClient, sizeof(serverResponse.NomClient), "%s", clientRequest.NomClient);
                serverResponse.NumeroFacture = 12345;  // Exemple de numéro de facture
                serverResponse.Prix = clientRequest.Quantite * 15000;  // Exemple de calcul
            } else {
                serverResponse.Type = Fail;
            }
            break;

        case Livraison:
            snprintf(serverResponse.Constructeur, sizeof(serverResponse.Constructeur), "%s", clientRequest.Constructeur);
            snprintf(serverResponse.Modele, sizeof(serverResponse.Modele), "%s", clientRequest.Modele);
            break;

        default:
            serverResponse.Type = Fail;
            break;
    }

    // Envoyer la réponse au client
    if (write(clntSocket, &serverResponse, sizeof(serverResponse)) != sizeof(serverResponse)) {
        perror("write() failed");
    } else {
        printf("Réponse envoyée :\n");
        AfficheRequete(stdout, serverResponse);
    }

    // Fermer la connexion avec le client
    close(clntSocket);
}

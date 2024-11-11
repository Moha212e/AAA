#include "Classroom.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// Constructeur par défaut
Classroom::Classroom() {
    setName("");
    setSeatingCapacity(0);
}

// Constructeur avec paramètres
Classroom::Classroom(int i, string n, int s) {
    Schedulable::setId(i);  // Initialiser l'ID via la classe de base
    setName(n);
    setSeatingCapacity(s);
}

// Fonction pour obtenir l'ID
int Classroom::getId() const {
    return Schedulable::getId();  // Utiliser la méthode de la classe de base
}

// Setters
void Classroom::setName(string n) {
    name = n;
}

void Classroom::setSeatingCapacity(int s) {
    seatingCapacity = s;
}

// Getters
string Classroom::getName() const {
    return name;
}

int Classroom::getSeatingCapacity() const {
    return seatingCapacity;
}

// Méthode toString
string Classroom::toString() const {
    ostringstream oss;
    oss << name << " " << seatingCapacity;
    return oss.str();
}

// Méthode tuple
string Classroom::tuple() const {
    ostringstream oss;
    oss << Schedulable::getId() << ";" << name << ";" << seatingCapacity;
    return oss.str();
}

// Opérateur d'assignation
Classroom &Classroom::operator=(const Classroom &c) {
    Schedulable::setId(c.getId());  // Copier l'ID de l'objet source
    setName(c.getName());
    setSeatingCapacity(c.getSeatingCapacity());
    return *this;
}

// Opérateur de flux de sortie (sérialisation)
std::ostream &operator<<(std::ostream &os, const Classroom &c) {
    os << "<Classroom>" << std::endl;
    os << "<id>" << c.getId() << "</id>" << std::endl;  // Affichage de l'ID
    os << "<name>" << c.getName() << "</name>" << std::endl;
    os << "<seatingCapacity>" << c.getSeatingCapacity() << "</seatingCapacity>" << std::endl;
    os << "</Classroom>" << std::endl;
    return os;
}

// Opérateur de flux d'entrée (désérialisation)
std::istream &operator>>(std::istream &is, Classroom &c) {
    std::string line;
    while (std::getline(is, line)) {
        // Rechercher et lire l'ID entre les balises <id> et </id>
        if (line.find("<id>") != std::string::npos) {
            int id;
            is >> id;
            c.setId(id);  // Affecter l'ID
            std::getline(is, line);  // Consommer la ligne de fermeture </id>
        }
        // Rechercher et lire le nom entre les balises <name> et </name>
        else if (line.find("<name>") != std::string::npos) {
            std::string name;
            std::getline(is, name);  // Lire le nom
            c.setName(name);
            std::getline(is, line);  // Consommer la ligne de fermeture </name>
        }
        // Rechercher et lire la capacité entre <seatingCapacity> et </seatingCapacity>
        else if (line.find("<seatingCapacity>") != std::string::npos) {
            int capacity;
            is >> capacity;
            c.setSeatingCapacity(capacity);
            std::getline(is, line);  // Consommer la ligne de fermeture </seatingCapacity>
        }
    }
    return is;
}

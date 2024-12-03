#include "XmlFileSerializer.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace planning
{
    // Constructeur
    template <typename T>
    XmlFileSerializer<T>::XmlFileSerializer(const std::string &fn, char m, const std::string &cn)
        : fileName(fn), mode(m), collectionName(cn)
    {
        if (mode == WRITE)
        {
            file.open(fileName, std::ios::out);
            if (!file.is_open())
            {
                throw XmlFileSerializerException("Erreur en mode WRITE; impossible d'ouvrir le fichier", XmlFileSerializerException::FILE_NOT_FOUND);
            }
            file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
            file << "<" << collectionName << ">" << std::endl;
        }
        else if (mode == READ)
        {
            file.open(fileName, std::ios::in);
            if (!file.is_open())
            {
                throw XmlFileSerializerException("Erreur en mode READ; le fichier n'existe pas sur le disque", XmlFileSerializerException::FILE_NOT_FOUND);
            }
            std::string line, sCollectionName;
            std::getline(file, line); // Lire la déclaration XML
            if (line.find("<?xml") == std::string::npos)
            {
                throw XmlFileSerializerException("Fichier non valide: déclaration XML manquante", XmlFileSerializerException::INVALID_FILE);
            }
            std::getline(file, sCollectionName);
            collectionName = sCollectionName.substr(1, sCollectionName.length() - 2);
        }
        else
        {
            throw XmlFileSerializerException("Mode invalide spécifié", XmlFileSerializerException::INVALID_MODE);
        }
    }

    // Destructeur
    template <typename T>
    XmlFileSerializer<T>::~XmlFileSerializer() noexcept
    {
        if (mode == WRITE && file.is_open())
        {
            file << "</" << collectionName << ">" << std::endl;
        }
        if (file.is_open())
        {
            file.close();
        }
    }

    // Getter pour fileName
    template <typename T>
    std::string XmlFileSerializer<T>::getFilename() const noexcept
    {
        return fileName;
    }

    // Getter pour collectionName
    template <typename T>
    std::string XmlFileSerializer<T>::getCollectionName() const noexcept
    {
        return collectionName;
    }

    // Vérifie si le mode est READ
    template <typename T>
    bool XmlFileSerializer<T>::isReadable() const noexcept
    {
        return mode == READ;
    }

    // Vérifie si le mode est WRITE
    template <typename T>
    bool XmlFileSerializer<T>::isWritable() const noexcept
    {
        return mode == WRITE;
    }

    // Écriture dans le fichier
    template <typename T>
    void XmlFileSerializer<T>::write(const T &val)
    {
        if (mode == READ)
        {
            throw XmlFileSerializerException("Erreur; mode doit être WRITE et pas READ", XmlFileSerializerException::NOT_ALLOWED);
        }
        if (!file.is_open())
        {
            throw XmlFileSerializerException("Erreur; fichier fermé", XmlFileSerializerException::FILE_NOT_OPEN);
        }
        file << val << std::endl;
    }

    // Lecture depuis le fichier
    template <typename T>
    T XmlFileSerializer<T>::read()
    {
        if (mode == WRITE)
        {
            throw XmlFileSerializerException("Erreur; mode doit être READ et pas WRITE", XmlFileSerializerException::NOT_ALLOWED);
        }
        if (!file.is_open())
        {
            throw XmlFileSerializerException("Erreur; fichier fermé", XmlFileSerializerException::FILE_NOT_OPEN);
        }

        std::string line;
        T val;

        // Sauvegarder la position actuelle pour vérifier la fin
        std::streampos currentPos = file.tellg();
        file >> line;

        // Vérifier si la fin de la collection est atteinte
        if (line == "</" + collectionName + ">")
        {
            throw XmlFileSerializerException("Fin du fichier atteinte", XmlFileSerializerException::END_OF_FILE);
        }

        // Revenir à la position précédente et lire l'objet
        file.seekg(currentPos);
        file >> val;

        return val;
    }
}

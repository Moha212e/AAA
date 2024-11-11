# Makefile pour UNIX_Exercice4 et Traitement

CXX = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
INCLUDES = -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I/usr/include/mysql
QT_LIBS = /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so
MYSQL_LIBS = -L/usr/lib64/mysql -lmysqlclient -lpthread -lz -lm -lrt -lssl -lcrypto -ldl

# Cibles pour les exécutables
all: UNIX_Exercice4 Traitement

# Cible pour l'exécutable UNIX_Exercice4
UNIX_Exercice4: mainex4.o mainwindowex4.o moc_mainwindowex4.o
	$(CXX) -o $@ $^ $(QT_LIBS) $(MYSQL_LIBS)

# Cible pour l'exécutable Traitement
Traitement: maintraitement.o mainwindowtraitement.o moc_mainwindowtraitement.o
	$(CXX) -o $@ $^ $(QT_LIBS) $(MYSQL_LIBS)

# Compilation des fichiers .cpp en fichiers objets .o pour UNIX_Exercice4
mainex4.o: mainex4.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

mainwindowex4.o: mainwindowex4.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

moc_mainwindowex4.o: moc_mainwindowex4.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

# Compilation des fichiers .cpp en fichiers objets .o pour Traitement
maintraitement.o: maintraitement.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

mainwindowtraitement.o: mainwindowtraitement.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

moc_mainwindowtraitement.o: moc_mainwindowtraitement.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

# Commande pour nettoyer les fichiers objets et exécutables
clean:
	rm -f *.o UNIX_Exercice4 Traitement

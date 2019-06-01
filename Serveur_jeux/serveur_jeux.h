#ifndef SERVEUR_JEUX_H
#define SERVEUR_JEUX_H

#include <QtWidgets>
#include<QtNetwork>
#include <QMainWindow>
#include<QtSql>

#include "ui_serveur_jeux.h"


namespace Ui {
class serveur_jeux;
}

class serveur_jeux : public QMainWindow, private Ui::serveur_jeux
{
    Q_OBJECT

public:
    explicit serveur_jeux(QWidget *parent = nullptr);
    ~serveur_jeux();

private slots :
void demande_connexion() ;
void lecture();
void deconnexion();
//void envoyer(const QString &message);
void on_pushButton_clicked();

void on_pushButton_2_clicked();

void on_actionQuittez_triggered();

void on_pushButton_8_clicked();

void on_pushButton_7_clicked();

void on_pushButton_10_clicked();

//void on_pushButton_9_clicked();

//void on_pushButton_6_clicked();

void   envoyerVeri(const QString &vrai);
void envoyerMessage();

void on_pushButton_9_clicked();

private:
    Ui::serveur_jeux *ui;
    QTcpSocket *clientConnection;
    QTcpServer *server;
     QSqlDatabase db;

     QString nom;
     QString indice__db;
     int position ;
     int nombre;
     QString ligne;
     QString lig;
     bool connecter;
     bool reponse;
};

#endif // SERVEUR_JEUX_H

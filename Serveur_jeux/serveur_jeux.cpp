#include "serveur_jeux.h"
#include "ui_serveur_jeux.h"
#include <iostream>

using namespace std;

serveur_jeux::serveur_jeux(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serveur_jeux)
{
    setupUi(this);

    QObject::connect(actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    server = new QTcpServer(this);


    if(!server->listen(QHostAddress::Any, 9089))
    {
        label_2->setText("Connexion échouée!\n"+ server->errorString());
    }else
    {

        db = QSqlDatabase::addDatabase("QSQLITE" , "CONNECTION NAME");
        db.setDatabaseName(":Pendu:");

        connecter = db.open();

        if(!connecter)
        {
            qDebug() << "Can't create in-memory Database!";
        }else
        {
            qDebug() << "In-memory Successfully created!";
            QSqlQuery query(db);
            if(!query.exec("SELECT ID, mot , indice, commentaire FROM motss"))
            {
                qDebug() << "Can't Execute Query !";
                return;
            }
            qDebug() << "Query Executed Successfully !";
            while(query.next())
            {

                QString id = query.value(0).toString();

                QString nom = query.value(1).toString();

                QString number = query.value(2).toString();

                 QString numb = query.value(3).toString();



                qDebug() << "Employee ID : " << query.value(0).toString();
                qDebug() << "Employee Mot  : " << query.value(1).toString();
                qDebug() << "Employee Indice: " << query.value(2).toString();
                qDebug() << "Employee Indice: " << query.value(3).toString();


            }

        label_2->setText("Connexion au serveur réussie sur le port "+ QString::number(server->serverPort())+ ". \n Les clients peuvent maintenant se  connecter.");
        QObject:: connect(server, SIGNAL(newConnection()), this, SLOT(demande_connexion()));

        }}

}


void serveur_jeux :: demande_connexion()
{
// on crée une nouvelle socket pour ce client
clientConnection = server->nextPendingConnection();
// si on reçoit des données, le slot lecture() est appelé
label_6->setText("Connexion établie");

QObject:: connect(clientConnection, SIGNAL(readyRead()),this, SLOT(lecture()));


}

void serveur_jeux ::lecture()
{

cout<<"Etape 1"<<endl;


while(clientConnection->canReadLine()) // tant qu'on peut lire sur la socket
{
    cout<<"Etape 2"<<endl;
  lig = clientConnection->readLine();
        // on lit une ligne

    cout<<"Etape 3"<<endl;
}

cout<<"Etape 4"<<endl;

QTextStream texte(clientConnection); // création d'un flux pour écrire dans la socket
    label_4->setText(lig);

    qDebug()<<lig;


    nombre = lig.size() - 1;
    QString vMot = lig.left(nombre);
    qDebug()<<vMot;


    envoyerVeri(vMot);
        envoyerMessage();

}

serveur_jeux::~serveur_jeux()
{
    db.close();
    delete ui;
}

void serveur_jeux::deconnexion()
{
    label_6->setText("Connexion perdue");
    server->deleteLater();

}

void serveur_jeux::on_pushButton_clicked()
{
    int rep = QMessageBox::critical(this, "Quittez", "Voulez-vous stopper le serveur?", QMessageBox::No | QMessageBox::Yes);

    if (rep == QMessageBox::No)
    {
        this->show();
    }else
    {
        this->close();
    }
}

void serveur_jeux::on_actionQuittez_triggered()
{
    int rep = QMessageBox::critical(this, "Quittez", "Voulez-vous stopper le serveur?", QMessageBox::No | QMessageBox::Yes);

    if (rep == QMessageBox::No)
    {
        this->show();
    }else
    {
        this->close();
    }
}

void serveur_jeux::on_pushButton_2_clicked()
{
    stackedWidget->setCurrentIndex(1);
}



void serveur_jeux::on_pushButton_8_clicked()
{
    stackedWidget->setCurrentIndex(0);
}

void serveur_jeux::on_pushButton_7_clicked()
{
    int rep = QMessageBox::critical(this, "Quittez", "Voulez-vous stopper le serveur?", QMessageBox::No | QMessageBox::Yes);

    if (rep == QMessageBox::No)
    {
        this->show();
    }else
    {
        this->close();
    }
}


void serveur_jeux::on_pushButton_10_clicked()
{
    stackedWidget_2->setCurrentIndex(1);
}

void serveur_jeux::envoyerMessage()
{
    QTextStream out(clientConnection);
cout<<"Etape "<<endl;

srand(time(0));


 position = rand() % 7;


if(position != 0)
{

    if(!connecter)
    {
        qDebug() << "Can't create in-memory Database!";
    }else
    {
        qDebug() << "In-memory Successfully created!";
        QSqlQuery query(db);
        if(!query.exec("SELECT ID, mot , indice, commentaire FROM motss WHERE ID ="+QString::number(position)+""))
        {
            qDebug() << "Can't Execute Query !";
            return;
        }
        qDebug() << "Query Executed Successfully !";
        while(query.next())
        {

            QString id = query.value(0).toString();

            nom = query.value(1).toString();

            indice__db= query.value(2).toString();

            QString numb = query.value(3).toString();



            qDebug() << "MOT ID : " << query.value(0).toString();
            qDebug() << "MOT Mot  : " << query.value(1).toString();
            qDebug() << "MOT Indice: " << query.value(2).toString();
            qDebug() << "MOT Commentaire : " << query.value(3).toString();


        }
        QTextStream out(clientConnection);

        QString messageAEnvoyer = indice__db;


        qDebug()<<messageAEnvoyer<<endl;

        out<<messageAEnvoyer<<endl;

    }}
}

void serveur_jeux::envoyerVeri(const QString &vrai)
{
    if (vrai == nom)
    {
        reponse = true;
    }else
    {
        reponse = false;
    }

    qDebug()<<reponse;
    qDebug()<<nom;
    qDebug()<<vrai;

    QTextStream out(clientConnection);


    qDebug()<<reponse<<endl;

    out<<reponse<<endl;

}

void serveur_jeux::on_pushButton_9_clicked()
{
    stackedWidget_2->setCurrentIndex(0);
}

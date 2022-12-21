/**************************************************************************
    PROTÓTIPO de Interface de configuração de estação Metereológica (ICEM)
    Arquivo de cabeçalho

    Descrição: Neste arquivo contém as variáveis necessárias para o projeto

    Por: Saulo José Almeida Silva
    Última atualização: 21/12/2022
**************************************************************************/
#ifndef ICEMCONFIG_H
#define ICEMCONFIG_H

/*==========================||BIBLIOTECAS||==============================*/
//Bibliotecas Necessárias
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

//Biblioteca do Sistema de controle dos arquivos
#include "SPIFFS.h"

/*================|| Variáveis do protótipo || =======================*/

//enumeração
enum ConectionMode { APMode, //Modo de conexão Acess Point
                     WiFiMode,  //Modo de conexão WiFi
                     BluetoothMode, //Modo de Conexão Bluetooth
                     SMSMode}; //Modo de Conexão SMSM

//Como Padrão o valor começa como APMode
volatile ConectionMode Mode = APMode; 

//Modelo do projeto
const char* MODELO = "MeteoPIN 1.2";
const char* TOKEN = "BMOD0112PIAL";
const char* LOCAL = "Palmeira dos Índios - AL";


/*================|| Variáveis de Conexão com a REDE||=================*/
//Criando objeto do servidor assíncron
AsyncWebServer server(80);

//Configurações para acesso a internet
IPAddress localIp;
IPAddress localGateway;
IPAddress subnet; //É necessário criar uma

//Variáveis de configuração

//WiFi Mode
static String ssid;
static String pass;
static String ip;
static String gateway;
static String mascara;

//AcessPoint
static String ssidAP;
static String passAP;
static String ipAP;

//Bluetooth Mode


//SMS mode

/*=======================|| Caminhos para os arquivos ||================*/

//Parâmetros do formulário HTTP POST

//Parâmetros para WiFiManager
const char* PARAM_INPUT_1 = "ssid";
const char* PARAM_INPUT_2 = "pass";
const char* PARAM_INPUT_3 = "ip";
const char* PARAM_INPUT_4 = "gateway";
const char* PARAM_INPUT_41 = "mascara";

//Parâmetros para configurações de AcessPoint
const char* PARAM_INPUT_5 = "ssidAP"; //Nome do acessPoint
const char* PARAM_INPUT_6 = "passAP"; //Senha para o acessPoint
const char* PARAM_INPUT_7 = "ipAP";   //IP que foi configurado
const char* PARAM_INPUT_8 = "OK";     //Serve apenas para resetar as configurações

//Caminhos para os arquivos no sistema de arquivos
//arquivos da configuração WiFi
const char* ssidPath = "/ssid.txt";
const char* passPath = "/password.txt";
const char* ipPath = "/ip.txt";
const char* gatewayPath = "/gateway.txt";
const char* mascaraPath = "/mascara.txt";

//arquivos da configuração do AcessPoint
const char* ssidAPPath = "/ssidAP.txt";
const char* passAPPath = "/passwordAP.txt";
const char* ipAPPath = "/ipAP.txt";

/*==========================* Funções *====================================*/

/*================| Funções para gerenciar os arquivos |==================*/
//Sistema de gerenciamento de arquivos

//Função para inicializar o sistemade arquivos
void initSPIFFS();

//Funções para gerenciamento do SPIFFS
String readFile(fs::FS &fs, const char * path);

//Função para escrever em um arquivo
void writeFile(fs::FS &fs, const char * path, const char * message);

//configurar todos os arquivos
void configurar();

//Função para resetar todos os arquivos ao modo de fabricante
void resetSPIFFS();

//resetar dados cadastrados no WiFi, caso eles não sejam verdadeiros.
void resetWiFiConfig();

/*=================| FUNÇÕES PARA CONFIGURAR A INTERFACE | ================*/

//Atualiza PlaceHolders
String processor(const String& var);

/*=================| FUNÇÕES PARA CONFIGURAÇÃO DE REDE|===================*/

//Iniciar configuração WiFi
bool initWiFi();

//Configura o servidor dentro da rede.
bool initServerAP(AsyncWebServer* server);

//configura o servidor em modo estação.
bool initServerWEB(AsyncWebServer* server);

#endif

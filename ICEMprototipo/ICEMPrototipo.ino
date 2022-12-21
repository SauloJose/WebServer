/**************************************************************************
    PROTÓTIPO de Interface de configuração de estação Metereológica (ICEM)
    Arquivo fonte

    Descrição: Este projeto utiliza do SPIFFS do ESP32 para gerar uma
               interface de configurações de conexão e análise de dados

    Por: Saulo José Almeida Silva
    Última atualização: 21/12/2022
**************************************************************************/
//incluindo arquivo de configurações
#include "ICEMconfig.h"


void setup() {
  //Iniciando a Serial
  Serial.begin(115200);

  //Iniciando o SPIFFS
  initSPIFFS();

  //Configurando os arquivos do SPIFFS.
  configurar();

  //Gerando servidor assíncrono
  if(initWiFi()){
    initServerWEB(&server);
  }else{
    initServerAP(&server);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

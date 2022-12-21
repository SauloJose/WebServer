/*Variáveis globais*/

console.log("[MeteoPin]: Conseguiu conectar....");

//variáveis do produto
var modelo;
var token;
var localizacao;
var modo;
var atualização;

//variaveis do ponto de acesso
var sap 
var ipap
var pap


if(typeof(Storage)!=="undefined"){
    console.log("suporta web storage")
}else{
    console.log("Desculpa, não suporta web storage")
}
/*
Projeto: Conversor de Bases Numericas em C++

O programa é simples mas realiza convertor entre as bases
binario, decimal, octal e hexadecimal.

Foi feito com o auxilio de IA, me ensinando passo a passo
mas atesto que busquei compreender cada passo desse script.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

// Funcao para converter decimal em binario
string decimalParaBinario(int numero) {

    string resultado = "";

    if (numero == 0) {
        return "0";
    }

    while (numero > 0) {

        int resto = numero % 2;

        if (resto == 1){
        	resultado = "1" + resultado;
		} else {
			resultado = "0" + resultado;
		}

        numero = numero / 2;
    }

    return resultado;
}
//Funcao para converter decimal para octal
string decimalParaOctal(int numero){
	
	string resultado = "";
	
	if (numero == 0){
		return "0";
	}
	
	while (numero > 0){
		
		int resto = numero % 8;
		
		if (resto >= 0 && resto <= 7){
			resultado = char('0' + resto) + resultado;
		}
		
		numero = numero / 8;
	}
	
	return resultado;
}
//funcao para converter decimal para hexadecimal
string decimalParaHexadecimal(int numero){
	
	string resultado = "";
	
	if (numero == 0){
		return "0";
	}
	
	while (numero > 0){
		
		int resto = numero % 16;
		
		if (resto < 10){
			resultado = char('0' + resto) + resultado;
		} else{
			resultado = char('A'+ (resto - 10)) + resultado;
		}
	
	numero = numero / 16;
	}
	
	return resultado;
}
//funcao para converter binario para decimal
int binarioParaDecimal(string numero){
	
	int resultado = 0;
	int i = 0;
	
	while (i < numero.length()){
		char digito = numero[i];
		
		if (digito != '0' && digito != '1'){
			return -1;
		}
		
		int valor = digito - '0';
		
		if (resultado > (INT_MAX - valor) / 2){
			return -2;
		}
		
		resultado = resultado * 2 + valor;
		
		i++;
	}
	
	return resultado;
}
//funcao para converter octal para decimal
int octalParaDecimal(string numero){
	
	int resultado = 0;
	int i = 0;
	
	while (i < numero.length()){
		char digito = numero[i];
		
		if (digito < '0' || digito > '7'){
			return -1;
		}
	
		int valor = digito - '0';
		
		if (resultado > (INT_MAX - valor) / 8){
			return -2;
		}
		
		resultado = resultado * 8 + valor;
		
		i++;
		
	}
	
	return resultado;
}
//funcao para converter hexadecimal para decimal
int hexadecimalParaDecimal(string numero){

	int resultado = 0;
	int i = 0;
	
	while (i < numero.length()){
		char digito = numero[i];
		int valor;
		
		if (digito >= '0' && digito <= '9'){
			valor = digito - '0';
		}else if (digito >= 'A' && digito <= 'F'){
			valor = digito - 'A' + 10;
		}else if (digito >= 'a' && digito <= 'f'){
			valor = digito - 'a' + 10;
		}else{
			return -1;
		}
		
		if (resultado > (INT_MAX - valor) / 16){
			return -2;
		}
		
		resultado = resultado * 16 + valor;
		
		i++;
	}
	
	return resultado;
}
//funcao para verificar caracteres
bool numeroValido(string entrada){
	
	int i = 0;
	
	if (entrada.length() == 0){
		return false;
	}
	
	while (i < entrada.length()){
		
		if (entrada[i] < '0' || entrada [i] > '9'){
			return false;
		}
		
		i++;
	}
	
	return true;
}


// =====================================
//         PROGRAMA PRINCIPAL
// =====================================


int main(){
	
	int opcao;
	// CARA INICIAL DO PROGRAMA
	do {
		cout << "----------------------------------" << endl;
		cout << endl;	
		cout << "============================" << endl;
		cout << "     CONVERSOR DE BASES     " << endl;
		cout << "============================" << endl;
	
		cout << "1 - Binario" << endl;
		cout << "2 - Decimal" << endl;
		cout << "3 - Octal" << endl;
		cout << "4 - Hexadecimal" << endl;
		cout << "0 - Sair" << endl;
	
		cout << "\nEscolha a base de origem: ";
		cin >> opcao;
		
		if (cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			
			cout << "Entrada invalida! Digite um numero." << endl;
			
			opcao = -1;
			continue;
		}
	// MENU SWITCH COMEÇA AQUI
		switch (opcao){
			// BINARIO
			case 1:{
				string numero;
				
				cout << endl;
				cout << "Digite um numero binario: ";
				cin >> numero;
				cout << endl;
				
				int resultado = binarioParaDecimal(numero);
				
				if (resultado == -1){
					cout << "Numero binario invalido!" << endl;
				}else if (resultado == -2){
					cout << "Numero binario muito grande!" << endl;
				}else{
					cout << "Resultado em decimal: " << resultado << endl;
				}
				
				break;
			}
			// DECIMAL	
			case 2: {
				string entrada;
				int numero;
				int subOpcao;
				
				cout << endl;
				cout << "====== CONVERSAO DECIMAL ======" << endl;
				cout << endl;
				
				cout << "1 - Decimal para binario" << endl;
				cout << "2 - Decimal para octal" << endl;
				cout << "3 - Decimal para hexadecimal" << endl;
				cout << "4 - Mostrar todas as conversoes" << endl;
				cout << "0 - Voltar ao menu principal" << endl;
				
				cout << endl;
				cout << "Escolha uma opcao: ";
				cin >> subOpcao;
				cout << endl;
				
				//verifica se a entrada do submenu e valida
				if (cin.fail()){
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Opcao invalida!" << endl;
					break;
				}
				
				//Volta ao menu principal
				if (subOpcao == 0){
					cout << "Voltando ao menu principal..." << endl;
					break;
				}
				
				//verifica se a opcao existe
				if (subOpcao < 1 || subOpcao > 4){
					cout << "Opcao invalida!" << endl;
					break;
				}
				
				cout << endl;
				cout << "Digite um numero decimal: ";
				cin >> entrada;
				
				if (numeroValido(entrada) == false){
					cout << "Numero invalido!" << endl;
					break;
				}
				
				stringstream conversor(entrada);
				
				if (!(conversor >> numero)){
					cout << "Numero muito grande ou invalido!" << endl;
					break;
				}
				
				cout << endl;
				
				switch (subOpcao){
					
					case 1:
						cout << "Resultado em binario: " << decimalParaBinario(numero) << endl;
						break;
					
					case 2:
						cout << "Resultado em octal: " << decimalParaOctal(numero) << endl;
						break;
						
					case 3:
						cout << "Resultado em hexadecimal: " << decimalParaHexadecimal(numero) << endl;
						break;
					
					case 4:
						cout << "Resultado em binario: " << decimalParaBinario(numero) << endl;
				
						cout << "Resultado em octal: " << decimalParaOctal(numero) << endl;
				
						cout << "Resultado em hexadecimal: " << decimalParaHexadecimal(numero) << endl;
						break;
						
					case 0:
						cout << "Voltando ao menu principal..." << endl;
						break;
						
					default:
						cout << "Opcao invalida" << endl;
				}
				
				break;
		}
			// OCTAL	
			case 3:{
				string numero;
				
				cout << endl;
				cout << "Digite um numero octal: ";
				cin >> numero;
				cout << endl;
				
				int resultado = octalParaDecimal(numero);
				
				if (resultado == -1){
					cout << "Numero octal invalido!" << endl;
				}else if (resultado == -2){
					cout << "Numero octal muito grande!" << endl;
				}else{
					cout << "Resultado em decimal: " << resultado << endl;
				}
				
				break;
			}
			// HEXADECIMAL
			case 4:{
				string numero;
				
				cout << endl;
				cout << "Digite um numero hexadecimal: ";
				cin >> numero;
				cout << endl;
				
				int resultado = hexadecimalParaDecimal(numero);
				
				if (resultado == -1){
					cout << "Numero hexadecimal invalido!" << endl;
				}else if (resultado == -2){
					cout << "Numero hexadecimal muito grande!" << endl;
				}else{
					cout << "Resultado em decimal: " << resultado << endl;
				}
				
				break;
			}
			// EXIT			
			case 0:
				cout << "Encerrando programa..." << endl;
				break;
			// CODIGO DE ERRO, RETORNA AO COMEÇO	
			default:
				cout << "Opcao invalida! Tente novamente." << endl;
				
				break;
		}
		
		cout << endl << endl;
			
	}while (opcao != 0);
		
	return 0;
}

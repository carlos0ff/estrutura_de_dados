/**
 * Função : Inverter uma string usando recursão.
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q5 - Recursão.
 */
package algoritmos.recursao.java;
import java.util.Scanner;

public class ED2Lista1_questao05 {
    
    // Função recursiva para inverter a string
    public static String inverterString(String str) {
        // Caso base: se a string estiver vazia ou tiver um caractere, retorna a própria string
        if (str.isEmpty()) {
            return str;
        }
        // Chamada recursiva: pega o último caractere e concatena com a inversão do restante da string
        return str.charAt(str.length() - 1) + inverterString(str.substring(0, str.length() - 1));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Solicita ao usuário que insira uma string
        System.out.print("Digite uma string para inverter: ");
        String inputString = scanner.nextLine();
        
        // Chama a função recursiva para inverter a string
        String invertedString = inverterString(inputString);
        
        // Exibe a string invertida
        System.out.println("String invertida: " + invertedString);
        
        scanner.close();
    }
}
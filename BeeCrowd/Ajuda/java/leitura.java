import java.util.Scanner;

public class leitura {
    char lerUmChar(Scanner entrada){
        char resp;
        System.out.println("Digite uma letra: ");
        resp = entrada.nextLine().charAt(0);
        return resp;
    }
    
    String lerUmaLinha(Scanner entrada){
        String resp;
        System.out.println("Digite uma linha: ");
        resp = entrada.nextLine();
        return resp;
    }
    
    int lerUmInt(Scanner entrada){
        int resp;
        System.out.println("Digite um numero: ");
        resp = Integer.parseInt(entrada.nextLine());
        return resp;
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
    }
    
}
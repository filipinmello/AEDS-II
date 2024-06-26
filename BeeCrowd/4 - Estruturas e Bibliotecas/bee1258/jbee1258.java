import java.util.Scanner;

public class jbee1258 {
    static class Camisa{
        public String nome;
        public String cor;
        public char tamanho;

        public Camisa(String nome, String cor, char tamanho) {
            this.nome = nome;
            this.cor = cor;
            this.tamanho = tamanho;
        }
        
    }

    static void mostrar(Camisa array[], int tam){
        for (int i = 0; i < tam; i++) {
            System.out.println(array[i].cor + " " + array[i].tamanho + " " + array[i].nome);
        }
    }

    static void ordenar(Camisa array[], int tam){
        Camisa tmp;
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                if(array[j].cor.compareTo(array[i].cor) > 0){
                    tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                }else if(array[j].cor.equals(array[i].cor) && array[j].tamanho < array[i].tamanho){
                    tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                }else if(array[j].cor.equals(array[i].cor) && array[j].tamanho == array[i].tamanho && array[j].nome.compareTo(array[i].nome) > 0){
                    tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int N = Integer.parseInt(entrada.nextLine());
        String nome, cor;
        char tamanho;
        String[] parts;
        
        while (N != 0) {
            Camisa[] alunos = new Camisa[N];
            for (int i = 0; i < N; i++) {
                nome = entrada.nextLine();
                String input = entrada.nextLine();
                parts = input.split(" ");
                cor = parts[0];
                tamanho = parts[1].charAt(0);

                alunos[i] = new Camisa(nome, cor, tamanho);
            }

            ordenar(alunos, N);
            mostrar(alunos, N);

            N = Integer.parseInt(entrada.nextLine());
            System.out.println();
        }

        entrada.close();
    }
}
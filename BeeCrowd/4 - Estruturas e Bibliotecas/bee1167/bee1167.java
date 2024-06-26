import java.util.Scanner;

public class bee1167 {
    static class Pessoa{
        String nome;
        int num;
        public Pessoa(String nome, int num) {
            this.nome = nome;
            this.num = num;
        }
    }

    static void mostrar(Pessoa[] array, int tam){
        for (int i = 0; i < tam; i++) {
            System.out.println(array[i].nome + ", " + array[i].num);
        }
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Pessoa[] alunos = new Pessoa[100];

        int N = Integer.parseInt(entrada.nextLine());

        for (int i = 0; i < N; i++) {
            String line = entrada.nextLine();
            String[] parts = line.split(" ");
            alunos[i] = new Pessoa(parts[0], Integer.parseInt(parts[1]));
        }

        mostrar(alunos, N);
    }
}
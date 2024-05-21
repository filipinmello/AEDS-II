import java.util.Scanner;


public class bee1861 {
    static class Lista{
        private Pessoas array[];
        public int tam;
    
        public Lista(){
            this(10);
        }

        public Lista (int tamanho){
            array = new Pessoas[tamanho];
            tam = 0;
         }

        public void inserir(int pos, Pessoas x){
            for(int i = tam; i > pos; i--){
                array[i] = array[i-1];
            }

            array[pos] = x;
            tam++;
        }

        public void mostrar(){
            for (int i = 0; i < tam; i++) {
                System.out.println(array[i].name + " " + array[i].count);
            }
        }

        public void remover(String name) {
            for (int i = 0; i < array.length; i++) {
                if (array[i] != null && name.equals(array[i].name)) {
                    for (int j = i; j < array.length - 1; j++) {
                        array[j] = array[j + 1];
                    }
                    array[array.length - 1] = null; 
                    tam--; 
                    i--; 
                }
            }
        }

        boolean newAssassino(String input){
            boolean resp = true;
            for (int i = 0; i < tam; i++) {
                if(array[i].name.equals(input)){resp = false; break;}
            }
            return resp;
        }
    }

    static class Pessoas{
        public String name;
        public int count;

        Pessoas(String name){
            this.name = name;
            count = 1;
        }
    }


    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Lista assassinos = new Lista(100);
        Lista mortos = new Lista(100);

        String input;

        while (entrada.hasNext()) {
            input = entrada.nextLine();
            String [] inputName = input.split(" ", 2);
            if(assassinos.newAssassino(inputName[0])){
                Pessoas tmp1 = new Pessoas(inputName[0]);
                assassinos.inserir(assassinos.tam, tmp1);
            } else{
                for (Pessoas assassino : assassinos.array) {
                    if(assassino != null && assassino.name.equals(inputName[0])){assassino.count++;}
                }
            }

            Pessoas tmp2 = new Pessoas(inputName[1]);
            mortos.inserir(mortos.tam, tmp2);
        }
        
        for (int i = 0; i < assassinos.tam; i++) {
            for (int j = 0; j < mortos.tam; j++) {
                if(assassinos.array[i].name.equals(mortos.array[j].name)){
                    assassinos.remover(assassinos.array[i].name);
                }
            }
        }

        assassinos.mostrar();

        entrada.close();
    }
}
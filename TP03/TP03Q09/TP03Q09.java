import java.util.Scanner;

/**
 * matrizFlex
 */
public class TP03Q09 {
    static class Celula{
        public int elemento;
        public Celula sup;
        public Celula inf;
        public Celula esq;
        public Celula dir;

        Celula(){
            this(0);
        }
        Celula(int x){
            this.elemento = x;
            this.sup=null;
            this.inf=null;
            this.esq=null;
            this.dir=null;
        }
    }

    static class Matriz{
        private int linhas, colunas;
        private Celula inicio;

        Matriz(){
            this(3,3);
        }
        Matriz(int x, int y){
            this.linhas = x;
            this.colunas = y;
            this.inicio = new Celula();

            preencher();
        }

        private void preencher(){
            Celula tmp1 = inicio;
            Celula tmp2 = inicio;

            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    tmp1.dir = new Celula();
                    tmp1.dir.esq = tmp1;
                    tmp1 = tmp1.dir;
                }
                tmp2.inf = new Celula();
                tmp2.inf.sup = tmp2;
                tmp2 = tmp2.inf;
                tmp1 = tmp2;
            }

            tmp1=inicio.dir;
            tmp2=inicio.inf.dir;
            Celula tmp3 = inicio;
            for (int i = 1; i < colunas; i++) {
                for (int j = 1; j < linhas; j++) {
                    tmp1.inf = tmp2;
                    tmp2.sup = tmp1;
                    tmp1 = tmp1.dir;
                    tmp2 = tmp2.dir;
                }
                tmp1 = tmp3.inf.dir;
                tmp2 = tmp3.inf.inf.dir;
                tmp3 = tmp3.inf;
            }
        }

        public void mostrar(){
            Celula i = inicio;
            Celula j = inicio.inf;

            while (i.inf!=null && i.dir!=null) {
                do{
                    System.out.print(i.elemento+" ");
                    i=i.dir;
                }while(i.dir!=null);
                System.out.println("");
                i = j;
                j = j.inf;
            }
        }

        void setArray(int[] array){
            Celula i = inicio;
            Celula j = inicio.inf;
            int current = 0;

            while (i.inf!=null && i.dir!=null) {
                do{
                    i.elemento = array[current];
                    current++;
                    i=i.dir;
                }while(i.dir!=null);
                i = j;
                j = j.inf;
            }
        }

        void getDiagonalPrincipal(){
            Celula i = inicio;
            while (i!=null) {
                System.out.print(i.elemento+" ");
                if(i.dir != null&&i.inf!=null){i=i.inf.dir;}
                else{break;}
            }
            System.out.println();
        }

        void getDiagonalSecundaria(){
            Celula i;
            for(i = inicio; i.dir.dir!=null; i=i.dir);
            while (i!=null) {
                System.out.print(i.elemento+" ");
                if(i.esq != null && i.inf!=null){i=i.inf.esq;}
                else{break;}
            }
            System.out.println();
        }

        int[] toArray(){
            int[] resp = new int[this.linhas * this.colunas];
            int count = 0;
            Celula i = inicio;
            Celula j = inicio.inf;

            while (i.inf!=null && i.dir!=null) {
                do{
                    resp[count] = (i.elemento);
                    count++;
                    i=i.dir;
                }while(i.dir!=null);
                i = j;
                j = j.inf;
            }

            return resp;
        }

        Matriz somarMatrizes(Matriz matriz2){
            Matriz resp = new Matriz(this.linhas, this.colunas);
            int[] array = new int[this.linhas * this.colunas];
            int[] tmp1 = this.toArray();
            int[] tmp2 = matriz2.toArray();
            
            for (int i = 0; i < array.length; i++) {
                array[i] = tmp1[i] + tmp2[i];
            }

            resp.setArray(array);
            return resp;
        }

        private int get(int x, int y) {
            Celula tmp = inicio;
            for (int i = 0; i < x; i++) {
                tmp = tmp.inf;
            }
            for (int j = 0; j < y; j++) {
                tmp = tmp.dir;
            }
            return tmp.elemento;
        }
    
        private void set(int x, int y, int elemento) {
            Celula tmp = inicio;
            for (int i = 0; i < x; i++) {
                tmp = tmp.inf;
            }
            for (int j = 0; j < y; j++) {
                tmp = tmp.dir;
            }
            tmp.elemento = elemento;
        }
    
        Matriz multiplicarMatrizes(Matriz matriz2) {
            Matriz resp = new Matriz(this.linhas, matriz2.colunas);
    
            for (int i = 0; i < this.linhas; i++) {
                for (int j = 0; j < matriz2.colunas; j++) {
                    int soma = 0;
                    for (int k = 0; k < this.colunas; k++) {
                        soma += this.get(i, k) * matriz2.get(k, j);
                    }
                    resp.set(i, j, soma);
                }
            }
    
            return resp;
        }
    }

    private static int[] lerDimensoes(Scanner entrada) {
        int rows = entrada.nextInt();
        int cols = entrada.nextInt();
        entrada.nextLine();
        return new int[]{rows, cols};
    }

    private static int[] lerElementos(Scanner entrada, int rows, int cols) {
        int[] array = new int[rows * cols];
        for (int i = 0; i < rows; i++) {
            String line = entrada.nextLine();
            String[] parts = line.split(" ", cols);
            for (int j = 0; j < cols; j++) {
                array[j + i * cols] = Integer.parseInt(parts[j]);
            }
        }
        return array;
    }

    private static Matriz inicializarMatriz(Scanner entrada) {
        int[] dimensions = lerDimensoes(entrada);
        int rows = dimensions[0];
        int cols = dimensions[1];
        int[] data = lerElementos(entrada, rows, cols);
        Matriz matriz = new Matriz(cols, rows);
        matriz.setArray(data);
        return matriz;
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int casos = entrada.nextInt();
        entrada.nextLine();

        for (int i = 0; i < casos; i++) {
            Matriz matriz1 = inicializarMatriz(entrada);
            Matriz matriz2 = inicializarMatriz(entrada);
    
            matriz1.getDiagonalPrincipal();
            matriz1.getDiagonalSecundaria();
    
            matriz1.somarMatrizes(matriz2).mostrar();
    
            matriz1.multiplicarMatrizes(matriz2).mostrar();
        }

        entrada.close();
    }
}
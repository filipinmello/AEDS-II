/**
 * matrizFlex
 */
public class matrizFlex {
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

    static class Matriz implements Cloneable {
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
                System.out.print("[ ");
                do{
                    System.out.print(i.elemento+" ");
                    i=i.dir;
                }while(i.dir!=null);
                System.out.println("]");
                i = j;
                j = j.inf;
            }
        }

        void setCrescente(){
            Celula i = inicio;
            Celula j = inicio.inf;
            int current = 0;

            while (i.inf!=null && i.dir!=null) {
                do{
                    i.elemento = current;
                    current++;
                    i=i.dir;
                }while(i.dir!=null);
                i = j;
                j = j.inf;
            }
        }

        int soma(){
            int soma = 0;
            
            Celula i = inicio;
            Celula j = inicio.inf;

            while (i.inf!=null && i.dir!=null) {
                do{
                    soma += i.elemento;
                    i=i.dir;
                }while(i.dir!=null);
                i = j;
                j = j.inf;
            }

            return soma;
        }

        void getDiagonal(){
            Celula i = inicio;
            while (i!=null) {
                System.out.print(i.elemento+" ");
                if(i.dir != null&&i.inf!=null){i=i.inf.dir;}
                else{break;}
            }
        }

        void multiplicarLinha(int x, int line){
            if(line<0 || line>linhas){
                System.out.println("Erro!");
                return;
            }
            
            Celula i = inicio;
            for (int j = 0; j < line; j++, i=i.inf);
            
            while (i.dir!=null) {
                i.elemento = i.elemento*x;
                i=i.dir;
            }
        }

        void trocarLinhas(int line1, int line2){
            if(line1<0 || line1>linhas || line2<0 || line2>linhas){
                System.out.println("Erro!");
                return;
            }

            Celula i = inicio;
            Celula j = inicio;
            int tmp;
            for (int k = 0; k < line1; k++, i=i.inf);
            for (int k = 0; k < line2; k++, j=j.inf);

            while (i.dir!=null) {
                tmp = i.elemento;
                i.elemento = j.elemento;
                j.elemento = tmp;
                i=i.dir;
                j=j.dir;
            }
        }

        void somarLinha(int line1, int line2){
            somarLinha(line1, line2, 1);
        }

        void somarLinha(int line1, int line2, int x){ //line1 -> linha que esta sendo somada | line2 -> linha q nao ira mudar
            if(line1<0 || line1>linhas || line2<0 || line2>linhas){
                System.out.println("Erro!");
                return;
            }

            Celula i = inicio;
            Celula j = inicio;
            for (int k = 0; k < line1; k++, i=i.inf);
            for (int k = 0; k < line2; k++, j=j.inf);

            while (i.dir!=null) {
                i.elemento = i.elemento+(x*j.elemento);
                i=i.dir;
                j=j.dir;
            }
        }

        Matriz toTriangular(int x, int y){
            Matriz triangular = new Matriz(x, y);
            triangular.mostrar();
            Celula i = triangular.inicio;
            int currentLine = 0;
            int testLine = 1;
            int coef;

            if(i.elemento!=1){
                if(i.elemento!=0){
                    coef = 1/i.inf.elemento;
                    triangular.multiplicarLinha(coef, currentLine);
                }else{
                    while (testLine<triangular.linhas) {
                        i = i.inf;
                        if(i.elemento!=0){
                            coef = 1/i.elemento;
                            triangular.somarLinha(currentLine, testLine, coef);
                            break;
                        }
                        testLine++;
                    }
                }
            }

            return triangular;
        }

        int getDeterminante(){
            if(this.linhas != this.colunas){
                System.out.println("Erro: atriz nao quadrada");
                return -1;
            }
            
            int det=0;

            Matriz triangular = toTriangular(this.linhas, this.colunas);

            return det;
        }

        boolean isInversivel(){
            boolean resp = true;

            Celula i = inicio;
            while (i!=null) {
                System.out.print(i.elemento+" ");
                if(i.dir != null&&i.inf!=null){i=i.inf.dir;}
                else{break;}
            }

            return resp;
        }
    }

    public static void main(String[] args) {
        Matriz matriz = new Matriz();
        matriz.setCrescente();
        matriz.mostrar();
        // matriz.somarLinha(0, 1, 2);
        // matriz.mostrar();

        Matriz triangular = matriz.toTriangular(3, 3);

        triangular.mostrar();
    }
    
}
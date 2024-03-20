public class TP01Q05v2preOrAnd {
    public static void main(String[] args) {
        boolean A = false;
        boolean B = false;
        boolean C = false;
        String exp = "and(not(A) , not(B))";
    
      
        String operator = "";
        String[] aux = new String[100];
        int j = 0;
    
        for(int i = 0; i < exp.length(); i++){//preenche vetor com os termos da expressão
          operator += exp.charAt(i);
          if(exp.charAt(i) == '(' || exp.charAt(i) == ','  || i+1 == exp.length()){
            aux[j] = operator;
            j++;
            operator = "";
          }
        }
    
        for (int k = 0; k < j; k++){ //limpa o vetor e converte as variáveis para true ou false
          aux[k] = aux[k].replace("(", "");
          aux[k] = aux[k].replace(")", "");
          aux[k] = aux[k].replace(",", "");
          aux[k] = aux[k].replace(" ", "");
          aux[k] = aux[k].replace("A", String.valueOf(A));
          aux[k] = aux[k].replace("B", String.valueOf(B));
          aux[k] = aux[k].replace("C", String.valueOf(C));
    
          System.out.println(aux[k]);
        }
    
        
        for(int i = 0; aux[i] != null && i < aux.length; i++){ //percorre o vetor até o final ou encontrar um espaço vazio
          System.out.println("___________________________________");
          switch(aux[i]){//testa um caso, imprime o caso testado e o vetor após cada iteração
            case "not":
              System.out.println("Case: "+aux[i]);
              if(aux[i+1].equals("true") || aux[i+1].equals("false") ){//se o elemento na frente do not for uma variavel, resolve o not
                aux[i] = solveNot(aux[i+1]);//resultado da expressao substitui o not no array
                aux[i+1] = "-";//local da variavel é substituido por -
                i++;//passa pra proxima posicao
                for(int k = 0; aux[k] != null && k < aux.length; k++){
                  System.out.println(aux[k]);              
                }
              }
              break;
              
            case "or":
              System.out.println("Case: "+aux[i]);
              for(int k = 0; aux[k] != null && k < aux.length; k++){
                System.out.println(aux[k]);              
              }
              break;
              
            case "and":
              System.out.println("Case: "+aux[i]);
              for(int k = 0; aux[k] != null && k < aux.length; k++){
                System.out.println(aux[k]);              
              }
              break;
    
            default:
              System.out.println("Case: "+aux[i]);
              for(int k = 0; aux[k] != null && k < aux.length; k++){
                System.out.println(aux[k]);              
              }
              
          }
        }
      }
    
      public static String solveNot(String X){    
        return String.valueOf(!(Boolean.parseBoolean(X)));
      }
}
    
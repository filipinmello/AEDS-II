import java.util.ArrayList;

public class TP01Q05 {
    public static class BooleanExpression {
        private static boolean[] binaryValues;
        private int numVariables;
        private String input;
        private String expression;
        private String lastOperator;
        private int i = 0;

        public BooleanExpression(String input){
            this.input = input;
            breakExpression();
            //this.lastOperator = checkOperator("");
        }

        private void breakExpression(){
            this.numVariables = Integer.parseInt(input.charAt(0) + "");
            String[] token = input.split(" ", (numVariables + 2));
            binaryValues = new boolean[numVariables];
            expression = token[token.length-1];
            for(int p=1; p<=numVariables; p++){
                MyIO.println("posicao p"+token[p]);

                binaryValues[p-1] = token[p].equals("1")?true:false; 
            }

            MyIO.println("N: " + numVariables); //print apenas para teste
            for(int p=0; p<binaryValues.length; p++){ //print apenas para teste
                MyIO.println("binaryValues " + (p) + ": " + binaryValues[p]);
            }
            MyIO.println("Expressao: " + expression);//print apenas para teste

            solveOperation("and");
        }

        // public String checkOperator(String operator){ //formato: and(not(A) , not(B))
        //     if(expression.charAt(i) == '('){
        //         //operator += expression.charAt(i);
        //         return operator;
        //     } else{
        //         operator += expression.charAt(i);
        //         return checkOperator(operator); //2 0 0 and(A , B)
        //     }
        // }

        public boolean solveOperation(String operator){
            ArrayList<Boolean> variables = new ArrayList<>();
            String exp = "";
            //boolean[] results;
            for(; i<expression.length(); i++){
                exp += expression.charAt(i);
                if(exp.contains("not")) {
                    MyIO.println("marcu");
                    exp = "";
                    solveOperation("not");
                } else if(exp.contains("and")){
                    exp = "";
                    solveOperation("and");
                } else if(exp.contains("or")){
                    exp = "";
                    solveOperation("or");
                }
                if(expression.charAt(i) == ')'){
                    String content = "";
                    for(int j=exp.length()-1; j>0; j--){
                        content += exp.charAt(j);
                        if(exp.charAt(j) == '('){ //condição de parada total
                            MyIO.println(content);
                            variables = splitVariables(content);
                            break;
                        }
                    }
                    if(operator == "not"){
                        MyIO.println("fouuudase 1"+(variables));
                        MyIO.println("fouuudase "+!(variables.get(0)));
                        return (!variables.get(0));
                    } else if(operator == "and"){
                        return resolveAnd(variables);
                    } else if(operator == "or"){
                        return resolveOr(variables);
                    }
                    
                }
            }
            return false;
        }
        public static ArrayList<Boolean> splitVariables(String content) {
            String[] parts = content.split(" , ");
            ArrayList<Boolean> values = new ArrayList<>();
            for (int j = 0; j < parts.length; j++) {
                if(parts[j].trim().equals("A")){
                    values.add(binaryValues[0]);
                } else if(parts[j].trim().equals("B")){
                    values.add(binaryValues[1]);
                } else if(parts[j].trim().equals("C")){
                    values.add(binaryValues[2]);
                } else{
                    values.add(Boolean.parseBoolean(parts[j].trim()));
                }
            }
            return values;
        }
        public static boolean resolveOr(ArrayList<Boolean> array) {
            for (Boolean value : array) {
                if (value != null && value) {
                    return true;
                }
            }
            return false;
        }
        public static boolean resolveAnd(ArrayList<Boolean> array) {
            for (Boolean value : array) {
                if (value == null || !value) {
                    return false;
                }
            }
            return true;
        }
    }


    public static void main(String[] args) { 
        BooleanExpression teste = new BooleanExpression(MyIO.readLine());
        // if(!false&&!false)
        //     MyIO.println("true");
        // else
        //     MyIO.println("false");



    }
}
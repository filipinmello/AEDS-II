import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TP02Q03 {
        static class Personagem implements Cloneable{
            private String id;
            private String name;
            private ArrayList<String> alternateNames;
            private String house;
            private String ancestry;
            private String species;
            private String patronus;
            private boolean hogwartsStaff;
            private boolean hogwartsStudent;
            private String actorName;
            private boolean alive;
            private String alternate_actors;
            private String dateOfBirth;
            private int yearOfBirth;
            private String eyeColour;
            private String gender;
            private String hairColour;
            private boolean wizard;

            public Personagem(){}

            public Personagem(String id, String name, String alternateNames, String house, String ancestry, String species, String patronus, String hogwartsStaff, String hogwartsStudent, String actorName, String alive, String alternate_actors, String dateOfBirth, String yearOfBirth, String eyeColour, String gender, String hairColour, String wizard)
            {
                this.id = id;
                this.name = name;
                
                String[] temp = alternateNames.split(",");
                this.alternateNames = new ArrayList<>();
                for(int i =0; i<temp.length; i++){
                    this.alternateNames.add(temp[i]);
                }

                this.house = house;
                this.ancestry = ancestry;
                this.species = species;
                this.patronus = patronus;

                if (hogwartsStaff.equals("VERDADEIRO")) {
                    this.hogwartsStaff = true;
                } else {
                    this.hogwartsStaff = false;
                }
                

                if (hogwartsStudent.equals("VERDADEIRO")) {
                    this.hogwartsStudent = true;
                } else {
                    this.hogwartsStudent = false;
                }

                this.actorName = actorName;

                if (alive.equals("VERDADEIRO")) {
                    this.alive = true;
                } else {
                    this.alive = false;
                }
                
                this.alternate_actors = alternate_actors;

                this.dateOfBirth = dateOfBirth;
                
                this.yearOfBirth = Integer.parseInt(yearOfBirth);
                this.eyeColour = eyeColour;
                this.gender = gender;
                this.hairColour = hairColour;

                if (wizard.equals("VERDADEIRO")) {
                    this.wizard = true;
                } else {
                    this.wizard = false;
                }
            }

            public void imprimir(){
                MyIO.print("[");
                MyIO.print(id);
                MyIO.print(" ## ");
                MyIO.print(name);
                MyIO.print(" ## {");
                for (int i = 0; i < alternateNames.size(); i++) {
                    MyIO.print(alternateNames.get(i));
                    if (i != alternateNames.size() - 1) {
                        MyIO.print(",");
                    }
                }
                MyIO.print("} ## ");
                MyIO.print(house);
                MyIO.print(" ## ");
                MyIO.print(ancestry);
                MyIO.print(" ## ");
                MyIO.print(species);
                MyIO.print(" ## ");
                MyIO.print(patronus);
                MyIO.print(" ## ");
                MyIO.print(hogwartsStaff);
                MyIO.print(" ## ");
                MyIO.print(hogwartsStudent);
                MyIO.print(" ## ");
                MyIO.print(actorName);
                MyIO.print(" ## ");
                MyIO.print(alive);
                MyIO.print(" ## ");
                MyIO.print(dateOfBirth);
                MyIO.print(" ## ");
                MyIO.print(yearOfBirth);
                MyIO.print(" ## ");
                MyIO.print(eyeColour);
                MyIO.print(" ## ");
                MyIO.print(gender);
                MyIO.print(" ## ");
                MyIO.print(hairColour);
                MyIO.println(" ## " + wizard + "]");
            }

            @Override
            public Object clone() throws CloneNotSupportedException {
                Personagem clonedPersonagem = (Personagem) super.clone();
        
                clonedPersonagem.alternateNames = new ArrayList<>(this.alternateNames);
        
                return clonedPersonagem;
            }

            public String getId() {
                return id;
            }

            public void setId(String id) {
                this.id = id;
            }

            public String getName() {
                return name;
            }

            public void setName(String name) {
                this.name = name;
            }

            public ArrayList<String> getAlternateNames() {
                return alternateNames;
            }

            public void setAlternateNames(ArrayList<String> alternateNames) {
                this.alternateNames = alternateNames;
            }

            public String getHouse() {
                return house;
            }

            public void setHouse(String house) {
                this.house = house;
            }

            public String getAncestry() {
                return ancestry;
            }

            public void setAncestry(String ancestry) {
                this.ancestry = ancestry;
            }

            public String getSpecies() {
                return species;
            }

            public void setSpecies(String species) {
                this.species = species;
            }

            public String getPatronus() {
                return patronus;
            }

            public void setPatronus(String patronus) {
                this.patronus = patronus;
            }

            public boolean isHogwartsStaff() {
                return hogwartsStaff;
            }

            public void setHogwartsStaff(boolean hogwartsStaff) {
                this.hogwartsStaff = hogwartsStaff;
            }

            public boolean isHogwartsStudent() {
                return hogwartsStudent;
            }

            public void setHogwartsStudent(boolean hogwartsStudent) {
                this.hogwartsStudent = hogwartsStudent;
            }

            public String getActorName() {
                return actorName;
            }

            public void setActorName(String actorName) {
                this.actorName = actorName;
            }

            public boolean isAlive() {
                return alive;
            }

            public void setAlive(boolean alive) {
                this.alive = alive;
            }

            public String getAlternate_actors() {
                return alternate_actors;
            }

            public void setAlternate_actors(String alternate_actors) {
                this.alternate_actors = alternate_actors;
            }

            public String getDateOfBirth() {
                return dateOfBirth;
            }

            public void setDateOfBirth(String dateOfBirth) {
                this.dateOfBirth = dateOfBirth;
            }

            public int getYearOfBirth() {
                return yearOfBirth;
            }

            public void setYearOfBirth(int yearOfBirth) {
                this.yearOfBirth = yearOfBirth;
            }

            public String getEyeColour() {
                return eyeColour;
            }

            public void setEyeColour(String eyeColour) {
                this.eyeColour = eyeColour;
            }

            public String getGender() {
                return gender;
            }

            public void setGender(String gender) {
                this.gender = gender;
            }

            public String getHairColour() {
                return hairColour;
            }

            public void setHairColour(String hairColour) {
                this.hairColour = hairColour;
            }

            public boolean isWizard() {
                return wizard;
            }

            public void setWizard(boolean wizard) {
                this.wizard = wizard;
            }

            
    }

    static String[] parseLine(String fileLine){
        String[] values = fileLine.split(";");
        for (int i = 0; i < values.length; i++) {
            if(values[i].equals("[]")){
                values[i] = "";
            }else{
                values[i] = values[i].replace("[", "");
                values[i] = values[i].replace("]", "");
                values[i] = values[i].replace("'", "");
            }
        }
        return values;
    }

    public static boolean nameSearch(String targetName, ArrayList<String> input, Integer[] comparisons){
        boolean resp = false;

        for (int i=0; i<input.size();i++){
            if(input.get(i).equals(targetName)){
                resp = true;
                comparisons[0]++;
                break;
            }
            comparisons[0]++;
        }

        return resp;
    }

    public static void main(String[] args) {
        long startTime = System.nanoTime();
        List<Personagem> lista = new ArrayList<Personagem>();
        String fileName = "/tmp/characters.csv";
        String fileLine = "";
        ArrayList<String> input = new ArrayList<>();
        String line;
        Scanner entrada = new Scanner(System.in);
        String targetName = "";
        
        Arq.openRead(fileName);
        
        for(int i=0; i<405; i++){
            fileLine = Arq.readLine();
            if(i>0){
                String[] values = parseLine(fileLine);
                Personagem e = new Personagem(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8], values[9], values[10], values[11], values[12], values[13], values[14], values[15], values[16], values[17]);
                lista.add(e);
            }
        }
        Arq.close();
        
        do {
            line = entrada.nextLine();

            if (!line.equals("FIM")) {
                for(int j=0; j<lista.size(); j++){
                    Personagem tmp = lista.get(j);
                    if(tmp.getId().equals(line)){
                        input.add(tmp.getName());
                        break;
                    }
                }
            }
        } while (!line.equals("FIM"));

        Integer[] comparisons = {0};

        do {
            targetName = entrada.nextLine();

            if (!targetName.equals("FIM")) {
                if(nameSearch(targetName, input, comparisons)){MyIO.println("SIM");}
                else{MyIO.println("NAO");}
            }
        } while (!targetName.equals("FIM"));
        
        entrada.close();
        
        long endTime = System.nanoTime();
        long executionTime = (endTime - startTime) / 1000000;

        Arq.openWrite("log");
        Arq.println("827761\t" + executionTime + "ms\t" + comparisons[0]);
        Arq.close();
    }
}
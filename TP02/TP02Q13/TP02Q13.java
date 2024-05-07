import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Date;

public class TP02Q13 {
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
            private Date dateOfBirth;
            private int yearOfBirth;
            private String eyeColour;
            private String gender;
            private String hairColour;
            private boolean wizard;
            private DateFormat dateFormat  = new SimpleDateFormat("dd-MM-yyyy");

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

                try {
                    this.dateOfBirth = dateFormat.parse(dateOfBirth);
                } catch (ParseException e) {
                    e.printStackTrace();
                }
                
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
                System.out.print(dateFormat.format(dateOfBirth));
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

            public Date getDateOfBirth() {
                return dateOfBirth;
            }

            public void setDateOfBirth(Date dateOfBirth) {
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
    
    public static void swap(ArrayList<Personagem> input, int i, int j) {
        Personagem temp1 = input.get(i);
        Personagem temp2 = input.get(j);
    
        input.set(i, temp2);
        input.set(j, temp1);
    }

    public static int compareActorName(Personagem p1, Personagem p2) {
        String actorName1 = p1.getActorName();
        String actorName2 = p2.getActorName();
    
        if (actorName1 == null && actorName2 == null) {
            return 0;
        } else if (actorName1 == null) {
            return -1;
        } else if (actorName2 == null) {
            return 1;
        }
    
        int comparacao = actorName1.compareTo(actorName2);
        if (comparacao == 0) {
            return p1.getName().compareTo(p2.getName());
        }
        return comparacao;
    }

    public static void sort(ArrayList<Personagem> input, Integer[] comparisons, Integer[] swapsMade) {
        mergesort(input, 0, input.size() - 1);
    }
    
    private static void mergesort(ArrayList<Personagem> input, int esq, int dir) {
        if (esq < dir) {
            int meio = (esq + dir) / 2;
            mergesort(input, esq, meio);
            mergesort(input, meio + 1, dir);
            intercalar(input, esq, meio, dir);
        }
    }
    
    public static void intercalar(ArrayList<Personagem> input, int esq, int meio, int dir) {
        int n1, n2, i, j, k;
    
        n1 = meio - esq + 1;
        n2 = dir - meio;
    
        Personagem[] a1 = new Personagem[n1 + 1];
        Personagem[] a2 = new Personagem[n2 + 1];
    
        for (i = 0; i < n1; i++) {
            a1[i] = input.get(esq + i);
        }
    
        for (j = 0; j < n2; j++) {
            a2[j] = input.get(meio + j + 1);
        }
    
        a1[i] = a2[j] = new Personagem();
    
        for (i = j = 0, k = esq; k <= dir; k++) {
            input.set(k, (compareActorName(a1[i], a2[j]) <= 0) ? a1[i++] : a2[j++]);
        }
    }
    
    public static void main(String[] args) {
        long startTime = System.nanoTime();
        List<Personagem> lista = new ArrayList<Personagem>();
        String fileName = "characters.csv";
        String fileLine = "";
        ArrayList<Personagem> input = new ArrayList<>();
        String line;
        Scanner entrada = new Scanner(System.in);
        
        Arq.openRead(fileName);

        for(int i=0; i<405; i++){
            fileLine = Arq.readLine();
            if(i>0){
                String[] values = parseLine(fileLine);
                Personagem e = new Personagem(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8], values[9], values[10], values[11], values[12], values[13], values[14], values[15], values[16], values[17]);
                lista.add(e);
            }
        }
        
        do {
            line = entrada.nextLine();

            if (!line.equals("FIM")) {
                for(int i=0; i<lista.size(); i++){
                    Personagem tmp = lista.get(i);
                    if(tmp.getId().equals(line)){
                        input.add(tmp);
                        break;
                    }
                }
            }
        } while (!line.equals("FIM"));

        Integer[] comparisons = {0};
        Integer[] swapsMade = {0};

        sort(input, comparisons, swapsMade);

        for (Personagem personagem : input) {
            personagem.imprimir();
        }

        entrada.close();
        long endTime = System.nanoTime();
        long executionTime = (endTime - startTime) / 1000000;

        Arq.openWrite("827761_heapsort.txt");
        Arq.println("827761\t" + comparisons[0] + "\t" + swapsMade[0] + "\t" + executionTime + "ms");
        Arq.close();
    }
}
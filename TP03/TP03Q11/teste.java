import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Date;

public class teste {
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
        public DateFormat dateFormat  = new SimpleDateFormat("dd-MM-yyyy");

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

    //Classe Celula

    static class Celula {
        public Personagem elemento;
        public Celula prox, ant;
        public int posicao;


        public Celula() {
            this(null);
        }
    
        public Celula(Personagem elemento) {
            this.elemento = elemento;
            this.prox = ant = null;
            posicao = 0;
        }
    }

    //Classe Lista

    static class Lista {
	private Celula primeiro;
	private Celula ultimo;

	public Lista() {
		primeiro = new Celula();
		ultimo = primeiro;
	}

	public void inserirInicio(Personagem x) {
		Celula tmp = new Celula(x);
		tmp.prox = primeiro.prox;
        if (primeiro.prox != null) { 
            primeiro.prox.ant = tmp;
        }
		primeiro.prox = tmp;
		if (primeiro == ultimo) {                 
			ultimo = tmp;
		}
		tmp = null;

        Celula j = primeiro.prox;
        for (int i = 1; i < tamanho(); i++, j = j.prox) {
            j.posicao = j.posicao + 1;
        }
	}

	public void inserirFim(Personagem x) {
		ultimo.prox = new Celula(x);
        ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox;
        ultimo.posicao = tamanho() - 1;
	}

	public Personagem removerInicio(){
		if (primeiro == ultimo) {
			System.out.println("Erro ao remover (vazia)!");
            return null;
		}

		Celula tmp = primeiro;
		primeiro = primeiro.prox;
        if (primeiro != null) {
            primeiro.ant = null;
        }
		Personagem resp = primeiro.elemento;
		tmp.prox = null;
		tmp = null;
		return resp;
	}

	public Personagem removerFim(){
        if (primeiro == ultimo) {
            System.out.println("Erro ao remover (vazia)!");
            return null;
        }
    
        Personagem resp = ultimo.elemento;
        ultimo = ultimo.ant;
        ultimo.prox = null;

        return resp;
	}

	public void inserir(Personagem x, int pos){
		int tamanho = tamanho();

		if(pos < 0 || pos > tamanho){
			System.out.println("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
		} else if (pos == 0){
			inserirInicio(x);
		} else if (pos == tamanho){
			inserirFim(x);
		} else {
			Celula i = primeiro;
			for(int j = 0; j < pos; j++, i = i.prox);
		
			Celula tmp = new Celula(x);
			tmp.prox = i.prox;
            tmp.ant = i;
            i.prox.ant = tmp;
			i.prox = tmp;
			tmp = i = null;
		}
	}

	public Personagem remover(int pos){
		Personagem resp;
		int tamanho = tamanho();

		if (primeiro == ultimo){
			System.out.println("Erro ao remover (vazia)!");
            return null;
		} else if(pos < 0 || pos >= tamanho){
			System.out.println("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
            return null;
		} else if (pos == 0){
			resp = removerInicio();
		} else if (pos == tamanho - 1){
			resp = removerFim();
		} else {
			Celula i = primeiro;
			for(int j = 0; j < pos; j++, i = i.prox);
		
			Celula tmp = i.prox;
			resp = tmp.elemento;
			i.prox = tmp.prox;
            tmp.prox.ant = i;
            tmp.prox = tmp.ant = null;
			i = tmp = null;
		}

		return resp;
	}

	public void mostrar() {
        int j=0;
		for (Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.print("["+j+" ## ");
            i.elemento.imprimir();
            j++;
		}
	}

	public boolean pesquisar(Personagem x) {
		boolean resp = false;
		for (Celula i = primeiro.prox; i != null; i = i.prox) {
			if(i.elemento.getId() == x.getId()){
				resp = true;
				i = ultimo;
			}
		}
		return resp;
	}

    public Personagem retElementPersonagem(int posicao) {
        Celula j = primeiro;
        for (int i = 0; i < posicao; i++, j = j.prox)
            ;
        return j.elemento;
    }

	public int tamanho() {
		int tamanho = 0; 
		for(Celula i = primeiro; i != ultimo; i = i.prox, tamanho++);
		return tamanho;
	}

    public Personagem getPersonagem(int pos){
        Celula resp = primeiro;
        for (int i = 0; i <= pos; resp=resp.prox, i++);
        return resp.elemento;
    }

    public Personagem buscarPersonagem(String targetId){
        Celula resp;
        for(resp = primeiro.prox; resp!=null; resp=resp.prox){
            if(resp.elemento.getId().equals(targetId)){return resp.elemento;}
        }
        
        System.out.println("Personagem nao encontrado!");
        return null;
    }
}


   public static void sort(Lista lista) {
      quicksort(lista, 1, lista.tamanho()-1);
   }

	/**
	 * Algoritmo de ordenacao Quicksort.
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
	 */
	public static void quicksort(Lista l,int esq,int dir){
		int i = esq,j = dir;
		Personagem pivo = elemento(l, (dir+esq)/2).elemento;
		while(i<=j){
			while(toCompare1(elemento(l, i).elemento, pivo)) i++;
			while(toCompare2(elemento(l, j).elemento, pivo)) j--;
			if(i <= j){
				swap(l,i,j);
				i++;
				j--;
			}
		}
		if (esq < j)  quicksort(l,esq, j);
		if (i < dir)  quicksort(l,i, dir);
	}

	public static boolean toCompare1(Personagem p1,Personagem p2){
		if(p1.getHouse().compareTo(p2.getHouse()) < 0){
			return true;
		}else if(p1.getHouse().compareTo(p2.getHouse()) == 0){
			if(p1.getName().compareTo(p2.getName()) < 0){
				return true;
			}
		}
		return false;
	}

	public static boolean toCompare2(Personagem p1,Personagem p2){
		if(p1.getHouse().compareTo(p2.getHouse()) > 0){
			return true;
		}else if(p1.getHouse().compareTo(p2.getHouse()) == 0){
			if(p1.getName().compareTo(p2.getName()) > 0){
				return true;
			}
		}
		return false;
	}

    public static void swap(Lista l,int i , int j){
		Personagem tmp = elemento(l,i).elemento;
		elemento(l, i).elemento = elemento(l, j).elemento;
		elemento(l, j).elemento = tmp;
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

    public static Celula elemento(Lista l,  int posicao){
		Celula j = l.primeiro;
		for(int i = 0;i != posicao;i++, j = j.prox);
		return j;
	}

    public static void main(String[] args) {
        Lista personagens = new Lista();
        Lista lista = new Lista();
        String fileName = "/tmp/characters.csv";
        String fileLine = "";
        String line = "";
        Scanner entrada = new Scanner(System.in);
        
        Arq.openRead(fileName);
        
        for(int i=0; i<405; i++){
            fileLine = Arq.readLine();
            if(i>0){
                String[] values = parseLine(fileLine);
                Personagem e = new Personagem(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8], values[9], values[10], values[11], values[12], values[13], values[14], values[15], values[16], values[17]);
                personagens.inserirFim(e);
            }
        }

        do {
            line = entrada.nextLine();

            if (!line.equals("FIM")) {
                for(int i=0; i<personagens.tamanho(); i++){
                    Personagem tmp = personagens.getPersonagem(i);
                    if(tmp.getId().equals(line)){
                        lista.inserirFim(tmp);
                    }
                }
            }
        } while (!line.equals("FIM"));

        sort(lista);
        lista.mostrar();

        entrada.close();
    }
}
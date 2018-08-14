public class exec{

	public static void main(String args[]){


		Pessoa presidente=new Pessoa();
		presidente.setNome("S2 Luis Inacio Lula da Silva S2");
		presidente.setEndereco("Delegacia de Curitiba #lulalivre");
		presidente.setDataDeNascimento("27 de outubro de 1945");
		presidente.setPai("Pai do Lula");
		presidente.setMae("Dilmae");
		
		System.out.println("A pessoa criada : \n"+ presidente.toString()+ "\n");

		GrupoEmpresa empresa = new GrupoEmpresa();
		empresa.setPresidente(presidente);
		empresa.setCNPJ("123123123123");
		empresa.setFaturamentoAnual("R$ 999.999,99");		
	
		System.out.println("O fim é : \n" + empresa.toString() + "\n");

	}
	
	public static class Pessoa{	
		String nome;
		String endereco;
		String dataDeNascimento;
		String pai;
		String mae;	
	
	
		//acesso
		
		public void setNome(String nome){this.nome = nome;}
		public void setEndereco(String endereco){this.endereco = endereco;}
		public void setDataDeNascimento(String dataDeNascimento){this.dataDeNascimento = dataDeNascimento;}
		public void setPai(String pai){this.pai = pai;}
		public void setMae(String mae){this.mae = mae;}
		
		
		public String getNome(){return this.nome;}
		public String getEndereco(){return this.endereco;}
		public String getdDataDeNascimento(){return this.dataDeNascimento;}
		public String getPai(){return this.pai;}
		public String getMae(){return this.mae;}

		public String toString(){
			String str = "";
			str = str + "nome = " + this.nome + "\n";
			str = str + "endereco = " + this.endereco + "\n";
			str = str + "nacimento = " + this.dataDeNascimento + "\n";
			str = str + "pai = " + this.pai + "\n";
			str = str + "mae = " + this.mae + "\n";
			return str;			
		}
	}
	
		public static class GrupoEmpresa{
		Pessoa presidente = new Pessoa();
		String CNPJ;
		String faturamenteAnual;
		
		//Acesso
		public void setPresidente(Pessoa presidente){
			this.presidente=presidente;
		}
		public void setCNPJ(String CNPJ){
			this.CNPJ=CNPJ;
		}
		public void setFaturamentoAnual(String faturamentoAnual){
			this.faturamentoAnual=faturamentoAnual;
		}
		
		
		public Pessoa getPresidente(){
			return this.presidente;
		}
		public String getCNPJ(){
			return this.CNPJ;
		}
		public String getFaturamentoAnual(){
			return this.faturamentoAnual;
		}
		
		public static String toString(){
			String str = "";
			str= str + "Presidente = " + presidente.toString() + "\n";
			str= str + "CNPJ = " + this.CNPJ + "\n";
			str= str + "Faturamento Anual = " + this.faturamentoAnual + "\n";
			return str;
		}
	}
	



}

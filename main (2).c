#include <stdio.h>
#include <string.h>
#include <time.h>

int creaMatrice( int dim){
  srand(time(NULL));
  int riga,colonna;
  do{ 

  }while(dim<=0);
  int m[dim][dim];
  for(riga=0;riga<dim;riga++){
    for(colonna=0;colonna<dim;colonna++){
      m[riga][colonna]=rand()%10;
    }
  }
  return m;
}

int stampaCsv(int dim, int m){
  int riga,colonna;
  FILE *fp;
  fp=fopen("file.csv", "w");
  for(riga=0;riga<dim;riga++){
    for(colonna=0;colonna<dim;colonna++){
      fprintf(fp,"%d,\t",m[riga][colonna]);
       if(colonna==dim-1){
         fprintf(fp,"\n");
       }
    }
    fclose(fp);
  }
  return 0;
}

int caricaCsv(){
  FILE *fp;
  char *line = NULL;
  size_t len;
  ssize_t read;
  fp=fopen("file.csv", "r");
  while ((read = getline(&line, &len, fp)) != -1) {  
      // Split line by comma
      char* token = strtok(line, ",");
      while (token != NULL) {
          printf("%s ", token);
          token = strtok(NULL, ",");
      }
  }
  
  return 0;
}
int main(void) {
  int scelta,dim;
  do{
    printf("inserire \n1) per genrerare su  una matrice\n2) salva su csv la matrice, una riga dell'array per ogni riga del file, con le colonne separate dalla virgola\n3)stampa a video dal csv la matrice\ninserire 0 per uscire");
    printf("inserire la dimensione della matrice:\t");
    scanf("%d",&dim);
    scanf("%d",&scelta);
    if(scelta==1){
      
      creaMatrice(dim);
    }
    if(scelta==2){
      stampaCsv(dim);
    }
  }while(scelta!=0);
return 0;
}
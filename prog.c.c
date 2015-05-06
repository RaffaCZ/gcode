#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int lettura(char file[],float vettx[],float vetty[]){
	int i=0;
	FILE *fp;
	char carattere;
	fp=fopen(file,"r");
			while(!feof(fp)){
				fscanf(fp,"%c",&carattere);
				  if(carattere=='X'){
				    fscanf(fp,"%f",&vettx[i]);
				    
				}
				if(carattere=='Y'){
					fscanf(fp,"%f",&vetty[i]);
					i++;
				}
		}
	fclose(fp);
	return i;
  }
void bubble_sort(float vettx[],float vetty[],int dim){
	int i,j;
	float tmpx,tmpy;
	for(i=dim-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
		   if(vettx[j]>vettx[j+1])
		     {
				 tmpx=vettx[j+1];
		         vettx[j+1]=vettx[j];
		         vettx[j]=tmpx;
		         tmpy=vetty[j+1];
		         vetty[j+1]=vetty[j];
		         vetty[j]=tmpy;
		         
			 }
		}
	}
}
void scrittura(char file[],float vettx[],float vetty[],int dim){
	FILE *fp;
	int i;
	fp=fopen(file,"w");
	fprintf(fp,"G90\nG21\n");
	for(i=1;i<dim;i++){
		
		fprintf(fp,"X%f ",vettx[i]);
		fprintf(fp,"Y%f\n",vetty[i]);
	}
	fprintf(fp,"G0 X0.000 Y0.000\nM05\nM02");	
	 }
int main(){
	char file[40];
	float vettx[MAX],vetty[MAX];
	int dim;
	printf("Nome del file: ");
	scanf("%s",file);
	dim=lettura(file,vettx,vetty);
	printf("Nome del file dove scrivere i risultati: ");
	scanf("%s",file);
	bubble_sort(vettx,vetty,dim);
	scrittura(file,vettx,vetty,dim);
	return 0;
  }

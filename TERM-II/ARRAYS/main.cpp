#include <iostream>

using namespace std;

int main()
{
    int jp_longitud, jp_contador = 0, jp_contador2 = 0, jp_longi1=0, jp_indnuevo=0;
    string jp_palabra;
    string jp_arreglo[] = {"mama", "papa", "sopa", "polo", "mapa"};
    string jp_norepe[6];
    bool jp_encuentra;
    string lolo;

    cout<<"El arreglo con las letras contenidas"<<endl;
    for(int i=0;i<sizeof jp_arreglo / sizeof jp_arreglo[0];i++){
    	jp_palabra=jp_arreglo[i];

      	jp_longi1 = jp_longi1 + jp_palabra.length();

    	//esto está de mas porque la longitud de ese arreglo es la longitud de la palabra
    	//for(int j=0;j<jp_palabra.length();j++){
    	//	jp_contador = jp_contador+ 1;
		//}

		string jp_arregloNuevo[jp_longi1];

	    if(i+1 == sizeof jp_arreglo / sizeof jp_arreglo[0] ){

 		    for(int k=0;k< sizeof jp_arreglo / sizeof jp_arreglo[0];k++){
    	        jp_palabra=jp_arreglo[k];
    	        for(int p=0;p<jp_palabra.length();p++){
    	            jp_arregloNuevo[jp_contador2]= jp_palabra[p];
    	            cout<<jp_arregloNuevo[jp_contador2]<<endl;
    	            jp_contador2++;
	        	}
        	}

		    cout<<"Las letras que no son repetidas"<<endl;

		    for(int u=0;u<sizeof jp_arregloNuevo /sizeof jp_arregloNuevo[0];u++){
		        jp_encuentra= false;
		        for (int p=0;p<=jp_indnuevo;p++)
		        {
	                if(jp_arregloNuevo[u] == jp_norepe[p]) {
		               jp_encuentra = true;
		            }
		         }

		         if (jp_encuentra == false)
		            {
		              jp_norepe[jp_indnuevo] = jp_arregloNuevo[u];
		              //cout<<jp_norepe[jp_indnuevo]<<endl;
		              jp_indnuevo = jp_indnuevo+1;
		            }
		      }

		      for(int i=0;i<jp_indnuevo;i++)
		      {
		          cout<<jp_norepe[i]<<endl;
		      }
	    }
    }
    return 0;
}
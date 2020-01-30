#include<stdio.h>
#include<stdlib.h>

typedef struct liste
{
	short deger;
	struct liste *sonraki;
}liste;
liste *bas=NULL;


ekle(short neyi)
{
	liste *yeni=malloc(sizeof(liste));
	yeni->deger=neyi;
	yeni->sonraki=NULL;
	if(bas==NULL)
	{
		bas=yeni;
	}
	else
	{
		liste *d=bas;
		//sonuncuya kadar git(sonraki NULl olaný bul)
		while(d->sonraki != NULL)
		{
			d = d->sonraki;
		}
		//baðlayalým...
		d->sonraki = yeni;
	}
}

goster(){
	liste *d=bas;
	while(d != NULL)
	{
		printf("%d, \n",d->deger);
		d = d->sonraki;
	}
}

basaekle(short neyi)
{
	liste *yeni=malloc(sizeof(yeni));
	yeni->deger=neyi;
	yeni->sonraki=bas;
	bas=yeni;
}

short bastancikar()
{
	if(bas!=NULL)
	{
		//short gonder = bas->deger;
		bas= bas->sonraki;
		//return gonder;
	}else{
		return -1;
	}
	
}

ara(short aranan)
{
	liste *d=bas;
	short buldum=0;
	while(d!=NULL)
	{
		if(d->deger==aranan)
		{		
			buldum++;
			
		}
		d=d->sonraki;
	}
	printf("%d tane buldum",buldum);
}


//istenilen sayýyý nerde olursa olsun silen fonksiyon
sil(short neyi)
{
	liste *d=bas, *onceki=bas;
	
	while(d!=NULL && d->deger!=neyi)
	{
		onceki=d;
		d=d->sonraki;
	}
	if(d==NULL)
	{
		printf("bulamadik\n");
	}
	else if(d!=bas)
	{
		onceki->sonraki = d->sonraki;
	}

	else if(d==bas)
	{
		bas=bas->sonraki;//ya da bastancikar()
	}
}

sil2(short neyi)
{
	liste *d=bas,*onceki=bas;
	
	while(d!=NULL)
	{
		if(d->deger==neyi)
		{
			if(d==bas)
			{
				bas=bas->sonraki;
				
			}
			else
			{
				onceki->sonraki=d->sonraki;
			}
		}
		
		else{
			onceki=d;
	} 
		d=d->sonraki;
	}
}

arayaekle(short nereye,short neyi)
{
	liste *yeni=malloc(sizeof(liste));
	yeni->deger=neyi;
	liste *d=bas;
	short i=1;
	if(nereye==1)
	{
		liste *yeni=malloc(sizeof(yeni));
		yeni->deger=neyi;
		yeni->sonraki=bas;
		bas=yeni;
		//basaekle(neyi);
	}
	else
	{
		while(d->sonraki!=NULL && i<nereye-1)
		{
			d=d->sonraki;
			i=i+1;
		}
		yeni->sonraki=d->sonraki;
		d->sonraki=yeni;
		
	}
	
	
}


main()
{
	ekle(20);ekle(10);ekle(45);ekle(20);ekle(20);
	basaekle(5);
	goster();
	/*
	bastancikar();
	short x= bastancikar();
	if(x!=-1)
	{
		printf("bastan cikarilan=%d\n",x);
    }
	else
	{
		printf("Liste Bos");
	}
	*/
	


}

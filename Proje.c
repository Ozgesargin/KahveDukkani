#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void order(int i);
void cancel();
void convert_to_letters(int cust_num);
int discount (int sum);
  
long int cust_num;
int product [10]= {9,23,26,45,42,49,40,47,47,35};
int sum,i,j,k;
char ans1,ans2,ans3;



int main(){

  k=0;
  cust_num=20232400;
  printf("Kayit olmak ister misiniz? Evet icin (E), hayir icin (H) harfini tuslayiniz.\n");
  scanf("%s",&ans1);
  
  sign_up(ans1);
  
  printf("\n\nMENU\n");
  printf("1. Fincan Cay 9TL\n");
  printf("2. Turk Kahvesi 23TL\n");
  printf("3. Filtre Kahve 26TL\n");
  printf("4. Latte 45 TL\n");
  printf("5. Americano 42TL\n");
  printf("6. Mocha 49TL\n");
  printf("7. Espresso 40TL\n");
  printf("8. Cappuccino 47TL\n");
  printf("9. Sicak Cikolata 47TL\n");
  printf("10. Yesil Cay 35TL\n");


  printf("\nSiparisinizi tuslayiniz.\n");
  scanf("%d",&i);

  order(i);
  
  cancel();
  
  printf(discount (sum));
  
  return 0;

}



// MUSTERI KAYDI ALMA

void sign_up(char ans1){
  
  if(ans1=='E'||ans1=='e'){


    FILE*dosya;
    dosya=fopen("D:\\Desktop\\Algoritma\\customer.txt","a");
    
    char name[50];
    char lastname[50];

    printf("Lutfen, adinizi giriniz.\n");
    scanf("%s",&name);
    printf("Lutfen, soyadinizi giriniz.\n");
    scanf("%s",&lastname);
    
    strcat(name, lastname);

    printf("Ogrenci misiniz? Evet icin (E), hayir icin (H) harfini tuslayiniz.\n");
    scanf("%s",&ans2);

      if(ans2 =='E'|| ans2 =='e'){
      printf("\n\nOGRENCI KARTI\n\n");
      fprintf(dosya,"\nOGRENCÝ\n");

      }else if(ans2=='H'|| ans2=='h'){
      printf("\n\nSTANDART KART\n\n");
      fprintf(dosya,"\nSTANDART\n");

      }else if(!((ans2=='E'|| ans2=='e')||(ans2=='H'|| ans2=='h'))){
      printf("Hatali tuslama yaptiniz. Evetse (E), hayirsa (H) tuslayiniz.\n");
      }

    printf("%s\n",name);

    ++cust_num;

    printf("Musteri no:%d \n",cust_num);
    
    convert_to_letters(cust_num);

    
    fprintf(dosya,"%s\nmusteri no:%d\n",name,cust_num);
    fclose(dosya);
}
}

// REF KODU OLUÞTURMA

void convert_to_letters(int cust_num){
  
  FILE*dosya;
  dosya=fopen("D:\\Desktop\\Algoritma\\customer.txt","a");

  int j;

    // Sayiyi basamaklarina ayirir
    int digits[8];
    for (j = 0; j < 8; j++) {
        digits[7-j] = cust_num % 10;
        cust_num /= 10;
    }

    // Basamaklara harfler atar
    char letters[8];
    for (j = 0; j < 8; j++) {
        letters[j] = 'A' + digits[j];
    }

    printf("REF No:");
    fprintf(dosya,"ref kodu:");

    // Harfleri yazdirir
    for (j = 0; j < 8; j++) {
        printf("%c", letters[j]);
        fprintf(dosya,"%c",letters[j]);
        }
    }




// SIPARIS VERME

 void order(int i){

  while(1){

    if (!(i>=0 && i<11)){

    printf("Hatali tuslama yaptiniz. Lutfen, tekrar siparis giriniz.");
    break;
      
    }else if ((i>0 && i<11)||(i==0)){
      
    printf("%d numarali icecegi siparis ettiniz.Fiyati: %d\n",++i,product[--i]);

    sum += product[--i];
    printf("Total:%d TL\n",sum);

    printf("Baska bir siparisiniz varsa tuslayiniz? Hayir icin 0'i tuslayiniz.");
    scanf("%d",&i);
   
    
      if(i==0){
      break;
      }
      
    }
}

}


// SIPARIS IPTAL


  void cancel(){
    
  while(1){
    
  FILE*dosya2;
  dosya2 = fopen("D:\\Desktop\\Algoritma\\order.txt","a");
    
  printf("Siparisi iptal etmek ister misiniz? Evetse (E), hayirsa (H) tuslayiniz.");
  scanf("%c",&ans3);
   
    if((ans3=='E')|| (ans3=='e')){
    sum=0;
    printf("Siparisiniz iptal edildi. Total:%d\n",sum);
    break;

    }else if((ans3=='H')|| (ans3=='h')){
    printf("Total:%d\n",sum);
    k++;
    fprintf(dosya2,"%d",k);
    break;
    
    }else{
      printf("Hatali tuslama yaptiniz. Evetse (E), hayirsa (H) tuslayiniz.");
    }
  }

}


// INDIRIMLER

int discount (int sum){

  while(k<=6){

  sum=sum -(sum*(0.05*k));
  printf("%d TL odemeniz gerekmektedir.",sum);
  break;
  if(k==6){
    break;
    }
  }
  
    return 0;

}


  
  
  
  
  

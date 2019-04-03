#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
 
 int main(void)
 
 {
      
   char string[101]; 
    
    
      printf("Please enter text you want to encrypt:");
       
      fgets(string, sizeof(string), stdin);
      
      printf("Encrypted text is:");     
   
  } 
      
      void Cipher(char* string, int key){
          int i=0;
          key=1;
          int cyphervalue; 
          char cypher;
           
          while( string[i] != '\0' && strlen(string)-1 > i){
              cyphervalue = ((int)string[i] - 97 + key) % 26 + 97;
               
              cypher = (char)(cyphervalue);
               
              scanf("%s, %c", string, &cypher);
              
              printf("read: %s, %c", string, cypher); 
              
              i++;
          }
printf("\n"); 
}
      
      
      
       
     

 

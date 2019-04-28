#include <stdio.h>

char encrypt_rotate (char c, int k);
char decrypt_rotate (char c, int k);

int main () {
	char e; //encryted variable
	char d; //decryted variable

	printf("Select operation. \n");
	int k; //value of encrytion key
	scanf("%d", &k); //enter value for k
	printf("Key is %d\n", k);

	int o=0; //Choosing operation value
	printf("(1) For Encrytion. \n");
	printf("(2) For Decrytion. \n");
	scanf("%d", &o);
    
    switch (o) { //switch case for chosen variable
		case 1: printf("Encryption chosen.\n");
		break;
		case 2: printf("Decryption chosen. \n");
		break;
	}

	switch (o) {
	    case 1: {
	        int k;
	        printf("Enter key value into key folder.\n");
	        scanf("%d", &k);
	        printf("The key is %d\n", k);
			FILE *input;
			FILE *output;

			input = fopen("input", "r"); //Message to be encrypted will be contained in this file 
			output = fopen("output", "w"); //writes encrypted message and places into output file

			while (feof(input) ==0){ //Reads input file and encrypts it
				char c;
				fscanf(input, "%c", &c); //Reads input file

			    e = encrypt_rotate (c,k); //Encryption function
			    fprintf(output, "%c", e); //Prints encrypted file and puts into output file  
			}
			break;
		}
		case 2: {
			int k;
			printf("Enter key value into key folder.\n");
			scanf("%d", &k);
			printf("The key is %d\n", k);

			FILE *input;
			FILE *output; 

			input = fopen("Input.txt", "r"); //Message to be decrypted will be contained in this file 
			output = fopen("Output.txt", "w"); //writes decrypted message and places into output file

			while (feof(input) == 0) {
				char c;
				fscanf(input, "%c", &d);

				d = decrypt_rotate(c,k); //Decryption function
				fprintf(output, "%c", d); //Prints encrypted file and puts into output file
			}
			break;
		}
	}
	return 0;
}
	
char encrypt_rotate (char c, int k) {
    if ((c<65) || (c>90 && c<97) || (c>122)) //Non letter characters dont change
        return c;
     
    if (c>=65 && c<=90) //Upper case letters 
        return (((c-65)+k)%26)+65; // A=0 - Z=25, value changed by key
    return 0;
}

char decrypt_rotate (char c, int k){
	if ((c<65) || (c>90))   //Non letter characters dont change
		return c;

	if (c>=65 && c<=90) {
		if (c-65-k<0) {
			return ((((c-65)-k)+26)%26)+65; //Incase value is -ve
		}

		if (c-65>=0) {
			return (((c-65)-k)%26)+65; //A=0 - Z=25, value changed by key, 65 added to get back to ASCII value
		}
	}
}

      
      
       
     

 

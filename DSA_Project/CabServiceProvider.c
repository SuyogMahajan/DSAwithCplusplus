#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// void CabCode(){




// }

// void userlogin(){



// }

void creatuser() {

	FILE * t = fopen("Cabfile1.txt", "w");

	string s, p;

	printf("Enter User name : ");
	scanf("%s", s);

	printf("Enter Password : ");
	scanf("%s", p);

	if (t == NULL ) {
		printf("something went Wrong !!");
		return;
	} else {

		fputs(s, t);
		fputs("\n", t);
		fputs(p, t);
		fputs("\n", t);
	}

	printf("Your User Name & password saved successfully !!!");
}

void loginPage() {

	printf("1 : user login \n2 : creat an account \n3 : Exit");
	int n;
	printf("Enter Your Choice : ");
	scanf("%d", &n);

	creatuser();

	// switch(n){
	// 	case 1:{ userlogin();
	// 		     CabCode();
	// 	         break;  }
	// 	case 2:{ creatuser();
	// 	         CabCode();
	// 	         break; }
	// 	case 3: exit;
	// }
}

int main() {

	// login page
	loginPage();
	// source and destination

	// find shortest path and output money required .


	return 0;
}
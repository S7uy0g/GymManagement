#include<stdio.h>
#include<stdlib.h>
struct membership_time
  {
  	int year,month,day;
  };
struct member_info
  {
  	char name[25];
  	int id,age,height,weight;
  	struct membership_time time;
  };
struct trainer_info
  {
  	char name[25];
  	int id,age,salary,time;
  };   
struct equipment_info
  {
  	char equip[20];
  	int numbers;
  };   
int main()
   {
   	  int choice;
   	  FILE *fp1;
   	  struct member_info dataM;
   	  struct trainer_info dataT;
   	  struct equipment_info dataE;
   	  fp1=fopen("E:\\GymProject.txt","w");
   	  if(fp1==NULL)
   	     {
   	     	printf("File not opened!!!");
   	     	return 0;
   	     	exit(0);
	   	 }
	  while(1)
	   {    
   	  	printf("\nGym Managemnet");
   	  	printf("\n");
   	  	printf("\n1.Add Members");
   	  	printf("\n2.List Members");
   	  	printf("\n3.Trainer Information");
   	  	printf("\n4.Equipement Information");
   	  	printf("\n5.Exit");
   	  	printf("\n");
   	  	flag:
   	  	printf("\nPlaease enter your choice down bellow");
   	  	printf("\nChoice:");
   	  	scanf("%d",&choice);
   	  switch(choice)
   	    {
   	    	case 1:
   	    	 {
			   add:
			   fseek(fp1,0, SEEK_END);	 	
   	    	   printf("Add Member details down bellow:");
			   printf("\n");
			   printf("Name:");
			   gets(dataM.name);
			   fflush(stdin);
			   printf("Id:");
			   scanf("%d",&dataM.id);
			   fflush(stdin);   
			   printf("Age:");
			   scanf("%d",&dataM.age);
			   fflush(stdin);
			   printf("Height(in foot):");
			   scanf("%d",&dataM.height);
			   fflush(stdin);
			   printf("Weight(in kg):");
			   scanf("%d",&dataM.weight);
			   printf("Membership starting date:");
			   printf("\nYear:");
			   scanf("%d",&dataM.time.year);
			   monthwrong:
			   printf("Month:");
			   scanf("%d",&dataM.time.month);
			   if(dataM.time.month>12)
			     {
			     	printf("Wrong Entry!!!!");
			     	printf("\n");
			     	goto monthwrong;
				 }
			   fflush(stdin);	 
			   daywrong: 
			   printf("Day:");
			   scanf("%d",&dataM.time.day);
			   if(dataM.time.day>31)
			     {
			     	printf("Wrong Entry!!");
			     	printf("\n");
			     	goto daywrong;
			     }
			   fflush(stdin);  
			   fwrite(&dataM,sizeof(dataM),1,fp1);
			   fclose(fp1);
			   char YN;
			   YNwrong:
			   printf("Do you want to add another member(input Y/N):");
			   scanf("%s",&YN);
			   if(YN=='Y'||YN=='y')
			     {
			     	goto add;
				   }
			   else if(YN=='N'||YN=='n')
			      {
			      	break;
					   }
				else
				  {
				  	 printf("Wrong Entry!!");
				  	 goto YNwrong;
							  }	        
   	    	   break;
   	         }
   	    	case 2:
   	    	 {
   	    	   fp1=fopen("E:\\GymProject.txt","r");
   	    	   printf("\n");
   	    	   printf("List of all members:");
   	    	   printf("\n");
   	    	   rewind (fp1);
	           while(fread(&dataM,sizeof(dataM),1,fp1)==0)
	             { 
	                 printf("\nId:%d",dataM.id);
			         printf("\nAge:%d",dataM.age);
			         printf("\nHeight(in foot):%d",dataM.height);
			         printf("\nWeight(in kg:)%d",dataM.weight);
			         printf("\nMembership starting date:");
			         printf("\nYear:%d",dataM.time.year);
			         printf("\nMonth:%d",dataM.time.month);
			         printf("\nDay:%d",dataM.time.day);
	             } 
			   break;
		     }
			case 3:
			 {	
			   printf("To be added2");
			   break;
		     }
			case 4:
			 {	
			   printf("To be added3");
			   break;
		     }
			case 5:
			 {	
			   exit(0);	
			   break;
		     }
			default:
			printf("out of range");
			goto flag;
			break;	
	    }
     }
   	  return 0;
   }


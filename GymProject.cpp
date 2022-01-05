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
  	struct membership_time time[5];
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
   	  struct member_info dataM[5];
   	  struct trainer_info dataT[5];
   	  struct equipment_info dataE[5];
   	  fp1=fopen("E:\\GymProject.txt","w+");
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
   	  	printf("\n2.Find Members");
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
   	    	   printf("Add Member details down bellow:");
			   printf("\n");
			   printf("Name:");
			   gets(dataM[1].name);
			   fflush(stdin);
			   printf("Id:");
			   scanf("%d",&dataM[1].id);
			   fflush(stdin);   
			   printf("Age:");
			   scanf("%d",&dataM[1].age);
			   fflush(stdin);
			   printf("Height(in foot):");
			   scanf("%d",&dataM[1].height);
			   fflush(stdin);
			   printf("Weight(in kg):");
			   scanf("%d",&dataM[1].weight);
			   printf("Membership date:");
			   printf("\nYear:");
			   scanf("%d",&dataM[1].time[1].year);
			   monthwrong:
			   printf("Month:");
			   scanf("%d",&dataM[1].time[1].month);
			   if(dataM[1].time[1].month>12)
			     {
			     	printf("Wrong Entry!!!!");
			     	printf("\n");
			     	goto monthwrong;
				 }
			   fflush(stdin);	 
			   daywrong: 
			   printf("Day:");
			   scanf("%d",&dataM[1].time[1].day);
			   if(dataM[1].time[1].day>31)
			     {
			     	printf("Wrong Entry!!");
			     	printf("\n");
			     	goto daywrong;
			     }
			   fflush(stdin);  
			   fwrite(dataM,sizeof(dataM),1,fp1);
			   fclose(fp1);
			   char YN;
			   YNwrong:
			   printf("Do you want to add another member(Y/N):");
			   scanf("%s",&YN);
			   if(YN=='Y'||YN=='y')
			     {
			     	goto add;
				   }
			   else if(YN=='N'||YN=='n')
			      {
			      	return 0;
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
   	    	   printf("To be added");
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


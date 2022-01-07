#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
   	  fp1=fopen("E:\\GymProject.txt","rb+");
   	  if(fp1==NULL)
   	     {
   	     	printf("File not opened!!!");
   	     	return 0
   	     	exit(0);
	   	 }
	  while(1)
	   { 
	    printf("\n");   
   	  	printf("\nGym Managemnet");
   	  	printf("\n");
   	  	printf("\n1.Add Members");
   	  	printf("\n2.List Members");
   	  	printf("\n3.Find Members");
   	  	printf("\n4.Trainer Information");
   	  	printf("\n5.Equipement Information");
   	  	printf("\n6.Exit");
   	  	printf("\n");
   	  	flag:
   	  	printf("\nPlaease enter your choice down bellow");
   	  	printf("\nChoice:");
   	  	scanf("%d",&choice);
   	  	fflush(stdin);
   	    switch(choice)
   	    {
   	    	case 1:
   	    	 {
			   add: 	
   	    	   printf("Add Member details down bellow:");
			   printf("\n");
			   printf("Name:");
			   gets(dataM.name);
			   fflush(stdin);
			   int i=0;
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
			   fflush(stdin);
			   printf("Membership starting date:");
			   printf("\nYear:");
			   scanf("%d",&dataM.time.year);
			   fflush(stdin);
			   monthwrong:
			   printf("Month:");
			   scanf("%d",&dataM.time.month);
			   fflush(stdin);
			   if(dataM.time.month>12||dataM.time.month<1)
			     {
			     	printf("Wrong Entry!!!!");
			     	printf("\n");
			     	goto monthwrong;
				 }	 
			   daywrong: 
			   printf("Day:");
			   scanf("%d",&dataM.time.day);
			   fflush(stdin);
			   if(dataM.time.day>31||dataM.time.day<1)
			     {
			     	printf("Wrong Entry!!");
			     	printf("\n");
			     	goto daywrong;
			     } 
			   fwrite(&dataM,sizeof(dataM),1,fp1);
			   char YNmember;
			   YNwrong:
			   printf("Do you want to add another member(input Y/N):");
			   scanf("%s",&YNmember);
			   fflush(stdin);
			   if(YNmember=='Y'||YNmember=='y')
			     {
			     	goto add;
				   }
			   else if(YNmember=='N'||YNmember=='n')
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
   	    	   printf("\n");
   	    	   printf("List of all members:");
   	    	   printf("\n");
   	    	   rewind (fp1);
	           while(fread(&dataM,sizeof(dataM),1,fp1)>0)
	             { 
	                 printf("\n");
	                 printf("\nName:");
	                 puts(dataM.name);
	                 printf("Id:%d",dataM.id);
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
			   char member_name[20];
			   int member_id;
			   printf("\n");
			   printf("Enter Name and ID down bellow");
			   printf("\nName:");
			   gets(member_name);
			   fflush(stdin);
			   printf("ID:");
			   scanf("%d",&member_id);
			   fflush(stdin);
			   rewind(fp1);
			   while(fread(&dataM,sizeof(dataM),1,fp1)>0)
			     {
			      if(strcmp(member_name,dataM.name)==0 && member_id==dataM.id)
			        {
			           printf("\n");
	                   printf("\nName:");
	                   puts(dataM.name);
	                   printf("Id:%d",dataM.id);
			           printf("\nAge:%d",dataM.age);
			           printf("\nHeight(in foot):%d",dataM.height);
			           printf("\nWeight(in kg:)%d",dataM.weight);
			           printf("\nMembership starting date:");
			           printf("\nYear:%d",dataM.time.year);
			           printf("\nMonth:%d",dataM.time.month);
			           printf("\nDay:%d",dataM.time.day); 
			           char YNmodify;
					   printf("\nDo you want to modify this data(Y/N):")	
					   scanf("%s",&YNmodify);
			           fflush(stdin);
			           YNwrong2:
			           if(YNmodify=='Y'||YNmodify=='y')
			              {
			            	printf("To be added");
				          }
			           else if(YNmodify=='N'||YNmodify=='n')
			             {
			               break;
					     }
					   else
					     {
					     	printf("Wrong Entry!!!");
					     	goto YNwrong2;
					     } 			
					}
			     }
			   break;
		     }
			case 4:
			 {	
			   printf("To be added3");
			   break;
		     }
		    case 5:
			 {
			 	printf("To be added4");
			 } 
			case 6:
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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct membership_time
  {
  	int year,month,day;
  };
struct time
  {
  	int shour,smin,ehour,emin;
  };   
struct member_info
  {
  	char name[25];
  	int id,age,height,weight;
  	struct membership_time time;
  	char workchoice[10];
  	struct time tm;
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
   	  int choice,choicemembership;
	  long int recsize,recsize2,recsize3;  	
   	  FILE *fp1;
   	  struct member_info dataM;
   	  struct trainer_info dataT;
   	  struct equipment_info dataE;
   	  fp1=fopen("E:\\BITproject.txt","rb+");
   	  if(fp1==NULL)
   	     {
   	     	fp1=fopen("E:\\BITproject.txt","wb+");
   	     	if(fp1==NULL)
   	     	{
   	     	    printf("File not opened!!!");
   	     	    return 0;
   	     	    exit(0);
   	        }
	   	 }
	  recsize=sizeof(dataM); 
	  recsize2=sizeof(dataT);
	  recsize3=sizeof(dataE); 
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
   	  	system("cls");
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
			   membershipwrong:	  
			   printf("Choose a membership plan:");
			   printf("\n3months");
			   printf("\n6months");
			   printf("\n9months");
			   printf("\n12months");
			   printf("\nEnter the membership plan(months):");
			   scanf("%d",&choicemembership);
			   if(choicemembership==3||choicemembership==6||choicemembership==9||choicemembership==12)
			   { 
  	           int temptime=0,endyear=0,tempmonth=0;
	           printf("\nMembership ending date:");
	           temptime=dataM.time.month+choicemembership;
	           if(temptime>12)
		         {
	    	        tempmonth=temptime-12;
		            endyear=dataM.time.year+1;
			        printf("\nYear:%d",endyear);
			        printf("\nMonth:%d",tempmonth);
			        printf("\nDay:%d",dataM.time.day);
		         }
	           else
		         {
			        printf("\nYear:%d",dataM.time.year);
			        printf("\nMonth:%d",dataM.time.month+choicemembership);
			        printf("\nDay:%d",dataM.time.day);
		         }
			   }
			   else
			   {
			   	 printf("This package doesnot exist!!");
			   	 goto membershipwrong;
			   }
			   fwrite(&dataM,recsize,1,fp1);
			   char YNmember;
			   YNwrong:
			   printf("\nDo you want to add another member(input Y/N):");
			   scanf("%s",&YNmember);
			   fflush(stdin);
			   system("cls");
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
   	    	   int anynumber;
   	    	   printf("\n");
   	    	   printf("List of all members:");
   	    	   printf("\n");
   	    	   rewind (fp1);
	           while(fread(&dataM,recsize,1,fp1)>0)
	             { 
	                 int temptime=0,endyear=0,endmonth=0,tempmonth=0;
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
	                 printf("\nMembership ending date:");
	                 temptime=dataM.time.month+choicemembership;
	                 if(temptime>12)
		              {
	    	             tempmonth=temptime-12;
		                 endyear=dataM.time.year+1;
			             printf("\nYear:%d",endyear);
			             printf("\nMonth:%d",tempmonth);
			             printf("\nDay:%d",dataM.time.day);
		              }
	                 else
		              {
			             printf("\nYear:%d",dataM.time.year);
			             printf("\nMonth:%d",dataM.time.month+choicemembership);
			             printf("\nDay:%d",dataM.time.day);
		              }             
	             } 
			   printf("\nPress any key to continue.");  
	           getchar();
			   system("cls"); 
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
			   while(fread(&dataM,recsize,1,fp1)>0)
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
			           int temptime=0,endyear=0,tempmonth=0;
	                   printf("\nMembership ending date:");
	                   temptime=dataM.time.month+choicemembership;
	                   if(temptime>12)
		                 {
	    	                tempmonth=temptime-12;
		                    endyear=dataM.time.year+1;
			                printf("\nYear:%d",endyear);
			                printf("\nMonth:%d",tempmonth);
			                printf("\nDay:%d",dataM.time.day);
		                 }
	                   else
		                 {
			                printf("\nYear:%d",dataM.time.year);
			                printf("\nMonth:%d",dataM.time.month+choicemembership);
			                printf("\nDay:%d",dataM.time.day);
		                 }
					   printf("\nWorkout details");
					   printf("\nWorkout Time");
			           printf("\nStarting time:%02d:%02d",dataM.tm.shour,dataM.tm.smin);
			           printf("\nEnding time:%02d:%02d",dataM.tm.ehour,dataM.tm.emin);
			           printf("\nWorkout focus:");
			           puts(dataM.workchoice);
			           int datachoice;
			           datachoicewrong:
			           printf("\nWhat do you want to do with this data:");
			           printf("\n1.Modify");
			           printf("\n2.Input today's workout details");
			           printf("\nEnter your choice:");
			           scanf("%d",&datachoice);
			           switch(datachoice)
			             {
			             	case 1:
			             	  {
			              	     printf("\n");
			            	     printf("Enter the new information for this data:");
			            	     printf("Name:");
			            	     gets(dataM.name);
			            	     fflush(stdin);
			            	     printf("ID:");
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
			                     monthwrong2:
			                     printf("Month:");
			                     scanf("%d",&dataM.time.month);
			                     fflush(stdin);
			                     if(dataM.time.month>12||dataM.time.month<1)
			                        {
			     	                  printf("Wrong Entry!!!!");
			     	                  printf("\n");
			     	                  goto monthwrong2;
				                    }	 
			                     daywrong2: 
			                     printf("Day:");
			                     scanf("%d",&dataM.time.day);
			                     fflush(stdin);
			                     if(dataM.time.day>31||dataM.time.day<1)
			                       {
			     	                  printf("Wrong Entry!!");
			                       	  printf("\n");
			     	                  goto daywrong2;
			                        }
			                     membershipwrong2:	  
			                     printf("Choose a membership plan:");
			                     printf("\n3months");
			                     printf("\n6months");
			                     printf("\n9months");
			                     printf("\n12months");
			                     printf("\nEnter the membership plan(months):");
			                     scanf("%d",&choicemembership);
			                     if(choicemembership!=3||choicemembership!=6||choicemembership!=9||choicemembership!=12)
			                       { 
  	                                  int temptime=0,endyear=0,tempmonth=0,originalmonth=dataM.time.month;
	                                  printf("\nMembership ending date:");
	                                  temptime=originalmonth+choicemembership;
	                                  if(temptime>12)
		                                {
	    	                               tempmonth=temptime-12;
		                                   endyear=dataM.time.year+1;
			                               printf("\nYear:%d",endyear);
			                               printf("\nMonth:%d",tempmonth);
			                               printf("\nDay:%d",dataM.time.day);
		                                }
	                                  else
		                                {
			                               printf("\nYear:%d",dataM.time.year);
			                               printf("\nMonth:%d",dataM.time.month+choicemembership);
			                               printf("\nDay:%d",dataM.time.day);
		                                }
								   }
								 else
								    {
								      printf("This plan doesnot exists!!");
			      	                  goto membershipwrong2;
									}
								  fseek(fp1,-recsize,SEEK_CUR);	            
			                      fwrite(&dataM,recsize,1,fp1);
			                      break;
				            }
			            case 2:
			             {
			               printf("Enter today's workout details:");	
			               printf("\nWorkout Time(00:00)");
			               printf("\nStarting time:");
			               scanf("%02d:%02d",&dataM.tm.shour,&dataM.tm.smin);
			               fflush(stdin);
			               printf("Ending time:");
			               scanf("%02d:%02d",&dataM.tm.ehour,&dataM.tm.emin);
			               fflush(stdin);
			               printf("\nWorkout type:");
			               printf("\nChest");
			               printf("\nLegs");
			               printf("\nFull Body");
			               printf("\nAbs");
			               printf("\nArms");
			               printf("\nBack");
			               printf("\nEnter your workout focus:");
			               gets(dataM.workchoice);
			               fflush(stdin);
						   fseek(fp1,recsize,SEEK_CUR);	 	
			               fwrite(&dataM,recsize,1,fp1);
			               break;
					     }
					    default:
					    printf("Wrong Entry!!!");
					    goto datachoicewrong;
					    break;		
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
			 	break;
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

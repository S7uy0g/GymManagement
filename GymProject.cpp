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
  	int id,age,height,weight,choicemembership;
  	struct membership_time time;
  	char workchoice[10];
  	struct time tm;
  }; 
struct trainer_info
  {
  	char name[25];
  	int id,age,salary,stime,etime;
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
   	  FILE *fp1,*fp2,*ft1,*ft2;
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
	  fp2=fopen("E:\\TrainerInfo.txt","wb+");
	  if(fp2==NULL)
	     {
	     	printf("File2 not opened!!!");
	     	return 0;
	     	exit(0);
	     } 	 
	  recsize=sizeof(dataM); 
	  recsize2=sizeof(dataT);
	  recsize3=sizeof(dataE); 
	  while(1)
	   { 
	    top:
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
			   scanf("%d",&dataM.choicemembership);
			   if(dataM.choicemembership==3||dataM.choicemembership==6||dataM.choicemembership==9||dataM.choicemembership==12)
			   { 
	              printf("\nYour package will end after %dmonths prior to this date.",dataM.choicemembership);
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
	                 printf("\nYour package will end after %dmonths prior to this date.",dataM.choicemembership);           
	             } 
			   printf("\nPress any key to continue.");  
	           getchar();
			   system("cls"); 
			   break;
		     }
			case 3:
			 {	
			   char member_name[20],re;
			   int member_id;
			   printf("\n");
			   refind:
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
			           printf("\nMembership will end after %d months prior to this date",dataM.choicemembership);
			           char datachoice;
			           datachoicewrong:
			           printf("Edit the data?(Y/N)");
			           scanf("%s",&datachoice);
			           fflush(stdin);
			           if(datachoice=='Y'||datachoice=='y')
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
    	                    scanf("%d",&dataM.choicemembership);
			                if(dataM.choicemembership==3||dataM.choicemembership==6||dataM.choicemembership==9||dataM.choicemembership==12)
			                       { 
  	                                  printf("Membership will end after %d months prior to this date.",dataM.choicemembership);
								   }
			   			    else
								    {
								      printf("This plan doesnot exists!!");
			      	                  goto membershipwrong2;
									}
					  	    fseek(fp1,-recsize,SEEK_CUR);	            
			                fwrite(&dataM,recsize,1,fp1);
			                printf("\nPress R to find other data");
			                scanf("%s",&re);
			                fflush(stdin);
			                if(re=='R'||re=='r')
			                  {
			                  	goto refind;
							  }
							else 
			                break;
			           }
			           else if(datachoice=='N'||datachoice=='n')
					   {
					   	  printf("\nPress R to find other data");
			              scanf("%s",&re);
			              fflush(stdin);
			              if(re=='R'||re=='r')
			                  {
			                  	goto refind;
							  }
						  else 
					   	  printf("Press any key to continue");
					   	  getchar();
					   	  break;
					   } 
					   else
					   break;   
				   }
			    }
		     break;
		    }
			case 4:
			 {	
			   int choicetrainer;
			   while(1)
			   {
			   	   Tchoicewrong:
			   	   printf("\n");
			       printf("1.Add Trainer");
			       printf("\n2.Find a Trainer");
			       printf("\n3.List Trainers");
			       printf("\n4.Exit");
			       printf("\nEnter your choice.");
			       scanf("%d",&choicetrainer);
			       fflush(stdin);
			       system("cls");
			       switch(choicetrainer)
			         {
			         	case 1:
			         		{
			         			addtrainer:
			         			printf("\n");
			         			printf("Enter Trainer Details:");
			         			printf("\nName:");
			         			gets(dataT.name);
			         			fflush(stdin);
			         			printf("Id:");
			         			scanf("%d",&dataT.id);
			         			fflush(stdin);
			         			printf("\nAge:");
			         			scanf("%d",&dataT.age);
			         			fflush(stdin);
			         			printf("\nSalary(Rs.):");
			         			scanf("%d",&dataT.salary);
			         			fflush(stdin);
			         			printf("Working hours:");
			         			printf("\nStarting time:");
			         			scanf("%d",&dataT.stime);
			         			fflush(stdin);
			         			printf("Ending time:");
			         			scanf("%d",&dataT.etime);
			         			fflush(stdin);
			         			fwrite(&dataT,recsize2,1,fp2);
			         			char YNtrainer;
			                    YNtrainerwrong:
			                    printf("\nDo you want to add another member(input Y/N):");
			                    scanf("%s",&YNtrainer);
			                    fflush(stdin);
			                    system("cls");
			                    if(YNtrainer=='Y'||YNtrainer=='y')
			                       {
			                        	goto add;
				                    }
			                    else if(YNtrainer=='N'||YNtrainer=='n')
			                       {
			      	                   break;
					               }
				                else
				                   {
				  	                  printf("Wrong Entry!!");
				  	                  printf("Press any key to continue.");
				  	                  getchar();
				  	                  system("cls");
				  	                  goto YNtrainerwrong;
							       }		
							}
						case 2:
							{
								char tname[20];
								int tid;
								ft2=fopen("E:\\temp1.txt","wb+");
								if(ft2==NULL)
								  {
								  	printf("Temp File not opened!!");
								  	return 0;
								  	exit(0);
								  }
								printf("\nEnter Trainer information:");
								printf("\nName:");
								gets(tname);
								fflush(stdin);
								printf("\nID:");
								scanf("%d",&tid);
								fflush(stdin);
								rewind(fp1);
								while(fread(&dataT,recsize2,1,fp2)>0)
								  {
								  	if(strcmp(dataT.name,tname)==0&&tid==dataT.id)
								  	  {
								  	  		printf("\nName:");
			         			            puts(dataT.name);
			         			            printf("Id:%d",&dataT.id);
			         		   	            printf("\nAge:%d",&dataT.age);
			         			            printf("\nSalary(Rs.):%d",&dataT.salary);
			         			            printf("\nWorking hours(24hrs format):");
			         			            printf("\nStarting time:%d",&dataT.stime);
			         			            printf("Ending time:%d",&dataT.etime);
								  	  }
								  	int tdatachoice;    
								  	printf("\nWhat do you want to do with this data:");
								  	tdatawrong:
									printf("\n1.Modify");
									printf("\n2.Delete");
									printf("\n3.Exit");
									printf("\nEnter your choice:");
									scanf("%d",&tdatachoice);
									fflush(stdin);
									system("cls");
									switch(tdatachoice)
									  {
									  	case 1:
									  		{
									  			if(strcmp(dataT.name,tname)==0&&tid==dataT.id)
									  			  {
									  			  	printf("\nEnter new details:");
									  			  	printf("\nName:");
			         			                    gets(dataT.name);
			         			                    fflush(stdin);
			         			                    printf("Id:");
			         			                    scanf("%d",&dataT.id);
			         			                    fflush(stdin);
			         			                    printf("\nAge:");
			         			                    scanf("%d",&dataT.age);
			         			                    fflush(stdin);
			         			                    printf("\nSalary(Rs.):");
			         			                    scanf("%d",&dataT.salary);
			         			                    fflush(stdin);
			         			                    printf("Working hours:");
			         			                    printf("\nStarting time:");
			         			                    scanf("%d",&dataT.stime);
			         			                    fflush(stdin);
			         			                    printf("Ending time:");
			         			                    scanf("%d",&dataT.etime);
			         			                    fflush(stdin);
			         			                    fseek(fp2,-recsize2,SEEK_CUR);
			         			                    fwrite(&dataT,recsize2,1,fp2);
												  }
												break;  
										    }
										case 2:
										    {
										    	if(strcmp(dataT.name,tname)!=0&&tid!=dataT.id)
										    	  {
										    	  	fwrite(&dataT,recsize2,1,ft2);
												  }
												fclose(ft2);
												fclose(fp2);
												remove("TrainerInfo.txt");
												rename("temp1.txt","TrainerInfo.txt");
												fp2=fopen("E:\\TrainerInfo.txt","wb+");
	                                            if(fp2==NULL)
	                                             {
	     	                                        printf("File2 not opened!!!");
	     	                                        return 0;
	     	                                        exit(0);
	                                             }
												break;  	
										    }
										case 3:
										    {
										    	goto top;
											}
										default:
										printf("Wrong Entry!!");
										goto tdatawrong;
										system("cls");		    
									  }    
								  } 
								break;
							}
						case 3:
							{
								printf("\nList of all Trainers");
								printf("\n");
   	    	                    rewind (fp2);
	                            while(fread(&dataT,recsize2,1,fp2)>0)
	                                { 
	                                  
	                                  printf("\n");
	                                  printf("\nName:");
			        		          puts(dataT.name);
			         	              printf("Id:%d",&dataT.id);
			         		   	      printf("\nAge:%d",&dataT.age);
			        		          printf("\nSalary(Rs.):%d",&dataT.salary);
			         	              printf("\nWorking hours(24hrs format):");
			         			      printf("\nStarting time:%d",&dataT.stime);
			         			      printf("Ending time:%d",&dataT.etime);
	                                } 
			                    printf("\nPress any key to continue.");  
	                            getchar();
			                    system("cls"); 
								break;
							}
						case 4:
							{
								break;
							}	
						default:
						printf("Wrong choice!!");
						goto Tchoicewrong;
						break;	
					 }
			   }
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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
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
  	char equip[30];
  	int numbers;
  };
struct workout_info
  {
  	char workout_focus[10];
  	int wtime;
  };
struct workout_infoA
  {
  	int wid;
  	struct workout_info wi[6];
  };         
int main()
   {
   	  int choice,choicemembership;
	  long int recsize,recsize2,recsize3,recsize4,tempsize1;  	
   	  FILE *fp1,*fp2,*fp3,*fp4,*ft1,*ft2,*ft3,*ft4;
   	  struct member_info dataM;
   	  struct trainer_info dataT;
   	  struct equipment_info dataE;
   	  struct workout_infoA dataW;
   	  fp1=fopen("E:\\BITproject.txt","rb+");
   	  if(fp1==NULL)
   	     {
   	     	fp1=fopen("E:\\BITproject.txt","wb+");
   	     	if(fp1==NULL)
   	     	{
   	     	    printf("File not opened!!!");
   	     	    exit(0);
   	     	    return 0;
   	        }
	   	 }
	  fp2=fopen("E:\\TrainerInfo.txt","rb+");
	  if(fp2==NULL)
	     {
	     	fp2=fopen("E:\\TrainerInfo.txt","wb+");
   	     	if(fp1==NULL)
   	     	 {
   	     	 	printf("File2 not opened!!!");
	     	    exit(0);
   	     	    return 0;
			 }
	     } 	
	  fp3=fopen("E:\\EquipmentInfo.txt","rb+");
	  if(fp3==NULL)
	     {
	     	fp3=fopen("E:\\EquipmentInfo.txt","wb+");
	        if(fp3==NULL)
	         {
	     	   printf("File3 not opened!!!");
	     	   exit(0);
   	     	   return 0;
	         }
	     }
	  fp4=fopen("E:\\WorkoutInfo.txt","rb+");
	  if(fp4==NULL)
	     {
	     	fp4=fopen("E:\\WorkoutInfo.txt","wb+");
	        if(fp4==NULL)
	         {
	     	   printf("File4 not opened!!!");
	     	   exit(0);
   	     	    return 0;
	         }
	     }       
	  recsize=sizeof(dataM); 
	  recsize2=sizeof(dataT);
	  recsize3=sizeof(dataE);
	  recsize4=sizeof(dataW); 
	  tempsize1=sizeof(dataE.numbers);
	  while(1)
	   { 
	    top:
	    printf("\n\n\n\n\n\n\n\n");   
   	  	printf("\n\t\t\t\t\t\t\t\t\t(|--|)Gym Managemnet(|--|)");
   	  	printf("\n\t\t\t\t\t\t\t\t\t**************************");
   	  	printf("\n");
   	  	printf("\n\t\t\t\t\t\t\t\t\t1.Add Members");
   	  	printf("\n\t\t\t\t\t\t\t\t\t2.List Members");
   	  	printf("\n\t\t\t\t\t\t\t\t\t3.Find Members");
   	  	printf("\n\t\t\t\t\t\t\t\t\t4.Workout Sheet");
   	  	printf("\n\t\t\t\t\t\t\t\t\t5.Trainer Information");
   	  	printf("\n\t\t\t\t\t\t\t\t\t6.Equipement Information");
   	  	printf("\n\t\t\t\t\t\t\t\t\t7.Exit");
   	  	printf("\n");
   	  	flag:
   	  	printf("\n\t\t\t\t\t\t\t\t\tPlaease enter your choice down bellow");
   	  	printf("\n\t\t\t\t\t\t\t\t\t\t\tChoice:");
   	  	scanf("%d",&choice);
   	  	fflush(stdin);
   	  	system("cls");
   	    switch(choice)
   	      {
   	    	case 1:
   	    	 {
			   add: 	
			   printf("\n\n\n\n\n\n\n\n"); 
   	    	   printf("\n\t\t\t\t\t\t\t\t\t(|--|)Add Member details down bellow(|--|)");
   	    	   printf("\n\t\t\t\t\t\t\t\t\t******************************************");
			   printf("\n");
			   printf("\n\t\t\t\t\t\t\t\t\tName:");
			   gets(dataM.name);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tId:");
			   scanf("%d",&dataM.id);
			   fflush(stdin); 
			   printf("\t\t\t\t\t\t\t\t\tAge:");
			   scanf("%d",&dataM.age);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tHeight(in foot):");
			   scanf("%d",&dataM.height);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tWeight(in kg):");
			   scanf("%d",&dataM.weight);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tMembership starting date:");
			   printf("\n\t\t\t\t\t\t\t\t\tYear:");
			   scanf("%d",&dataM.time.year);
			   fflush(stdin);
			   monthwrong:
			   printf("\t\t\t\t\t\t\t\t\tMonth:");
			   scanf("%d",&dataM.time.month);
			   fflush(stdin);
			   if(dataM.time.month>12||dataM.time.month<1)
			     {
			     	printf("Wrong Entry!!!!");
			     	printf("\n");
			     	goto monthwrong;
				 }	 
			   daywrong: 
			   printf("\t\t\t\t\t\t\t\t\tDay:");
			   scanf("%d",&dataM.time.day);
			   fflush(stdin);
			   if(dataM.time.day>31||dataM.time.day<1)
			     {
			     	printf("Wrong Entry!!");
			     	printf("\n");
			     	goto daywrong;
			     }
			   membershipwrong:	  
			   printf("\t\t\t\t\t\t\t\t\tChoose a membership plan:");
			   printf("\n\t\t\t\t\t\t\t\t\t3months");
			   printf("\n\t\t\t\t\t\t\t\t\t6months");
			   printf("\n\t\t\t\t\t\t\t\t\t9months");
			   printf("\n\t\t\t\t\t\t\t\t\t12months");
			   printf("\n\t\t\t\t\t\t\t\t\tEnter the membership plan(months):");
			   scanf("%d",&dataM.choicemembership);
			   if(dataM.choicemembership==3||dataM.choicemembership==6||dataM.choicemembership==9||dataM.choicemembership==12)
			   { 
	              printf("\n\t\t\t\t\t\t\t\t\tYour package will end after %dmonths prior to this date.",dataM.choicemembership);
			   }
			   else
			   {
			   	 printf("\n\t\t\t\t\t\t\t\t\tThis package doesnot exist!!");
			   	 goto membershipwrong;
			   }
			   fwrite(&dataM,recsize,1,fp1);
			   char YNmember;
			   YNwrong:
			   printf("\n\t\t\t\t\t\t\t\t\tDo you want to add another member(input Y/N):");
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
				  	 printf("\n\t\t\t\t\t\t\t\t\tWrong Entry!!");
				  	 goto YNwrong;
				  }
			   printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue");
			   getchar();
			   system("cls");  			  	        
   	    	   break;
   	         }
   	    	case 2:
   	    	 {
   	    	   int anynumber;
   	    	   printf("\n");
   	    	   printf("\n\t\t\t\t\t\t\t\t\tList of all members:");
   	    	   printf("\n");
   	    	   rewind (fp1);
	           while(fread(&dataM,recsize,1,fp1)>0)
		     {

	                 printf("\n");
	                 printf("\n\t\t\t\t\t\t\t\t\tName:");
	                 puts(dataM.name);
	                 printf("\t\t\t\t\t\t\t\t\tId:%d",dataM.id);
			         printf("\n\t\t\t\t\t\t\t\t\tAge:%d",dataM.age);
			         printf("\n\t\t\t\t\t\t\t\t\tHeight(in foot):%d",dataM.height);
			         printf("\n\t\t\t\t\t\t\t\t\tWeight(in kg:)%d",dataM.weight);
			         printf("\n\t\t\t\t\t\t\t\t\tMembership starting date:");
			         printf("\n\t\t\t\t\t\t\t\t\tYear:%d",dataM.time.year);
			         printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",dataM.time.month);
			         printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day); 
	                 printf("\n\t\t\t\t\t\t\t\t\tYour package will end after %dmonths prior to this date.",dataM.choicemembership);         
	             } 
			   printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue.");  
	           getchar();
			   system("cls"); 
			   break;
		     }
			case 3:
			 {	
			   char member_name[20],membermodify;
			   int member_id,count=0;
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
   		          if(strcmp(dataM.name,member_name)==0&&dataM.id==member_id)
                    {
                    	count=count+1;
                    }
                }
               if(count==0)
			     {
			     	printf("Member not found.");
			     	goto refind;
				  } 
			   int datachoice;
			   printf("\nWhat do you want to do with this data:");
			   datachoicewrong:
			   printf("\n1.Show");
	           printf("\n2.Modify");
			   printf("\n3.Delete");
		       printf("\n4.Exit");
	           printf("\nInput your choice:");
	           scanf("%d",&datachoice);
		       fflush(stdin);
		       system("cls"); 
		       switch(datachoice)
			       {
			       	  case 1:
			       	  	{
			       	  		rewind(fp1);
			       	  		while(fread(&dataM,recsize,1,fp1)>0)
	                           { 
	                             if(strcmp(dataM.name,member_name)==0&&dataM.id==member_id)
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
	                                    printf("\nYour package will end after %d months prior to this date.",dataM.choicemembership);  
	                                    printf("Press any key to continue..");
	                                    getchar();
	                                    system("cls");
								    }
	                           } 
			       	  		break;
					    }
					  case 2:
					    {
					    	rewind(fp1);
			       	  		while(fread(&dataM,recsize,1,fp1)==1)
			       	  		   {
			       	  		   	  if(strcmp(dataM.name,member_name)==0&&dataM.id==member_id)
			       	  		   	    {
			       	  		   	    	 printf("\nModify details down bellow:");
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
	                                            printf("\nYour package will end after %dmonths prior to this date.",dataM.choicemembership);
			                                }
			                             else
			                                {
			   	                                printf("This package doesnot exist!!");
			   	                                goto membershipwrong;
			                                }
			                             fseek(fp1,-recsize,SEEK_CUR);  
			                             fwrite(&dataM,recsize,1,fp1);
			                             system("cls");
			                             break;
									}
							   }
					    	break;
					    }
					  case 3:
					    {
			   	   	        ft1=fopen("E:\\temp1.txt","wb+");
			                if(ft1==NULL)
			                    {
			                	     printf("Temp1 File not opened!!");
						             exit(0);
   	     	                         return 0;
		      	               }
					    	rewind(fp1);
			       	  		while(fread(&dataM,recsize,1,fp1)==1)
			       	  		   {
			       	  		   	  if(strcmp(dataM.name,member_name)!=0&&dataM.id!=member_id)
									 {
							    	  	fwrite(&dataM,recsize,1,ft1);
								     }   
							    }
							fclose(fp1);    
						    fclose(ft1);
				  		    remove("E:\\BITproject.txt");
				 		    rename("E:\\temp1.txt","E:\\BITproject.txt");  
						    fp1=fopen("E:\\BITproject.txt","rb+");
	                        if(fp1==NULL)
	                           {
							                printf("File1.1 not opened!!!");
	     	                                exit(0);
   	     	                                return 0;					
	                            } 	   
					    	break;
					    }
					  case 4:
					    {
					    	printf("Press any key to continue..");
							getchar();
							system("cls"); 
					    	break;
					    }
					  default:	
					  printf("Wrong choice!!");
					  goto datachoicewrong;
					  system("cls");
					  break;				  
				   }
		 	   break;  
			  }	
		    case 4:
		      {
		      	int wcount=0;
		      	char WSname[25];
		      	int i=0;
		      	int WSchoice,WSid;
	 	  	  	NIwrong:
		      	printf("\nEnter Name and ID:");
		      	printf("\nName:");
	 	  	  	gets(WSname);
		      	fflush(stdin);
		      	printf("ID:");
		      	scanf("%d",&WSid);
		      	fflush(stdin);
		      	rewind(fp1);
			    while(fread(&dataM,recsize,1,fp1)>0)
			       	{
		      	   	  	if(strcmp(WSname,dataM.name)==0&&WSid==dataM.id)
		      		  	  	  {
		      	 	  	  	  	system("cls");
								wcount=wcount+1;		 	
							  }
					}
				if(wcount==0)
				   {
						printf("\nMember Not Found");
				      	printf("\nPress any key to continue.");
				      	getchar();
				      	system("cls");
					  	goto NIwrong;
				   }
		      	while(1)
		      	 {
		      	 	WSchoicewrong:
		      	 	printf("Workout Sheet Info:");
					printf("\n");   	
		      	 	printf("\n1.Modify Workoutsheet");
		      	 	printf("\n2.Show Workoutsheet");
		      	 	printf("\n3.Exit");
		      	 	printf("\nChoice:");
		      	 	scanf("%d",&WSchoice);
		      	 	fflush(stdin);
		      	 	system("cls");
		      	 	switch(WSchoice)
		      	 	  {
		      	 	  	case 1:
		      	 	  	  {
							WScontinue:
							printf("Enter your id:"); 
							scanf("%d",&dataW.wid);
							fflush(stdin);
							printf("Enter the workout details of 7days");
							for(i=0;i<7;i++)
							  {
							  	printf("\nWorkout Focus");
							  	printf("\n1.FullBody");
							  	printf("\n2.Arms");
							  	printf("\n3.Abs");
							  	printf("\n4.Legs");
							  	printf("\n5.Rest");
							  	printf("\nFocus(Input in words):");
							  	scanf("%s",&dataW.wi[i].workout_focus);
							  	fflush(stdin);
								printf("Workout Time(hrs spent):");
								scanf("%d",&dataW.wi[i].wtime);
								fflush(stdin);
								system("cls");  
							  }
							fwrite(&dataW,recsize4,1,fp4);     
		      	 	  	  	break;
					      }
					    case 2:
						  {
						  	printf("Enter ID:");
						  	scanf("%d",&WSid);
						  	fflush(stdin);
						  	rewind(fp4);
						  	while(fread(&dataW,recsize4,1,fp4)>0)
						  	  {
						  	  	if(WSid==dataW.wid)
						  	  	  {
						  	  	  	printf("\nTrainer ID:%d",dataW.wid);
						  	  	  	printf("\nWorkout Details");
						  	  	  	for(i=0;i<7;i++)
						  	  	  	  {
						  	  	  	    printf("\nWorkout Focus:%s",dataW.wi[i].workout_focus);
						  	  	  	    if(dataW.wi[i].workout_focus=="Rest")
						  	  	  	       {
						  	  	  	       	  break;
											}
						  	  	  	    printf("\nWorkout Time(hrs spent):%d",dataW.wi[i].wtime);
						  	  	      }
								  }
							  }
						  	break;
						  }
						case 3:
						  {
						  	goto top;
							break;
						  }  
						default:  
						printf("Wrong choice!!");
					    goto WSchoicewrong;
					    system("cls");
					    break;	  
					  }
				 }
			break;
			  }
			case 5:
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
			         			printf("Age:");
			         			scanf("%d",&dataT.age);
			         			fflush(stdin);
			         			printf("Salary(Rs.):");
			         			scanf("%d",&dataT.salary);
			         			fflush(stdin);
			         			printf("Working hours:");
			         			printf("\nStarting time:");
			         			scanf("%d",&dataT.stime);
			         			fflush(stdin);
			         			printf("\nEnding time:");
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
			                        	goto addtrainer;
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
								invalidtrainer:  
								printf("\nEnter Trainer information:");
								printf("\nName:");
								gets(tname);
								fflush(stdin);
								printf("\nID:");
								scanf("%d",&tid);
								fflush(stdin);
								rewind(fp2);
								while(fread(&dataT,recsize2,1,fp2)>0)
								  {
								  	if(strcmp(dataT.name,tname)==0&&tid==dataT.id)
								  	  {
								  	  	printf("\nName:");
			         			        puts(dataT.name);
			         			        printf("Id:%d",dataT.id);
			         		   	        printf("\nAge:%d",dataT.age);
			         			        printf("\nSalary(Rs.):%d",dataT.salary);
			         			        printf("\nWorking hours(24hrs format):");
			         	                printf("\nStarting time:%d",dataT.stime);
			         			        printf("Ending time:%d",dataT.etime);
			         			        break;
								  	  }
								  	else
								  	  {
								  	  	printf("This Trainer doesnot exist.");
								  	  	printf("Press any key to continue...");
								  	  	getchar();
								  	  	system("cls");
								  	  	goto invalidtrainer;
									  }
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
									  			rewind(fp2);
								                while(fread(&dataT,recsize2,1,fp2)>0)
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
			         			                        printf("Age:");
			         			                        scanf("%d",&dataT.age);
			         			                        fflush(stdin);
			         			                        printf("Salary(Rs.):");
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
												break;  
										    }
										case 2:
										    {
										    	ft2=fopen("E:\\temp2.txt","wb+");
								                if(ft2==NULL)
								                 {
									  	                printf("Temp File not opened!!");
								  	                    exit(0);
   	     	                                            return 0;  	
								                  }
										    	rewind(fp2);
								                while(fread(&dataT,recsize2,1,fp2)>0)
								                  {
								                    if(strcmp(dataT.name,tname)!=0&&tid!=dataT.id)
										    	      {
										    	  	    fwrite(&dataT,recsize2,1,ft2);
												      }
										 	      }
												    fclose(ft2);
												    fclose(fp2);
												    remove("E:\\TrainerInfo.txt");
												    rename("E:\\temp2.txt","E:\\TrainerInfo.txt");
	                                             	    fp2=fopen("E:\\TrainerInfo.txt","rb+");
	                                                    if(fp2==NULL)
	                                                      {
	                                                   	    printf("File2.1 not opened!!!");
	     	                                                exit(0);
   	     	                                                return 0;
													      }	
												printf("Press any key to continue..");
							                    getchar();
							                    system("cls");    
												break;  
										    }
										case 3:
										    {
										       printf("Press any key to continue..");
							                   getchar();
							                   system("cls");    
											   break;  	
											}
										default:
										printf("Wrong Entry!!");
										goto tdatawrong;
										system("cls");
										break;		    
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
			         	              printf("Id:%d",dataT.id);
			         		   	      printf("\nAge:%d",dataT.age);
			        		          printf("\nSalary(Rs.):%d",dataT.salary);
			         	              printf("\nWorking hours(24hrs format):");
			         			      printf("\nStarting time:%d",dataT.stime);
			         			      printf("\nEnding time:%d",dataT.etime);
	                                } 
			                    printf("\nPress any key to continue.");  
	                            getchar();
			                    system("cls"); 
								break;
							}
						case 4:
							{
								printf("Press any key to continue.");
								getchar();
								system("cls");
								goto top;
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
		    case 6:
			 {
			 	int equipchoice;
			 	while(1)
			 	{
			 	printf("\n");	
			 	printf("Equipment Management");
			 	printf("\n");
			 	printf("\n1.Add Equipment");
			 	printf("\n2.List all Equipments");
			 	printf("\n3.Find Equipment");
			 	printf("\n4.Exit");
			 	printf("\nEnter your choice:");
			 	scanf("%d",&equipchoice);
			 	fflush(stdin);
			 	system("cls");
			 	switch(equipchoice)
			 	   {
			 	   	  case 1:
			 	   	  	{
			 	   	  		addequip:
			 	   	  		printf("\nAdd equipment information");
			 	   	  		printf("\n");
			 	   	  		printf("\nEquipment name:");
			 	   	  		gets(dataE.equip);
			 	   	  		fflush(stdin);
							printf("No. of ");
							puts(dataE.equip);
							scanf("%d",&dataE.numbers);
							fflush(stdin);
							fwrite(&dataE,recsize3,1,fp3);
			         	    char YNequipment;
			                YNequipwrong:
			                printf("\nDo you want to add another equipment(input Y/N):");
			                scanf("%s",&YNequipment);
			                fflush(stdin);
			                system("cls");
			                if(YNequipment=='Y'||YNequipment=='y')
			                    {
			                      	goto addequip;
				                }
			               else if(YNequipment=='N'||YNequipment=='n')
			                    {
		      	                   break;
   			                    }
				            else
				                {
				  	              printf("\nWrong Entry!!");
				                  printf("\nPress any key to continue.");
			 	                  getchar();
			  	                  system("cls");
			  	                  goto YNequipwrong;
						       }		
							break;
				 	    }
				 	  case 2:
					   {
					   	    printf("\n");
					   	    printf("List of all equipments");
					   	    printf("\n");
   	    	                rewind (fp3);
	                        while(fread(&dataE,recsize3,1,fp3)>0)
	                          {
	                          	printf("\nEquipemnt name:");
	                          	puts(dataE.equip);
								printf("Total no:%d",dataE.numbers);  
							  }
							printf("\nPress any key to continue..");
							getchar();
							system("cls");  
					   	    break;
					   }
					  case 3:
					   {
					   	  char tequip[30];
					   	  int tweight,aequip;
					   	  printf("\n");
					   	  printf("Enter Equipment information");
					   	  printf("\nEquipment name:");
					   	  gets(tequip);
					   	  fflush(stdin);
						  system("cls");  
						  int edatachoice;
				  		  MRwrong:
						  printf("\nWhat do you want to do with this data");
						  printf("\n1.Show");
						  printf("\n2.Modify");
						  printf("\n3.Remove");
						  printf("\n4.Exit");
						  printf("\nEnter your choice:");
						  scanf("%d",&edatachoice);
						  fflush(stdin);
						  system("cls");
						  switch(edatachoice)
								  {
								  	 case 1:
								  	 	{
								  	 	    rewind(fp3);
			                                while(fread(&dataE,recsize3,1,fp3)>0)
						                    {
						    	            if(strcmp(dataE.equip,tequip)==0)
						    	            {
									   	          printf("\nEquipment name:");
						    	  	              puts(dataE.equip);
						    	  	              printf("Total no:%d",dataE.numbers);  
								            }
								            break;
							                }
								  	 		break;
									    }
								  	 case 2:
								  	 	{
								  	 		char AR,a,r;
								  	 		rewind (fp3);
	                                        while(fread(&dataE,recsize3,1,fp3)>0)
	                                          {
	                                          	if(strcmp(dataE.equip,tequip)==0)
	                                          	  {
	                                       	  	            ARwrong:
								  	 		                printf("Add or Remove no. of ");
								  	                        puts(dataE.equip);
								  	 	                    printf("\nPress (A to add/R to remove):");
								  	 	                    scanf("%s",&AR);
								  	 	                    if(AR=='a'||AR=='A')
								  	 	                      {
								  	 	      	                printf("Add(in no.):");
								  	 	      	                scanf("%d",&a);
								  	 	      	                fflush(stdin);
								  	 	      	                dataE.numbers=dataE.numbers+a;
								  	 	      	                fseek(fp3,-tempsize1,SEEK_CUR);
								  	 	      	                fwrite(&dataE,tempsize1,1,fp3);
											                  }
											                else if(AR=='r'||AR=='R')
								  	 	                      {
								  	 	      	                printf("Remove(in no.):");
								  	 	      	                scanf("%d",&r);
								  	 	      	                fflush(stdin);
								  	 	      	                dataE.numbers=dataE.numbers-r;
								  	 	      	                fseek(fp3,-tempsize1,SEEK_CUR);
								  	 	      	                fwrite(&dataE,tempsize1,1,fp3);
											                  }
													        else
													          {
													         	printf("Wrong Entry!!");
													  	        goto ARwrong;
													          } 
												  }
												break;  
										      }
								  	 		break;
									    }
									  case 3:
									    {
									    	
					   	                   ft3=fopen("E:\\temp3.txt","wb+");
				  		                   if(ft3==NULL)
							                   {
				  		          	              printf("Temp File not opened!!");
							  	                  exit(0);
   	     	                                      return 0;
							                  }
									       rewind(fp3);
									       while(fread(&dataE,recsize3,1,fp3)>0)
									       {
											   	    if(strcmp(dataE.equip,tequip)!=0)
											   	      {
											   	      	fwrite(&dataE,recsize3,1,ft3);
													  }
										    }    
											fclose(ft3);
											fclose(fp3);
											remove("E:\\EquipmentInfo.txt");
											rename("E:\\temp3.txt","E:\\EquipmentInfo.txt");
	                                        fp3=fopen("E:\\EquipmentInfo.txt","rb+");
	                                        if(fp3==NULL)
	                                            {
	                                                  	printf("File3 not opened!!!");
	     	                                            exit(0);
   	     	                                            return 0;
												}
	                                        break ;   
									    }  
									  case 4:
									    {
									    	printf("Press any key to continue..");
								            getchar();
								            system("cls");
								            break;
									    }
									  default:
									  printf("Wrong choice!!");
									  printf("Press any key to continue..");
									  getchar();
									  goto MRwrong;
									  break;
							break;
					   }
					  case 4:
					   {
					   	  printf("Press any key to continue..");
					      getchar();
			              system("cls");
			 			  goto top;			
				      break;
					   }
					  default:
					  printf("Wrong choice!!");
				      printf("Press any key to continue..");
					  getchar();	
					  break;     
				   }
			   }
			 } 
			case 7:
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
   }
   fclose(fp1);
   fclose(fp2);
   fclose(fp3);
   fclose(fp4);
   return 0; 
   closegraph();
}

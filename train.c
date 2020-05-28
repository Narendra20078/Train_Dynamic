#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Train_info{
    int train_No;
    char train_Name[50];
    struct Time{
        int Hour;
        int minute;
    }Departure_time,Arrival_Time;
    char StartStation[20];
    char EndStation[20];
}s[20];
void main()
{
    int i,n,choice,min,j;
    printf("Enter The Number of Trains to fill Data:-\t");
    scanf("%d",&n);
    printf("Enter The Data of Trains\n\n");
    for(i=0;i<n;i++)
    {
        printf("Enter The Details of %d train\n",i+1);
        printf("Enter Train No                       :- ");
        scanf("%d",&s[i].train_No);
        fflush(stdin);
        printf("Enter Train Name                     :- ");
        gets(s[i].train_Name);
        printf("Enter Starting station               :- ");
        gets(s[i].StartStation);
        printf("Enter The End Station                :- ");
        gets(s[i].EndStation);
        printf("Enter The Arival Time(Hour:Minute)   :- ");
        scanf("%d%d",&s[i].Arrival_Time.Hour,&s[i].Arrival_Time.minute);
        printf("Enter The Departure Time(Hour:Minute):- ");
        scanf("%d%d",&s[i].Departure_time.Hour,&s[i].Departure_time.minute);
        printf("\n\n");
    }
    printf("\n\bThe Stored Information:-\n\n");
    for(i=0;i<n;i++)
    {
        printf("Train Info %d",i+1);
        printf("\nTrain No.       :-\t%d",s[i].train_No);
        printf("\nTrain Name      :-\t%s",s[i].train_Name);
        printf("\nStarting Station:-\t%s",s[i].StartStation);
        printf("\nEnd Station     :-\t%s",s[i].EndStation);
        printf("\nArival Time     :-\t%d\t%d",s[i].Arrival_Time.Hour,s[i].Arrival_Time.minute);
        printf("\nDeparture Time  :-\t%d\t%d",s[i].Departure_time.Hour,s[i].Departure_time.minute);
        printf("\n\n");
    }
    system("pause");
    while(1)
    {
        system("cls");
        printf("Lets Short The Trains:-\n\n");
        printf("1.Short By Train No.\n");
        printf("2.Short By Train Name.\n");
        printf("3.Short By Starting Station.\n");
        printf("4.Short End Station.\n");
        printf("5.Short By Train Arival Time.\n");
        printf("6.Short By Train Departure Time.\n");
        printf("7.For Exit\n\n");
        printf("Enter Your Choice!\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                system("cls");
                printf("The Shorted List According to Train Number is:-\n\n");
                system("pause");
                for(i=0;i<n-1;i++)
                {
                    min=i;
                    for(j=0;j<n-i-1;j++)
                        if(s[min].train_No>s[j].train_No)
                            min=j;
                    fflush(stdin);
                    fflush(stdout);
                    printf("\nTrain No               :- %d",s[min].train_No);
                    printf("\nTrain Name             :- %s",s[min].train_Name);
                    printf("\nTrain starting station :- %s",s[min].StartStation);
                    printf("\nTrain End Station      :- %s",s[min].EndStation);
                    printf("\nTrain Arival Time      :- %d\t%d",s[min].Arrival_Time.Hour,s[min].Arrival_Time.minute);
                    printf("\nDeparture Time         :- %d\t%d",s[min].Departure_time.Hour,s[min].Departure_time.minute);
                    printf("\n");        
                }
                break;
            case 2:
                system("cls");
                printf("The Shorted Liste Acording to Train Name is:-\n\n");
                for(i = 0 ; i < n - 1 ; i++)
                    {
                        for(j = 0 ; j < n - i - 1; j++)
                        {
                            if(strcmp(s[j].train_Name,s[j+1].train_Name) > 0)
                                min=j;
                        }
                        printf("\nTrain No               :- %d",s[min].train_No);
                        printf("\nTrain Name             :- %s",s[min].train_Name);
                        printf("\nTrain starting station :- %s",s[min].StartStation);
                        printf("\nTrain End Station      :- %s",s[min].EndStation);
                        printf("\nTrain Arival Time      :- %d\t%d",s[min].Arrival_Time.Hour,s[min].Arrival_Time.minute);
                        printf("\nDeparture Time         :- %d\t%d",s[min].Departure_time.Hour,s[min].Departure_time.minute);
                        printf("\n");    
                    }
                break;
            case 7:
                exit(0);
        }
    }
    getch();
}
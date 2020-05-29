//    Program To store Train information 
//    Shorting with different Attributes
//    Like Train_no,Train Name,Starting station ..

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <string.h>

//  "Train Structure"
struct Train_info{
    int train_No;
    char train_Name[50];
    struct Time{
        int Hour;
        int minute;
    }Departure_time,Arrival_Time;
    char StartStation[20];
    char EndStation[20];
};

// Function To Receive The Train Info
void Ginfo(struct Train_info *train,int n)
{
    int i;
    printf("Enter The Data of Trains\n\n");
    for(i=0;i<n;i++)
    {
        printf("Enter The Details of %d train\n",i+1);
        printf("Enter Train No                       :- ");
        scanf("%d",&(train + i)->train_No);
        fflush(stdin);
        printf("Enter Train Name                     :- ");
        gets((train + i)->train_Name);
        printf("Enter Starting station               :- ");
        gets((train + i)->StartStation);
        printf("Enter The End Station                :- ");
        gets((train + i)->EndStation);
        printf("Enter The Arival Time(Hour:Minute)   :- ");
        scanf("%d%d",&(train + i)->Arrival_Time.Hour,&(train +i)->Arrival_Time.minute);
        printf("Enter The Departure Time(Hour:Minute):- ");
        scanf("%d%d",&(train +i)->Departure_time.Hour,&(train + i)->Departure_time.minute);
        printf("\n\n");
    }
}

//Function To Print tored Info
void Pinfo(struct Train_info *train,int n)
{
    int i;
    printf("\n\bThe Stored Information:-\n\n");
    for(i=0;i<n;i++)
    {
        printf("Train Info %d",i+1);
        printf("\nTrain No.       :-\t%d"    ,(train + i)->train_No);
        printf("\nTrain Name      :-\t%s"    ,(train + i)->train_Name);
        printf("\nStarting Station:-\t%s"    ,(train + i)->StartStation);
        printf("\nEnd Station     :-\t%s"    ,(train + i)->EndStation);
        printf("\nArival Time     :-\t%d\t%d",(train + i)->Arrival_Time.Hour,(train + i)->Arrival_Time.minute);
        printf("\nDeparture Time  :-\t%d\t%d",(train + i)->Departure_time.Hour,(train + i)->Departure_time.minute);
        printf("\n\n");
    }
}

//Function To Sort BY "SORT TRAIN NUMBER"
void STNo(struct Train_info *train, int n)
{
    int i,j;
    struct Train_info temp;
    for(i = 0; i < n-1 ; i++)//Using Bubble Sort Technique
    {
        for(j = 0; j < n - i -1; j++)
            if( train[j].train_No > train[j+1].train_No)
            {
                temp = train[j];
                train[j] = train[j+1];
                train[j+1] = temp;
            }        
    }
}

//Function To Sort BY "SORT TRAIN NAME"
void STName(struct Train_info *train, int n)
{
    int i,j;
    struct Train_info temp;
    for(i = 0 ; i < n - 1 ; i++)
    {
        for(j = 0 ; j < n - i - 1; j++)
        {
            if (strcmp( train[j].train_Name, train[j + 1].train_Name) > 0)
            {
                temp=train[j];
                train[j]=train[j+1];
                train[j+1]=temp;
            }
        }
    }            
}

//Function To Sort BY "SORT TRAIN" by "STARTING STATION"
void STSS(struct Train_info *train, int n)
{
    int i,j;
    struct Train_info temp;
    for(i = 0 ; i < n - 1 ; i++)
    {
        for(j = 0 ; j < n - i - 1; j++)
        {
            if (strcmp( train[j].StartStation, train[j + 1].StartStation) > 0)
            {
                temp=train[j];
                train[j]=train[j+1];
                train[j+1]=temp;
            }
        }
    }            
}

//Function To Sort BY "SORT TRAIN" by "END STATION"
void STES(struct Train_info *train, int n)
{
    int i,j;
    struct Train_info temp;
    for(i = 0 ; i < n - 1 ; i++)
    {
        for(j = 0 ; j < n - i - 1; j++)
        {
            if (strcmp( train[j].EndStation, train[j + 1].EndStation) > 0)
            {
                temp=train[j];
                train[j]=train[j+1];
                train[j+1]=temp;
            }
        }
    }            
}

//Function To Sort BY "SORT TRAIN" by "ARRIVAL TIME"
void STAT(struct Train_info *train, int n)
{
    int i,j;
    struct Train_info temp;
    for(i = 0; i < n-1 ; i++)
    {
        for(j = 0; j < n - i -1; j++)
        {
            if( train[j].Arrival_Time.Hour > train[j+1].Arrival_Time.Hour)
            {
                temp = train[j];
                train[j] = train[j+1];
                train[j+1] = temp;
            }
            if( train[j].Arrival_Time.Hour = train[j+1].Arrival_Time.Hour)
            {
                if(train[j].Arrival_Time.minute > train[j+1].Arrival_Time.minute)
                {
                    temp = train[j];
                    train[j] = train[j+1];
                    train[j+1] = temp;
                }
            }
        }        
    }
}

//Function To Sort By "SORT TRAIN" by "DEPARTURE TIME"
void STDT(struct Train_info *train, int n)
{
    int i,j;
    struct Train_info temp;
    for(i = 0; i < n-1 ; i++)
    {
        for(j = 0; j < n - i -1; j++)
        {
            if( train[j].Departure_time.Hour > train[j+1].Departure_time.Hour)
            {
                temp = train[j];
                train[j] = train[j+1];
                train[j+1] = temp;
            }
            if( train[j].Departure_time.Hour = train[j+1].Departure_time.Hour)
            {
                if(train[j].Departure_time.minute > train[j+1].Departure_time.minute)
                {
                    temp = train[j];
                    train[j] = train[j+1];
                    train[j+1] = temp;
                }
            }
        }        
    }
}

//Driver Code
void main()
{
    int i,n,choice,min,j;
    printf("Enter The Number of Trains to fill Data:-\t");
    scanf("%d",&n);

    //Memory Allocation for No. of Trains
    struct Train_info *train = (struct Train_info*)malloc(n * sizeof(struct Train_info));
    
    //Call Ginfo Fuunction To receive Train Info
    Ginfo(train , n);
    
    //Call Pinfo Function To print Stored Train Info
    Pinfo(train , n);
    system("pause");
    while(1)
    {
        system("cls");
        printf("Lets Short The Trains:-\n\n");
        printf("1.Short By Train No.\n");
        printf("2.Short By Train Name.\n");
        printf("3.Short By Starting Station.\n");
        printf("4.Short By End Station.\n");
        printf("5.Short By Train Arival Time.\n");
        printf("6.Short By Train Departure Time.\n");
        printf("7.For Exit\n\n");
        printf("Enter Your Choice!\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                system("cls");
                printf("The Sorted List According to Train Number is:-\n\n");
                STNo(train , n);
                Pinfo(train , n);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("The Sorted List Acording to Train Name is:-\n\n");
                STName(train , n);
                Pinfo(train , n);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("The Sorted List According to Starting Station:-\n\n");
                STSS(train , n);
                Pinfo(train , n);
                system("pause");
                break;
            case 4:
                system("cls");
                printf("The Sorted List According To End Station:-\n\n");
                STES(train , n);
                Pinfo(train , n);
                system("pause");
            case 5:
                system("cls");
                printf("The Sorted List According To Arrival Time:-\n\n");
                STAT(train , n);
                Pinfo(train , n);
                system("pause");
                break;
            case 6:
                system("cls");
                printf("The Sorted List According to Departure Time:-\n\n");
                STDT(train , n);
                Pinfo(train , n);
                system("pause");
                break;
            case 7:
                exit(0);
        }
    }
    free(train);
    getch();
}

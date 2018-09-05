#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>


void cgpa();
int Menu1();
int Menu2();
int Menu3();
void Registration();
void Login();
void Advisor_Informations();
void Course_Code();
void Rules_And_Regulations();
void Notice_Board();
void Search();
void logout();
void Profile();
void time();

struct Student_Info
{

    char Id[15];
    char Name[25];
    char Department[15];
    char Father_Name[25];
    char Mother_Name[25];
    char Guardian_Name[25];
    int FContact_Number;
    int MContact_Number;
    char Blood_Group[10];
    char Permanent_Address[50];
    char Present_Address[50];
    char Email[25];
    char User_Name[20];
    char Password[15];
};


int main()
{

    time();

    struct Student_Info S[1000];
    int Choice,EXIT;

    Choice=Menu1();

    switch(Choice)
    {
    case 1:
        Registration();
        break;

    case 2:
        Login();
        break;

    case 3:
        Search();
        break;

    case 4:
        EXIT=0;
        break;

    default :
        printf("It's a warning for you,Please enter the correct KEYWORD");
        Choice=Menu1();
    }
}


int Menu1()
{
    system("cls");
    int Choice,EXIT;


    printf("You Are Welcome To Our East West University\n");
    printf("\nSelect the KEYWORD which you want\n\n");
    printf("(1)Registration\n");
    printf("(2)Login\n");
    printf("(3)Search\n");
    printf("(4)EXIT\n\n");


    scanf("%d",&Choice);
    fflush(stdin);


    system("cls");

    return Choice;
}


void Registration()
{

    struct Student_Info r;
    int n=0;


    printf("Give The Student's Information: \n");


    FILE *fp;
    fp=fopen("Registration.txt","a");

    printf("\nEnter Your ID: ");
    scanf("%s",&r.Id);
    fflush(stdin);

    printf("\nEnter Your Name: ");
    scanf("%s",r.Name);
    fflush(stdin);

    printf("\nEnter Your Department: ");
    scanf("%s",r.Department);
    fflush(stdin);

    printf("\nEnter Your Father Name: ");
    scanf("%s",r.Father_Name);
    fflush(stdin);

    printf("\nEnter Your Mother Name: ");
    scanf("%s",r.Mother_Name);
    fflush(stdin);

    printf("\nEnter Your Guardian Name: ");
    scanf("%s",r.Guardian_Name);
    fflush(stdin);

    printf("\nEnter Your Father's Contact Number: ");
    scanf("%d",&r.FContact_Number);
    fflush(stdin);

    printf("\nEnter Your Mother's Contact Number: ");
    scanf("%d",&r.MContact_Number);
    fflush(stdin);

    printf("\nEnter Your Blood Group: ");
    scanf("%s",r.Blood_Group);
    fflush(stdin);

    printf("\nEnter Your Permanent Address: ");
    scanf("%s",r.Permanent_Address);
    fflush(stdin);

    printf("\nEnter Your Present Address: ");
    scanf("%s",r.Present_Address);
    fflush(stdin);

    printf("\nEnter Your Email Address: ");
    scanf("%s",r.Email);
    fflush(stdin);

    printf("\nEnter Your User Name: ");
    scanf("%s",r.User_Name);
    fflush(stdin);

    printf("\nEnter Your Password: ");
    scanf("%s",r.Password);
    fflush(stdin);


    fprintf(fp,"%s\n",r.Id);
    fprintf(fp,"%s\n",r.Name);
    fprintf(fp,"%s\n",r.Department);
    fprintf(fp,"%s\n",r.Father_Name);
    fprintf(fp,"%s\n",r.Mother_Name);
    fprintf(fp,"%s\n",r.Guardian_Name);
    fprintf(fp,"%d\n",r.FContact_Number);
    fprintf(fp,"%d\n",r.MContact_Number);
    fprintf(fp,"%s\n",r.Blood_Group);
    fprintf(fp,"%s\n",r.Permanent_Address);
    fprintf(fp,"%s\n",r.Present_Address);
    fprintf(fp,"%s\n",r.Email);
    fprintf(fp,"%s\n",r.User_Name);
    fprintf(fp,"%s\n",r.Password);


    fclose(fp);

    fp=fopen("student number.txt","r");

    fscanf(fp,"%d",&n);

    fclose(fp);

    n=n+1;

    fp=fopen("student number.txt","w");

    fprintf(fp,"%d\n",n);

    fclose(fp);

    printf("\n\nYou Have Registered Successfully\n\n");


    int Choice,EXIT;

    Choice=Menu1();

    switch(Choice)
    {
    case 1:
        Registration();
        break;

    case 2:
        Login();
        break;

    case 3:
        Search();
        break;

    case 4:
        EXIT=0;
        break;

    default :
        printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
        Choice=Menu1();
    }

}


void Search()
{

    struct Student_Info d[1000];
    char search_name[25];
    char search_user_name[15];
    int i,n,ans1,ans2,cnt1,cnt2,cnt3;


    printf("\nEnter Your Name For Search: ");
    scanf("%s",search_name);
    fflush(stdin);

    printf("\nEnter Your User Name For Search: ");
    scanf("%s",search_user_name);
    fflush(stdin);


    FILE *fp;
    fp=fopen("student number.txt","r");

    fscanf(fp,"%d",&n);

    fclose(fp);

    fp=fopen("registration.txt","r");


    for(i=0; i<n; i++)
    {
        fscanf(fp,"%s\n",&d[i].Id);
        fscanf(fp,"%s\n",d[i].Name);
        fscanf(fp,"%s\n",d[i].Department);
        fscanf(fp,"%s\n",d[i].Father_Name);
        fscanf(fp,"%s\n",d[i].Mother_Name);
        fscanf(fp,"%s\n",d[i].Guardian_Name);
        fscanf(fp,"%d\n",&d[i].FContact_Number);
        fscanf(fp,"%d\n",&d[i].MContact_Number);
        fscanf(fp,"%s\n",d[i].Blood_Group);
        fscanf(fp,"%s\n",d[i].Permanent_Address);
        fscanf(fp,"%s\n",d[i].Present_Address);
        fscanf(fp,"%s\n",d[i].Email);
        fscanf(fp,"%s\n",d[i].User_Name);
        fscanf(fp,"%s\n",d[i].Password);
    }

    fclose(fp);


    for(i=0; i<n; i++)
    {
        ans1=strcmp(search_name,d[i].Name);
        ans2 =strcmp(search_user_name,d[i].User_Name);
        cnt1=0;
        cnt2=0;


        if( ans1==0 && ans2==0)
        {
            cnt1++;
            break;
        }

        else if(ans1==0 && ans2!=0)
        {
            cnt2++;
            break;
        }

    }

    if(cnt1==1)
    {
        printf("\nCONGRATULATIONS_YOU ARE AVAILABLE HERE\n");
    }

    else if(cnt2==1)
    {
        printf("\nSORRY_YOU ARE NOT AVAIABLE HERE\n\n");
    }

    int Choice,EXIT;

    Choice=Menu1();

    switch(Choice)
    {
    case 1:
        Registration();
        break;

    case 2:
        Login();
        break;

    case 3:
        Search();
        break;

    case 4:
        EXIT=0;
        break;

    default :
        printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
        Choice=Menu1();
        }
}



void Login()
{

    struct Student_Info r[1000];
    char login_user_name[25];
    char login_password[15];
    int i,n,ans1,ans2,cnt1,cnt2,cnt3;


    printf("\nEnter Your Login User Name: ");
    scanf("%s",login_user_name);
    fflush(stdin);

    printf("\nEnter Your Login Password: ");
    scanf("%s",login_password);
    fflush(stdin);


    FILE *fp;
    fp=fopen("student number.txt","r");

    fscanf(fp,"%d",&n);

    fclose(fp);

    fp=fopen("registration.txt","r");


    for(i=0; i<n; i++)
    {
        fscanf(fp,"%s\n",&r[i].Id);
        fscanf(fp,"%s\n",r[i].Name);
        fscanf(fp,"%s\n",r[i].Department);
        fscanf(fp,"%s\n",r[i].Father_Name);
        fscanf(fp,"%s\n",r[i].Mother_Name);
        fscanf(fp,"%s\n",r[i].Guardian_Name);
        fscanf(fp,"%d\n",&r[i].FContact_Number);
        fscanf(fp,"%d\n",&r[i].MContact_Number);
        fscanf(fp,"%s\n",r[i].Blood_Group);
        fscanf(fp,"%s\n",r[i].Permanent_Address);
        fscanf(fp,"%s\n",r[i].Present_Address);
        fscanf(fp,"%s\n",r[i].Email);
        fscanf(fp,"%s\n",r[i].User_Name);
        fscanf(fp,"%s\n",r[i].Password);
    }

    fclose(fp);


    for(i=0; i<n; i++)
    {
        ans1=strcmp(login_user_name,r[i].User_Name);
        ans2=strcmp(login_password,r[i].Password);
        cnt1=0;
        cnt2=0;
        cnt3=0;


        if( ans1 ==0 && ans2==0)
        {
            cnt1++;
            break;
        }

        else if  (ans1==0 && ans2!=0)
        {
            cnt2++;
            break;
        }

        else if (ans1!=0)
        {
            cnt3++;
        }

    }

    if(cnt1==1)
    {
        system("cls");
        printf("\nLOGIN SUCCESSFULL\n");

        int Choice1;

        Choice1=Menu2();

        switch(Choice1)
        {
        case 1:
            Advisor_Informations();
            break;

        case 2:
            Rules_And_Regulations();
            break;

        case 3:
            Course_Code();
            break;

        case 4:
            Notice_Board();
            break;

        case 5:
            Profile();
            break;

        case 6:
            cgpa();
            break;
        case 7:
            logout();

        default :
            printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
            Choice1=Menu2();

        }
    }

        else if(cnt2==1)
        {
            system("cls");
            printf("\nPASSWORD MISMATCH\n");


            int Choice,EXIT;

            Choice=Menu1();

            switch(Choice)
            {
            case 1:
                Registration();
                break;

            case 2:
                Login();
                break;

            case 3:
                Search();
                break;

            case 4:
                EXIT=0;
                break;

            default :
                printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
                Choice=Menu1();
            }
        }

        else if (cnt3==1)
        {
            system("cls");
            printf("\nTHERE IS NO SUCH USER IN THE RECORD\n");
            int Choice,EXIT;

            Choice=Menu1();

            switch(Choice)
            {
            case 1:
                Registration();
                break;

            case 2:
                Login();
                break;

            case 3:
                Search();
                break;

            case 4:
                EXIT=0;
                break;

            default :
                printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
                Choice=Menu1();

            }
        }


    }


    int Menu2()
    {

        int Choice1;

        printf("\nNOW You Are Most Welcome To-EAST WEST UNIVERSITY-Information Page\n");
        printf("\nSelect the KEYWORD which you want\n\n");
        printf("(1)Advisor_Informations\n");
        printf("(2)Rules_&_Regulations\n");
        printf("(3)Course_Code\n");
        printf("(4)Notice_Board\n");
        printf("(5)Profile\n");
        printf("(6)Cgpa calculation\n");
        printf("(7)Logout\n\n");

        scanf("%d",&Choice1);
        fflush(stdin);

        system("cls");

        return Choice1;
    }


    void Advisor_Informations()
    {

        printf("\nAdvisor Informations of Computer Science And Engineering\n\n");

        printf("(1)Advisor Name: Dr.Mozammel Huq Azad Khan\n");
        printf("   Office Room: 216\n");
        printf("   Email Id: mhakhan AT ewubd DOT edu\n");
        printf("   Homepage: http://www.ewubd.edu/~mhakhan\n\n");


        printf("(2)Advisor Name: Dr. Md. Nawab Yousuf Ali\n");
        printf("   Office Room: 221\n");
        printf("   Email Id: nawab AT ewubd DOT edu\n");
        printf("   Homepage: http://www.ewubd.edu/~nawab\n\n");


        printf("(3)Advisor Name: Dr. Shamim Hasnat Ripon\n");
        printf("   Office Room: 104\n");
        printf("   Email Id: dshr AT ewubd DOT edu\n");
        printf("   Homepage: http://www.ewubd.edu/~dshr\n\n");


        printf("(4)Advisor Name: Dr. Shaikh Muhammad Allayear\n");
        printf("   Office Room: 351\n");
        printf("   Email Id: allayear AT ewubd DOT edu\n");
        printf("   Homepage: http://ewubd.edu/~allayear\n\n");


        printf("(5)Advisor Name: Dr. Taskeed Jabid\n");
        printf("   Office Room: 372\n");
        printf("   Email Id: taskeed AT ewubd DOT edu\n");
        printf("   Homepage: http://ewubd.edu/~taskeed\n\n");


        printf("(6)Advisor Name: Fahmida Azmi\n");
        printf("   Office Room: 206\n");
        printf("   Email Id: fazmi AT ewubd DOT edu\n");
        printf("   Homepage: http://www.ewubd.edu/~fazmi\n\n");


        printf("(7)Advisor Name: Md. Shamsujjoha\n");
        printf("   Office Room: 107\n");
        printf("   Email Id: msj AT ewubd DOT edu\n");
        printf("   Homepage: http://www.ewubd.edu/~msj\n\n");


        printf("(8)Advisor Name: Mohammad Kamrul Islam\n");
        printf("   Office Room: 206\n");
        printf("   Email Id: kamrultopu AT ewubd DOT edu\n");
        printf("   Homepage: http://www.ewubd.edu/~kamrultopu\n\n");


        printf("(9)Advisor Name: K.M.Imtiaz-Ud-Din\n");
        printf("   Office Room: 239\n");
        printf("   Email Id: kmimtiaz AT ewubd DOT edu\n");
        printf("   Homepage: http://www.ewubd.edu/~kmimtiaz\n\n");


        int Choice1;

        Choice1=Menu2();

        switch(Choice1)
        {
        case 1:
            Advisor_Informations();
            break;

        case 2:
            Rules_And_Regulations();
            break;

        case 3:
            Course_Code();
            break;

        case 4:
            Notice_Board();
            break;

        case 5:
            Profile();
            break;

        case 6:
            cgpa();
            break;
        case 7:
            logout();
            break;

        default :
            printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
            Choice1=Menu2();
        }


    }


    void Rules_And_Regulations()
    {

        printf("\nSEE THE GRADING SYSTEM OF ~EAST WEST UNIVERSITY~\n\n");
        printf("97-100;(A+);4.00\n90-below97;(A);4.00\n87-below90;(A-);3.70\n");
        printf("83-below87;(B+);3.30\n80-below83;(B);3.00\n77-below80;(B-);2.70\n");
        printf("73-below77;(C+);2.30\n70-below73;(C);2.00\n67-below70;(C-);1.70\n");
        printf("63-below67;(D+);1.30\n60-below63;(D);1.00\nbelow60;(F);0.00\n");
        printf("\n\n\n");
        printf("\nSEE THE UNDERGRADUATE PROGRAMS CREDITS IN ~EAST WEST UNIVERSITY~\n\n");
        printf("Bachelor of Business Administration-30 Credits\n");
        printf("BSS in Economics-30 Credits\n");
        printf("BA in English-30 Credits\n");
        printf("BSS in Sociology-30 Credits\n");
        printf("BS in Applied Statistics-31 Credits\n");
        printf("B.Sc.in Computer Science & Engineering-35 Credits\n");
        printf("B.Sc.in Information and Communications Engineering-35 Credits\n");
        printf("B.Sc.in Electronic & Telecommunication Engineering-35 Credits\n");
        printf("B.Sc.in Electrical & Electronic Engineering-35 Credits\n");
        printf("B.Sc.in Genetic Engineering and Biotechnology-33 Credits\n");
        printf("Bachelor of Pharmacy-40 Credits\n\n");

        int Choice1;

        Choice1=Menu2();

        switch(Choice1)
        {
        case 1:
            Advisor_Informations();
            break;

        case 2:
            Rules_And_Regulations();
            break;

        case 3:
            Course_Code();
            break;

        case 4:
            Notice_Board();
            break;

        case 5:
            Profile();
            break;

        case 6:
            cgpa();
            break;
        case 7:
            logout();
            break;

        default :
            printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
            Choice1=Menu2();
        }


    }


    void Notice_Board()
    {

        printf("URGENT NEWS:-\n\n");
        printf("(1)ADMISSION FOR FALL-2014 going on,The Dates of Undergraduate Admission Test:\n");
        printf("=>(BBA,ENG,ECO, Sociology)16 August 2014 at 10:00 AM\n=>(CSE,ICE,ETE,EEE,Genetic,Pharmacy,Applied Statistics)16 August 2014 at 02:30PM\n");
        printf("(2)Application Deadline:14 August 2014 by 2:00PM\n\n");
        printf("LATEST NEWS:-\n\n");
        printf("(1)World Environment Day Observed at East West University\n=>Posted on:June 05,2014");
        printf("(2)Fresher`s Reception at EWU\n=>Posted on:June 03,2014\n\n");
        printf("EVENTS OF THIS WEEK:\n\n");
        printf("Mentoring Day of FIREFOX,Held at ICS Lab on June 17,2014(Time-4:00PM)\n");
        printf("In CCC the BCCP Program held on June 19,2014(Time-9:00AM)\n\n");
        printf("You Will Get Other Newses As Soon As Possible...\n\n            ~~~THANK YOU~~~\n\n\n");

        int Choice1;

        Choice1=Menu2();

        switch(Choice1)
        {
        case 1:
            Advisor_Informations();
            break;

        case 2:
            Rules_And_Regulations();
            break;

        case 3:
            Course_Code();
            break;

        case 4:
            Notice_Board();
            break;

        case 5:
            Profile();
            break;

        case 6:
            cgpa();
            break;
        case 7:
            logout();
            break;

        default :
            printf("\nIt's a warning for you,Please enter the correct KEYWORD\n\n");
            Choice1=Menu2();

        }
    }


    void Profile()
    {

        struct Student_Info k[1000];
        char profile_name[25];
        char profile_user_name[15];
        int i,n,pos,ans1,ans2,cnt1,cnt2,cnt3;

        FILE *fp;
        fp=fopen("student number.txt","r");

        fscanf(fp,"%d",&n);
        fclose(fp);

        fp=fopen("Registration.txt","r");


        for(i=0; i<n; i++)
        {
            fscanf(fp,"%s\n",&k[i].Id);
            fscanf(fp,"%s\n",k[i].Name);
            fscanf(fp,"%s\n",k[i].Department);
            fscanf(fp,"%s\n",k[i].Father_Name);
            fscanf(fp,"%s\n",k[i].Mother_Name);
            fscanf(fp,"%s\n",k[i].Guardian_Name);
            fscanf(fp,"%d\n",&k[i].FContact_Number);
            fscanf(fp,"%d\n",&k[i].MContact_Number);
            fscanf(fp,"%s\n",k[i].Blood_Group);
            fscanf(fp,"%s\n",k[i].Permanent_Address);
            fscanf(fp,"%s\n",k[i].Present_Address);
            fscanf(fp,"%s\n",k[i].Email);
            fscanf(fp,"%s\n",k[i].User_Name);
            fscanf(fp,"%s\n",k[i].Password);
        }

        fclose(fp);

        fp=fopen("student number.txt","r");

        fscanf(fp,"%d",&n);
        fclose(fp);

        printf("\nEnter Your Name For Search In Profile: ");
        scanf("%s",profile_name);
        fflush(stdin);

        printf("\nEnter Your User Name For Search In Profile: ");
        scanf("%s",profile_user_name);
        fflush(stdin);

        printf("\n\n\n");

        for(i=0; i<n; i++)
        {
            ans1=strcmp(profile_name,k[i].Name);
            ans2 =strcmp(profile_user_name,k[i].User_Name);
            pos=i;
            cnt1=0;
            cnt2=0;


            if( ans1==0 && ans2==0)
            {
                cnt1++;
                break;
            }

            else if(ans1==0 && ans2!=0)
            {
                cnt2++;
                break;
            }
        }

        if(cnt1==1)
        {

            printf("Student ID              : %s\n",k[pos].Id);
            printf("Student Name            : %s\n",k[pos].Name);
            printf("Department              : %s\n",k[pos].Department);
            printf("Father's Name           : %s\n",k[pos].Father_Name);
            printf("Mother's Name           : %s\n",k[pos].Mother_Name);
            printf("Guardian's Name         : %s\n",k[pos].Guardian_Name);
            printf("Father's Contact Number : %d\n",k[pos].FContact_Number);
            printf("Mother's Contact Number : %d\n",k[pos].MContact_Number);
            printf("Blood Group             : %s\n",k[pos].Blood_Group);
            printf("Permanent Address       : %s\n",k[pos].Permanent_Address);
            printf("Present Address         : %s\n",k[pos].Present_Address);
            printf("Email                   : %s\n",k[pos].Email);
            printf("User Name               : %s\n",k[pos].User_Name);
            printf("Password                : %s\n",k[pos].Password);

        }
        int Choice1;

        Choice1=Menu2();

        switch(Choice1)
        {
        case 1:
            Advisor_Informations();
            break;

        case 2:
            Rules_And_Regulations();
            break;

        case 3:
            Course_Code();
            break;

        case 4:
            Notice_Board();
            break;

        case 5:
            Profile();
            break;

        case 6:
            cgpa();
            break;
        case 7:
            logout();
            break;

        default :
            printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
            Choice1=Menu2();
            }

    }


    void Course_Code()
    {

        printf("COURSE CODE OF COMPUTERSCIENCE AND ENGINEERING\n\n");
        printf("1. CSE 105\n");
        printf("2. CSE 107\n");
        printf("3. CSE 109\n");
        printf("4. CSE 205\n");
        printf("5. CSE 209\n");
        printf("6. CSE 225\n");
        printf("7. CSE 245\n");
        printf("8.  CSE 251\n");
        printf("9.  CSE 301\n");
        printf("10. CSE 325\n");
        printf("11. CSE 345\n");
        printf("12. CSE 348\n");
        printf("13. CSE 350\n");
        printf("14. CSE 360\n");
        printf("15. CSE 365\n");

        int Choice1;

        Choice1=Menu2();

        switch(Choice1)
        {
        case 1:
            Advisor_Informations();
            break;

        case 2:
            Rules_And_Regulations();
            break;

        case 3:
            Course_Code();
            break;

        case 4:
            Notice_Board();
            break;

        case 5:
            Profile();
            break;

        case 6:
            cgpa();
            break;
        case 7:
            logout();
            break;

        default :
            printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
            Choice1=Menu2();
        }

    }

    void logout()
    {
        printf("\nAre You sure you want to logout? if yes press 1 or press anything to go bact to menu\n");

        int Choice2,Logout,Choice1;

        Choice2=Menu3();

        if(Choice2==1)
        {
            system("cls");
            Menu1();
        }
        else
        {
            system("cls");
            Choice1=Menu2();
            switch(Choice1)
            {
            case 1:
                Advisor_Informations();
                break;

            case 2:
                Rules_And_Regulations();
                break;

            case 3:
                Course_Code();
                break;

            case 4:
                Notice_Board();
                break;

            case 5:
                Profile();
                break;

            case 6:
                cgpa();
                break;
            case 7:
                logout();
                break;

            default :
                printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
                Choice1=Menu2();
            }
        }

    }


    int Menu3()
    {

        int Choice2;

        printf("(1)Logout\n");

        scanf("%d",&Choice2);
        fflush(stdin);

        return Choice2;
    }


    void time()
    {

        time_t ts;
        struct tm *current;
        int a,b,c;

        time(&ts);
        current=localtime(&ts);

        a=current->tm_mday;
        b=current->tm_mon+1;
        c=current->tm_year+1900;

        printf("                            Date: %d-%d-%d\n", a,b,c);
        printf("\n\n");
    }

    void cgpa()
    {
        int n;
        float mark[100];
        int total,p;
        float Credit[100];
        int q=0;
        int r=0;
        float sum_credit=0;
        printf("Enter the Number of subjects you have taken\n");
        scanf("%d",&n);
        for(p=1; p<=n; p++)
        {
            printf("Enter your subject(%d) marks (one by one)\n",p);
            scanf("%f",&mark[q]);
            q++;
            printf("Enter Credit\n");
            scanf("%f",&Credit[r]);
            sum_credit=sum_credit+Credit[r];
            r++;
        }
        q=0;
        r=0;
        float sum=0;
        for(p=0; p<n; p++)
        {
            if(mark[q]<60)
            {
                printf("Failed\n");
            }
            else if(mark[q]>=60 && mark[q]<70)
            {
                sum=sum+Credit[r]*1;
            }
            else if(mark[q]>=70 && mark[q]<80)
            {
                sum=sum+Credit[r]*2;
            }
            else if(mark[q]>=80 && mark[q]<=83)
            {
                sum=sum+Credit[r]*3;
            }
            else if(mark[q]>=84 && mark[q]<87)
            {
                sum=sum+Credit[r]*3.3;
            }
            else if(mark[q]>=87 && mark[q]<90)
            {
                sum=sum+Credit[r]*3.7;
            }
            else if(mark[q]>=90 && mark[q]<=100)
            {
                sum=sum+Credit[r]*4.0;
            }
            q++;
            r++;
        }
        printf("Total Credit: %f\n",sum_credit);
        printf("Total Credit points: %2f\n",sum);

        float Cgpa;
        Cgpa=sum/sum_credit;
        printf("Your CGPA is : %f\n",Cgpa);


        int Choice1;

        Choice1=Menu2();

        switch(Choice1)
        {
        case 1:
            Advisor_Informations();
            break;

        case 2:
            Rules_And_Regulations();
            break;

        case 3:
            Course_Code();
            break;

        case 4:
            Notice_Board();
            break;

        case 5:
            Profile();
            break;

        case 6:
            cgpa();
            break;
        case 7:
            logout();
            break;

        default :
            printf("\nIt's a warning for you,Please enter the correct KEYWORD\n");
            Choice1=Menu2();
        }

        system("cls");
    }

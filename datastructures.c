#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
int song_op=0,lang_op=0,genre_op=0,fav_op=0;
char lang_ch[10];
struct song
{
    char name[30];
    char genre[30];
    char lang[30];
    char singer[30];
    char movie[30];
}s[SIZE];
struct operations
{
    char name[30];
    char lang[30];
    struct operations *next;
}*head_his,*head_fav,*temp,*newnode;
void display_songs()
{
    printf("\n\t");
    line(30);
    printf("\n");
    int i;
    for(i=0; i<SIZE; i++)
        printf("%\t%d->%s\n",i+1,s[i].name);
    printf("\t");
    line(30);
}

void history(int index)
{
    newnode = (struct operations*)malloc(sizeof(struct operations));
    strcpy(newnode->name,s[index].name);
    newnode->next = NULL;
    if(head_his == NULL)
    {
        head_his = newnode;
    }
    else
    {
        temp = head_his;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display_history()
{
    int i=1;
    line(30);
    printf("\n");
    if(head_his == NULL)
     printf("no songs are available");
    else
    {
        temp = head_his;
        while(temp != NULL)
        {
            printf("%d->%s\n",i,temp->name);
            temp = temp->next;
            i++;
        }
    }
    printf("\n");
    line(30);
}
int size_his()
{
    int i;
    temp = head_his;
    while(temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
void del_in_his( int index)
{
    line();
    printf("\n");
    int i=1;
    struct operations *temp1;
    if(head_his==NULL)
    {
        printf("\n\tNo songs are not in the history list... ");
    }
    else
    {
        if(index == 1)
        {
            temp1 = head_his;
            head_his = temp1->next;
            printf("\n\t%s is successfully deleted ",temp1->name);
            free(temp1);
        }
        else
        {
        temp = head_his;
        while(i < index - 1)
        {
            temp = temp->next;
            i++;
        }
        if(temp->next->next == NULL)
        {
            printf("\n\t%s is successfully removed from history\n",temp->next->name);
            temp->next = NULL;
        }
        else
        {
            temp1 = temp->next;
            temp->next = temp->next->next;
            printf("\n\t%s is successfully removed from history\n",temp1->name);
            free(temp1);
        }
    }
        }
        printf("\n");
       line(30);
}
void Delete_history()
{
    line();
    printf("\n");
    if(head_his == NULL)
        printf("\tNo songs are available in the History ...\n");
    else
    {
        head_his = NULL;
        printf("\t");
        line(30);
        printf("\n\n\tHistory is Succesfully Deleted...\n\n");
        printf("\t");
        line(30);
    }
}
void add_to_fav(int index)
{
    newnode = (struct operations*)malloc(sizeof(struct operations));
    strcpy(newnode->name,s[index].name);
    newnode->next=NULL;
    if(head_fav == NULL)
            head_fav=newnode;
    else
    {
        temp = head_fav;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
int size_fav()
{
    printf("\n");
    int i;
    temp = head_fav;
    while(temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
void del_in_fav(int index)
{
    int i=1;
    struct operations *temp1;
    if(head_fav == NULL)
        printf("\n\tNo songs are not in the Favourites list... ");
    else
    {
        if(index == 1)
        {
            temp1 = head_fav;
            head_fav = temp1->next;
            printf("\n\t%s is successfully deleted ",temp1->name);
            free(temp1);
        }
        else
        {
        temp = head_fav;
        while(i < index - 1)
        {
            temp = temp->next;
            i++;
        }
        if(temp->next->next == NULL)
        {
            printf("\n\t%s is successfully removed from favorites",temp->next->name);
            temp->next = NULL;
        }

        else
        {
            temp1 = temp->next;
            temp->next = temp->next->next;
            printf("\n\t%s is successfully removed from favorites",temp1->name);
            free(temp1);
        }
    }
}
}
void display_fav()
{
    int i=1;
    line(30);
    printf("\n");
    if(head_fav == NULL)
        printf("\n\tNO songs are added to the favourites ....\n\n");
    else
    {
        temp=head_fav;
        while(temp != NULL)
        {
            printf("%d->%s\n",i,temp->name);
            temp = temp->next;
            i++;
        }
    }
    line(30);
}
void sort_by_lang(char str[])
{
    line(30);
    printf("\n");
        int i;
        printf("\n \t Displaying %s songs.....\n",str);
        for(i = 0 ; i < SIZE ; i++)
        {
            if(strcmp(str,s[i].lang) == 0)
                printf("\n%s",s[i]);
        }
printf("\n");
        line(30);
}
void line(int n)
{
    int i;
    for(i=1 ; i<=n ; i++ )
        printf("*");
}
void display_details(int opt)
{
    line(30);
    printf("\n");
    int i;
    for(i=0 ; i<SIZE ; i++)
    {
        if(opt == i)
        {
            printf("\nsong name : %s", s[i].name);
            printf("\nMovie name : %s",s[i].movie);
            printf("\nGenre : %s",s[i].genre);
            printf("\nLanguage : %s",s[i].lang);
            printf("\nSinger :%s",s[i].singer);
        }
    }
    printf("\n");
    line(30);
}
void sort_by_genre(char str[])
{
    line(30);
    printf("\n");
    int i;
    printf("songs of %s are : ",str);
    for(i=0 ; i < SIZE ; i++)
    {
        if(strcmp(str,s[i].genre) == 0)
            printf("\n %s",s[i]);
    }
    printf("\n");
    line(30);
}


void main()
{
    int i,ch;
    //Maintaining information of songs
    strcpy(s[0].name,"Bekhayali");
    strcpy(s[0].genre,"sad");
    strcpy(s[0].lang,"Hindi");
    strcpy(s[0].singer,"Sanchet Tandon");
    strcpy(s[0].movie,"Kabir singh");

    strcpy(s[1].name,"Spirit of Jersey");
    strcpy(s[1].genre,"inspirational");
    strcpy(s[1].lang,"Telugu");
    strcpy(s[1].singer,"Kala Bhairava");
    strcpy(s[1].movie,"Jersey");

    strcpy(s[2].name,"Adiga Adiga");
    strcpy(s[2].genre,"Romantic");
    strcpy(s[2].lang,"Telugu");
    strcpy(s[2].singer,"Sid Sriram");
    strcpy(s[2].movie,"Ninnu Kori");

    strcpy(s[3].name,"Jaamurathri");
    strcpy(s[3].genre,"90's Hits");
    strcpy(s[3].lang,"Telugu");
    strcpy(s[3].singer,"s.p.Bala subramanyam sir");
    strcpy(s[3].movie,"Kshana Kshanam");

    strcpy(s[4].name,"Pilla Raa");
    strcpy(s[4].genre,"Romantic");
    strcpy(s[4].lang,"Telugu");
    strcpy(s[4].singer,"Chaitan Bhardwaj");
    strcpy(s[4].movie,"RX 100");

    strcpy(s[5].name,"Bheemla Naayak Title song");
    strcpy(s[5].genre,"pop");
    strcpy(s[5].lang,"Telugu");
    strcpy(s[5].singer,"Thaman.s");
    strcpy(s[5].movie,"Bheemla Nayak");

    strcpy(s[6].name,"Apna Time Aayaga");
    strcpy(s[6].genre,"pop");
    strcpy(s[6].lang,"Hindi");
    strcpy(s[6].singer,"Dub sharma");
    strcpy(s[6].movie,"Gully Boy");

    strcpy(s[7].name,"Mein Tera Boy Friend");
    strcpy(s[7].genre,"Hit song");
    strcpy(s[7].lang,"Hindi");
    strcpy(s[7].singer,"RAABTA");
    strcpy(s[7].movie,"Pritan,Arjit singh");

    strcpy(s[8].name,"Kadhal Psycho");
    strcpy(s[8].genre,"pop");
    strcpy(s[8].lang,"Tamil");
    strcpy(s[8].singer,"Anirudh Ravichandar");
    strcpy(s[8].movie,"Saaho");

    strcpy(s[9].name,"Ennai Vuttu");
    strcpy(s[9].genre,"party");
    strcpy(s[9].lang,"Tamil");
    strcpy(s[9].singer,"Ranjith govind");
    strcpy(s[9].movie,"Kanulu Kanulanu Dochayantay");

    strcpy(s[10].name,"Neeyum Naamum Anbe");
    strcpy(s[10].genre,"romantic");
    strcpy(s[10].lang,"Tamil");
    strcpy(s[10].singer,"Raghu Dixit");
    strcpy(s[10].movie,"Imaikkaa Nodigal");

    strcpy(s[11].name,"Kanna Veesi Kanna Veesi");
    strcpy(s[11].genre,"romantic");
    strcpy(s[11].lang,"Tamil");
    strcpy(s[11].singer,"Rahul Hariharan");
    strcpy(s[11].movie,"Kadhal Ondru Kanden");

    strcpy(s[12].name,"Bllood Bath");
    strcpy(s[12].genre,"party");
    strcpy(s[12].lang,"Tamil");
    strcpy(s[12].singer,"Arunraga Kamaraj");
    strcpy(s[12].movie,"Asuran");

    strcpy(s[13].name,"Yaanjai");
    strcpy(s[13].genre,"party");
    strcpy(s[13].lang,"Tamil");
    strcpy(s[13].singer,"Anirudh Ravi Chandra");
    strcpy(s[13].movie,"Vikram Vedha");

    strcpy(s[14].name,"Yaar indha saalai");
    strcpy(s[14].genre,"pop");
    strcpy(s[14].lang,"Tamil");
    strcpy(s[14].singer,"G.V.Prakash kumar");
    strcpy(s[14].movie,"Thalaiva");

    strcpy(s[15].name,"Jab tak");
    strcpy(s[15].genre,"party");
    strcpy(s[15].lang,"Hindi");
    strcpy(s[15].singer,"Armaan Malik");
    strcpy(s[15].movie,"M.S.dhoni");

    strcpy(s[16].name,"Khairiyat");
    strcpy(s[16].genre,"party");
    strcpy(s[16].lang,"Hindi");
    strcpy(s[16].singer,"arijit singh");
    strcpy(s[16].movie,"chhichhore");

    strcpy(s[17].name,"Raabta Title song");
    strcpy(s[17].genre,"pop");
    strcpy(s[17].lang,"Hindi");
    strcpy(s[17].singer,"arijit singh");
    strcpy(s[17].movie,"Raabta");

    strcpy(s[18].name,"Dil Bechara");
    strcpy(s[18].genre,"inspirational");
    strcpy(s[18].lang,"Hindi");
    strcpy(s[18].singer,"A.R.rahman");
    strcpy(s[18].movie,"Dil Bachara");

    strcpy(s[19].name,"Love Is A Waste Of Time");
    strcpy(s[19].genre,"Hit song");
    strcpy(s[19].lang,"Hindi");
    strcpy(s[19].singer,"Shreya Ghoshal");
    strcpy(s[19].movie,"p.k");
    while(1)
    {
    printf("\n 1. play a song \n 2. display history\n 3.delete a song from history \n 4. Delete History\n 5. Favourites \n"
           " 6. displaying favourites\n 7. sort by language \n 8. display_details \n 9. sort by Genre\n 10.exit ");
    printf("\n\n\tChoose an option->");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        display_songs();
        printf("\n\n\tChoose a song -> ");
        scanf("%d",&song_op);
        if(song_op > 0 && song_op <=SIZE)
        {
            printf("\n\tPlaying song %s...\n",s[song_op-1].name);
            history(song_op - 1);
        }
        else
            printf("\n\n\tThe option is invalid\n");
        break;
    case 2:
        display_history();
        break;
    case 3:
         if(head_his==NULL)
         {
            line(30);
            printf("\n\tNo history");
            printf("\n\n");
            line(30);
         }
         else
         {
            display_history();
            printf("\n Choose a song to delete from history :");
            scanf("%d",&song_op);
            if(song_op > 0 && song_op <=size_his())
            {
                del_in_his(song_op);
            }
            else
            {
            printf("\n\t The option is invalid..  ");
            }
         }
         break;
    case 4:
        Delete_history();
        break;
    case 5:
         printf("\n 1.Add to Favourites \
                \n 2.Delete a song from Favourites \
                \n 3.delete favourites");
        printf("\n\n\tchoose an option : ");
        scanf("%d",&fav_op);
        if(fav_op == 1)
        {
            display_songs();
            printf("\n\n\tchoose a song to add to favourites: ");
            scanf("%d",&song_op);
            if(song_op > 0 && song_op <=SIZE)
            {
                printf("\n\tsong %s is added to favourites\n",s[song_op-1].name);
                add_to_fav(song_op-1);
          }
            else
            {
                printf("\n\tThe option is invalid.. \n");
            }
        }
        else if(fav_op == 2)
        {
            if(head_fav != NULL)
            {
                display_fav();
                printf("\n\n\tChoose  a song to delete from favourites : ");
                scanf("%d",&song_op);
                if(song_op > 0 && song_op <= size_fav())
                {
                    del_in_fav(song_op);
                }
                else
                {
                    printf("\n\tThe option is invalid..\n");
                }
            }
            else
            {
                printf("\n\tThere are not songs in the favourites\n");
            }
        }
        else if(fav_op == 3)
        {
            head_fav = NULL;
            printf("\n\tNo favourites\n");
        }
        break;
    case 6:
        display_fav();
        break;
    case 7:
        printf("\n 1.Telugu \n 2. Tamil \n 3.Hindi");
        printf("\n Choose your language : ");
        scanf("%d",&lang_op);
        if(lang_op == 1)
        {
            strcpy(lang_ch,"Telugu");
        }
        else if(lang_op == 2)
            strcpy(lang_ch, "Tamil");
        else if(lang_op == 3)
            strcpy(lang_ch,"Hindi");
        sort_by_lang(lang_ch);
        break;
    case 8:
        display_songs();
        printf("\n Choose a song to display the details of the song : ");
        scanf("%d",&song_op);
        display_details(song_op-1);
        break;
    case 9 :
        printf("\n 1.Sad \n 2.Inspirational \n 3. Romantic \n 4. 90's Hits \n 5. pop \n 6.Hit song \n 7. Party");
        printf("\n choose the genre of a song : ");
        scanf("%d",&genre_op);
        if(genre_op == 1)
            strcpy(lang_ch,"sad");
        else if(genre_op == 2)
            strcpy(lang_ch,"inspirational");
        else if(genre_op == 3)
            strcpy(lang_ch,"Romantic");
        else if(genre_op == 4)
            strcpy(lang_ch,"90's Hits");
        else if(genre_op == 5)
            strcpy(lang_ch,"pop");
        else if(genre_op == 6)
            strcpy(lang_ch,"Hit song");
       else if(genre_op == 7)
            strcpy(lang_ch,"party");
        else
            printf("\n Enter a valid option ..");
         sort_by_genre(lang_ch);
        break;
    case 10:
        exit(1);
        break;
    }
    }
    getch();
}

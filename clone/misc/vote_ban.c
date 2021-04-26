// ����ϵͳ ���ݰ�
// Written by Sunyc@kync 2001��8��30��
// All Copyrights.

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
/*�����µĶ���*/
int add_vote(string me_name,string time,string subject,mapping choice);
/*������*/
void check();
/*�г�����*/
int do_list(int z);
/*����ͶƱ*/
int add_vote_piao(int i,string choice,string id);
/*��Ҫ����*/
mapping vote_ban,vote_ban_choice;
/*�����ӿ�*/
mixed query_data() { 
    if (!restore() || undefinedp(vote_ban[0]))
        return 0;
    else return vote_ban; 
}
mixed query_choice() { 
    if (!restore() || undefinedp(vote_ban_choice[0]))
        return 0;
    else return vote_ban_choice; 
}

void create()
{
    set_name("�� ���� �����ͶƱϵͳ", ({"SZ-vote-sys"}) );
    seteuid(getuid());
    restore();
    check();
}

string query_save_file()
{
    return DATA_DIR + "vote";
}

int add_vote(string me_name,string time,string subject,mapping choice)
{
    mapping list;
    int i;
    //��ʼ������ʽ
    list=([
      "id":me_name,
      "time":time,
      "subject":subject,
      "choice":choice,
    ]);
    if( !mapp(vote_ban)) vote_ban=([]);
    if( !mapp(vote_ban_choice)) vote_ban_choice=([]);
    vote_ban+=([sizeof(vote_ban):list,]);
    list=([]);
    for (i=0;i<sizeof(keys((mapping)choice));i++)
        list+=([keys((mapping)choice)[i]:0,]);
    list+=(["id":({"a"})]);
    vote_ban_choice+=([sizeof(vote_ban_choice):list,]);
    check();
    return 1;
}

int do_list(int z)
{
    string *letters=({"!","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"});
    int i,t;
    mapping list;
    //  if (vote_ban=({})) return 0;
    if(z==-1)
    {
        /*�����д�����*/
	printf("                                          %s\n",HIG" Ŀǰ�������������� "NOR);
	printf("%s\n","--------------------------------------------------------------------------------------------------------");
        printf("%-4s|%-40s| %-24s | %s\n",CYN"���"NOR,"             �ύ��","        �ύʱ��","        ������Ŀ");
        printf("%s\n","--------------------------------------------------------------------------------------------------------");
        for(i=1; i<sizeof(vote_ban)+1; i++)
        {
            if (vote_ban[i-1]=="") continue;
            list=vote_ban[i-1];
            printf(" %2s |%-40s| %-24s | %s\n",chinese_number(i),list["id"],list["time"],YEL+list["subject"]+NOR);
            printf("%s\n","--------------------------------------------------------------------------------------------------------");
        }
            printf("%s\n","�����֪����ϸ��������"+HIG+"vote <���>"+NOR+"�鿴��");
        return 1;
    }
    else 
    {
        list=vote_ban[z];
        if (vote_ban_choice[z]=="") return 0;
        printf("%s%d\n%s\n%s\n%s\n",CYN"��ţ�"NOR,i+1,WHT"�ύ�ߣ�"NOR+list["id"],CYN"�ύʱ�䣺"NOR+list["time"],WHT"������Ŀ��"+YEL+list["subject"]+NOR);
        printf("%s\n","ѡ�");
        for (i=1;i<sizeof(keys((mapping)list["choice"]))+1;i++)
            printf("%-4s:%-50s %10sƱ\n",letters[i],list["choice"][letters[i]],chinese_number(vote_ban_choice[z][letters[i]]));
        return 1;
    }
}
int add_vote_piao(int i,string choice,string id)
{
    mixed list;
    list=vote_ban_choice[i-1];
    list[choice]=list[choice]+1;
    list["id"]+=({id});
    vote_ban_choice[i-1]=list;
    check();
    return 1;
}
int del(int i)
{
    vote_ban[i]+=(["name":"none"]);
    check();
    return 1;
}
void check_data()
{
    int i;
    string *vote_ban1=values((mapping)vote_ban),*vote_ban2=values((mapping)vote_ban_choice);
    vote_ban=([]);
    vote_ban_choice=([]);
    for(i=0;i<sizeof(vote_ban1);i++)
        vote_ban+=([i:vote_ban1[i]]);
for(i=0;i<sizeof(vote_ban2);i++)
    vote_ban_choice+=([i:vote_ban2[i]]);
save();
}
void check()
{
    int t,i;
    mixed list;
    if(vote_ban && vote_ban_choice)
        check_data();
    restore();
    for (i=0;i<sizeof(vote_ban);i++)
    {
        list=vote_ban[i];
        if (vote_ban[i]=="") continue;
        if ((string)list["name"]=="none")
        {               
            message("channel:chat",HIG+"��������"+"��"+(i+1)+"�Ŷ������������\n"NOR,users());
            map_delete(vote_ban,i);
            map_delete(vote_ban_choice,i);
            check();
            continue;
        }
    }
}
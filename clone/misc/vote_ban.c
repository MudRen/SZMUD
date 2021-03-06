// 动议系统 数据板
// Written by Sunyc@kync 2001年8月30日
// All Copyrights.

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
/*增加新的动议*/
int add_vote(string me_name,string time,string subject,mapping choice);
/*动议检查*/
void check();
/*列出动议*/
int do_list(int z);
/*向动议投票*/
int add_vote_piao(int i,string choice,string id);
/*主要变量*/
mapping vote_ban,vote_ban_choice;
/*交互接口*/
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
    set_name("【 神州 】玩家投票系统", ({"SZ-vote-sys"}) );
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
    //初始变量格式
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
        /*对齐有待改正*/
	printf("                                          %s\n",HIG" 目前神州有以下提议 "NOR);
	printf("%s\n","--------------------------------------------------------------------------------------------------------");
        printf("%-4s|%-40s| %-24s | %s\n",CYN"序号"NOR,"             提交者","        提交时间","        动议题目");
        printf("%s\n","--------------------------------------------------------------------------------------------------------");
        for(i=1; i<sizeof(vote_ban)+1; i++)
        {
            if (vote_ban[i-1]=="") continue;
            list=vote_ban[i-1];
            printf(" %2s |%-40s| %-24s | %s\n",chinese_number(i),list["id"],list["time"],YEL+list["subject"]+NOR);
            printf("%s\n","--------------------------------------------------------------------------------------------------------");
        }
            printf("%s\n","如果想知道详细内容请用"+HIG+"vote <编号>"+NOR+"查看。");
        return 1;
    }
    else 
    {
        list=vote_ban[z];
        if (vote_ban_choice[z]=="") return 0;
        printf("%s%d\n%s\n%s\n%s\n",CYN"序号："NOR,i+1,WHT"提交者："NOR+list["id"],CYN"提交时间："NOR+list["time"],WHT"动议题目："+YEL+list["subject"]+NOR);
        printf("%s\n","选项：");
        for (i=1;i<sizeof(keys((mapping)list["choice"]))+1;i++)
            printf("%-4s:%-50s %10s票\n",letters[i],list["choice"][letters[i]],chinese_number(vote_ban_choice[z][letters[i]]));
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
            message("channel:chat",HIG+"【表决】"+"第"+(i+1)+"号动议表决结束。\n"NOR,users());
            map_delete(vote_ban,i);
            map_delete(vote_ban_choice,i);
            check();
            continue;
        }
    }
}

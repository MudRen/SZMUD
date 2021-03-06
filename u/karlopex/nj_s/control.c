// control.c
// CODE BY SCATTER
#include <ansi.h>
inherit ROOM;

string vermsg="\n\n(V 5.7 正式版)\n";
//****** GLOBAL VAR ********
void get_player();
void detect_menpai(object me, string strName, string strId, string strFName, int intExp);
void create_path(object me, string strName, string strId, string strFName, int intExp, string strMenpai, string strMsg, string strDir, string strCPlace);
void create_msg(object me, object room, string strMsg, string strDir, object npc, string strCPlace);
void final_count();
void do_set_skill(object me, object room, string strMsg, string strDir, string strCPlace, string roomx);
int do_check_user(object ob, string strMenpai);
private int copy_skill(object npc, object me);
//**************************



//**** MENPAI KILLER JOB ***
void menpai_killer(object me, string strName, string strId, string strFName, int intExp);
//**************************


//**** MENPAI QUESTION JOB ***
void menpai_question(object me, string strName, string strId, string strFName, int intExp);
//****************************

//*** INCLUDE FUNCTION ***
#include "get_user.h"
#include "menpai_question.h"
#include "menpai_killer.h"
#include "menpai_job.h"
//************************

void create()
{
        set("short", HIY"门派工作控制室"NOR);
        set("channel_id", "主动工作系统(AAJ)");
        set("long", "功能如下\n启动 (start_job)\n关闭 (stop_job)\n启动一次工作 (give_job)\n设定发放时间 (set_time <时间>)\n\n");
		set_temp("menpai_count", 0);

		set("exits", ([
        "out" : "/d/wizard/meeting_room"]));
		seteuid(getuid());
        set("no_refresh",1);
        setup();
}

void init()
{
        add_action("start_job", "start_job");
        add_action("stop_job", "stop_job");
        add_action("give_job", "give_job");
        add_action("do_set_time", "set_time");
}

int do_set_time(string arg)
{
        if(!arg)
        {
                write("格式错误\n");
                return 1;
        }

        set("looptime", arg);
        write(sprintf("发放工作时间设定改为 %s 秒。\n", arg));
        return 1;
}



int stop_job(string arg)
{
        if(!query_temp("job_enable"))
        {
                write("工作系统以本来就是关闭的\n");
                return 1;
        }
        write(sprintf("自动分发工作系统关闭。\n"));
        delete_temp("job_enable");
        return 1;
}

int start_job(string arg)
{
        if(query_temp("job_enable"))
        {
                write("工作系统已启动\n");
                return 1;
        }

        write(sprintf("自动分发工作系统启动。\n"));
        set_temp("job_enable", 1);
        get_player();
        return 1;
}


void final_count()
{
        string ctime;
        int looptime;
        
        if(query("looptime"))
        {
                ctime = query("looptime");
                looptime = atoi(ctime);
        }
        
        else
        {
                looptime = 60;
        }


        remove_call_out("do_reset");
        call_out("get_player", looptime);
        return;
}
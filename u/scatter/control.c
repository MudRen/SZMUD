// control.c
// CODE BY SCATTER
#include <ansi.h>
#define SAVE_NPC "/family_job/savenpc"
inherit ROOM;

object *plist;
int k;
string vermsg="\n\n(NEW_FAMILY_JOB V 2.0A 测试版)\n";
//****** GLOBAL VAR ********
void get_player();
void detect_menpai(object me, string strName, string strId, string strFName, int intExp);
void create_path(object me, string strName, string strId, string strFName, int intExp, string strMenpai, string strMsg, string strDir, string strCPlace);
void create_msg(object me, object room, string strMsg, string strDir, object npc, string strCPlace);
void final_count();
void do_set_skill(object me, object room, string strMsg, string strDir, string strCPlace, string roomx);
//***** MULTI-PLAYER JOB *****
void mplayer_get_user();
void do_mp_setup();
void do_mp_npc_setup(int totalexp, int expavg);
//****************************
int do_check_user(object ob, string strMenpai);
int do_mp_check_user(object ob, string strMenpai);
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
#include "mplayer_select.h"
#include "mplayer_setup.h"
//************************

void create()
{
		seteuid(getuid());
        set("short", HIY"门派工作控制室"NOR);
        set("channel_id", "主动工作系统(AAJ)");
        set("long", "功能如下\n启动 (start_job)\n关闭 (stop_job)\n启动一次工作 (give_job)\n设定发放时间 (set_time <时间>)\n检查目前的时间设定(ctime)\n检查所有门派的贡献度(chkall)\n\n");
		set_temp("menpai_count", 0);

		set("exits", ([
			"out" : "/d/wizard/ccenter"]));
		
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
		add_action("do_ctime", "ctime");
		add_action("do_chkall", "chkall");
		add_action("temp_start", "temp_start");
}

int temp_start()
{
	mplayer_get_user();
	CHANNEL_D->do_channel(this_object(), "rumor", HIC+"多人攻城模式启动 Family_Job V9.0 (测试版)"+NOR+"\n");
}

int do_chkall()
{
	string fname, ropen;
	int fropen;
	

	fname = "family_job/wd";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("武当 : " + fropen + "\n");

	fname = "family_job/sl";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("少林 : " + fropen + "\n");

	fname = "family_job/gb";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("丐帮 : " + fropen + "\n");

	fname = "family_job/xx";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("星宿 : " + fropen + "\n");

	fname = "family_job/em";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("峨嵋 : " + fropen + "\n");

	fname = "family_job/dl";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("大理 : " + fropen + "\n");

	fname = "family_job/gm";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("古墓 : " + fropen + "\n");

	fname = "family_job/bt";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("白驼 : " + fropen + "\n");

	fname = "family_job/hs";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("华山 : " + fropen + "\n");

	fname = "family_job/xs";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("雪山 : " + fropen + "\n");

	fname = "family_job/th";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("桃花 : " + fropen + "\n");

	fname = "family_job/qz";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("全真 : " + fropen + "\n");

	fname = "family_job/kl";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("昆仑 : " + fropen + "\n");

}

int do_ctime(string arg)
{
	write("目前设定的时间为 " + query("looptime") + " 秒\n");
	return 1;
}

int do_set_time(string arg)
{
        if(!arg)
        {
                write("格式错误\n");
                return 1;
        }

        set("looptime", arg);
		switch(random(5))
		{
		case 0:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"天地间突然晃动了一下，瞬间流星从东方的空中划了过去。"));
				break;
			}
		case 1:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIB"突然间西边的上空出现了一道闪电，顿时间感到一切生命是如此得脆弱。"));
				break;
			}
		case 2:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIG"天地间突然晃动了一下，突然间大地生机从现。"));
				break;
			}
		case 3:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"天地间突然晃动了一下，瞬间流星从东方的空中划了过去。"));
				break;
			}
		case 4:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIB"突然间西边的上空出现了一道闪电，顿时间感到一切生命是如此得脆弱。"));
				break;
			}
		case 5:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIG"天地间突然晃动了一下，突然间大地生机从现。"));
				break;
			}
		}
        

        CHANNEL_D->do_channel(this_object(), "sys", sprintf("发放工作时间设定改为 %s 秒。", arg));
        return 1;
}



int stop_job(string arg)
{
        if(!query("job_enable"))
        {
                write("工作系统以本来就是关闭的\n");
                return 1;
        }
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("自动分发工作系统关闭。"));
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"天空中的彩虹慢慢的消失，看来这其中藏有玄机。"));
        delete("job_enable");
        return 1;
}

int start_job(string arg)
{
        if(query("job_enable"))
        {
                write("工作系统以启动\n");
                return 1;
        }

        CHANNEL_D->do_channel(this_object(), "sys", sprintf("自动分发工作系统启动。"));
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"突然天地间有一股说不说来的压力，天空上慢慢的出现了一到彩虹，看来这其中藏有玄机。"));
        set("job_enable", 1);
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
                looptime = 250;
        }


        remove_call_out("do_reset");
        call_out("get_player", looptime);
        return;
}

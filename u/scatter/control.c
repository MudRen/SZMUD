// control.c
// CODE BY SCATTER
#include <ansi.h>
#define SAVE_NPC "/family_job/savenpc"
inherit ROOM;

object *plist;
int k;
string vermsg="\n\n(NEW_FAMILY_JOB V 2.0A ���԰�)\n";
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
        set("short", HIY"���ɹ���������"NOR);
        set("channel_id", "��������ϵͳ(AAJ)");
        set("long", "��������\n���� (start_job)\n�ر� (stop_job)\n����һ�ι��� (give_job)\n�趨����ʱ�� (set_time <ʱ��>)\n���Ŀǰ��ʱ���趨(ctime)\n����������ɵĹ��׶�(chkall)\n\n");
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
	CHANNEL_D->do_channel(this_object(), "rumor", HIC+"���˹���ģʽ���� Family_Job V9.0 (���԰�)"+NOR+"\n");
}

int do_chkall()
{
	string fname, ropen;
	int fropen;
	

	fname = "family_job/wd";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("�䵱 : " + fropen + "\n");

	fname = "family_job/sl";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("���� : " + fropen + "\n");

	fname = "family_job/gb";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("ؤ�� : " + fropen + "\n");

	fname = "family_job/xx";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("���� : " + fropen + "\n");

	fname = "family_job/em";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("���� : " + fropen + "\n");

	fname = "family_job/dl";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("���� : " + fropen + "\n");

	fname = "family_job/gm";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("��Ĺ : " + fropen + "\n");

	fname = "family_job/bt";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("���� : " + fropen + "\n");

	fname = "family_job/hs";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("��ɽ : " + fropen + "\n");

	fname = "family_job/xs";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("ѩɽ : " + fropen + "\n");

	fname = "family_job/th";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("�һ� : " + fropen + "\n");

	fname = "family_job/qz";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("ȫ�� : " + fropen + "\n");

	fname = "family_job/kl";
	ropen = SAVE_NPC->do_load(fname);
	fropen = atoi(ropen);
	write("���� : " + fropen + "\n");

}

int do_ctime(string arg)
{
	write("Ŀǰ�趨��ʱ��Ϊ " + query("looptime") + " ��\n");
	return 1;
}

int do_set_time(string arg)
{
        if(!arg)
        {
                write("��ʽ����\n");
                return 1;
        }

        set("looptime", arg);
		switch(random(5))
		{
		case 0:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"��ؼ�ͻȻ�ζ���һ�£�˲�����ǴӶ����Ŀ��л��˹�ȥ��"));
				break;
			}
		case 1:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIB"ͻȻ�����ߵ��Ͽճ�����һ�����磬��ʱ��е�һ����������˵ô�����"));
				break;
			}
		case 2:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIG"��ؼ�ͻȻ�ζ���һ�£�ͻȻ�����������֡�"));
				break;
			}
		case 3:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"��ؼ�ͻȻ�ζ���һ�£�˲�����ǴӶ����Ŀ��л��˹�ȥ��"));
				break;
			}
		case 4:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIB"ͻȻ�����ߵ��Ͽճ�����һ�����磬��ʱ��е�һ����������˵ô�����"));
				break;
			}
		case 5:
			{
				CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIG"��ؼ�ͻȻ�ζ���һ�£�ͻȻ�����������֡�"));
				break;
			}
		}
        

        CHANNEL_D->do_channel(this_object(), "sys", sprintf("���Ź���ʱ���趨��Ϊ %s �롣", arg));
        return 1;
}



int stop_job(string arg)
{
        if(!query("job_enable"))
        {
                write("����ϵͳ�Ա������ǹرյ�\n");
                return 1;
        }
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("�Զ��ַ�����ϵͳ�رա�"));
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"����еĲʺ���������ʧ�����������в���������"));
        delete("job_enable");
        return 1;
}

int start_job(string arg)
{
        if(query("job_enable"))
        {
                write("����ϵͳ������\n");
                return 1;
        }

        CHANNEL_D->do_channel(this_object(), "sys", sprintf("�Զ��ַ�����ϵͳ������"));
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"ͻȻ��ؼ���һ��˵��˵����ѹ��������������ĳ�����һ���ʺ磬���������в���������"));
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
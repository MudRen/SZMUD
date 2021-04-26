// control.c
// CODE BY SCATTER
#include <ansi.h>
inherit ROOM;

string vermsg="\n\n(V 5.7 ��ʽ��)\n";
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
        set("short", HIY"���ɹ���������"NOR);
        set("channel_id", "��������ϵͳ(AAJ)");
        set("long", "��������\n���� (start_job)\n�ر� (stop_job)\n����һ�ι��� (give_job)\n�趨����ʱ�� (set_time <ʱ��>)\n\n");
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
                write("��ʽ����\n");
                return 1;
        }

        set("looptime", arg);
        write(sprintf("���Ź���ʱ���趨��Ϊ %s �롣\n", arg));
        return 1;
}



int stop_job(string arg)
{
        if(!query_temp("job_enable"))
        {
                write("����ϵͳ�Ա������ǹرյ�\n");
                return 1;
        }
        write(sprintf("�Զ��ַ�����ϵͳ�رա�\n"));
        delete_temp("job_enable");
        return 1;
}

int start_job(string arg)
{
        if(query_temp("job_enable"))
        {
                write("����ϵͳ������\n");
                return 1;
        }

        write(sprintf("�Զ��ַ�����ϵͳ������\n"));
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
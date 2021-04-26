// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����Ǵ����µ�ɽ�ţ���ǰ�����ﲻ���Ľ��㳯ʥ����ͽ���е�������
����˿�����ϵĲ�˿��ɽ��(gate)ǰվ�˼����ֳַ����ĸ��ײ���ά������
������һ����ʯ���̳ɵ�ɽ·��
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"dshanlu",
                "north" : __DIR__"guangchang",
        ]));
        set("item_desc", ([
                "gate" : "���Ⱥ���ͭɫ���ţ��Ǻ�����֮�����������ƶ��ġ�\n"
        ]));
	set("objects", ([
                __DIR__"npc/gelun1" : 2,
		__DIR__"npc/xiangke" : 1,
        ]));
        set("outdoors","qilian-shan");
	set("no_clean_up", 1);
	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

   if (dir =="north" ) {
	this_player()->delete_temp("mark/comin");

        if (present("ge lunbu", environment(me))) {
            if (!myfam || myfam["family_name"] != "ѩɽ��"
	    && myfam["family_name"] != "Ѫ����" 
	    && !present("suyou guan", this_player()))
            if (!this_player()->query_temp("marks/��"))		
                return notify_fail("���ײ���ס��˵����׼����ʲ�ṩ�����Ƿ�үѽ��\n");
	else this_player()->set_temp("marks/��", 0);
        }
        
        return 1;
   }
   return ::valid_leave(me, dir);
}
static string current_id = "";
static int current_job = 0;

int introduce_robber(object current_player);
int reset_to_normal();

void init() {
    object challenger, me = this_player();

    if ( (me->query("family/family_name") == "ѩɽ��" ||
          me->query("family/family_name") == "Ѫ����")
         && (me->query("combat_exp") < 100000) ) {
        call_out("introduce_robber", random(10)+10, me);
        current_job = 1;
    }
}

int introduce_robber(object current_player)
{
    object robber;

    if ( objectp(present(current_player->query("id"), this_object())) )
    {
        robber = new(__DIR__"npc/robber2");
        robber->setup_robber(current_player->query("combat_exp"));
        robber->move(this_object());
        message_vision(HIC"һ��$N����ææ���˹�����\n"NOR, robber);
        message_vision(HIR"$N˵������˵��������������б����������������ӽ�ȥ������\n" NOR, robber, current_player);
        robber->start_checking(current_player);
    }
    else
    {
        reset_to_normal();
    }
}

int reset_to_normal()
{

   current_job = 0;
   return 1;
}

// Code of ShenZhou
// /d/xueshan/dumudian.c
// Summer 9/25/96
#include <ansi.h>
#include "room.h"

inherit ROOM;

nosave string current_id = "";
nosave int current_job = 0;

int introduce_robber(object current_player);
int reset_to_normal();

void create()
{
        set("short", "��ĸ��");
        set("long", @LONG
�����Ǵ����µĶ�ĸ�������������𣬾�Ϊ�����١�����
̻�����ġ�����������ִ��ӡ���������졣���ڶԳ������ĸ�������
�ϵ��̶��ƣ��¿������ơ������Ϲ�������������ͷ��������
ħ������
LONG
        );
        set("exits", ([
				"north" : __DIR__"changlang",
                "southdown" : __DIR__"yanwu",
        ]));
	set("objects", ([
		__DIR__"npc/zrlama": 1,
		__DIR__"obj/tonggang": 1,
	]));

	set("cost", 1);
    setup();
}

void reset()
{
	::reset();
	set("no_clean_up", 1);
}

void init() {
    object challenger, me = this_player();

//    printf("blah blah blah\n");
    if ( (me->query("family/family_name") == "ѩɽ��" ||
          me->query("family/family_name") == "Ѫ����")
         && !(current_job)
         && (me->query("combat_exp") > 2000000) ) {
//        printf("hehehe\n");
        call_out("introduce_robber", random(10)+10, me);
        current_job = 1;
    }
//    printf("current_job = %d\n",current_job);
}

int introduce_robber(object current_player)
{
    object robber;

//    printf("name = %s\n", current_player->query("id"));
    if ( objectp(present(current_player->query("id"), this_object())) )
    {
//        printf("test1\n");
        robber = new(__DIR__"npc/robber");
//        printf("test2\n");
        robber->setup_robber(current_player->query("combat_exp"));
        robber->move(this_object());
//        printf("test3\n");
//        message("vision", "һ��"+robber->name(1)+"����ææ���˹�����\n", this_object(), robber);
        message_vision(HIC"һ��$N����ææ���˹�����\n"NOR, robber);
        message_vision(HIR"$N˵������˵���ͭ������������õ����ͣ����ӽ����ص���������ʶ��ĸϿ���ҹ�����\n" NOR, robber, current_player);
        robber->start_checking(current_player);
//        printf("test4\n");
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

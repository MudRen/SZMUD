// Code of ShenZhou
// baoguo1.c �����´��۵�
// Shan: 96/06/22

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "���۵�");
        set("long", @LONG
�����Ǳ����´��۵�������Ƕ���ɽ�����Ժ֮һ�����۵��ڹ��Ž��
�Ӳӵķ�������������
LONG
        );
        set("exits", ([
                "out" : __DIR__"baoguo",
		"west": __DIR__"baoguo3",
		"north" : __DIR__"baoguo2",
        ]));

        set("objects", ([
                __DIR__"npc/xiang-ke.c": 2,
        ]));

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("family/family_name") != "������" && dir == "west" )
		return notify_fail("����������ֻ�Ӵ����ҵ��ӣ���Ҫ�ǳ�������ڴ˶����ע��ɡ�\n");

	if ( me->query("gender") == "Ů��" && dir == "west" )
		return notify_fail("��λ" + RANK_D->query_respect(me) +
				"�����������е�����Ϣ����������һŮ�Ӳ�̫����ɣ���\n");

	return ::valid_leave(me, dir);
}
nosave string current_id = "";
nosave int current_job = 0;

int introduce_robber(object current_player);
int reset_to_normal();

void init() {
    object challenger, me = this_player();

    if ( (me->query("family/family_name") == "ѩɽ��" ||
          me->query("family/family_name") == "Ѫ����")
         && (me->query("combat_exp") > 100000) ) {
        call_out("introduce_robber", random(10)+10, me);
        current_job = 1;
    }
}

int introduce_robber(object current_player)
{
    object robber;

    if ( objectp(present(current_player->query("id"), this_object())) )
    {
        robber = new(__DIR__"npc/robber");
        robber->setup_robber(current_player->query("combat_exp"));
        robber->move(this_object());
        message_vision(HIC"һ��$N����ææ���˹�����\n"NOR, robber);
        message_vision(HIR"$N˵����ѩɽ��ͺ¿������ɫ֮��������߿������������ʦ̫���ޣ�\n" NOR, robber, current_player);
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

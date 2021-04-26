// Code of ShenZhou
// dao96.c ��ʮ�ŵ���
// Shan: 96/06/22

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʮ�ŵ���");
	set("long", @LONG
���������ġ���ʮ�ŵ��ա�����·����������ǧ�۰ٻء���˵��ȥ���и�
������ķ�ɮ���ˣ���һ������·�������������������ǵ�֪�˴��о�����û
�󣬱���Ҳ���˸�������Ĳ�ľ�����ԡ����ӡ���֮���ɴ˶�����ǧ���֣���
����϶���
LONG
	);
	set("exits", ([
		"eastdown" : __DIR__"dao97",
		"southwest" : __DIR__"jiulao1",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 4);
	setup();
//	replace_program(ROOM);

}

private void move_to_tree(object me)
{
	if (!me) return;
        message_vision( HIR"��Ȼһ���ȷ�Ϯ����һ�����������Դ��������£���$N�����ˡ�\n"NOR,
                                me);
        me->move("/d/emei/treeup");
	me->start_busy(1);
}

void init()
{
        object me = this_player();
        if ( !find_object("/d/emei/treeup") )
		call_other("/d/emei/treeup", "???");
	if ( objectp(present("ju mang", find_object("/d/emei/treeup"))) 
           && random((int)me->query_kar() + (int)me->query_per()) < 5 ) {
		me->start_busy(1);
		call_out("move_to_tree", 1, me);
        }
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

	if ( me->query_skill("dodge", 1) > 100 )
		return ::valid_leave(me, dir);

        current_jingli = me->query("jingli");
        if (dir == "southwest" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(10));
                me->improve_skill("dodge", random(10));
                write("���ؾ�ʮ�ŵ�������������һ�󣬾��ú��ۡ�\n");
        }

        else if (dir == "southwest" && current_jingli <= 5)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

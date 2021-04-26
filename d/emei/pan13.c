// Code of ShenZhou
// pan13.c ʮ����
// Shan: 96/06/22

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "ʮ����");
        set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡������·���и������أ�����������
���л���(clap)���ɴ����Ͽɴﻪ�϶��������������֡�
LONG
        );
        set("exits", ([
		"southwest" : __DIR__"pan12",
                "eastdown" : __DIR__"pan14",
        ]));

	set("outdoors", "emei");

	set("cost", 4);
        setup();
}

void init()
{
    add_action("do_clap", "clap");
}

int do_clap(string arg)
{
    object me = this_player();

	if (me->query("jing") < 30)
                return notify_fail("���Ѿ�û�о���������Ү��\n");

    message_vision(
"���ں�Ȼ���ܴ���һ��������Ⱥ�ܴε���ϣ��������һ�ܴ�����Ⱥ�ܱ��Ȼ
��ֹ����������Ϊ�ˡ�\n", this_player());

    if (me->query_skill("strike", 1) < 30) {
	me->receive_damage("jing", 25, "ʧ�����������������");
	me->improve_skill("strike", me->query_str());
	tell_object(me, HIY"��Ļ����Ʒ������ˡ�\n"NOR);
    }
    return 1;
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southwest" && current_jingli >10 
	&& me->query_skill("dodge", 1) < 100)
        {
                me->set("jingli",current_jingli-random(10));
                me->improve_skill("dodge", random(5));
                write("��������ʮ���̣�������ɽ��·�ֶ����䣬�����ˡ�\n");
        }

        else if (dir == "southwest" && current_jingli <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}


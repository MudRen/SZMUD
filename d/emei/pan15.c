// Code of ShenZhou
// pan15.c ʮ����
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "ʮ����");
        set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡����ɴ����Ͽɴﻪ�϶�����������
���֡�
LONG
        );
        set("exits", ([
		"southwest" : __DIR__"pan14",
                "eastdown" : __DIR__"wannian",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 4);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southwest" && current_jingli >10)
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

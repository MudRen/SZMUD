// Code of ShenZhou
// pan14.c ʮ����
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
		"westup" : __DIR__"pan13",
                "northeast" : __DIR__"pan15",
        ]));

	set("outdoors", "emei");

	set("cost", 4);
        setup();
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "westup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(10));
                me->improve_skill("dodge", random(5));
                write("��������ʮ���̣�������ɽ��·�ֶ����䣬�����ˡ�\n");
        }

        else if (dir == "westup" && current_jingli <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}


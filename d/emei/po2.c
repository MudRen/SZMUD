// Code of ShenZhou
// po2.c ������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����ʯ��ϴ���֮�䣬��·������ʯջ���ݣ�ֱ�����죬ʯ�Ŵ�һǧ����
�༶�����ڶ���ɽ���Ͽ���������µ����������ϣ�ǰ������ӣ�һ����졣
���·�С������졹����ζ���Ҳ��˶��С������¡������������¶��㵽
ϴ��أ����¿ɴ�����ʯ��
LONG
        );
        set("exits", ([
		"westup" : __DIR__"xixiang",
                "eastdown" : __DIR__"po1",
        ]));

	set("outdoors", "emei");

	set("cost", 5);
        set("fjing", 1);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "westup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(8));
                write("������������������һ�����ڵ���ϴ��أ������ˡ�\n");
        }

        else if (dir == "westup" && current_jingli <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}


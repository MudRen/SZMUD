// Code of ShenZhou
// lianhua.c ����ʯ
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "����ʯ");
        set("long", @LONG
��������ʯ���˴���ʯ�����ݺᣬ��������������ܽ�أ��·��������
ϸ������������һ�֣��С������硹���ɴ�������ֱ��ϴ��أ�������ͨ����
������ͨ���϶���
LONG
        );
        set("exits", ([
		"westup" : __DIR__"po1",
                "southeast" : __DIR__"jiulao1",
                "eastdown" : __DIR__"huayanding",
        ]));

        set("objects", ([
                "/kungfu/class/emei/zhao.c" :1,
                "/kungfu/class/emei/su.c" :1,
        ]));

	set("outdoors", "emei");

	set("cost", 2);
        setup();
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "westup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(8));
                write("������������������һ�󣬺����ˡ�\n");
        }

        else if (dir == "westup" && current_jingli <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}


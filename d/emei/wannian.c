// Code of ShenZhou
// wannian.c ������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����ֽ���һ��ͻ���ɽ���ϣ���Χ��ľɭɭ����Ȫ���ȣ��в��޿�����
���޿�����ɫ�ǳ����ˡ��ɴ����Ϲ�ʮ���̿ɴﻪ�϶�����������������
LONG
	);
	set("exits", ([
		"westup" : __DIR__"pan15",
		"southdown" : __DIR__"bailong",
		"enter" : __DIR__"wannian1",
	]));

        set("outdoors", "emei" );

	set("cost", 1);
        set("fjing", 1);
	setup();
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "westup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(10));
                me->improve_skill("dodge", random(6));
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


// Code of ShenZhou
// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ϴ�������ϱ���ͷ���졣�ϱ����ϳ��ţ�����ͨ�������ġ�������
һ�ҹ˿��ڶ�ľƹݣ����̾�����ʿ��������̸��˵�ء�����һ�������¥����
��������Ц���Ǿ�����������������Ժ������������ϱ������н����ֵ�һ����
���������ھƹݺ�����Ժ�����Ե�ʰɡ�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"lichunyuan",
		"south" : __DIR__"nanmen",
		"west" : __DIR__"jiuguan",
		"north" : __DIR__"nandajie2",
	]));

        set("objects", ([
                CLASS_D("shaolin") + "/tuoboseng" : 1,
        ]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && (int)me->query("age") < 18 && !wizardp(me))
		return notify_fail("С���Ѳ�Ҫ�����ֵط�ȥ����\n");
	return 1;
}

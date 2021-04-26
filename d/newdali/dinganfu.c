// Code of ShenZhou
// Room: /d/dali/dinganfu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǵ����˾�����أ��ӹܵ���Ҫ��һЩ����֮��ľ��׺���⣬��˸���
�к��壬���壬�����壬�����壬׳���Ա��һ������ʾ���������⣬���ﻹ��
��ͨ�룬�Ա�Ѷ�ʡ���������̬���ͣ���������ǰ���嵭���������ǿ���ǽ����
�졣�ϱ��Ǵ���ͼ���Ա��ס����
LONG);
	set("objects", ([
		"kungfu/class/dali/fusigui" : 1,
		__DIR__"npc/weishi5" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"dinganfu1",
		"south" : __DIR__"dinganfu2",
		"west" : __DIR__"dalicheng1",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	if (me->query("family/family_name")!="����μ�"
		&& !me->query("dali/employee")
		&& dir == "south"
		&& living(ob=present("fu sigui", find_object(__DIR__"dinganfu.c"))))
		return notify_fail("�����ȵ��������˵ȣ������Ҵ���\n");

	return ::valid_leave(me, dir);
}

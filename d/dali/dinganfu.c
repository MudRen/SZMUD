// Code of ShenZhou
// Room: /d/newdali/dinganfu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǵ����˾�����أ��ӹܵ���Ҫ��һЩ����֮��ľ��׺���⣬
��˸����к��壬���壬�����壬�����壬׳���Ա��һ������ʾ��
�������⣬���ﻹ����ͨ�룬�Ա�Ѷ�ʡ���������̬���ͣ���������
ǰ���嵭���������ǿ���ǽ�����졣�ϱ��Ǵ���ͼ���Ա��ס����
LONG);

	set("cost", 1);
	set("exits", ([
		"north" : __DIR__"fatang",
		"west" : __DIR__"taihejie5.c",
		"south" : __DIR__"diziarea",
		]));

	set("objects", ([
		"kungfu/class/dali/fusigui" : 1,
		__DIR__"npc/weishi5" : 2,
		]));

	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	if (me->query("family/family_name")!="����μ�"
		&& !me->query("dali/employee")
		&& dir == "south"
		&& living(ob=present("fu sigui", find_object("/d/dali/dinganfu.c"))))
		return notify_fail("�����ȵ��������˵ȣ������Ҵ���\n");

	return ::valid_leave(me, dir);
}

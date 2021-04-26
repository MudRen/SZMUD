// Code of ShenZhou
// Room: /d/shaolin/guangchang4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
���Ǻ��ǰ�ľ��������㳡��ש�̵أ���Ϊ����Ĳ�̤����
͹��ƽ��ǰ��������¸�ǽ���������㳡�����м䣬�γ�һ��խ
խ�ĳ����Ρ����߿�����С�ţ�һ������������Ʈ�˹���������
�Ǹ����ţ���λɮ���ڴ˰��ء�
LONG
	);

	set("exits", ([
		"south" : __DIR__"guangchang3",
		"northup" : __DIR__"houdian",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		CLASS_D("shaolin") + "/hui-kong" : 1,
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") != "������"
	&& !me->query("luohan_winner")
	&& dir == "northup" 
	&& objectp(present("huikong zunzhe", environment(me))))
			return notify_fail("�ۿպȵ����㲻�����ֵ��ӣ����ý����\n");

	return ::valid_leave(me, dir);
}


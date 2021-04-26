// Code of ShenZhou
// Room: /d/shaolin/guangchang5.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�㳡");
	set("long", @LONG
����ǧ���ǰ��һ���㳡����������̨�׾��ǹ����������
��ǧ�������ǹ���ز��������ĵزص�����ǹ�����¹�
����ʿ�İ��µ����ÿ�궼�в�����;ۼ��ٰ�ˮ½�󷨻ᡣ
LONG
	);

	set("exits", ([
		"east" : __DIR__"bydian",
		"west" : __DIR__"dzdian",
		"south" : __DIR__"wuchang3",
		"northup" : __DIR__"qfdian",
		"southup" : __DIR__"dmyuan",
	]));

	set("outdoors", "shaolin");
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;

	if (dir == "southup")
	{
		if( mapp(fam = me->query("family")) 
		&&  fam["family_name"] == "������" 
		&&  fam["generation"] > 37  ) 
			return notify_fail("�����Ǳ��µ��ӣ� �����𲻹������ܽ����ĦԺ��\n");
		if( !me->query("luohan_winner") )
			return notify_fail("�㲻�Ǳ��µ��ӣ�δ��ͨ��ʮ���޺��󣬲��ܽ����ĦԺ��\n");
	}
	return ::valid_leave(me, dir);
}



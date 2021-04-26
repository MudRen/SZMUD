// Code of ShenZhou
// Room: /d/shaolin/qyping.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����ƺ");
	set("long", @LONG
����������Ҿ�������Ŀ��ȥ��ֻ���������ƣ���������룻
��ɽ�δ䣬�ƽ�����졣ɽ������ٲ���к���£�ʯ���������ۣ�
����һ�����棬���˷׷����ϣ��������Ρ���ǰ��ƽ���ϴ�ݲ�
�����������þ���Χ��һȦ��Ȧ�����ƺ���ʲô�������������⡣
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shulin14",
		"enter" : __DIR__"fumoquan",
	]));

/*
        set("objects", ([
                 "/d/shaolin/npc/chengkun" : 1,
        ]));
*/

	set("outdoors", "shaolin");
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "enter" ) {
		if ( me->query("combat_exp") <= 50000 ) 
			return notify_fail("ֻ����������˵��: �������գ�ʩ���书��������֮ѡ����Ҳ�����ر���δ��̫�Բ�����Щ�˰ɣ�\n");

		if ( present("fumo dao", me) || present("jingang zhao", me) 
		  || present("fumo dao", environment(me)) || present("jingang zhao", environment(me)) )
			return notify_fail("ֻ����������˵��: �����ϻ��������˴����˿���Я�ر���������룬\nˡ���ĵ�ʧ���ˡ�\n");
	}


	return ::valid_leave(me, dir);
}



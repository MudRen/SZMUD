// Code of ShenZhou
// Room: /city/zhengting.c
// YZC 1995/12/04
// modified by sdong, 12/12/98 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ����ھֵ���������ֻ̫ʦ��һ���ſ�����������������ͷ���ֳ���
�������ڱ�Ŀ��˼��ǽ�Ϲ��ż����ֻ���һ�ѱ�����
LONG
	);

	set("exits", ([
		"north" : __DIR__"biaoju",
	]));
        set("no_fight", 1);

	set("objects", ([
		"/kungfu/class/misc/linzhennan" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}


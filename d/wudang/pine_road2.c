// Code of ShenZhou
// pine_road2.c ����С��
// by Marz@XKX 11/11/96

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
	����ɽ�������е�С·�����߳�������ĺ�������ֻ�ܿ���һ����ա�
·���е�ʿ�ڷ�����(chop)�����ϱ�ͨ������������߿ɻش����
LONG
	);
	
	set("objects", ([
		CLASS_D("wudang") + "/famu" : 1,
		__DIR__"obj/pine" : 2]));
	                        	
	
	set("exits", ([
		"south" : __DIR__"pine_forest1",
		"north" : __DIR__"pine_road",
	]));
	
	set("cost", 1);
	setup();
	replace_program(ROOM);
}


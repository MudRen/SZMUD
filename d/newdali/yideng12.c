// Code of ShenZhou
// yideng quest room 12

inherit ROOM;
void create()
{
        set("short", "���ʯ��");
        set("long", @LONG
�������ʯ�������ľ����������������ı����������ڲ���֮��������
��С���ϵ���һ¯̴�㣬����һλ��ɮ�����������ϡ�
LONG);
	set("objects", ([
		"/kungfu/class/dali/yideng.c" : 1,
		]) );
	set("exits", ([
		"south" : __DIR__"yideng11",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}

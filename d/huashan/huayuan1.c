// Code of ShenZhou
// huayuan1.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ��԰�ӣ�ͥԺ���ģ����ֻ������ǲ��١��ٻ����ţ�ɽʯ��׾��
�������壬���ɴ��񣬾���ɷ�����ˡ��峺��Ϫ����������һ��Сͤ�ӣ�
����Ϫˮ��������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "south" : __DIR__"houyuan",
	    "north" : __DIR__"buwei1",
	    "west" : __DIR__"xilang",
	    "east" : __DIR__"donglang",
	    "southwest" : __DIR__"huayuan2",  
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}
//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "���� ");
	set("long",  @LONG
����һ������Ĺ㳡�������Ǿ����ڴ˲������㳡�������Ͻ���
�Ļ��Ǻӡ����߱����Ͻ��ǵ��ϴ������š�
LONG
	);


	set("exits", ([
		"north" : __DIR__"wumen",
		"south" : __DIR__"tiananmen",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}

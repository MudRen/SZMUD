//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "�Ļ���");
	set("long",  @LONG
�������򶫾Ϳ��Գ������ţ�������Э���ţ������Ǻ챾�⣬��
�����Ļ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"wenhuadian",
		"south" : __DIR__"hongbenku",
		"west"  : __DIR__"xiehemen",
		"east"  : __DIR__"donghuamen",
	]));
	set("outdoors","beijing");
	
	setup();
	replace_program(ROOM);
}
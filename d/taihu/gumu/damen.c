// Code of ShenZhou
//GU MU FROM SANTA
//DAMEN.C

inherit ROOM;

void create()
{
	set("short", "������Ĺ");
	set("long", @LONG
ǰ����һ������ɭ�ϵĴ��Ĺ�����˾��������෽��Ȼ
�д������ƣ�����Ī������ס�����棿 
LONG
	);
	 set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"qianyuan",
		"east" : __DIR__"shufang",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}



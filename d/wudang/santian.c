// Code of ShenZhou
// santian.c ������ 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǵ�ɽʯ�׵ľ�ͷ�������š����������߾����䵱�����ˡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"ertian",
                "southup" : __DIR__"jinding",
	]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}


// river.c  СϪ
//Jiuer 10-28-2001

inherit ROOM;

void create()
{
        set("short", "СϪ");
        set("long", @LONG
����һ��Ƭ���֣�������һ����ɽ�ﻺ�����ʵ�СϪ��Ϫˮ��ɽʯ��
��ݵؼ侲����������Ϫ����Ư����Щ��Ҷ�͸�׮��ǡ����Ȼ�γ���һ��
С�ţ�Խ��СϪ��������������һƬɽ�ȡ�
LONG);
        
		set("exits", ([
			"north" : __DIR__"grassland",
			"south" : __DIR__"forest2",
			"east" : __DIR__"huangshaling",
		//	"west" : "/d/jueqing/"
			]));

		set("resource/water", 1);
		set("cost", 1);
		set("outdoors", "gumu");
		setup();
		replace_program(ROOM);
}

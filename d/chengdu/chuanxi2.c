//Cracked by Roath
//Jay 10/18/96

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ��ɽ·������ɽ�䡣������ȥ�����Լ�����ѩɽ����ɫ��ѩ
�����������ԡ�
LONG
        );
        set("exits", ([
		"eastdown" : __DIR__"chuanxi1",
                "westup" : "/d/xueshan/shanlu7",
        ]));

	set("outdoors", "emei");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}


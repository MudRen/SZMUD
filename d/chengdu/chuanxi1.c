//Cracked by Roath
//Jay 10/18/96

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�������ǳ�ɽ���룬��ͨ���㡣һ��ɽ·������ɽ�䣬������
�رߺ���ԭ��
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"tulu2",
                "westup" : __DIR__"chuanxi2",
        ]));

	set("outdoors", "emei");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}


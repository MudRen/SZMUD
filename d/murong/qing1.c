// Code of ShenZhou
// Room: /d/murong/qing1
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
��������С��ǰ��һ�鳡�أ�ǰ���������������������ᣬ
������һ����֪��С�����ǰ뵺֮�ϡ�����С�����磬��
Ϊ���¡�
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "north" : __DIR__"qing2",
        "east" : __DIR__"road1",
                      ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// Room: /d/murong/road1


inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�����������С·���ö���ʯ�̳ɣ�������
�����������͸������������Կ�������ɽʯ��ľ��
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "east" : __DIR__"tingyu",
        "west" : __DIR__"qing1",
        "northeast" : __DIR__"xiaoqiao",
                      ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

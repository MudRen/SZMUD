// Code of ShenZhou
// Room: /d/murong/huac4
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
    ֻ��С·��һ������һ������֪��һ��������·��
��ǰ��ɽ�趼�Ǹղ�û�п������ġ�
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "west" : __FILE__,
        "north" : __FILE__,
        "southeast" : __DIR__"huac5",
        "east" : __DIR__"mantuo2",
        "southwest" : __FILE__,
        "south" : __FILE__,
                      ]));
	set("no_clean_up", 0);

	setup();
        replace_program(ROOM);
}


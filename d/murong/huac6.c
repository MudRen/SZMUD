// Code of ShenZhou
// Room: /d/murong/huac6
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
        "southeast" : __FILE__,
        "north" : __FILE__,
        "west" : __DIR__"huac7",
        "east" : __DIR__"mantuo2",
        "southwest" : __FILE__,
        "south" : __FILE__,
                      ]));
	set("no_clean_up", 0);

	setup();
        replace_program(ROOM);
}


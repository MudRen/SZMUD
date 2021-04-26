// Code of ShenZhou
// Room: /d/murong/lianwu
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
    ����������������䳡�����ܷ�����ʮ�˰��������˵
Ľ����ͨ�������似�����ܴ��Բ��顣
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"xiaoqiao",
        "southeast" : __DIR__"humian",
        "east" : __DIR__"lianwu1",
                      ]));

	set("no_clean_up", 0);
        set("outdoors", "murong");

        set("objects", ([
		"/d/murong/npc/menke" : 3,
		]));

	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (dir=="southwest" ) {
                if (dir=="southwest" && me->query("family/family_name")=="����Ľ��")
                        return notify_fail("�Ƕ���Ľ�ݵ�������ĵط�,û����ȥΪ�\n");
        }
        return ::valid_leave(me, dir);
}

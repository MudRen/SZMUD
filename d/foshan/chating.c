// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ��·�ߵ�С��ͤ����ɽ·���˳��ڴ˴�ЪЪ�š�ͤ����
�м������Ӻͼ�֧���ʡ���Χ��һƬ���֡�
LONG
        );
        set("exits", ([
		"west" : __DIR__"road3",
	]));


        set("objects", ([
                        __DIR__"npc/yuan" : 1
	]));
	set("cost", 1);
	setup();
	set("outdoors","quanzhou");
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( present("yuan ziyi",me))
		return notify_fail("����մ����Ҹ�Ů��С�ĺ컨���Ӣ�����㱨��\n");

        return ::valid_leave(me, dir);
}


// Code of ShenZhou
// ɽ�� /d/shenlong/shangang
// ywz 09/18/96

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����ʯ�ڣ�Ұ�ݴ�������ʯ�ɶѣ��Եúܻ�����ʯ���������С����
�����������ʯ��
LONG
        );
        set("outdoors", "shenlong");
	set("exits", ([
		"northdown" : __DIR__"shulin1",
		"westdown" : __DIR__"tiandi4",
		"southwest" : __DIR__"shanqiu",
        ]));
      set("objects", ([
	    "/d/shenlong/npc/mangshe" : 1,
	]));
	set("cost", 3);

        setup();
        replace_program(ROOM);
}


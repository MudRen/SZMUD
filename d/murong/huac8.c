// Code of ShenZhou
// Room: /d/murong/huac8
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
    ת��һ��Сɽ��ֻ����Ϫˮ���ģ�����һ������
�����������ľ����õ���ɽ��֮�����չ����䲻������
��ֲɽ��ĺõط���
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "southeast" : __FILE__,
        "west" : __FILE__,
        "north" : __DIR__"huac7",
        "east" : __DIR__"mantuo2",
        "southwest" : __FILE__,
        "south" : __FILE__,
                      ]));
	set("no_clean_up", 0);
        set("objects", ([
		"/kungfu/class/murong/yuyan" : 1,
		]));

	setup();
        replace_program(ROOM);
}


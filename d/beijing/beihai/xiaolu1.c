//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�����ź���С·��·������һƬ�����֣�������Կ������ϵİ�����
�������ﲻʱ���Կ���һֻֻ����������ȥ��
LONG
	);
	set("cost", 2);
	set("exits", ([
                "south" : __DIR__"ximen",
                "north" : __DIR__"xiaolu2",
        ]));
	
	
	setup();
	replace_program(ROOM);
}

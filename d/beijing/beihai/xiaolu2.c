//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�����ź���С·��·������һƬ�����֣��ϵİ������������ﲻʱ����
����һֻֻ����������ȥ�������������Կ���һ��ͤ�ӵ�һ�ǡ�
LONG
	);
	set("cost", 2);
	set("exits", ([
                "northeast" : __DIR__"dukou1",
                "east" : __DIR__"wulong",
                "south" : __DIR__"xiaolu1",
        ]));
	
	
	setup();
	replace_program(ROOM);
}

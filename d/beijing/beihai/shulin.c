//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
���Ǻ���һƬС�����֣����������������һ��С�����������������쿪ȥ��
������Ƭ���־Ϳ��Կ���������ǰ�����ˡ�
LONG
	);
	set("cost", 2);
	 
	set("exits", ([
                "west" : __DIR__"qianmen",
                "north" : __DIR__"dongmen",
        ]));
	
	setup();
	replace_program(ROOM);
}

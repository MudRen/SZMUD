//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ֻ��һ��Сʯ�ţ������������ú���������Ȼ����ȴ�ǳ�������������
�������໨�ݶ������������
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "northwest" : __DIR__"yilan",
                "southup" : __DIR__"zhizhu",
        ]));
	
	
	setup();
	replace_program(ROOM);
}

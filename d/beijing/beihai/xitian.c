//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�峯ʱ�����ڽ̽�������Ҫ������������ʽ����������С���졢�����¡�
�����졢��������ȡ����������Ͼ���ȥ�����Ķɿڡ�
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "west" : __DIR__"jiulongbi",
                "southwest" : __DIR__"dukou1",
                "northeast" : __DIR__"jingqing",
        ]));
	
	
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ�����ĺ�̲��һ���Ǻ���һ����һƬ�һ��֡�һЩ����ʯ��һ�飬
��һ���ɢ���ں�̲�ϡ�������һ����̨��
LONG
	);
	 set("exits", ([
                "west" : __DIR__"citeng",
                "northup" : __DIR__"guanchao",
        ]));
	 
	set("objects", ([
                __DIR__"obj/shizi" : 3,
        ]));
	
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "�ƺӰ���");
        set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ
�ĺ�ˮ�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ��ƺ�
����������ܵ�����̩ɽ���赲��ת���򱱡�
LONG
        );

        set("exits", ([
		"northeast" : __DIR__"bank5",
		"west" : __DIR__"bank3",
        ]));
        
	set("objects", ([
		"/kungfu/class/misc/youxun.c" : 1,
	]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}


// Code of ShenZhou
// Room: gucd.c

inherit ROOM;

void create()
{
	set("short", "�Ȳݶ�");
	set("long", @LONG
����һ�����İ��棬�����ǰ������һƬ�Ͱ������ꡣԶԶ��ȥ����
�պ�ѳɵĹȲݶ⣬�������飬�������ж��ٸ���������Ƭ���������У�
�Ϳɽ��볤�״�ɽ�ˡ�����������һ�ƴ��̣������ƺ����ˡ�
LONG	);
	set("exits", ([ 
              "northwest" : __DIR__"mantx",
              "east" : __DIR__"baihe",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}

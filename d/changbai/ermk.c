// Code of ShenZhou
// Room: ermk.c

inherit ROOM;

void create()
{
	set("short", "���ſ���");
	set("long", @LONG
�����Ĳ�·���ѵ���ʧ��ԭ������ߣ�·����ϡ������һЩǳǳ����ӡ
��������ǰ��Ĳο����µġ���ãã��ѩ�ط����ҫ�۵����⣬������ͷ��
�ۻ���ż���м�ֻѩ�÷ɳ۶�����ת�۾���Ӱ�����ˡ�
LONG	);
	set("exits", ([ 
              "northwest" : __DIR__"damk",
              "east" : __DIR__"mantx",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// /d/huanghe/tccunko.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����ǻƺӱߺ��������һ��С���Ĵ�ڣ�ԭ�Ȼ��в��������ڴ�
����Ϊ�����������겻֪��Ϊʲ��һ��������֪ȥ��ֻʣ��һ���տյ�
����С�塣�������ش�ʮ�����Σ�������ϸѰ�ң����ѱ��˷��֡�����
��������İ�����������Ѳ�ߡ�
LONG );

        set("exits", ([
		"south"  : __DIR__"tcxiaolu",
		"north"  : __DIR__"bank6",
        ]));

        set("objects",([
                __DIR__"npc/tc_wang" : 1,
                __DIR__"npc/tc_bangzhong" : 1,
        ]));

        set("cost", 1);
        set("outdoors", "huanghe");

        setup();
        replace_program(ROOM);
}

// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������һ�ţ�Ψһ��һ�߹����Ǵ�����һ����������Ŀ׶���
������ġ��ı������͵ط������⣬ԭ������ǽ�ھ��Ǹ���������
LONG
        );

        set("exits", ([
		"out" : __DIR__"didao3",
	]));

	set("objects", ([
		__DIR__"obj/tiechuang1" : 1,
		__DIR__"npc/ren1" : 1,
	]));
        set("no_clean_up", 0);

	set("cost", 2);
	setup();
//        replace_program(ROOM);

}

void init()
{
	object me, ren;
	me = this_player();
        if (!present("ren woxing", environment(me)))
	{
		ren = new("/d/jiaxing/npc/ren1");
		ren -> move(environment(me));
	}
	
	
}

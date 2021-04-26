// Code of ShenZhou
// Room: Ȫ��������
// qfy August 17, 1996.

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʮ���ƾɵ�������Ҳ��֪�ķ��˶�ã����ϵ��²����˻ҳ���
�������������ǽ���и����ڣ������������������ļ��ˡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"lyqiao",
	]));

	set("objects", ([
		__DIR__"npc/laoshu" : 1,
		__DIR__"npc/dipi" : 1,
		__DIR__"npc/punk" : 1,
	]));

	set("cost", 1);
	setup();
	//replace_program(ROOM);
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me = this_player();
        mapping myfam;

	myfam = (mapping)me->query("family");

        if( !arg || arg=="" ) return 0;

        if( arg=="hole" || arg=="dong" )
        {
           if( myfam["family_name"] == "ؤ��" ) {
                message("vision", me->name()+"����ؤ�����ǹ���һ�������������˽�ȥ��\n", environment(me), ({me}) );
		me->move("/d/gaibang/underqz");
		message("vision", me->name() + "�Ӷ������˽�����\n", environment(me), ({me}) );
		return 1;
                }
           else return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}

}



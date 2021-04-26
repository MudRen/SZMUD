// Code of ShenZhou
// Room: /d/xingxiu/xxcave.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�������ɽ�����һ���ȳ�ζ�����۾���Ӧ�����������󣬲ŷ��ֵ�
�������ײҲҵĹǺ�(skeleton)�����˵�������ʱ������ɽ�������˻˻
ɳɳ��������������ʲô��������������������
LONG
        );
        set("exits", ([
  "southeast" : __DIR__"xxroad10",
]));

        set("objects", ([
		"/d/xingxiu/npc/jumang" : 1,
        ]) );


        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 1);
        setup();
        //replace_program(ROOM);
}
void init()
{
        add_action("do_move","move");
}
 int do_move(string arg)
{
        object ob, me = this_player();
	if( !arg || arg=="" ) return 0;
	if( arg=="skeleton" ) {
                ob = new("/d/xingxiu/obj/yaobo");
	if (!ob)
		return notify_fail("��Ų�����ǣ����������ƺ����������ˡ�\n");

                ob->move("/d/xingxiu/xxcave");
        message("vision","��Ų��һ�ߺ��ǣ������������һֻ���񲧣�\n", me);
	return 1;
	}
}

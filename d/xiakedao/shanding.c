//Cracked by Roath
// xiakedao/shanding.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����︩���������һ�����š�ɳ̲����Լ�ɼ�����С�ڵ㣬
��ֻ��������ͷ�����ŵػ��衣������ȥ��ֻ������һɫ��������ϴ��
�����Ļ��󳩡�ɽ���ϳ���һ�ô���(tree)���������ơ�
LONG );

        set("exits", ([
		"eastdown" : __DIR__"shanlu4",
		"westdown"  : __DIR__"shanlu3",
		"southdown" :  __DIR__"yelin",
        ]));
        set("item_desc",([
			  "tree" : "�����ϳ���һЩҰ������֪��������ժ������\n",
        ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/wudang" : 1,
	    __DIR__ + "npc/master1" : 1,
      ]));

	setup();

}

void init()
{
  ::init();

        add_action("do_pa", "pa");
	add_action("do_pa", "climb");
}

int do_pa(string arg)
{
        object me = this_player();

        if ( !arg )
                return notify_fail("��Ҫ���Ķ�����\n");
        if (( arg != "tree" )&&(arg!="up"))
                return notify_fail("ʲ�᣿\n");
        message_vision("$N���ֱ��ŵ���������������ȥ��\n",me);
        me->move(__DIR__"tree1");  
        message_vision("$N����������������\n",me);
        return 1;
}


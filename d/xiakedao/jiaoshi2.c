//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "��ʯ");
    	set("long", @LONG
������һ�߷��Ͳ���ˣ�����������᾵Ľ�ʯ����ɭɭ�ģ���
�䵽��ҹ�䣬����������ʬ��ɢ���ӫ�����������ȷ��⡣����
������ȥ��ֻ����Զ����һ���ʯ����֪�ܲ�����ˮ(tang)������
��ʯ��ȥ��
LONG
    	);

    	set("exits", ([
		       "north" : __DIR__"jiaoshi1",
		       "south" : __DIR__"jiaoshi3",
		       ]));
    	set("outdoors", "xiakedao");


    	setup();
}

void init()
{
  ::init();

        add_action("do_tang", "tang");
}

int do_tang(string arg)
{
        object me = this_player();

        if ( !arg )
                return notify_fail("��Ҫ���ĸ������ˣ�\n");
        if ( arg != "east" )
                return notify_fail("�Ǳ��˲���ȥ��\n");
        message_vision("$N������ȣ�����ʯ�����˹�ȥ��\n",me);
        me->move(__DIR__"dajiaoshi");  
        message_vision("$N�ӵ������˹�����\n",me);
        return 1;
}




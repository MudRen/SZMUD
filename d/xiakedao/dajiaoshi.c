//Cracked by Roath
// dajiaoshi.c  ��ʯ
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "��ʯ");
    	set("long", @LONG
һ���ʯ����Χ����ˮ�������ǵ���
LONG
    	);

    	set("outdoors", "xiakedao");
        set("objects", ([ 
                         __DIR__"npc/haigui" : 2,
                         __DIR__"npc/haigui_s" : 2,
                         ]));

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
        if ( arg != "west" )
                return notify_fail("�Ǳ��˲���ȥ��\n");
        message_vision("$N������ȣ����������˹�ȥ��\n",me);
        me->move(__DIR__"jiaoshi2");  
        message_vision("$N�Ӵ�ʯ�����˹�����\n",me);
        return 1;
}




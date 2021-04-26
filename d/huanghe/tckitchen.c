// Code of ShenZhou
// /d/huanghe/tckitchen.c

inherit ROOM;

void create()
{
        set("short", "Сé��");
        set("long", @LONG
�ƿ���һ����ԭ������һСС�ĳ�����������һ�����ڵ���������Ѿ�
�ܾ�δ�ù��ˡ������һ����ˮ�ף�gang)��
LONG );

        set("exits", ([
		"east" : __DIR__"tcxiaolu",
        ]));

	set("item_desc",([
	    "gang" : 
"һ��ʢ����ˮ�Ĵ�ˮ�ף������ˮ����յ���ȥ���ã�ˮ�׿���ȥ�ǳ����ء�\n"
	]));

    	set("cost", 1);

        setup();
        // replace_program(ROOM);
}

int init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object me = this_player();

        if( !arg || arg != "gang" )
                return 0;

        if( query("exits/down") )
                return notify_fail("ˮ���Ѿ����ƿ��ˡ�\n");

        if( me->query_str() < 22 ) {
                message_vision("$Nʹ��������һ��ˮ�ף����ˮ����˿������\n", me);
                return 1;
        }

        message_vision("$N����ˮ�׷���һ�ԣ��׵ױ�¶��һ������������\n", me);
        message_vision("$N�漴ץס����������һ�ᣬ����һ���죬һ������Ӧ�ֶ����ֳ�һ���󶴡�\n", me);
        set("exits/down", __DIR__"tctongdao");
        return 1;
}

void reset()
{
        ::reset();

        if( query("exits/down") ) {
                message("vision", "ֻ��һ��������ڹ�����ˮ���ƻ�ԭ����\n", this_object());
                delete("exits/down");
        }
}

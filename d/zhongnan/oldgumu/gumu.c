// Code of ShenZhou
// road: /zhongnan/gumu.c

inherit ROOM;

void create()
{
        set("short","��Ĺ");

        set("long",@LONG
���߹��˲ݵأ���ǰͻȻ��һƬ�����أ�ͻأ��������һ����Ĺ��Ĺ
������ʯͷ�Ѿ��ವ�ˣ����ĳ�����������Ĺ��Ĺǰû��������Ҳû����
�εı�ǣ���֪������ǰ����λ�����󳼵�ĹѨ��Ĺ�ſڱ�һ��������
��ʯͷ(shi)��յ�˿����͸��
LONG);

		  set("exits",([

				//"enter" : __DIR__"zoudao1",
				"east" : __DIR__"milin3",
				"south" : __DIR__"milin6",
				"west" : __DIR__"milin8",
				"north" : __DIR__"milin5",

							 ]));
	set("item_desc", ([
		"shi": "���ǿ��ʯ���²���������£��������Ŷ���ʯ�����֡�\n"
	]) );

	set("objects",([
		  "/d/zhongnan/npc/maque" : 3,
	 ]));
	  set("cost",1);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
        add_action("do_move", "move");
}


int do_move(string arg)
{
        object me=this_player();

        if( !arg || arg != "shi" ) {
                return notify_fail("��Ҫ�ƶ�ʲô��\n");
        }

        if((int)me->query_str()>33) //��������33
                {
                message_vision("$Nվ��ʯǰ��˫�Ʒ����ƶ���ʯ��ֻ���þ�ʯ֨֨������\n",this_player());
                message_vision("���������ȥ���ֳ�һ���Ż�����\n", this_player());
                set("exits/enter", __DIR__"zoudao1");
                remove_call_out("close");
                call_out("close", 5, this_object());
                }
        else
                message_vision("$N���������ƾ�ʯ����ʯ��˿������ֻ�ð��ˡ�\n", this_player());
        return 1;
}

void close(object room)
{
        message("vision","ֻ����ʯ��֨֨�ػص�ԭ�ء�\n", room);
        room->delete("exits/enter");
}

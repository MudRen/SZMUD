// July 31,2000
// Code by April
// /gumu/mudao13.c

inherit ROOM;

void create()
{
        set("short","Ĺ��");

        set("long",@LONG
����ɭɭ��Ĺ����Ҳ��֪����ͨ���Ķ��ġ�ǽ�ϵ�һ֦С��������
���ࣵ�ȼ���š��ǻ��ε�΢�⣬������������һ��Ĺ������Զһ�����
�������ˡ�Ĺ����ͷ�ƺ���Щ����������
LONG);

	 set("exits",([ 
		"west" : __FILE__,
		"north" : __DIR__"mudao12",
		"east" : __FILE__,
		"south" : __FILE__,
		 ])
			  );
	  set("cost",1);

		  setup();

}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg == "" ) return 0;
        if( arg == "stone" || arg == "shi") 
        {
        message_vision("$N���������������ʯǽ��������һ��ͻ������ʯ��һ������\n\n"+
        "ֻ����ˮ������һ���Ĺ����¶��һ��ͨ���ܵ����ڡ�\n",me);
        set("exits/down", __DIR__"midao1");
        remove_call_out("close_door");
        call_out("close_door",15,me);   
                return 1;
        }
        else
                return notify_fail("��Ҫ��ʲô��\n");
}

void close_door()
{
        tell_room(this_object(),"�ֹ���һ���������һ��ˮ���������ڱ���ס�ˡ�\n");
        delete("exits/down");
}

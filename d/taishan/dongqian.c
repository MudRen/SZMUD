// Code of ShenZhou
// dongqian.c ����������ɽ����ǰƽ��
// qfy July 10, 1996

inherit ROOM;

void create()
{
        set("short", "��ǰƽ��");
        set("long", @LONG
�߹����ܾ������ƻ�Ȼ���ʣ�ԭ���ѵ���һ�����֮�С�ǰ���и���
����Ĵ�ɽ��(cave)�������Ȼ��һͷ��񣬺�����������ɽ����������
ľ�Դ䣬ɽ�����ѡ�
LONG
        );

	set("exits", ([
                "enter" : __DIR__"dugudong",
	        "south" : __DIR__"mijing",
        ]));

	set("objects", ([
	    __DIR__"npc/shendiao" : 1,
	]));

	set("item_desc",([
	    "cave" : "һ��������Ĵ�ɽ������֪������Щʲô������\n"
	]));

	//set("no_fight", 1);

	set("outdoors", "taishan");

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("marks/��") && dir == "enter" 
	&& objectp(present("shen diao", environment(me))))
	   return notify_fail("ͻȻһ�ɾ������棬���������ǰ����������ص������㡣\n");

	if ( !(me->query_temp("marks/Ĺ")==1 && me->query_temp("marks/��")==1 
	&& me->query_temp("marks/ǽ") ) && dir == "west" )
	   return notify_fail("ֻ���á��ɡ���һ�����䣬����ҳἲչ���������͵�����һ�ģ��������ȥ��\n"); 

 	return ::valid_leave(me, dir);
}

void init()
{
	object me = this_player();

	if ( me->query_temp("marks/Ĺ") == 1 && me->query_temp("marks/��") == 1
	&& me->query_temp("marks/ǽ") == 1 && objectp(present("shen diao", environment(me)))) {
	   if ( !me->query_temp("marks/С") ) {
	      message_vision("�����$N����ص�ͷ�����ָ�����ߡ�ԭ��������������֮����С����\n", me);
	   }
	   set("exits/west",__DIR__"xiaojing");
	   remove_call_out("close_up");
	   call_out("close_up", 5, me);
	} 
	add_action("do_kneel", "kneel");
}

int do_kneel(string arg)
{
	object me = this_player();

	if( !arg || arg != "cave" ) 
	   return notify_fail( "ʲô��\n" );

	me->set_temp("marks/��", 1);
	message_vision("$N�ڶ�ǰ�򵹣����˼��ݡ�\n", me);

	if ( objectp(present("shen diao", environment(me))) ) {
	   message_vision("������$N���˵�ͷ��ʮ������$N�ı��֡�\n", me);
	}

	return 1;
}

int close_up(object me)
{
//	message_vision("$N��ͷ��˼���ɲ����˺�һ�������Ȼ̧ͷʱȴ����С���ķ���\n", me);
	delete("exits/west");
	return 1;
}

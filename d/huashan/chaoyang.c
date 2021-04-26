// Code of ShenZhou
// chaoyang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǻ�ɽ�Ķ��塪�����壬춴˸���ƺ����Զ������������
С�·屳��ɽ�ӡ����������ϣ�����һ��������ӡ���ഫΪ��������项
��ɽʱ�����µġ�һ���м��ô�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		  "westdown" : __DIR__"zhenyue",
	]));

	set("no_clean_up", 1);
        set("fjing", 1);
        set("outdoors", "huashan" );

	set("tian_count", 1);

	set("cost", 5);
	setup();
}

void init()
{
	object me = this_player();

   	if ( interactive(me) && me->query("huashan/job_pending") ) {
		me->set_temp("hz_job/chaoyang", 1);
  	}

	add_action("do_shout", "shout");
	add_action("do_shout", "hu");
	add_action("do_shout", "jiao");
	add_action("do_gofeng", "feng");
}

int do_gofeng()
{
	object me = this_player();

	if ( me->query("family/master_name") != "������" )
		return notify_fail("ʲô��\n");

	message_vision("$N�첽���º�ɽ�Ĵ����\n", me);
	me->move("/d/huashan/xiaojing1");

	return 1;
}


int do_shout(string arg)
{
	object ob, me = this_player();

	if( !arg || arg=="" ) return 0;

	message_vision("$N�����е���"+arg+"��\n", me);

	if( ( arg == "������ǰ��" || arg == "��ǰ��" || arg == "����ǰ��" ) 
	&& query("tian_count") >= 1 && me->query_temp("marks/��") == 1
	&& !present("tian boguang", environment(me)) ) {
	    add("call_times", 1);

	    if( (int)query("call_times") == 3 ) {
		message_vision("ֻ�������Ե����ϴ���һ����ɧ��˭Ҫ�ҷ���ǰ������\n", me);
		message_vision("����һ��΢��Ĵ󺺴��������������������㿴��һ�����\n", me);
		add("tian_count", -1);
		ob = new(__DIR__"npc/boguang.c");
		ob->move(environment(me));
		delete("call_times");
	    }

	}

	return 1;
}

void reset()
{
	::reset();
	delete("call_times");
}

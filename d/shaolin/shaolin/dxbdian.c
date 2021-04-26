// Code of ShenZhou
// Room: /d/shaolin/dxbdian.c
// Date: YZC 96/01/19

inherit ROOM;


void create()
{
	set("short", "���۱���");
	set("long", @LONG
�����������µĴ��۱�����й������������������Ҹ���
���⡢����������һȺ����С���������ڷ���ǰ�ĵ����о���
�����������󳪽�����һ�����ӷ����黨ǳЦ�����ݣ����˶�
ʱ���𼸷�����֮�С���߾�����һ�Ӷ�ɮ�������룬������
�ֳֽ䵶���ƺ���Ѳ�µ�ɮ�ˡ�
LONG
	);

	set("no_fight", "1");

	set("exits", ([
		"southdown" : __DIR__"guangchang2",
	]));

	set("valid_startroom",1);
	set("book_count",1);

	set("objects",([
		CLASS_D("shaolin") + "/dao-zheng" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_ketou", "ketou");
}

int do_ketou()
{
	object me, ob, *obs;

	me = this_player();
		
	if ( random(50 - me->query_temp("ketou_times")) == 0 )
	{
		message_vision("$N��ͷ�ĵ����˹�ȥ��\n", me);
		me->set_temp("ketou_times", 0);
		me->unconcious();
		return 1;
	}

	me->add_temp("ketou_times", 1);	

	message_vision("$N�ϵع�������������������ǰ��ͷ��\n", me);

	if ( random(100) == 37 
	&& !present("silk", me)
	&& query("book_count") >= 1)
	{
		add("book_count", -1);
		obs = filter_array(children(__DIR__"obj/book-silk.c"), (: clonep :));
        if (sizeof(obs) < 2){
		ob=new("d/shaolin/obj/book-silk");
		ob->move("/d/shaolin/dxbdian");
		add("book_count", -1);
		CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ�����׽����ƪ��", me->query("name")));
		tell_object(me, "ͻȻ����ǰ��ž��һ������һ����Ƥ�ߴ������ı��\n");
		}
	}

	if(me->query_skill("force", 1) >= 30 
	&& me->query_skill("force", 1) <= 100 
	&& present("silk", me) )
	{
	if( me->query("class") == "bonze" || me->query("class") == "lama")
		{
		if( me->query("jing") >= 30 ) 
			me->receive_damage("jing", random(50), "��ͷ������");
		else	me->unconcious();
		me->improve_skill("force", random(me->query_con()*2));
		if ( random(5) == 0 )
		tell_object(me, "ڤڤ֮�У����ƺ����÷����ڵ㲦�����ڹ���������ѡ�\n");
		}
	}

	return 1;

}

int valid_leave(object me, string dir)
{
	if(me->query_temp("ketou_times") >= 10 ) me->add_temp("ketou_times", 10);

	return ::valid_leave();
}

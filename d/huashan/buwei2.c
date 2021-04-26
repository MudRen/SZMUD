// Code of ShenZhou
// buwei2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������Ⱥ�����ң�����Ⱥ�ڽ������˳ơ����ӽ���������Ϊһ��
�����ţ�����������ȴ���õĺܼ򵥡�����һ�Ŵ�����ֻ���ӣ�ǽ������
��ױ̨��ֻ�п�ǽһ�ź�ľ�������Ե��������ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "north" : __DIR__"pianting2",
]));
	set ("item_desc", ([
		"desk" : 
"����һ�źܽ�ʵ�ĺ�ľ�����������ϰ��ż�ֻ�Ǻ��ʣ�ĥ��һ���ī��\n"
"����һ��δ�õİ�ֽ��\n",
		"bed" :
"���̼����أ�ߡ�����������롣\n",
	])  ) ;

	set("no_clean_up", 0);
        set("zixia_count", 30);
	set("cost", 0);

	setup();
}

void init()
{
//	add_action("do_move", "move");
	add_action("do_search", "search");
	add_action("do_search", "find");
}

/*
int do_move(string arg)
{
	object paper;
	paper = new(__DIR__"obj/paper");

	if( !arg || arg=="" ) return 0;

	if( arg=="desk" ) {
		if (!query("hs_trigger")){
		message_vision(
"$N��������������������ص������ƺ�����û��...��ͻȻ��������\n"
"ǽ��֮��Ʈ���һ��ֽ��\n", this_player());
		paper->move(__FILE__);
		set("hs_trigger", 1);
		return 1;
		}
		message_vision(
"$N��������������������ص�������˿������\n", this_player());
		return 1;
	}
	return 0;
}
*/

int do_search(string arg)
{
	object ob, *obs, me = this_player();

	if( !arg || arg=="" ) return 0;
	
	if( arg != "bed" ) return 0;

	if( me->query("family/family_name") != "��ɽ��" )
		return notify_fail("�㽫��ͷ���𣬵���ȴ���ᶼû�С�\n");

	if ( query("zixia_count") >= 1 && !me->query_temp("marks/��") ) {
	   obs = filter_array(children(__DIR__"obj/zixia_book.c"), (: clonep :));
           if (sizeof(obs) > 100)
	   	return notify_fail("�㽫��ͷ���𣬵���ȴ���ᶼû�С�\n"); 

   	   ob = new(__DIR__"obj/zixia_book");	   
	   ob->move(me);
	   add("zixia_count", -1);
	   CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ������ϼ�ؼ���", me->query("name")));
	   me->set_temp("marks/��", 1);
	   write("�㽫��ͷ����ͻȻ����һ�������Ĳ��ӣ���ϸһ��ԭ���ǻ�ɽ��ɽ֮������ϼ���š���\n");
	   write("��ѡ���ϼ���š�С�ĵ��պá�\n");
	}
	else {
	   write("�㽫��ͷ���𣬵���ȴ���ᶼû�С�\n");
	}
   
	return 1;
}

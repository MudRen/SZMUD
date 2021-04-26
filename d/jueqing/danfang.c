// Filename:   /d/jueqinggu/danfang.c ����
// Code by:    Jiuer Aug 15, 2001

inherit ROOM;

void create()
{
	set("short","����");

	set("long",@LONG
��������У��Ͽ�����һ�ѽ��κ�һ�ų������ӣ����ϰڷ���һЩ
С���ӡ����ϡ���������ҩƿ������һ�ԴԵĹ�������Ǭ��ҩ�����ײ�
��������¯(lu)���������洰�����ʯ�ұ�����ν�����ˡ�
LONG);

	set("item_desc", ([
		"lu" : "������¯������ͭ���ɣ�ÿ��¯���¶���һ�����֣���������Ų��(push)���ǡ�\n"
		]));

	set("exits",([ 
		"east" : __DIR__"changlang3",
		]));
		  
	set("objects", ([__DIR__"npc/jiading" : 1,]));
	set("cost",1);
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player(),obj;

	if ( !arg || arg == "lu") 
		return notify_fail("¯���ƶ��ķ��򲻶ԣ�\n");
	
	if ( (int)me->query_str() < 28 )     //���Ʊ�������28
		return notify_fail("Ų�����صĵ�¯���㻹�������깦��\n");
	
	if (arg == "left") {
		if ( !me->query_temp("jq") )
			me->set_temp("jq",1); //��ߵĵ�¯�ζ�
		else
			me->delete_temp("jq");
		message_vision("$N���Ž����׵ĵ�¯�Ƶ����ס�\n",me);
	}

	if ( arg == "right" ) {
		if ( me->query_temp("jq") == 1 )
			me->set_temp("jq",2);//�ұߵĵ�¯�ζ�
		else
			me->delete_temp("jq");
		message_vision("$N���Ž����׵ĵ�¯�Ƶ��м䡣\n",me);
	}

	if ( arg == "front" ) {
		if (me->query_temp("jq") == 2){
			message_vision("$N���Ž��м�ĵ�¯�ƿ���Ȼ��ԭ���м���Ƶ������ף���¡һ��.....\n\n",me);
			message_vision("$Nֻ����׿��飬��ǰһƬ�ڰ������ӱ�ֱ���²�֪�����ںδ�......\n\n\n", me);
			// (waaa. ��ɹ���, ���ǵȴ�����Ǹ����µ�...)
		
			//	remove_call_out("close_door");
			write("\n\n��ͨһ���������������̶��\n\n");
			me->move(__DIR__"eyutan");

			me->receive_damage("qi", 200, "��������̶������");
			me->receive_wound("qi",  200, "��������̶������");
			return 1;
		}
		else 
			message_vision("$N���Ž��м�ĵ�¯�ƿ���Ȼ��ԭ���м���Ƶ������ס�\n",me);

		me->delete_temp("jq");
	}	

	return 1;
}

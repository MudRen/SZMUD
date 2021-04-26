// Code of ShenZhou
// d/emei/tomb.c ����֮Ĺ
// xbc 1997/02/03

#include <ansi.h>

inherit ROOM;

int visited, start_visit; 
int is_visiting();
int look_tomb();
int dig_times;

void create()
{
	set("short", "����֮Ĺ");
	set("long", @LONG
������һ����ģ�����Ĺ��Ĺ���Ͽ��ż������֣���������ʦ����֮Ĺ��
ԭ�����Ƕ����ɴ�����ʦ�����Ĺ����Ů�����Ǵ���������СŮ����������
�ڶ���ɽ���ӣ������˶����ɣ�������ҵ��ӽ��������ڴ˴��������ļ���
���������ʻ�ʢ����ʮ���ľ���
LONG
	);
	
	set("exits", ([
		"south" : __DIR__"grassland",
		"east" : __DIR__"tombpath",
	]));
	
	set("item_desc", ([
		"tomb" : (: look_tomb :),
	]));
		                                
	set("cost", 1);
	setup();
	
	dig_times = 0;
	set("tomb_door", 0);	//door closed
	set("guard_count", 1);
	visited = 0;
	call_out("visit", 120, 1); 
}

void init()
{
	add_action("do_jing", "jing");
	add_action("do_clean", "sao");
	add_action("do_clean", "clean");
	add_action("do_dig", "dig");
	add_action("do_dig", "wa");
}

int is_visiting()
{
	return (visited < 3);
}	

string look_tomb()
{
	if ( !query("tomb_door")) {
		switch (visited) {
		case 0:
			return(GRN"Ĺ�ԵĲݼ����������룬Ĺ��Ҳ�˳���Ⱦ��\n"NOR);
			break;
		case 1:
			return(YEL"Ĺǰ���˼����㣬�������ơ�\n"NOR);
			break;
		case 2:
			return(MAG"Ĺǰ���ż���СҰ����\n"NOR);
			break;
		default:
			return(WHT"Ĺ���Ӳݴ������þ�û��������ɨ���ˡ�\n"NOR);
			break;
		}
	}
	else 
		return("Ĺ����˾�һ������һ����ʯ��¶������\n");
} 

void visit(int phase)
{
	visited = phase;
	
	if (visited < 3) call_out("visit", 120, phase + 1);

}

int do_jing(string arg)
{
	object obj, me;
	
	if ( !objectp(me = this_player()) ) return 0;	
	if (!arg ) return notify_fail("��Ҫ��ʲô��\n");  
	if( !objectp(obj = present(arg, me)) )
		return notify_fail("������û������������\n");
	if ( !(obj->id( "incense")) && !(obj->id( "flower")) ) 
		return notify_fail("�㾴�����ʲô��\n");  
	
	visited = 0;
	remove_call_out("visit");
	call_out("visit", 120, 1);
	
	message_vision("$N�ó�һ"+obj->query("unit")+obj->query("name")
		+"�����������ط���Ĺǰ��\n", me);
		
	me->add_temp("visit_tomb", 1);	                                         		                              		
	destruct(obj);
	
	return 1;		
}

int do_clean(string arg)
{
        object me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( arg == "tomb" ) {
                message_vision("$N��Ĺ�ߵ��Ӳ�����ɾ���\n", me);
		me->add_temp("visited", 1);
                return 1;
	}
	return 0;
}

int do_dig(string arg)
{
	object weapon, me = this_player();
	object guard;
	object room = load_object(__DIR__"tomb2") ) {
	
	if ( !arg || arg == "" ) return 0;

	if ( arg == "tomb" || arg == "mu") {
		if ( query("tomb_door")) {
			write("Ĺ�Ѿ����ˣ�һ����ʯ�ź��ڵ��ϡ�\n");
			return 1;
		}
		if( me->is_fighting() ){
			return notify_fail("����æ���ţ�\n");
		}
		if( !objectp(weapon = me->query_temp("weapon")) ) {
			message_vision(HIR"$N���Ĺ����һͨ��Ū��˫����Ѫ���ܡ�\n"NOR, me);
			me->add("jingli", -random(30));
			me->add("qi", -random(30));
                	return 1;
		}
		else if ((string)weapon->query("skill_type") != "sword"
                	&& (string)weapon->query("skill_type") != "blade" 
                	&& (string)weapon->query("skill_type") != "axe" 
			&& (string)weapon->query("id") != "tie qiao") {
        		message_vision(WHT"$N��������" + weapon->name() +WHT"����Ĺ����һͨ��\n"NOR, me);
                	message_vision(WHT"�����ž����һ����$N���е�" + weapon->name()
                        	+ "�Ѿ���Ϊ���أ�\n"NOR , me );
                	weapon->unequip();
                	weapon->move(environment(me));
                	weapon->set("name", "�ϵ���" + weapon->query("name"));
                	weapon->set("value", 0);
                	return 1;
        	}

        	message_vision(WHT"$N��������" + weapon->name() + WHT"���ԳԿԳԵ�����Ĺ����\n"NOR, me);
		me->add("jingli", -(8+random(36-(int)me->query("str"))));
        	me->receive_damage("jingli", 8+random(36-(int)me->query("str")),
                 	"��Ĺ������");

		dig_times++;

		if ( random(3) && (query("guard_count") > 0 ) 
		&& ! objectp(guard=present("guard", environment(me)) )) {
			add("guard_count", -1);
			guard = new(__DIR__"npc/guard2.c");
			guard->move(__FILE__);
			me->set_temp("digger/myname", 1);
			message_vision(RED"��Ȼ��һ������Ů���ɲ�������������������󵨵���������һ����\n"NOR,me); 
			message_vision(YEL"$Nһ��������ɱ��������ɱ����ڣ�\n\n"NOR,me);
			if( !guard->is_fighting() )
			guard->kill_ob(me);
			if( !me->is_fighting())
			me->kill_ob(guard);
			return 1;
		}

		if ( objectp(guard=present("guard", environment(me)) )) {
			guard->set_temp("digger/myname", 1);
			message_vision(RED"��Ĺ�������������󵨵���������һ����\n"NOR,me); 
			message_vision(YEL"$Nһ��������ɱ��������ɱ����ڣ�\n\n"NOR,me);
			if( !guard->is_fighting() )
			guard->kill_ob(me);
			if( !me->is_fighting())
			me->kill_ob(guard);
			return 1;
		}
		if ( dig_times > (15+random(5)) ) {
			message_vision("Ĺ�����汻�򿪸��󶴣���ǰ������һ��ʯ�š�\n",me); 
			set("tomb_door", 1);
			set("exits/down", __DIR__"tomb2");
			room->set("exits/up", __FILE__);
			tell_room(room, "���⴫��ɳɳ�����ƺ����˽����������ˡ�\n");
			delete("dig_times");
			remove_call_out("close_tomb");
			call_out("close_tomb", 30, me);
                	return 1;
		}
		else
			return 1;
        }
}


void close_tomb()
{
	object room = load_object("d/emei/tomb2";

	if( !query("tomb_door") ) return;

	message("vision", "��Ȼ�����Ե����������������Ѿ򿪵�ʯ�Ÿ���ס�ˡ�\n", this_object() );
	delete("exits/down");
	room->delete("exits/up");
	tell_room(room, "�����ִ���ɳɳ�����ƺ���������������ʯ�Ÿ���ס�ˡ�\n");
	dig_times = 0;
	set("tomb_door", 0);
}


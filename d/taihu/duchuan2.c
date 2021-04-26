// Code of ShenZhou
// maco

#include <ansi.h>

inherit ITEM;

int arriving();
void arrive();
void close_passage();
string look_lake();
string day_event(){return NATURE_D->outdoor_room_event();}

void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
���ǹ���ׯ����̫��(lake)��һҶ���ۡ��밶��Զ����������
������Ī֪���֮�ں������ֻ��Ǻ���֮����ء�
LONG
	);

	set_weight(3000000);
	set_max_encumbrance(5000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("water_name", "��");
		set("invalid_startroom",1);
		set("outdoors", "shaolin");
		set("item_desc", ([
			"lake" : (: look_lake :),
		]));

		set("cost", 2);
	}
	setup();
}

string look_lake()
{
	string desc;
	object *boat;

	if( day_event() == "event_night" || day_event() == "event_midnight")
	desc = WHT"������ȥ���������죬�������������������Ա��ᴵ�������ǳ��졣\n"NOR;
	else if( day_event() == "event_dawn" )
	desc = HIY"��ʱ���Ѵ������չ��Զ�������ˮ���ζ���������������ڴ��߷���һ�㡣\n"NOR;
	else if( day_event() == "event_evening" )
	desc = HIM"���۵���ĺ���Բԣ��̲�����Ϧ���Ȼƣ���ϼ�Һ죬������һ��ˮīɽˮһ�㡣\n"NOR;
	else  desc = HIG"���۵���ɽ��ˮ�̣������Ʋԣ�һ����紵����ˮ���������Ĵ��ڴ�ͷ��\n"NOR;
	boat = filter_array(children(base_name(this_object())), (: clonep :));
	if (sizeof(boat) > 8)
		desc += "ֻ��������һ���ŵ�ȫ��С����������ȥ�������Ͼۣ�����������"
		"����һ�Ŵ���ֽ�Ͻ���ī��һ�㡣\n";
	else if (sizeof(boat) > 1)
		desc += "�����Ϸ�Ӱ��㣬�����ֵ�������������ׯˮ·�ı���"+chinese_number(sizeof(boat))+"��"+chinese_number(sizeof(boat)+1)+"��С����\n";
	else desc += "�����Ϸ�Ӱ��㣬������������ׯˮ·�Ĵ����ƺ���������һ���ҡ�\n";

	return desc;
}

int is_container() { return 1; }

/*
void init()
{
	remove_call_out("auto_clean_up");
	call_out("auto_clean_up",60);
}
*/

int auto_clean_up()
{
	object *inv, room, exit;
	string dest, msg;
	int i, k = 0;
	room = this_object();
	exit = load_object(query("exits/out"));

	inv = all_inventory(room);

	if( room->query("exits/out") ) {

		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("race") == "����" )
				msg = "��";
			else msg = "��";

			if( inv[i]->is_character() ) {
				tell_object(inv[i], "��������˵������"+ RANK_D->query_respect(inv[i]) +"���Ѿ������ˣ����´��գ�\n");
				message_vision("�����$N"+msg+"���˶ɴ���\n", inv[i]);
				inv[i]->move(exit);
				if( inv[i]->query("race") == "����" ) message("vision", inv[i]->name()+"�Ӵ�������������\n", exit, inv[i]);
				else message( "vision", inv[i]->name() + inv[i]->query("comein_message") , environment(inv[i]), inv[i] );

			}
		}
		destruct(room);
	}

	for(i=0; i<sizeof(inv); i++) {
		if(userp(inv[i]))
		k++;
	}
	if ( k > 0 || !inv ) {
		remove_call_out("auto_clean_up");
		call_out("auto_clean_up", 20);
	}
	else destruct(room); 

	return 1;
}

int arriving()
{
	add_action("do_anchor", "anchor");
	add_action("do_anchor", "tingbo");

	call_out("auto_clean_up", 40);
	call_out("arrive", 20);
}

void arrive()
{
	object boat = this_object();

	message("vision", "����⽰�������ں��������������ͣ���ڰ��ߣ���һ��̤�Ű�����˵̰���\n", boat );

	boat->set("exits/out", this_object()->query_temp("opp"));

//	remove_call_out("close_passage");
//	call_out("close_passage", 20);
}

void close_passage()
{
	object *inv, boat = this_object();

	boat->delete("exits/out");
	message("vision", "�����̤�Ű����������ѱ���ʻ����ġ�\n", this_object());
	boat->delete("yell_trigger");
	inv = all_inventory(boat);
	if (sizeof(inv) < 1) 
	destruct(boat);
	else call_out("auto_clean_up",60);
}

int valid_leave(object me, string dir)
{
	return 1; 
}

int do_anchor(string arg)
{
	object me, boat;
	string dir;

	me = this_player();
	boat = this_object();

	if( arg ) return 0;

	if( boat->query("exits/out") )
		return notify_fail("���Ѿ������ˡ�\n");

	message_vision("$N�򴬷���ʣ������ң���û�����𣿡�\n", me);

	if( time() - query("sail_time") < 10 ) {
		message_vision("��������$Nһ�ۣ�˵������"+ RANK_D->query_respect(me) +"�����ǲŸ��밶�ģ���\n", me);
	}

	else if( time() - query("sail_time") < 30 ) {
		message("vision", "�����������յذ��Ž���һ�ߴ��ţ���"+ RANK_D->query_respect(me) +"���ģ��Ϳ쵽�ˣ���\n", boat );
	}

	else {
		message("vision", "������Ž�����������ģ��ⲻ�͵����᣿��\n", boat );
		message("vision", "���򽫴�����ͣ���ڰ��ߣ���һ��̤�Ű�����˵̰���\n", boat );
		boat->set("exits/out", this_object()->query_temp("opp"));
	}

	return 1;
}

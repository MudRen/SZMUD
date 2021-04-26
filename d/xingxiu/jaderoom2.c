// Code of ShenZhou
// �����
// maco
#include "localtime.h"
#include <ansi.h>

inherit ROOM;
void sun_light();
void check_turn();
int do_turn(string arg);
int do_move(string arg);
string look_bed();
string look_table();
string day_event(){ return NATURE_D->outdoor_room_event();}

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ң�һ�����ߴ�������ʮ�ɸߴ��ıڷ��������
�������꽨�������������Ȼ���ߣ��ڷ��ж�׼λ�ã��������
��ʯ��������(bed)������(table)������(chair)������̵�
���Ǿ��£�����б����һ�ߺ��ǡ�ʯ��һ�ǣ�����һ��һС����
�ߺ��ǡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"jaderoad6",
	]));
	set("item_desc", ([
	"bed" : (: look_bed :),
	"table" : (: look_table :),
	"chair" : "�����ɰ�����ɵ����ӡ�\n",
	]));
	set("sleep_room", 1);
	set("outdoors","xingxiu");
	set("bamboo", 1);
	set("table_wrong",5+random(6));
	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_turn", "turn");
	add_action("do_move", "move");
	add_action("do_move", "pull");
	add_action("do_move", "push");
	add_action("do_pick", "pick");
}

string look_bed()
{
	string desc;
	if(!query("exits/down")) desc = "һ�Ű�����ɵĴ�������б����һ�ߺ��ǡ�\n";
	else desc = "һ�Ű�����ɵĴ���������һ���󶴣�������һ���ݼ����Ա�б����һ�ߺ��ǡ�\n";	
	return desc;
}

string look_table()
{
	string desc, msg;
	int w;
	w = query("table_wrong");
	if(w >= 10) msg = "һ��";
	else if(w > 0) msg = chinese_number(w)+"��";

	if(wizardp(this_player())) tell_object(this_player(),"������"+day_event()+"��\n");
	if (day_event() == "event_morning" || day_event() == "event_afternoon") {
	this_player()->set_temp("checkd_table",1);
	desc = "��ʱ�չ���������������߽�ϸ��������������һȺ��������ķ����գ����Ƽ�ϸ��\n�չⲻ����ʱȫȻ�Ʋ��������̹����Ǿ��¡�\n";
		if(w > 0)
		desc += "Ȼ�����յ�ͷ������ȴ��������һ�𣬸����뿪��"+msg+"��λ�á�\n";
	}
	else {
	remove_call_out("sun_light");
	call_out("sun_light", 1);
	desc = "�����Բ�����������ʯ�е�̳����ģ����ڵ��ϣ�����������֮����\n";
	}
	return desc;
}
void sun_light()
{
	object room = this_object();

	if(day_event() == "event_morning") {
	message("vision", HIW"���˴���ʱ�����չ⽥�����䵽��Բ�����档\n"NOR, room );
	remove_call_out("sun_light");
	}
	else {
	remove_call_out("sun_light");
	call_out("sun_light", 1);
	}
}
int do_turn(string arg)
{
	object me = this_player();
	string dir;

	if (!me->query_temp("checkd_table")) return 0;

	if( !arg || arg=="" ) return 0;

	if( arg=="table") {
		write("��Ҫ�Ѱ���Բ����ʲ�᷽��ת����\n");
		return 1;
	}

	if( sscanf(arg, "table %s", dir)==1 ) {
		if (me->is_busy() || me->query_temp("pending/exercising"))
			return notify_fail("����æ���ء�\n");

		if(me->query_str() < 30)
			return notify_fail("��ı���̫С���ⲻ��ʯ����\n");

		if( dir=="left" ) {
			message_vision("$N��סԲ����Ե����������һ�⣬",me);
			add("table_wrong", 1);
			check_turn();
			me->start_busy(random(2));
			return 1;
		}
		if( dir=="right" ) {
			message_vision("$N��סԲ����Ե����������һ�⣬",me);
			add("table_wrong", -1);
			check_turn();
			me->start_busy(random(2));
			return 1;
		} else {
			write("��Ҫ����ת������Բ����\n");
			return 1;
		}
	}
}

void check_turn()
{
	object me, room;
	int w;
	w = query("table_wrong");
	me = this_player();

	if( w > 0 && query("exits/down")) {
		message_vision("ֻ���������������ϵĵص������ֺ����ˡ�\n",me);
		delete("exits/down");
		if( room = find_object(__DIR__"jaderoad7") ) {
			room->delete("exits/up");
			message("vision", "ֻ������������ͷ���ϵ�ʯ���ֹ����ˡ�\n",room );
		}
		return;
	}

	if( w >= 10) {
		message_vision("���Կ����ƶ�������ô���㲻���ˡ�\n", me );
		set("table_wrong",10);
		return;
	}
	
	if( w < 0 ) {
		message_vision("���Կ����ƶ�������ô���㲻���ˡ�\n", me );
		delete("table_wrong");
		return;
	}

	if( w < 1) {
		set("exits/down", __DIR__"jaderoad7");
		message_vision("���Կ����ƶ���\n",me);
		message_vision(HIW"$Nʹ�������ѱ�Ե�⽫��ȥ��ʹ�ÿ�����ԵһȦ������ͷ��������ĵ�������������һ�塣\n"
		"�ոմպϣ�ֻ���������������ϳ�����һ���󶴣�������һ���ݼ���\n"NOR,me);
		delete("table_wrong");
		if( room = find_object(__DIR__"jaderoad7") ) {
			room->set("exits/up", __FILE__);
			message("vision", "ֻ������������ͷ���ϵ�ʯ���������ˡ�\n",room );
		}
		remove_call_out("close_bed");
		call_out("close_bed", 10);

	}
	else message_vision("���Կ����ƶ���\n",me);

	return;
}

void close_bed()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "�����ú�¡ֻ���������������ϵĵص������ֺ����ˡ�\n", this_object() );
	delete("exits/down");
	set("table_wrong",5+random(6));
	if( room = find_object(__DIR__"jaderoad7") ) {
		room->delete("exits/up");
		message("vision", "ֻ������������ͷ���ϵ�ʯ���ֹ����ˡ�\n", room );
	}
}

int do_move(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "table") {
	message_vision("$N������Բ������������һ̧��ʯ����˿���������ۺ���ֱ��������ʼ�ձ��綤���ڵ���һ�㡣\n",me);
	return 1;
	}
	return 0;
}

int do_pick(string arg)
{
	object me, where, book;
	
	me = this_player();
	where = environment(me);
	
	if (me->query_kar() < 30 || !query("bamboo") )
	return 0;

	if(arg != "skeleton") {
	write("��Ҫ��ʲ�᣿\n");
	return 1;
	}

	book = new("/d/xingxiu/obj/zhujian");

	if(!book) return 0;

	message_vision("$N���𺡹ǣ�ֻ����������һ�����\n"
	"$N����������������Ƥ���Ѿ��öϣ����һ���ɢ��ƬƬ��\n",me);
	CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ����һ��ׯ�����", me->query("name")));
	delete("bamboo");
	book->move(me);
	return 1;
}

// Code of ShenZhou
// Room: /d/shaolin/zhonglou1.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;


void close_passage();
string look_floor();
int do_open(string);


void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
��������¥�ĵײ㣬һ���������ǽ�ϵĻ�ש��϶��͸��
����������ש����Ͷ�±��µĹ�Ӱ����ͬһ����������ơ���
�Ͽ���������ľ¥�����ƶ��ϣ��ƺ����޾�ͷ��ǽ�ǣ��ݼ���
�൱�ྻ������������ɮ�˴�ɨ��
LONG
	);

	set("exits", ([
		"up" : __DIR__"zhonglou2",
		"out" : __DIR__"zhonglou",
	]));

	set("item_desc",([
		"floor"		:	(: look_floor :),
	]));

	set("bing", 1);

	set("objects",([
		__DIR__"npc/saodi-seng" : 1,
	]));
	set("cost", 2);
	setup();
}


void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object room, me;

	if( !arg || arg=="" )
		return 0;

	if( arg=="brick" && !present("blade", this_player()))
		return notify_fail("�����ڣ� ���²��аɣ�\n");

	if( arg=="brick" && !query("exits/down") )
	{
		message_vision( 
		"$N�ߵ�¥���£�ſ�ڵ��ϣ������ý䵶�����ש������������š���\n"
		"�ȵ���שһ�������˳���������¶��һ���󶴣�����ʯ��������ȥ��\n"
		"���������ͨ��һ��������\n", this_player());

		set("exits/down", __DIR__"andao3");
		if( room = find_object(__DIR__"andao3") ) 
		{
			room->set("exits/up", __FILE__);
			message("vision", "�컨���Ȼ����������������¶��һ�����ϵĽ��ݡ�\n",
				room );
		}
		remove_call_out("close_passage");
		call_out("close_passage", 3);
		return 1;
	}
	return 0;
}

void close_passage()
{
	object man1, man2, man3, man4, room, *ob;
	int i;

	if( !query("exits/down") )
		return;

	if ( query("bing") >= 1 ) {
		message("vision", 
		"ֻ��ƹ��һ���죬��¥С�ű����˿�����һȺɮ��һӿ���롣\n"
		"�����е���ש���еİ转�����ְ˽ŵ���ש��Ѷ��ڷ���������\n"
		"����ש��佽���պ����֭��\n", this_object() );

		add("bing", -1);

		man1=new(__DIR__"npc/seng-bing3");
		man1->move(this_object());
		man2=new(__DIR__"npc/seng-bing3");
		man2->move(this_object());
		man3=new(__DIR__"npc/seng-bing3");
		man3->move(this_object());
		man4=new(__DIR__"npc/seng-bing3");
		man4->move(this_object());

		ob = all_inventory(this_object());
		for(i=0; i<sizeof(ob); i++) {
		   if( !living(ob[i]) || !userp(ob[i]) || ob[i]==man1
		   || ob[i]==man2 || ob[i]==man3 || ob[i]==man4 ) continue;
		   if( userp(ob[i]) ) { 
			man1->set_leader(ob[i]);
			man1->kill_ob(ob[i]);
			man2->set_leader(ob[i]);
                        man2->kill_ob(ob[i]);
                        man3->set_leader(ob[i]);
                        man3->kill_ob(ob[i]);
			man4->set_leader(ob[i]);
                        man4->kill_ob(ob[i]);
			ob[i]->fight_ob(man1);
			ob[i]->fight_ob(man2);
                        ob[i]->fight_ob(man3);
                        ob[i]->fight_ob(man4);
			}
		}
	}

	if( room = find_object(__DIR__"andao3") ) {
//		room->delete("exits/up");
		message("vision", 
	"ֻ��ƹ���Ҽ������죬���ż��ι��̵���ˮ����������\n"
	"���ϵĶ��ڱ�����ש������ʵʵ�ط���������\n", room );
	}
	delete("exits/down");
}

string look_floor()
{
	return
	"һƬ��ʵƽ������ש���棬ֻ��¥���µ�һ�Ǵ����԰�͹��ƽ��\n";
}

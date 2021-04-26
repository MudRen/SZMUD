// Code of ShenZhou
// pigtest room

#include <pig.h>

inherit "/inherit/room/pigroom";

string look_table();
string look_scoreboard();
string look_rules();
void do_back(object ob);

void create()
{
	set("short", "����");
	set("long", @LONG
	����һ��ר��Ϊ������ر���ƵĹ�������������ƻ�ͨ�����·���
Զ׼����Ϊ������Ƿ����Ƶġ���������ķ���һ���ð���������ľ�����ƵĹ�
����(table)����Χ�����İ��ľ�����Ρ������ϰ���һ���Ƿֲ�(scoreboard)��
���ߵ�ǽ������һ��ֽ(paper)��
LONG
	);
	set("pigging", 1);

	set("item_desc", ([
		"table" : (: look_table :),
		"scoreboard" : (: look_scoreboard :),
		"paper" : "����ض� help pig_cmds �� help pig_rules��\n",
	]));

	set("exits", ([
		"west": "/d/city/duchang2",
	]));

/*
	set("objects", ([
		__DIR__"qiao" : 1,
	]));
*/

	set("no_fight", "1");

	setup();
}
void init()
{
        ::init();

        add_action("do_knock", "knock");
}

int do_knock(string arg)
{       
        object me = this_player();
	object jiang;

        if ( (!arg )|| (arg != "table"))
	  {       
	        write("��ʲôѽ��(knock table)\n");
                return 1;
	  }
        if( (arg == "table") )
	  {     
                if(!(jiang = find_living("qiaozhu jiang")))
                  {
		        jiang = new("/u/xbc/npc/qiao");
		        jiang->move(environment(me));
                  }

                jiang->move(environment(me));
                message_vision("$N�������ָͷ�������������ӣ�ֻ��һλ�������˹�����\n", me);
		remove_call_out("do_back");
	        call_out("do_back", 20 + random(10), jiang);
                return 1;
	  }
        return 1;
}

void do_back(object ob)
{
  message("vision", 
	  "����������������ᣬ�ƺ��ŵ���ʲô��ζ������ææ�����˳�ȥ��\n", 
	  environment(ob), ({ob}));
  ob->move("/d/city/duchang2");
}


string look_table()
{
	if (this_player()->query_temp("pigging_seat"))
		return table_str(this_player()->query_temp("pigging_seat"));
	return table_str("");
}

string look_scoreboard()
{
	return scoreboard_str();
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("pigging_seat"))
		return notify_fail("���뿪�����������ж���\n");
	return ::valid_leave(me, dir);
}

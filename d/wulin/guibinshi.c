// Room: /u/piao/guibinshi.c
// piao 2001/10/07

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����������¥�Ĺ���ҡ����ڲ��õĹ�ɫ���㣬��ľ�Ҿߵ񹤾�ϸ��
ǽ�Ϲ����ֻ�����Ϊ���������漣���Ӵ���������ȥ��̩ɽ�ķ羰һ����
�࣬Ⱥɽ����������������ơ�����һ�Ų輸�ϰ���һ��ˮ������(panzi)
�����澭���·����˲ι���������֮��ĺ�����Ʒ��
LONG
        );

        set("exits", ([
                "down" : __DIR__"taotielou",
        ]));
/*        
        set("objects",([
                "/d/city/obj/kaoya" : 1,
         	"/d/xingxiu/obj/hulu" : 1,
	]));
*/
        set("item_desc", ([
                "panzi" : HIW"����һ��ˮ���Ƴɵ����ӡ�\n"NOR,
        ]));      
        
        set("no_fight","1");
        set("no_steal", "1");
        set("no_sleep_room", "1");
	set("cost", 0);
        setup();
}

void init()
{

        object me;
        me = this_player();
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_exercise",  "respirate");
        add_action("do_exercise",  "tuna");
        add_action("do_exercise",  "practice");
        add_action("do_exercise",  "lian");
        add_action("do_exercise",  "study");
        add_action("do_exercise",  "du");
	add_action("do_search",    "search");
	if (interactive(me)) 
	me->delete_temp("guibinshi");
	return;
	
}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, CYN"�������֮���������£���̫�ðɡ�\n"NOR);
        return 1;
}

int do_search(string arg)
{
        object ob,me;
        me = this_player();
        if (!arg || arg == "") return 0;
        
        if (arg == "panzi" || arg == "tray")

        {
                if (query("searched"))
                        return notify_fail("��������һ�������������Ʒ�Ѿ����˳����ˡ�\n");

                switch (random(5))
                {
                        case 0:
                        ob = new(DRUG_D("renshen_guo"));
                        break;
                        case 1:
                        ob = new(DRUG_D("xueteng"));
                        break;
                        case 2:
                        ob = new(DRUG_D("xuelian"));
                        break;
                        case 3:
                        ob = new(DRUG_D("lingzhi"));
                        break;
                        case 4:
                        ob = new("/d/xiakedao/obj/zhou");
                        break;
                }

                set("searched",1);              
                message_vision("$N���������ҵ���"+ob->query("name")+"��\n",me);
                ob->move(me);
                return 1;
        }
}       


   


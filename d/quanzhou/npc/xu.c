// Code of ShenZhou
// xu.c ���ϰ�/d/quanzhou/npc/xu.c
// modified by aln  2 / 98

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

#include "/d/REGIONS.h"

string ask_me();

void create()
{
	set_name("���ϰ�", ({ "xu laoban", "xu" }));
        set_color("$YEL$");
	set("title", "������ׯ�ϰ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "������ׯ�������ϰ��洫�����⣬�����ϰ����ǵ��Ĵ��ˡ�\n");
	set("combat_exp", 10000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("vendor_goods", ({
		__DIR__"obj/gua",
		__DIR__"obj/jin_ao",
		__DIR__"obj/red_cloth",
		__DIR__"obj/qun",
		__DIR__"obj/guazi",
		__DIR__"obj/green_beixin",
		__DIR__"obj/xiupao",
		__DIR__"obj/zhouqun",
		__DIR__"obj/chaoxue",
	}));

        set("inquiry", ([
               "���" : (: ask_me :),
               "silk" : (: ask_me :),
        ]));

            	
	setup();
//         add_money("silver", 50);
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

string ask_me()
{
        object obj, me = this_player();
        mapping prices;
        string *places, place;
        int price;

        if( !(obj = present("bang ling", me)) )
                return RANK_D->query_respect(me) + "�������⣬���ز��ĳ�ۡ�";

        if( (string)obj->query("job/type") != "����" )
                return RANK_D->query_respect(me) + "�������⣬���ز��ĳ�ۡ�";

        if( (string)obj->query("job/name") != CYN"���"NOR )
                return "��ֻ֪����ۣ�" + RANK_D->query_respect(me) + "����ȥ����˴����ɡ�";

        if( !mapp(prices = obj->query("job/prices")) )
                return "�����ۻ��ң��Ҳ���̫�����";

        price = 0;
        place = "city";
        places = keys(prices);
        for(int i = 0; i < sizeof(places); i++) {
                if( prices[places[i]] > price ) {
                        price = prices[places[i]];
                        place = places[i];
                }
        }

        return "��˵" + region_names[place] + "һ�������ߡ�";
}


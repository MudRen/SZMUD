// Code of ShenZhou
// huoji.c  ҩ�̻��
// modified by aln  2 / 98

inherit NPC;
inherit F_DEALER;

#include "/d/REGIONS.h"

string ask_me();

void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "����ƽ��ҽ������������æ�ġ�\n");
	set("combat_exp", 250);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		DRUG_D("jinchuang"),
		DRUG_D("sheyao"),
		DRUG_D("yangjing")
	}));

        set("inquiry", ([
               "����ɽ�˲�" : (: ask_me :),
               "renshen" : (: ask_me :),
        ]));

	setup();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

string ask_me()
{
        object obj, me = this_player();
        mapping prices;
        string *places, place;
        int price;

        if( !(obj = present("bang ling", me)) )
                return RANK_D->query_respect(me) + "�������⣬���ز��Ĳμۡ�";

        if( (string)obj->query("job/type") != "����" )
                return RANK_D->query_respect(me) + "�������⣬���ز��Ĳμۡ�";

        if( (string)obj->query("job/name") != "����ɽ�˲�" )
                return "��ֻ֪���μۣ�" + RANK_D->query_respect(me) + "����ȥ����˴����ɡ�";

        if( !mapp(prices = obj->query("job/prices")) )
                return "����μۻ��ң��Ҳ���̫�����";

        price = 0;
        place = "city";
        places = keys(prices);
        for(int i = 0; i < sizeof(places); i++) {
                if( prices[places[i]] > price ) {
                        price = prices[places[i]];
                        place = places[i];
                }
        }

        return "��˵" + region_names[place] + "һ���μ���ߡ�";
}
        
        

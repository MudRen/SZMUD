//Cracked by shenzhou
// tea seller.c ������ͷ
// �ƶ�  May 2002

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("������ͷ", ({ "tea seller", "seller", "man" }) );
        set("gender", "����" );
        set("age", 55);
        set("long", "��λ������ͷ��Ц�����æ�����������߹�����æ�ð׽��ӵ��˵�������\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set("no_get", "1");
        set("rank_info/respect", "�ϸ��");
        set("vendor_goods", ({
        	"/d/city/npc/tea/qimen_hongcha",
        	"/d/city/npc/tea/wuyi_yancha",
        	"/d/city/npc/tea/yinzhen",
        	"/d/city/npc/tea/maofeng",
        	"/d/city/npc/tea/longjing",
			"/d/city/npc/tea/biluo_chun",
			"/d/city/npc/obj/baozi",
			"/d/city/npc/obj/gaodian",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{       
        object ob; 
        mapping myfam; 

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family")) 
                && myfam["family_name"] == "ؤ��" 
                && ob->query_skill("begging",1) > 10 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) 
		{
			case 0:
				say( "������ͷЦ�����˵������λ" + RANK_D->query_respect(ob)
					+ "�������������\n");
				break;
			case 1:
				say( "������ͷ�ð�ë���˵�ľ�ʣ�˵������λ" + RANK_D->query_respect(ob)
					+ "��Զ��������������������ʰɣ�������ɱ���Щ�ò�ˮ��\n");
				break;
		}
}

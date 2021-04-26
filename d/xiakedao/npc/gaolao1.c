//Cracked by Roath
// gaolao.c ������
// qfy Sept 8, 1996.

inherit NPC;

void create()
{
        set_name("������", ({ "gao lao", "gao", "lao" }));
        set("long", 
"�����θߴ�˶״�������⡣��ֹ����������ɵ�����书ȴ�Ǽ��ߡ�\n"
"���򲻳��ڽ�����¶�棬���Բ���̫����֪��������\n");
        set("gender", "����");
        set("age", 73);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 27);
        set("int", 20);
        set("con", 27);
        set("dex", 25);
        
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 80);
        set("combat_exp", 1300000);
        set("score", 5000);

        set_skill("force", 160);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("blade", 165);
        set_skill("sword", 160);
        set_skill("strike", 150);
        set_skill("liangyi-dao", 165);
        set_skill("huashan-jianfa", 160);
        set_skill("hunyuan-zhang",150);
        set_skill("huashan-shenfa", 150);
        set_skill("zixia-gong", 160);
        set_skill("cuff", 150);
        set_skill("pishi-poyu", 150);
        set_skill("ziyin-yin", 130);
        set_skill("zhengqi-jue", 130);

        map_skill("cuff", "pishi-poyu");
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("blade", "liangyi-dao");
        map_skill("sword", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan-shenfa");
        
        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "pishi-poyu");

        create_family("��ɽ��", 12, "����");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        object me = this_player();

        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

void greeting(object me)
{     object obj = this_object();
	object sl1, sl2, sl3;
	object bro;
	string broname;
	int maxqi = obj->query("max_qi");
	int maxjingli = obj->query("max_jingli");
		
	if (obj->query("id") == "gao lao")
	{	broname = "ai lao";}
	else
	{	broname = "gao lao";}
	bro = present(broname, environment(obj));
	sl1 = present("du e", environment(obj));
	sl2 = present("du jie", environment(obj));
	sl3 = present("du nan", environment(obj));
      if (bro && sl1 && sl2 && sl3)
      {	if (!obj->is_fighting())
		{	if (random(2) == 1 )
                	{	obj->set("jingli", maxjingli);
				obj->set("eff_qi", maxqi);
				obj->set("qi", maxqi);
				command("say �������ֵ������������ɮ�Ľ�շ�ħȦ�ɡ�");
				obj->fight_obj(sl1);
				obj->fight_obj(sl2);
				obj->fight_obj(sl3);
				sl1->fight_obj(obj);
				sl2->fight_obj(obj);
				sl3->fight_obj(obj);
				if (!bro->is_fighting())
				{	bro->fight_obj(sl1);
					bro->fight_obj(sl2);
					bro->fight_obj(sl3);
					sl1->fight_obj(bro);
					sl2->fight_obj(bro);
					sl3->fight_obj(bro);
				}
				call_out("do_checking1", 2);
				//call_out("halt", 10);
                }
		}
	}
}
#include "/d/xiakedao/npc/zhanglao.c"
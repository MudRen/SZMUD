// Code of ShenZhou
// lu.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("½����", ({ "lu tianshu","lu" }) );
	set("nickname","����½��");
	set("gender", "����");
	set("age", 55);
	set("long",
		"����λ�������ˣ��ֳ�һ�ѹ�ͷ�󵶿����ƺ������ա�\n");
	set("str", 32);
	set("con", 25);
	set("dex", 25);
	set("max_neili", 1000);
	set("neili",2000);
//	set("title","�仨��ˮ�ϴ�");
	set("combat_exp", 500000);
        set("shen_type", 1);
	set("attitude", "heroism");
	set("jiali", 70);
	set("chat_chance", 3);
	set("chat_msg", ({

//	"½����޺޵�˵����Ѫ�����������������֪����ʲ��ط����ҵ����ǰ�����ʬ��Σ�\n",
	"½���㳤���е����䩤������ˮ��\n",
        }) );


	set_skill("blade", 150);
	set_skill("cuff", 120);
	set_skill("yanqing-quan", 150);
	set_skill("parry", 160);
	set_skill("force", 120);
	set_skill("liuhe-dao", 160);
	set_skill("ding-force", 120);
	set_skill("ding-dodge", 120);
	set_skill("dodge", 120);

	map_skill("blade", "liuhe-dao");
	map_skill("parry", "liuhe-dao");
	map_skill("cuff", "yanqing-quan");
	map_skill("force", "ding-force");
	map_skill("dodge", "ding-dodge");

	prepare_skill("cuff", "yanqing-quan");

	setup();

        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
              carry_object("/d/xueshan/obj/suyouguan"); 
	add_money("silver", 50);
}

void die()
{
        object corpse, killer;
        int i;

        if( !living(this_object()) ) revive(1);
        this_object()->clear_condition();
        if( objectp(killer = query_temp("last_damage_from")) ) 
	{
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
	 if (killer->query_temp("jidao",1)>0)
                {
                killer->add_temp("jidao", -1);
                killer->improve_skill("blade",
(int)(killer->query_skill("blade", 1)+1) * 40);
                killer->add("shen", -30000);

tell_object(killer,HIR"��ֻ����ɲ�Ǽ�����һ��ɱ����ӿ��������Ѫ����Ϊһ�壡\n",NOR);

		}
	}
	::die();
}



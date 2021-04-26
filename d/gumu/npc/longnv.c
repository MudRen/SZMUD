// longnv.c С��Ů
// by April 01/08/03
// update 01/08/06

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	object bj;

        set_name("С��Ů", ({ "xiao longnv", "long", "longnv" }));
        set("long", 
                "������һϮ��ɴ��İ��£������������������Ů����������������ʮ�꣬����\n"
				+"һͷ����ĺڷ�֮�⣬ȫ���ذס��������������ף�ֻ�Ǽ���������һ��Ѫɫ���Ե�\n"
				+"�԰��쳣��\n");
        set("gender", "Ů��");
		set("nickname","�������");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 25);
        set("con", 25);
        set("dex", 30);
        
        set("max_qi", 4000);
        set("max_jing", 5500);
        set("jiali", 200);
        set("neili", 6000);
        set("max_neili", 6000);
		set("jingli",4000);
		set("eff_jingli",4000);
		set("max_jingli",4000);

        set("combat_exp", 4500000);
        set("score", 10000);

        set_skill("force", 300);
        set_skill("yunu-xinjing", 300);
        set_skill("cuff", 300);
        set_skill("meinu-quan", 300);
        set_skill("sword", 320);
        set_skill("yunu-jianfa", 320);
        set_skill("finger", 300);
        set_skill("suhan-zhi", 300);
        set_skill("parry", 300);
        set_skill("dodge", 350);
        set_skill("feiyan-gong", 350);
		set_skill("bee-training",320);
		set_skill("lovingness",400);
		set_skill("parry",300);
		set_skill("suxin-jue",400);
		set_skill("zuoyou-hubo",300);
		set_skill("throwing",320);
		set_skill("whip",300);
		set_skill("jueqing-bian",300);
		set_skill("finger",300);
		set_skill("suhan-zhi",300);

        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "feiyan-gong");
        map_skill("cuff", "meinu-quan");
        map_skill("parry", "yunu-jianfa");
        map_skill("sword", "yunu-jianfa");

        prepare_skill("cuff", "meinu-quan");

        create_family("��Ĺ��", 3, "����");

		set("spouse/id", "yang guo");
		set("spouse/name", "���");
		set("spouse/title", "�ɷ�");

        set("chat_chance_combat", 50);

        setup();

        if( clonep() )
        {
                bj=carry_object("/d/gumu/obj/shunv-jian");
                if( objectp(bj) ) bj->wield();
					else carry_object("/clone/weapon/changjian")->wield();
				carry_object("/d/gumu/obj/white_silk")->wear();
        }
}

void init()
{
        object ob;

        ::init();
        return;
       
}

void attempt_apprentice(object ob)
{
    mapping fam;
	
	if (ob->query_per() < 25) {
		// ��ò<25����
	    command("say �����书������Ƿ������ӿ�Ϊ����ȥ��...");
		return;
	}

	if (ob->query("gender")!="Ů��"){
		// ֻ��Ů��
		command("say ����ѧ�ø����书��ȥ�����ɷ�����ɡ�");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
    command("recruit " + ob->query("id"));
}


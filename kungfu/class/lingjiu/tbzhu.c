// By Xuanyuan 11/18/2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();
void greeting(object);
void init();
void create()
{
	set_name("ʯɩ", ({ "shi sao", "shi", "sao" }));
	set("long",
	    "���ǡ����չ�������Ų������첿������.\n"+
	    "������ͯ�Ѷ���, ��������,������˪.\n");
	set("title", "���첿����");
	set("gender", "Ů��");
	set("age", 30);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 22);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 1300);
	set("max_qi", 1300);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 30);

	set("combat_exp", 500000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("literate",100);
	set_skill("music",100);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

        set("inquiry", ([
	"���չ�" : "������ǡ�\n",
	"ͯ��" : "�������չ������ˡ�\n",
	"����" : "���չ����ڵ������������������չ�Ψһ�����ӡ�\n",
	"������" : "�����������Ĺ����أ�\n",
        ]));

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	create_family("���չ�",4,"����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",25);
}
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "���չ�") 
	{
               message_vision("ʯɩ����$N���ͷ��΢΢Ц��Ц��\n",ob);
               return;
	}
        if (!(string)ob->query("family/family_name"))
	{
               message_vision("ʯɩ����$N΢Ц˵����������ʦ�İɣ����Ұɡ�\n",ob);
               return;
	}
}

int accept_object(object me, object ob)
{
	object qing;

        if( ob->query("money_id") ) 
	{
		if(ob->value() < 1000000)
		{
			command("heng");
			command("say ��򷢽л��Ӱ�������");
			return 1;
		}
		else
		{
			this_player()->apply_condition("zf_poison", 0);
			command("say �ã������ϵ��������ѽ��ˣ�");
			command("say �´θ������Ĺ���һ��Ҫ׼ʱ��");
			return 1;
		}
	}
}
#include "/kungfu/class/lingjiu/tianbu.h"
#include "/kungfu/class/lingjiu/auto_perform.h"
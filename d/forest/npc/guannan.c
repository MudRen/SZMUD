// Code of ShenZhou
// Jay 7/12/96

inherit NPC;

void create()
{
        set_name("Ԭ����", ({ "yuan guannan", "yuan", "guannan" }) );
        set("gender", "����" );
	set("title", "����");
        set("age", 24);
        set("long", 
	     "��������Ŀ����ü��ɣ����ռ�Ӣ�����ˡ�\n");
        set("str", 30);
        set("dex", 30);
        set("con", 27);
        set("int", 35);
        set("shen_type", 1);

	set_skill("blade",70);
        set_skill("unarmed", 70);
        set_skill("force", 60);
        set_skill("dodge", 75);

        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
	set("max_neili",800);
	set("jiali",20);

        set("combat_exp", 50000);

        set("attitude", "friendly");

	setup();

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	  "Ԭ���не���Ůò�ɲ���������\n",
	  "Ԭ����ʹһ�С��������Ϊ������\n",
	  "�������������̨����Ԭ���еĵ�������\n",
	  "Ԭ���е�����������ױ�ɽ��ݡ���\n",
	  "Ԭ����ʹһ�С�ϲ��˿������ľ��\n",
	  "Ԭ���е�����Ӣ����˫��������\n",
          "Ԭ���е�����ȴ�ȶ���ȼ����\n",
          "Ԭ���е�������������˫���\n",
          "Ԭ���е���������Ů������\n",
          "Ԭ���не�����ǧ��һ����������\n",
          "Ԭ���не�����ռ���˼����ϸ���\n",
          "Ԭ���не���������ӳ��ȸ����\n",
	}));

        set("chat_chance", 5);
        set("chat_msg", ({
             "Ԭ���г������������ƽ����ֿ��⾡�������Ʋ���ƶ���ɷ���¿�Х����������ȴͷ�Ͻ�����\n",
	}));
        carry_object("/d/city/obj/cloth")->wear();
	if (clonep()) 
	carry_object("/clone/unique/yuandao", "/clone/weapon/gangdao")->wield();
	add_money("gold",1);
}

int accept_kill()
{
	object wife;

	if (wife=present("xiao zhonghui", environment(this_object()))) {
		remove_call_out("killhim");
		call_out("killhim",1,wife, this_player());
	}
	return 1;
}

void killhim(object wife, object badguy)
{
	message_vision("$N���һ��������Ҫ�����๫����\n",wife);
	wife->kill_ob(badguy);
}

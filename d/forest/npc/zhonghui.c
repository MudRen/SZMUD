// Code of ShenZhou
// Jay 7/12/96

inherit NPC;

void create()
{
        set_name("���л�", ({ "xiao zhonghui", "xiao", "zhonghui" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long", 
	     "���������лۣ����������ǽ�����������͡�\n");
        set("str", 25);
        set("dex", 30);
        set("con", 27);
        set("int", 30);
        set("shen_type", 1);

	set_skill("blade",60);
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("dodge", 75);

        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 400);
	set("max_neili",400);
	set("jiali",20);

        set("combat_exp", 40000);

        set("attitude", "friendly");

	setup();

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	  "���л۽е���Ůò�ɲ���������\n",
	  "���л�ʹһ�С��������Ϊ������\n",
	  "�������������̨�������л۵ĵ�������\n",
	  "���л۵�����������ױ�ɽ��ݡ���\n",
	  "���л�ʹһ�С�ϲ��˿������ľ��\n",
	  "���л۵�����Ӣ����˫��������\n",
          "���л۵�����ȴ�ȶ���ȼ����\n",
          "���л۵�������������˫���\n",
          "���л۵���������Ů������\n",
          "���л۽е�����ǧ��һ����������\n",
          "���л۽е�����ռ���˼����ϸ���\n",
          "���л۽е���������ӳ��ȸ����\n",
	}));

        carry_object("/d/city/obj/pink_cloth")->wear();
	if (clonep())
	carry_object("/clone/unique/yangdao", "/clone/weapon/gangdao")->wield();
}

int accept_kill()
{
	object hus;

	if (hus=present("yuan guannan", environment(this_object()))) {
		remove_call_out("killhim");
		call_out("killhim",1,hus, this_player());
	}
	return 1;
}

void killhim(object hus, object badguy)
{
	message_vision("$N���һ��������Ҫ�������ӣ���\n",hus);
	hus->kill_ob(badguy);
}

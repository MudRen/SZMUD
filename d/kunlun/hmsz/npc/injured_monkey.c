// injured_monkey.c

inherit NPC;

void create()
{
	set_name("С��",({ "injured monkey", "monkey"}) );
	set("gender", "����");
	set("race", "Ұ��");
	set("age", 2);
	set("long", "����һֻ���������ĺ���,����ϴ���һ֦�̼�,��Ȼ�����ü�����.\n"
	    "�������м�֮�󣬲��ܴܸ���������ʱ��ƣ���ߣ���Ҳ����������\n");
	set("shen", 0);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
        set("attitude", "peaceful");

	set("max_qi", 400);
	set("qi", 400);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 0);
	set("combat_exp", 10000);

	set_skill("force", 35); 
	set_skill("strike", 35);
	set_skill("dodge", 35);
	set_skill("parry", 35);
	set("fight_times", 0);	

	set("chat_chance", 15);
	set("chat_msg", ({
		"���Ŀ����¶�������Ϳ־����ɫ��\n",
	}));
	setup();       
}

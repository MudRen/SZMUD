// Code of ShenZhou

inherit NPC;

void create()
{
	set_name("����", ({ "yangzong" }));
	set("long", 
"���Ǹ���̬��ӯ��������ᣬ���Ŷ�������£�˫��̻�ʣ�����΢¶��\n"
"���㣬���ų�ȹ��\n");
	set("gender", "Ů��");
	set("age", 20);
	set("attitude", "heroism");
	set("class","bonze");
	set("str", 28);
	set("int", 20);
	set("con", 32);
	set("dex", 31);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("parry", 80);
	set_skill("cuff", 80);
	set_skill("yujiamu-quan", 80);
	set_skill("sword", 90);
	set_skill("mingwang-jian", 90);

	map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
	map_skill("cuff", "yujiamu-quan");

	prepare_skill("cuff", "yujiamu-quan");

	setup();
	carry_object("/d/xingxiu/npc/obj/chouqun")->wear();
	carry_object("/d/qilian/obj/bichuan")->wear();
	carry_object("/clone/weapon/fachi")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	say("���ں�ʲΪ��˵��������٢��" + RANK_D->query_respect(ob)
	+ "��ƶ�����������ˡ�\n");
	return;
}

// Code of ShenZhou
// ling-zhi.c ��������

inherit NPC;

void create()
{
	set_name("��������", ({ "lingzhi shangren", "lingzhi", "shangren" }));
	set("long", 
"�����������������ɴ��ͷ��һ������Ȼ��ɮñ���Ǹ���ɮ��\n"
"����Ŀ���֮����վ�ű��������˸߳���һ����ͷ��\n");
	set_weight(10000000);
	set("class","lama");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 23);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 40);
	set("combat_exp", 700000);

        set_temp("apply/attack",  75);
        set_temp("apply/defense", 75);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand", 120);
        set_skill("lamaism", 80);
        set_skill("literate", 30);
	set_skill("longxiang-banruo", 100);
	set_skill("necromancy", 100);
	set_skill("dashou-yin", 120);
	set_skill("shenkongxing", 120);
	set_skill("staff", 120);
	set_skill("jingang-chu", 120);

	map_skill("parry", "dashou-yin");
	map_skill("hand", "dashou-yin");
	map_skill("dodge", "shenkongxing");
	map_skill("force", "longxiang-banruo");
	map_skill("staff", "jingang-chu");

	prepare_skill("hand", "dashou-yin");
	create_family("ѩɽ��", 10, "����");

        set("inquiry", ([
            "name" : "�ҵķ��������ǡ�",
            "here" : "��Ҳ������ԭ���ϣ����ϱ������飬��Ǹ��",
	    "����" : "�����Ƿ𷨵�һ�����ɣ��ֳƽ�����ڡ���̵��������ɻ���"
		     "�����ڡ����ڡ����ڡ������ڡ������ڵȡ�������ԭ��������"
		     "�����ڡ��������������ɵ�һ�������������������н����ܷ�"
                     "���ޡ�����ָ�𷨣�����ָ���䡣",
	    "��ެ" : "��ެ�����������������Ա����������ϡ�",
//	    "����" : "���·�Ϊ���ڵ��ӣ�ˡ�����ڡ�",
	    "������" : "����������ԭ�����ڴ��֡�",
	    "����" : "����д���ָ��Ժ��",
       ]) );

	setup();
//	carry_object("/clone/weapon/tongbo")->wield();
	carry_object("/d/qilian/obj/dahong-jiasha")->wear();
}
void attempt_apprentice(object ob)
{
	if( ob->query("family/family_name") != "ѩɽ��"
        && ob->query("family/family_name") != "Ѫ����"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }
        if (ob->query("class") != "lama") {
                command("say " + RANK_D->query_respect(ob) +
                        "�������������ڵĹ��򣬳�Եδ�Ϻ�����ߡ�");
                return;
        }
        else if ((int)ob->query_skill("longxiang-banruo", 1) < 45) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ���ڰ��������϶��µ㹦��");
                return;
        }
        else if ((int)ob->query("max_neili") < 400) {
                command("say " + RANK_D->query_respect(ob) +
                        "Ӧ���ټ���һ��������Ϊ�ɡ�");
                return;

}
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}

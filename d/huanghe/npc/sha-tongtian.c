// Code of ShenZhou
// sha-tongtian ɳͨ��

inherit NPC;

void create()
{
	set_name("ɳͨ��", ({ "sha tongtian", "sha" }));
	set("nickname", "��������");
	set("long", 
"ɳͨ���Ǹ�ͺ�ӣ�ͷ���͹���û���ͷ����˫Ŀ������˿����\n"
"��ͻ��������һ�����ࡣ���ӱ��꣬�书ȴ�ǳ���ظߣ�������\n"
"���˲�����\n");
	set("title", "�ƺӰ����");
	set("gender", "����");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25);
	set("int", 22);
	set("con", 21);
	set("dex", 22);
	
	set("max_qi", 900);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);
	set("combat_exp", 320000);

	set_skill("force", 95);
	set_skill("dodge", 90);
	set_skill("parry", 95);
	set_skill("cuff", 90);
	set_skill("wuxingbu", 100);
	set_skill("wuxing-quan", 120);
	set_skill("wuhu-gun", 120);
	set_skill("staff", 100);
	set_skill("ding-force", 100);

	map_skill("dodge", "wuxingbu");
	map_skill("staff", "wuhu-gun");
	map_skill("parry", "wuhu-gun");
	map_skill("cuff", "wuxing-quan");
	map_skill("force", "ding-force");

	prepare_skill("cuff", "wuxing-quan");

	setup();
	carry_object("/clone/weapon/tiejiang")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

/*void unconcious()
{
        command("say ���ֵܣ�����צ��̫Ӳ�����������");
	message_vision("\n$N������ǽ��һ�������������ֳ��İ����\n", this_object());
	destruct(this_object());
}
*/

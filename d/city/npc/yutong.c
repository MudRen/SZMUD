// Code of ShenZhou
// Jay 5/10/9, modified from /kungfu/class/dali/gaoshengtai.c

inherit NPC;
void create()
{
	set_name("����ͬ", ({ "yu yutong", "yu"}));
    set("long","����һλ�����������������������Ų���\n");
	set("title", "�컨��ʮ�ĵ���");
	set("nickname","������");
    set("gender", "����");
    set("age", 21);
    set_skill("cuff", 100);
    set_skill("jinyu-quan", 100);
    set_skill("dodge", 100);
    set_skill("duanshi-shenfa", 110);
    set_skill("parry", 90);
    set_skill("force", 105);
    set_skill("kurong-changong", 90);
    set_skill("duanjia-jian",80);
    set_skill("sword",80);
	set_skill("finger",90);
    set_skill("buddhism",110);
    map_skill("cuff","jinyu-quan");
    map_skill("sword","duanjia-jian");
    map_skill("dodge","duanshi-shenfa");
    map_skill("parry", "duanjia-jian");
    map_skill("force","kurong-changong");
    prepare_skill("cuff","jinyu-quan");

    set("str", 23);
    set("int", 23);
    set("con", 24);
    set("dex", 28);
    set("max_qi", 800);
    set("max_jing", 600);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 40);
    set("combat_exp", 500000);
	set("inquiry", ([
		"name" : "�����в��������������գ���������ͬ�����ߣ���δ֮�ࡣ"+
			"���ߣ���ˮ����֮��Ҳ��ͬ�ߣ����ӺͶ���֮ͬͬ������ͭ����֮ͭҲ��\n",
		"�컨��" : "��ô��������\n" ,
		"������" :  "��������׾����\n",
		"���" :  "����������ɩ����˵������ͬ��̾һ����\n",
		]));

	set("attitude", "heroism");
    set("shen_type", 1);

    setup();
    carry_object("/d/dali/obj/tiedi")->wield();
    carry_object("/d/city/obj/cloth")->wear();
}

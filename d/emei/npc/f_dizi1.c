// Code of ShenZhou
// /d/emei/npc/f_dizi1.c Ů���� 
// Shan: 96/07/09

inherit NPC;

void create()
{
	set_name("Ů����", ({ "dizi", "nu dizi" }));
	set("long", 
        "���Ƕ���ɽ�ĵ�������ӣ����ڽӴ���͵ġ�\n");
	set("gender", "Ů��");
	set("age", 18+random(5));
	set("attitude", "peaceful");
	set("shen_type", 1);

        set("str", 21+random(2));
        set("int", 21+random(2));
        set("con", 22+random(2));
        set("dex", 24+random(2));

	set("max_qi", 110+random(60));
	set("max_jing", 100+random(50));
	set("neili", 150+random(30));
	set("max_neili", 150+random(30));

	set("combat_exp", 2200+random(200));
	set("score", 1200+random(200));

	set_skill("force", 26+random(5));
	set_skill("dodge", 21+random(4));
	set_skill("unarmed", 19+random(2));
	set_skill("parry", 19+random(3));
	set_temp("apply/attack", 16+random(2));
	set_temp("apply/defense", 16+random(2));
	set_temp("apply/damage", 5+random(3));

	create_family("������", 5, "����");

	setup();
	
	carry_object(__DIR__"obj/hui-cloth")->wear();
	carry_object(__DIR__"obj/emei-shoes")->wear();
}

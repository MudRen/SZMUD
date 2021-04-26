// hunter.c ÁÔÈË
// jiuer 11/2001

inherit NPC;

void create()
{
	set_name("ÁÔÈË", ({ "lie ren", "hunter", "man" }) );
	set("long", "Ò»Î»½¡×³µÄÁÔÊÖ£¬ÉÃÓÃ¹­¼ıÉä·ÉÄñºÍÒ°ÊŞ¡£\n");

	set("age", 35);
	set("gender", "ÄĞĞÔ");

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 1500);
	
	set("max_qi", 200);
	set("qi", 200);
	
	set_skill("dodge", 10);
	set_skill("parry", 10);
	
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	
	carry_object("/d/dali/obj/hunterbow.c")->wield();
	carry_object("/clone/weapon/arrow.c");
	carry_object("/d/dali/obj/bcloth.c")->wear();
}

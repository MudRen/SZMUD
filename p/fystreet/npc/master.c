inherit NPC;
void create()
{	set_name("管家婆",({"room master","master"}));
	set("title","神州大街房管");
	set("gender","女性");
	set("age",22);
        set("combat_exp",10000);
	set("attitude","heroism");
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
#include "master_func.c"

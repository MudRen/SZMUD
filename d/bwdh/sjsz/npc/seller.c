//小厮
//troy 2001.12


inherit NPC;

void create()
{
	set_name("小厮", ({ "xiao si", "si" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
"这是试剑山庄的看门小厮，专门保管玩家物品。\n");
	set("shen_type", 1);
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	setup();
        carry_object("clone/misc/cloth")->wear();
	}



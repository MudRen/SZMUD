//Cracked by shenzhou
// tea girl.c 
// 酒儿  May 2002

inherit NPC;

void create()
{
        set_name("茶姑", ({ "cha gu", "girl" }) );
        set("gender", "女性" );
        set("age", 12);
        set("long", "她是买茶老汉的小闺女，身材还很单薄，脸蛋已出落的蛮标致的了。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");        
        setup();
        carry_object("/d/sanbuguan/obj/skirt")->wear();
}

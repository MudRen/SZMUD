/*-------------------------------------------------------------
** 文件名: guanshi.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 武馆花匠
**-----------------------------------------------------------*/

inherit NPC;
string random_chat();

void create()
{
        set_name("花匠", ({ "hua jiang","jiang","huajiang" }) );
        set("gender", "男性");
        set("age", 50);
        set("long",
                "这是一位老花匠，在武馆中从事养护花草的工作。\n");
        set("combat_exp", 3000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set("apply/attack", 10);
        set("apply/defense", 10);

        set_skill("blade", 35);
        set_skill("unarmed", 35);
        set_skill("parry", 35);
        set_skill("dodge", 35);
        
        set("chat_chance", 50);
	set("chat_msg", (: random_chat :));

        setup();

        carry_object("/d/dali/obj/huachu")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 1);
}

int random_chat() {

    switch (random(200)) {
    case 0:
        command("say 欢迎到来扬威武馆。");
	return 1;
    case 1:
        command("say 这里有好多的名花，小心不要踩坏了。");
	return 1;
    case 2:
        command("say 你不要采花，让马馆主看到，他会生气的。");
	return 1;
    case 3:
        command("say 马馆主花了好多的钱，买了很多的名花。");
	return 1;
    case 4:
        command("say 大理的花匠是我的师兄，我的手艺不比他差。");
	return 1;
    default:
	return 0;
    }
    return 1;
}

